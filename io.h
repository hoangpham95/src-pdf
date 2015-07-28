#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fstream>
#include "template.h"

using namespace std;

bool has_suffix(const string &str, const string &suffix)
{
  return str.size() >= suffix.size() &&
    str.compare(str.size() - suffix.size(), 
        suffix.size(), suffix) == 0;
}

string write_tex_template(string filename) {
  cout << "Opening file " << filename << "..." << endl;
  string start = "\\lstinputlisting";
  string line;
  const char* newfilename = filename.c_str();
  ifstream myfile (newfilename);

  if (myfile.is_open()) {
    start += "[caption=" + filename +"]{" + filename + "}\n";  
    myfile.close();
    cout << "Successfully convert file " << filename << " to latex." << endl;
    return start;
  }
  else {
    cerr << "Cannot open file!" << endl;
    return NULL;
  }
}

string recursive_tex_folder(string dirname) {
  DIR* dir;
  struct dirent *ent;

  string all = "";

  if ((dir = opendir(dirname.c_str())) != NULL) {
    while ((ent = readdir(dir)) != NULL) {
      struct stat st;
      stat(ent->d_name, &st);
      string name (ent->d_name);

      if (S_ISDIR(st.st_mode)) {
        if (name.compare(".") != 0 && name.compare("..") != 0) {
          cout << "Opening directory " << name << endl;
          all += recursive_tex_folder(name);
        }
      }

      else {
        if (has_suffix(name, ".cpp") || has_suffix(name, ".h")) {
          //all += ("File: " + dirname + "/" + name + '\n');
          string valid_dir = "File: " + dirname + "/" + name + '\n';
          all += generate_valid_tex_directory(valid_dir);
          all += write_tex_template(name);
          all += "\\clearpage\n";
        }
      }  
    }
  } 
  else {
    cout << "Folder " << dirname << " is not a valid folder!";
    return "";
  }
  return all;
}

bool check_file_existence(string dirname, string filename) {
  DIR* dir;
  struct dirent *ent;

  if ((dir = opendir(dirname.c_str())) != NULL) {
    while ((ent = readdir(dir)) != NULL) {
      struct stat st;
      stat(ent->d_name, &st);
      string name (ent->d_name);

      if (filename.compare(name) == 0) {
        return ! S_ISDIR(st.st_mode);
      }
    }

    return false;
  }

  return false;
}

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

bool has_valid_suffix(const string &filename) {
  for (int i = 0; i < SUPPORTED_LANGUAGES; i++) {
    if (has_suffix(filename, valid_file_extension[i]))
      return true;
  }
  return false;
}

string write_tex_template(string filename) {
  cout << "Opening FILE " << filename << "..." << endl;
  string start = "\\lstinputlisting";
  string line;
  const char* newfilename = filename.c_str();
  ifstream myfile (newfilename);

  if (myfile.is_open()) {
    start += "[caption=" + generate_valid_tex_directory(filename) +"]{" 
                         + filename + "}\n";  
    myfile.close();
    cout << "__Successfully__ convert file " << filename << " to latex." << endl;
    return start;
  }
  else {
    cerr << "==> !!!File " << filename << " cannot be opened!!!" << endl;
    return "";
  }
}

string recursive_tex_folder(string dirname) {
  DIR* dir;
  struct dirent *ent;

  string all = "";

  if ((dir = opendir(dirname.c_str())) != NULL) {
    while ((ent = readdir(dir)) != NULL) {
      struct stat st;
      lstat(ent->d_name, &st);
      string name (ent->d_name);

      if (S_ISDIR(st.st_mode)) {
        if (name.compare(".") != 0 && name.compare("..") != 0) {
          cout << "Opening DIRECTORY " << name << endl;
          all += recursive_tex_folder(dirname +"/" + name);
        }
      }

      else {
        if (has_valid_suffix(name)) {
          //all += ("File: " + dirname + "/" + name + '\n');
          string valid_dir = "File: " + dirname + "/" + name + '\n';
          all += generate_valid_tex_directory(valid_dir);
          all += write_tex_template(dirname +"/" + name);
          all += "\\clearpage\n";
        }
      }  
    }
  } 
  else {
    cout << " *** Folder " << dirname << " is not a valid folder!\n";
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

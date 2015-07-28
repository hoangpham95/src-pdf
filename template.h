#include "constants.h"
#include <cstdlib>

const string generating_template(string doc_class, string project_name, string author, 
                                string orientation, int font_size, string content) 
{
  string header = "\\documentclass[" + to_string(font_size) + "pt, " + orientation + ", a4paper]{" 
                  + doc_class +"}\n";
  header += "\\usepackage{listings}\n";
  header += "\\lstset{breaklines=true,"
                    "numbers=left,"
                    "firstnumber=1,"
                    "stepnumber=1,"
                    "numberfirstline=true}\n";
  // this options can be exempted up to user's preference
  header += "\\usepackage[left=2cm,right=2cm,top=2cm,bottom=2cm]{geometry}\n";
  header += "\\usepackage{color}\n"
            "\\definecolor{codegreen}{rgb}{0,0,6.0}\n"
            "\\definecolor{codegray}{rgb}{0.5,0.5,0.5}\n"
            "\\definecolor{codepurple}{rgb}{0.58, 0.0, 82}\n"
            "\\definecolor{backcolour}{rgb}{0.95, 0.95, 0.92}\n";

  header += "\\title{" + project_name +"}\n";
  header += "\\author{" + author +"}\n";
  header += "\\begin{document}\n\\lstlistoflistings\n\\maketitle\n" + content + "\n" + "\\end{document}\n";

  return header;
}

const string default_generation(string content) {
  return generating_template(DEFAULT_DOCUMENT_CLASS,
                             DEFAULT_AUTHOR,
                             DEFAULT_PROJECT_NAME,
                             DEFAULT_ORIENTATION,
                             DEFAULT_FONT_SIZE,
                             content);
}

const string generate_valid_tex_directory(string dirname) {
  const char* tex_template = "\\textbackslash ";
  int l = dirname.length();
  int backslash_count = 0;
  int underscore_count = 0;

  for (int i = 0; i < l; i++) {
    if (dirname.at(i) == '/')
      backslash_count += 1;
    if (dirname.at(i) == '_')
      underscore_count += 1;
  }

  int new_length = l + 14 * backslash_count + underscore_count;
  char* valid_dir = (char *) malloc(sizeof(char) * new_length);
  
  valid_dir[new_length] = '\0';

  for (int i = l-1; i >=0; i--) {
    if (dirname.at(i) == '/') {
      for (int j = 1; j <= 15; j++)
        valid_dir[new_length - j] = tex_template[15 - j];
      new_length = new_length - 15;
    }
    else if (dirname.at(i) == '_') {
      valid_dir[new_length - 1] = '_';
      valid_dir[new_length - 2] = '\\';
      new_length = new_length - 2;
    }
    else {
      valid_dir[new_length - 1] = dirname.at(i);
      new_length = new_length - 1;
    }
  }
  string result (valid_dir);
  return result;
}

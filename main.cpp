#include "io.h"

int main() {
  char* current = get_current_dir_name();
  string dir (current);
  string s = recursive_tex_folder(dir);
  string full_document = default_generation(s);
 
  ofstream output;
  output.open ("generated.tex");
  output << full_document;
  output.close();
  
  bool existing_info = check_file_existence(dir, "COPYRIGHT");
  if (existing_info) {
    cout << "You have the copyright form" << endl;
  } else {
    cout << no_copyright_form << endl;
  }

  return 0;
}

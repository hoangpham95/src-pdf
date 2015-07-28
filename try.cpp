#include <iostream>
#include "template.h"
#include <unistd.h>

int main() {
  const char* dir = get_current_dir_name();
  string cplusdir (dir);
  string valid = generate_valid_tex_directory(cplusdir);
  cout << valid << endl;
}

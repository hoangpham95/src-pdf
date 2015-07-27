#include "io.h"

int main() {
  char* current = get_current_dir_name();
  string dir (current);
  string s = recursive_tex_folder(dir);
  cout << s << endl;
}

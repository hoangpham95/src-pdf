// LaTeX constants
#include <iostream>

using namespace std;

#define DEFAULT_FONT_SIZE 11
#define DEFAULT_DOCUMENT_CLASS "article"
#define DEFAULT_PROJECT_NAME "Untitled"
#define DEFAULT_AUTHOR "(please make change to the *.tex file)"
#define DEFAULT_ORIENTATION ""

/*
typedef struct {
  string name;
  string author;
  string documentation;
} copyright;
*/

const char* no_copyright_form = "In order to make your document well-presented,"
                                "you should make a text file \"COPYRIGHT\" to include all"
                                "of the project information.";

const char* preferred_copyright_form = "PROJECT NAME: (fill here)\n"
                                       "AUTHOR: (fill here)\n"
                                       "DOCUMENTATION: (fill here)";


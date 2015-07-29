# src-pdf
I was inspired to do this because I am having a hard time reading linux source code 
on my editor vim, so I write this program to generate all source code to a pdf file.

User discretion advised. This program was only used and tested on Linux (Ubuntu 14.04 to be exact)

The pdf file will be generated in LaTeX. User should have installed miktex.

TODO:
- Need to add some comments for more details
- Writing a configure file to help user install the miktex (if user doesn't have it)
- Adding a feature of reading the README file (author, copyright, project name, etc.)

USAGE:
- To cleanup the folder, call "make clean".

- To compile the source code, call "make"
- After compiling, call "./main" to start generating the tex file
- Finally, call "make compile" and you will have the file "generated.pdf" in the folder 
you are working with

#include "interpreter/interpreter.h"
#include "output/batch.h"
#include "output/interactive.h"
#include "file_parser/file_parser.h"
#include <stdio.h>

int main(int argc, char **argv) {
  
  if (argc == 3) {
    interpreter();
    batch();
    printf("Args: '%s' & '%s'.\n", argv[1], argv[2]);
  } else if (argc == 1) {
    interpreter();
    printf("Entered in Interactive Mode\n");
    interactive();
  } else {
    printf("Call the program with 2 params (dataset & queries file) to batch mode.\n");
    printf("Call the program without params to interactive mode.\n");
    fprintf(stderr, "[ERROR] Invalid params\n");
    return 1;
  }

  return 0;
}
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc == 3) {
    printf("Entered in Batch Mode with params '%s' & '%s'.\n", argv[1], argv[2]);
  } else if (argc == 1) {
    printf("Entered in Interactive Mode\n");
  } else {
    printf("Call the program with 2 params (dataset & queries file) to batch mode.\n");
    printf("Call the program without params to interactive mode.\n");
    fprintf(stderr, "[ERROR] Invalid params\n");
    return 1;
  }

  return 0;
}
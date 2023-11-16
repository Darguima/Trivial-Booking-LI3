#include <stdio.h>

void print_invalid_path_error(char* name) {
  fprintf(stderr, "[ERROR] - Invalid %s path\n", name);
}
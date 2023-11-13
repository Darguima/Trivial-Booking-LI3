#include <stdio.h>
#include "interpreter/interpreter.h"

int batch() {
  printf("I'm in batch\n");
  interpreter();
  return 0;
}
#include <stdio.h>
#include "interpreter/interpreter.h"

int interactive() {
  printf("I'm in interactive\n");
  interpreter();
  return 0;
}
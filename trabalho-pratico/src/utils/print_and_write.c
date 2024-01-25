#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void print_and_write(FILE* file, const char* format, ...) {
  va_list args;

  va_start(args, format);

  vprintf(format, args);

  va_end(args);

  va_start(args, format);

  if (file != NULL) {
    vfprintf(file, format, args);
  }

  va_end(args);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <catalogs_creator/catalogs_creator.h>
#include <datatypes/datatypes.h>
#include <values_parser/values_parser.h>
#include "interpreter/interpreter.h"

int batch(char* queries_path, Catalogs CATALOGS) {
  char* line = NULL;
  int command_number = 1;

  FILE* file = fopen(queries_path, "r");

  if (file == NULL) {
    return -1;
  }

  size_t line_size = 0;

  while (getline(&line, &line_size, file) != -1) {
    size_t line_len = strlen(line);

    // Switch end of line from \n to \0
    line[line_len - 1] = '\0';

    interpreter(line, command_number, CATALOGS);
    command_number++;
  }

  free(line);
  fclose(file);

  return 0;
}
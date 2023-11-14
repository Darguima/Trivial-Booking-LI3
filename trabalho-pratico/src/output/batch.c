#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <datatypes/datatypes.h>
#include <values_parser/values_parser.h>
#include "interpreter/interpreter.h"

int batch(char* queries_path, Catalogs CATALOGS) {
  char* line = NULL;

  FILE* file = fopen(queries_path, "r");

  if (file == NULL) {
    perror("Erro ao abrir o file");
  }

  size_t line_size = 0;

  while (getline(&line, &line_size, file) != -1) {
    size_t line_len = strlen(line);

    // Switch end of line from \n to \0
    line[line_len - 1] = '\0';

    interpreter(line, CATALOGS);
  }

  free(line);
  fclose(file);

  return 0;
}
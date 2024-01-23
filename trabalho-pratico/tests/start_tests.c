#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogs_creator/catalogs_creator.h"
#include "datatypes/datatypes.h"
#include "interpreter/interpreter.h"
#include "utils/compare_files.h"
#include "utils/print_invalid_path_error.h"

void start_tests(Catalogs catalogs, char* queries_path, char* queries_expected_file_path) {
  FILE* file = fopen(queries_path, "r");
  int i = 1;
  char* line = NULL;
  size_t line_size = 0;

  while (getline(&line, &line_size, file) != -1) {
    size_t line_len = strlen(line);

    // Switch end of line from \n to \0
    line[line_len - 1] = '\0';
    interpreter(line, i, catalogs);
    compare_files(i, queries_expected_file_path);
    i++;
  }
  fclose(file);
  free(line);
}
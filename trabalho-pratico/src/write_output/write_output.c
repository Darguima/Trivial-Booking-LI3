#include "write_output/write_output.h"
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include "state/state.h"

FILE* create_output_file(int command_number) {
  char filename[256];
  sprintf(filename, "Resultados/command%d_output.txt", command_number);
  return fopen(filename, "w");
}

void write_output(FILE* file,
                  bool format_flag,
                  int results_acc,
                  output_key_value* output_array,
                  int output_array_len,
                  State state) {
  // Simple output
  if (state) {
    printf("\033[%d;%dH", 1 + results_acc, 4);  // move

    for (int i = 0; i < output_array_len; i++) {
      printf("%s", output_array[i].value);
      printf(i == output_array_len - 1 ? "\n" : ";");
    }
  }

  if (!format_flag) {
    for (int i = 0; i < output_array_len; i++) {
      fprintf(file, "%s", output_array[i].value);
      fprintf(file, i == output_array_len - 1 ? "\n" : ";");
    }

    // Formatted output
  } else {
    if (results_acc > 1)
      fprintf(file, "\n");

    fprintf(file, "--- %d ---\n", results_acc);
    for (int i = 0; i < output_array_len; i++) {
      fprintf(file, "%s: %s\n", output_array[i].field, output_array[i].value);
    }
  }
}

void close_output_file(FILE* file) {
  fclose(file);
}

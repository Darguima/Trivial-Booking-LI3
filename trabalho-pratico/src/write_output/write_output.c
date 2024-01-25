#include "write_output/write_output.h"
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

  char *array_copy = malloc((output_array_len + 1) * sizeof(char));

  if (state != NULL) {
    // output_array = [ ["key", "value"], ["key", "value"], ... ]
    // [["airline", "TAP"], ["origin", "LIS"], ...]

    for (int i = 0; i < output_array_len; i++) {
      array_copy[i] = strdup(output_array[i].field);
    }
    g_array_append_val(state->results, output_array);
  }
}

void close_output_file(FILE* file) {
  fclose(file);
}

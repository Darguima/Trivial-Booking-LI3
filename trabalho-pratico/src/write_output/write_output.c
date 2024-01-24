#include "write_output/write_output.h"
#include <stdbool.h>
#include <stdio.h>
#include "state/state.h"

FILE* create_output_file(int command_number) {
  char filename[256];
  sprintf(filename, "Resultados/command%d_output.txt", command_number);
  return fopen(filename, "w");
}

int is_State_Valid(const State* state) {
  return (state != NULL);
}

void write_output(FILE* file,
                  bool format_flag,
                  int results_acc,
                  output_key_value* output_array,
                  int output_array_len,
                  State* state) {
  // Simple output

  bool state_valid = is_State_Valid(state);

  if (!format_flag) {
    for (int i = 0; i < output_array_len; i++) {
      fprintf(file, "%s", output_array[i].value);
      fprintf(file, i == output_array_len - 1 ? "\n" : ";");
    }

    if (state_valid) {
      for (int i = 0; i < output_array_len; i++) {
        if (state->results_count < 1000) {
          strcpy(state->results[state->results_count], output_array[i].value);
          state->results_count++;
        }
      }
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

#include <stdbool.h>
#include <stdio.h>

typedef struct {
  char* field;
  char* value;
} output_key_value;

FILE* create_output_file(int command_number);
void write_output(FILE* file,
                  bool format_flag,
                  int results_acc,
                  output_key_value* output_array,
                  int output_array_len);
void close_output_file(FILE* file);
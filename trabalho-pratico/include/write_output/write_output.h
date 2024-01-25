//! @file
#include <stdbool.h>
#include <stdio.h>
#include "state/state.h"

/**
 * @brief Struct to store the output key value pairs.
 *
 * This struct is useful to print the output in a formatted way (with format flag).
 */
typedef struct {
  char* field;
  char* value;
} output_key_value;

/**
 * @brief Creates the output file..
 *
 * Will create the file, at the correct place and with the correct name (based on the command number)..
 *
 * @param command_number The position of the command on the queries list (file).
 * @return FILE* Pointer to the output file.
 */
FILE* create_output_file(int command_number);

/**
 * @brief Writes the output to the output file..
 *
 * Will write the output to the output file, based on the format flag..
 *
 * @param file Pointer to the output file.
 * @param format_flag Flag to indicate if the output should be formatted.
 * @param results_acc The position of the result on the results list (when many results are available).
 * @param output_array The output results, organized in a key value pair array.
 * @param output_array_len The length of the output array.
 */
void write_output(FILE* file,
                  bool format_flag,
                  int results_acc,
                  output_key_value* output_array,
                  int output_array_len,
                  State state);

/**
 * @brief Closes the output file.
 *
 * @param file Pointer to the output file.
 */
void close_output_file(FILE* file);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <datatypes/datatypes.h>
#include <values_parser/values_parser.h>
#include <write_errors/write_errors.h>

char** parse_line(char* line, int dataset_columns_amount) {
  char** line_elements = malloc(sizeof(char*) * (unsigned long)dataset_columns_amount);
  int i = 0;
  char* string;

  while ((string = strsep(&line, ";")) != NULL) {
    line_elements[i] = string;
    i++;
  }

  return (line_elements);
}

void file_parser(FILE* file, Catalogs CATALOGS, schema_name schema_name_) {
  // determine columns amount

  int dataset_columns_qnt = 0;
  if (schema_name_ == USERS) {
    dataset_columns_qnt = USERS_DATASET_COLUMNS;
  } else if (schema_name_ == FLIGHTS) {
    dataset_columns_qnt = FLIGHTS_DATASET_COLUMNS;
  } else if (schema_name_ == RESERVATIONS) {
    dataset_columns_qnt = RESERVATIONS_DATASET_COLUMNS;
  } else if (schema_name_ == PASSENGERS) {
    dataset_columns_qnt = PASSENGERS_DATASET_COLUMNS;
  }

  char* line = NULL;
  size_t line_size = 0;
  int values_parser_exit_code;

  // Ignoring file header
  if (getline(&line, &line_size, file)) {
  }

  while (getline(&line, &line_size, file) != -1) {
    size_t line_len = strlen(line);

    // Switch end of line from \n to \0
    line[line_len - 1] = '\0';

    char** line_elements = parse_line(line, dataset_columns_qnt);

    if (schema_name_ == USERS) {
      values_parser_exit_code = values_parser_users(line_elements, CATALOGS);
      if (values_parser_exit_code == 1) {
        write_users_errors(line_elements);
      }

    } else if (schema_name_ == FLIGHTS) {
      values_parser_exit_code = values_parser_flights(line_elements, CATALOGS);
      if (values_parser_exit_code == 1) {
        write_flights_errors(line_elements);
      }
    } else if (schema_name_ == RESERVATIONS) {
      values_parser_exit_code = values_parser_reservations(line_elements, CATALOGS);
      if (values_parser_exit_code == 1) {
        write_reservations_errors(line_elements);
      }

    } else if (schema_name_ == PASSENGERS) {
      values_parser_exit_code = values_parser_passengers(line_elements, CATALOGS);
      if (values_parser_exit_code == 1) {
        write_passengers_errors(line_elements);
      }
    }

    free(line_elements);
  }
  free(line);
}
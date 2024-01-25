#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "utils/number_to_string.h"
#include "utils/string_to_int.h"
#include "write_output/write_output.h"

int query_6(Catalogs catalogs, int command_number, bool format_flag, char* year, char* n) {
  int year_int = string_to_int(year);

  FILE* output_file = create_output_file(command_number);

  GList* top_n_airports_passengers_list = get_top_N_airports_passengers(catalogs->airports, year_int, string_to_int(n));
  GList* initial_list = top_n_airports_passengers_list;

  int acc = 1;
  for (GList* node = top_n_airports_passengers_list; node != NULL; node = node->next, acc++) {
    Airport airport = (Airport)node->data;

    char* airport_id = airport_get_id(airport);
    char* airport_passengers = int_to_string(airport_get_passenger_by_year(airport, year_int));

    output_key_value output_array[] = {{"name", airport_id}, {"passengers", airport_passengers}};

    write_output(output_file, format_flag, acc, output_array, 2);

    free(airport_id);
    free(airport_passengers);
  }

  g_list_free(initial_list);

  close_output_file(output_file);

  return 0;
}
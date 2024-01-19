#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "utils/number_to_string.h"
#include "utils/string_to_int.h"
#include "write_output/write_output.h"

int query_7(Catalogs catalogs, int command_number, bool format_flag, char* top_n_airports) {
  FILE* output_file = create_output_file(command_number);

  GList* top_n_airports_median_list =
      get_top_N_airports_median_delay(catalogs->airports, string_to_int(top_n_airports));
  GList* initial_list = top_n_airports_median_list;

  int acc = 1;
  for (GList* node = top_n_airports_median_list; node != NULL; node = node->next, acc++) {
    Airport airport = (Airport)node->data;

    char* airport_id = airport_get_id(airport);
    char* airport_median_delay = long_to_string(airport_get_median_delay(airport));

    output_key_value output_array[] = {{"name", airport_id}, {"median", airport_median_delay}};

    write_output(output_file, format_flag, acc, output_array, 2);

    free(airport_id);
    free(airport_median_delay);
  }

  g_list_free(initial_list);

  close_output_file(output_file);

  return 0;
}
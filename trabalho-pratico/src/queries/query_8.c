#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "state/state.h"
#include "utils/convert_string_to_seconds.h"
#include "utils/number_to_string.h"
#include "utils/string_to_int.h"
#include "write_output/write_output.h"

int query_8(Catalogs catalogs,
            int command_number,
            bool format_flag,
            char* id,
            char* begin_date,
            char* end_date,
            State state) {
  FILE* output_file = create_output_file(command_number);
  int hotel_id = string_to_int(id);
  Hotel hotel = get_hotel_by_id(catalogs->hotels, hotel_id);
  int total_revenue = hotel_get_total_revenue(hotel, begin_date, end_date);

  char* revenue_str = int_to_string(total_revenue);
  output_key_value output_array[] = {{"revenue", revenue_str}};
  write_output(output_file, format_flag, 1, output_array, 1, state);
  free(revenue_str);

  close_output_file(output_file);

  return 0;
}
#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "utils/number_to_string.h"
#include "utils/string_to_int.h"
#include "write_output/write_output.h"
#include "state/state.h"

int query_3(Catalogs catalogs, int command_number, bool format_flag, char* id, State state) {
  FILE* output_file = create_output_file(command_number);
  int hotel_id = string_to_int(id);
  Hotel hotel = get_hotel_by_id(catalogs->hotels, hotel_id);

  double rating = 0;

  if (hotel != NULL) {
    rating = hotel_get_rating(hotel);
  }
  char* rating_string = double_to_string(rating, 3);

  output_key_value output_array[] = {{"rating", rating_string}};
  write_output(output_file, format_flag, 1, output_array, 1);
  free(rating_string);
  close_output_file(output_file);

  return 0;
}
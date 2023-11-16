#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>
#include "utils/number_to_string.h"
#include "utils/string_to_int.h"
#include "write_output/write_output.h"
double calculate_average_rating(Catalogs CATALOGS, char* hotel_ID) {
  double ratingTotal = 0;
  double amount_of_rates = 0;

  GHashTableIter iter;
  gpointer key, value;

  g_hash_table_iter_init(&iter, CATALOGS->reservations);
  while (g_hash_table_iter_next(&iter, &key, &value)) {
    ReservationSchema reserva = (ReservationSchema)value;

    if (!g_strcmp0(reserva->hotel_id, hotel_ID) && g_strcmp0(hotel_ID, "") != 0) {
      ratingTotal += string_to_int(reserva->rating);
      amount_of_rates += 1;
    }
  }
  return (ratingTotal / amount_of_rates);
}

int query_3(Catalogs CATALOGS, int command_number, bool format_flag, char* id) {
  FILE* output_file = create_output_file(command_number);
  double average_rating = calculate_average_rating(CATALOGS, id);
  char* average_rating_string = double_to_string(average_rating, 3);

  output_key_value output_array[] = {{"rating", average_rating_string}};

  write_output(output_file, format_flag, 1, output_array, 1);
  free(average_rating_string);
  close_output_file(output_file);
  return 0;
}
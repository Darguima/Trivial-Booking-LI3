#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>
#include "utils/convert_string_to_seconds.h"
#include "utils/number_to_string.h"
#include "write_output/write_output.h"

int get_days_difference_inside_range(char* begin_date, char* end_date, char* date1, char* date2) {
  time_t time_date1 = convert_string_to_seconds(date1);
  time_t time_date2 = convert_string_to_seconds(date2);
  time_t time_interval_start = convert_string_to_seconds(begin_date);
  time_t time_interval_end = convert_string_to_seconds(end_date);
  if (time_date1 >= time_interval_start && time_date2 <= time_interval_end) {
    return (int)((time_date2 - time_date1) / (60 * 60 * 24));
  }

  if (time_date1 <= time_interval_start && time_date2 >= time_interval_end) {
    return (int)((time_interval_end - time_interval_start) / (60 * 60 * 24)) + 1;
  }

  if (time_date1 < time_interval_start && time_date2 >= time_interval_start && time_date2 <= time_interval_end) {
    return (int)((time_date2 - time_interval_start) / (60 * 60 * 24)) + 1;
  }

  if (time_date1 >= time_interval_start && time_date1 <= time_interval_end && time_date2 > time_interval_end) {
    return (int)((time_interval_end - time_date1) / (60 * 60 * 24)) + 1;
  }
  return 0;
}

int get_hotel_total_revenue(GHashTable* reservations, char* hotel_id, char* begin_date, char* end_date) {
  int total_revenue = 0;
  GHashTableIter iter;
  gpointer key, value;
  g_hash_table_iter_init(&iter, reservations);
  while (g_hash_table_iter_next(&iter, &key, &value)) {
    ReservationSchema reservation = (ReservationSchema)value;
    if (!strcmp(hotel_id, reservation->hotel_id) && strcmp(reservation->end_date, begin_date) >= 0 &&
        strcmp(reservation->begin_date, end_date) <= 0) {
      total_revenue +=
          reservation->price_per_night *
          get_days_difference_inside_range(begin_date, end_date, reservation->begin_date, reservation->end_date);
    }
  }
  return total_revenue;
}

int query_8(Catalogs CATALOGS, int command_number, bool format_flag, char* name, char* begin_date, char* end_date) {
  FILE* output_file = create_output_file(command_number);
  int revenue = get_hotel_total_revenue(CATALOGS->reservations, name, begin_date, end_date);
  char* revenue_str = int_to_string(revenue);
  output_key_value output_array[] = {{"revenue", revenue_str}};
  write_output(output_file, format_flag, 1, output_array, 1);
  free(revenue_str);
  close_output_file(output_file);

  return 0;
}
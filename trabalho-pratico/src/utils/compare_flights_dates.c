#include <catalogs_creator/flights_catalog.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils/convert_string_to_seconds.h>

gint compare_flights_dates(gconstpointer a, gconstpointer b) {
  Flight flight_1 = *(Flight*)a;
  Flight flight_2 = *(Flight*)b;

  char* begin_date_1 = flight_get_schedule_departure_date(flight_1);
  char* begin_date_2 = flight_get_schedule_departure_date(flight_2);

  int date_cmp = (int)(convert_string_to_seconds(begin_date_2) - convert_string_to_seconds(begin_date_1));
  free(begin_date_1);
  free(begin_date_2);
  if (date_cmp != 0) {
    return date_cmp;
  } else {
    char* id_1 = flight_get_id(flight_1);
    char* id_2 = flight_get_id(flight_2);
    int comp = strcmp(id_1, id_2);
    free(id_1);
    free(id_2);
    return comp;
  }
}
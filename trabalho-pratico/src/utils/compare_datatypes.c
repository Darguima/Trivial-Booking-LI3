#include <datatypes/datatypes.h>
#include <entities/flight_entity.h>
#include <entities/reservation_entity.h>
#include <glib.h>
#include <string.h>
#include <utils/convert_string_to_seconds.h>
#include "entities/airport_entity.h"
#include "stdio.h"

gint compare_string(gconstpointer a, gconstpointer b, gpointer user_data) {
  UNUSED(user_data);
  return strcmp((const char*)a, (const char*)b);
}

gint compare_long(gconstpointer a, gconstpointer b, gpointer user_data) {
  UNUSED(user_data);

  long r = *(long*)a - *(long*)b;

  return (gint)r;
}

gint compare_airports_by_median_delay(gconstpointer a, gconstpointer b) {
  Airport airport_a = *(Airport*)a;
  Airport airport_b = *(Airport*)b;

  long median_delay_a = airport_get_median_delay(airport_a);
  long median_delay_b = airport_get_median_delay(airport_b);

  gint r = (gint)(median_delay_b - median_delay_a);

  if (r != 0)
    return r;
  else {
    char* id_a = airport_get_id(airport_a);
    char* id_b = airport_get_id(airport_b);

    r = strcmp(id_a, id_b);

    free(id_a);
    free(id_b);

    return r;
  }
}

gint compare_airports_by_passengers(gconstpointer a, gconstpointer b, gpointer user_data) {
  Airport airport_a = *(Airport*)a;
  Airport airport_b = *(Airport*)b;
  int year = *(int*)user_data;

  long passengers_a = airport_get_passenger_by_year(airport_a, year);
  long passengers_b = airport_get_passenger_by_year(airport_b, year);

  gint r = (gint)(passengers_b - passengers_a);

  if (r != 0)
    return r;
  else {
    char* id_a = airport_get_id(airport_a);
    char* id_b = airport_get_id(airport_b);

    r = strcmp(id_a, id_b);

    free(id_a);
    free(id_b);

    return r;
  }
}

gint compare_flights_by_sched_dep_date(gconstpointer a, gconstpointer b) {
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
    int id_1 = flight_get_id(flight_1);
    int id_2 = flight_get_id(flight_2);

    return id_1 - id_2;
  }
}

gint compare_reservations_by_begin_date(gconstpointer a, gconstpointer b) {
  Reservation reservation_1 = *(Reservation*)a;
  Reservation reservation_2 = *(Reservation*)b;

  char* begin_date_1 = reservation_get_begin_date(reservation_1);
  char* begin_date_2 = reservation_get_begin_date(reservation_2);
  int date_cmp = (int)(convert_string_to_seconds(begin_date_2) - convert_string_to_seconds(begin_date_1));
  free(begin_date_1);
  free(begin_date_2);
  if (date_cmp != 0) {
    return date_cmp;
  } else {
    int id_1 = reservation_get_id(reservation_1);
    int id_2 = reservation_get_id(reservation_2);

    return id_1 - id_2;
  }
}
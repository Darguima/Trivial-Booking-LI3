#include <catalogs_creator/reservations_catalog.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils/convert_string_to_seconds.h>

gint compare_reservations_dates(gconstpointer a, gconstpointer b) {
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
    char* id_1 = reservation_get_id(reservation_1);
    char* id_2 = reservation_get_id(reservation_2);
    int comp = strcmp(id_1, id_2);
    free(id_1);
    free(id_2);
    return comp;
  }
}
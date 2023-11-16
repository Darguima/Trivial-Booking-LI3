#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "utils/number_to_string.h"
#include "write_output/write_output.h"

gint compare_reservations_order(gconstpointer a, gconstpointer b) {
  ReservationSchema reservationA = (ReservationSchema)a;
  ReservationSchema reservationB = (ReservationSchema)b;

  int date_comp = g_strcmp0(reservationB->begin_date, reservationA->begin_date);

  if (date_comp != 0) {
    return date_comp;
  }

  return g_strcmp0(reservationA->id, reservationB->id);
}

GList* getReservationsByHotelId(GHashTable* reservations_table, const char* target_hotel_id) {
  GList* result = NULL;
  GHashTableIter iter;
  gpointer key, value;

  g_hash_table_iter_init(&iter, reservations_table);
  while (g_hash_table_iter_next(&iter, &key, &value)) {
    ReservationSchema reservation = (ReservationSchema)value;

    if (g_strcmp0(reservation->hotel_id, target_hotel_id) == 0) {
      result = g_list_append(result, reservation);
    }
  }

  return result;
}

int query_4(Catalogs catalogs, int command_number, bool format_flag, char* hotel_id) {
  GList* hotelReservations = getReservationsByHotelId(catalogs->reservations, hotel_id);

  hotelReservations = g_list_sort(hotelReservations, compare_reservations_order);

  FILE* output_file = create_output_file(command_number);

  int results_acc = 1;
  for (GList* iterator = hotelReservations; iterator != NULL; iterator = iterator->next, results_acc++) {
    ReservationSchema reservation = (ReservationSchema)iterator->data;

    char* total_price_str = double_to_string(reservation->total_price, 3);

    output_key_value output_array[] = {
        {"id", reservation->id},           {"begin_date", reservation->begin_date}, {"end_date", reservation->end_date},
        {"user_id", reservation->user_id}, {"rating", reservation->rating},         {"total_price", total_price_str},
    };

    write_output(output_file, format_flag, results_acc, output_array, 6);

    free(total_price_str);
  }

  g_list_free(hotelReservations);
  close_output_file(output_file);

  return 0;
}
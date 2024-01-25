#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include "catalogs_creator/catalogs_creator.h"
#include "datatypes/datatypes.h"
#include "state/state.h"
#include "utils/number_to_string.h"
#include "utils/string_to_int.h"
#include "write_output/write_output.h"
#define UNUSED(x) (void)(x)


int query_4(Catalogs catalogs, int command_number, bool format_flag, char* id, State state)) {
  FILE* output_file = create_output_file(command_number);
  int hotel_id = string_to_int(id);
  Hotel hotel = get_hotel_by_id(catalogs->hotels, hotel_id);
  GArray* reservations = hotel_get_reservations(hotel);

  int results_acc = 1;
  for (guint i = 0; i < reservations->len; i++) {
    Reservation currentReservation = g_array_index(reservations, Reservation, i);
    char reservation_id[16];
    sprintf(reservation_id, "Book%010d", reservation_get_id(currentReservation));
    char* begin_date = reservation_get_begin_date(currentReservation);
    char* end_date = reservation_get_end_date(currentReservation);
    char* user_id = reservation_get_user_id(currentReservation);
    char rating = reservation_get_rating(currentReservation);
    char* total_price_str = double_to_string(reservation_get_total_price(currentReservation), 3);

    char rating_str[2];

    rating_str[0] = rating;

    rating_str[1] = '\0';

    output_key_value output_array[] = {
        {"id", reservation_id}, {"begin_date", begin_date}, {"end_date", end_date},
        {"user_id", user_id},   {"rating", rating_str},     {"total_price", total_price_str},
    };

    write_output(output_file, format_flag, results_acc, output_array, 6,state);
    results_acc++;
    free(begin_date);
    free(end_date);
    free(user_id);
    free(total_price_str);
  }

  g_array_free(reservations, TRUE);
  close_output_file(output_file);

  return 0;
}
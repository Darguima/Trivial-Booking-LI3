#include "queries/query_2.h"
#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "catalogs_creator/users_catalog.h"
#include "datatypes/datatypes.h"
#include "state/state.h"
#include "utils/convert_string_to_seconds.h"
#include "utils/extract_date_without_time.h"
#include "utils/number_to_string.h"
#include "write_output/write_output.h"

int query_2(Catalogs catalogs, int command_number, bool format_flag, char* id, char* optional, State state) {
  FILE* output_file = create_output_file(command_number);
  User user = get_user_by_id(catalogs->users, id);
  if (user == NULL || !user_get_is_active(user)) {
    fclose(output_file);
    return 0;
  }
  int result_acc = 1;

  GArray* array_of_flights = NULL;
  guint flights_i = 0, flights_len = 0;
  if (optional == NULL || !strcmp("flights", optional)) {
    array_of_flights = user_get_flights(user);
    flights_len = array_of_flights->len;
  }

  GArray* array_of_reservations = NULL;
  guint reservations_i = 0, reservations_len = 0;
  if (optional == NULL || !strcmp("reservations", optional)) {
    array_of_reservations = user_get_reservations(user);
    reservations_len = array_of_reservations->len;
  }

  while (flights_i < flights_len || reservations_i < reservations_len) {
    Flight flight = NULL;
    Reservation reservation = NULL;
    char* begin_flight_date = NULL;
    char* begin_reservation_date = NULL;

    if (flights_i < flights_len) {
      flight = g_array_index(array_of_flights, Flight, flights_i);
      begin_flight_date = flight_get_schedule_departure_date(flight);
    }

    if (reservations_i < reservations_len) {
      reservation = g_array_index(array_of_reservations, Reservation, reservations_i);
      begin_reservation_date = reservation_get_begin_date(reservation);
    }

    int date_cmp = 0;

    if (begin_flight_date != NULL && begin_reservation_date != NULL)
      date_cmp =
          (int)(convert_string_to_seconds(begin_reservation_date) - convert_string_to_seconds(begin_flight_date));
    else if (begin_flight_date != NULL)
      date_cmp = -1;
    else if (begin_reservation_date != NULL)
      date_cmp = 1;

    if (date_cmp <= 0) {
      char flight_id[11];
      sprintf(flight_id, "%010d", flight_get_id(flight));

      char* begin_flight_date_without_time = extract_date_without_time(begin_flight_date);
      if (optional != NULL && date_cmp == -1) {
        output_key_value output_array[] = {{"id", flight_id}, {"date", begin_flight_date_without_time}};
        write_output(output_file, format_flag, result_acc, output_array, 2, state);
      } else {
        output_key_value output_array[] = {
            {"id", flight_id}, {"date", begin_flight_date_without_time}, {"type", "flight"}};
        write_output(output_file, format_flag, result_acc, output_array, 3, state);
      }
      free(begin_flight_date_without_time);
      if (begin_reservation_date) {
        free(begin_reservation_date);
      }
      result_acc++;
      flights_i++;
    } else {
      char reservation_id[16];
      sprintf(reservation_id, "Book%010d", reservation_get_id(reservation));

      if (optional != NULL && date_cmp == 1) {
        output_key_value output_array[] = {{"id", reservation_id}, {"date", begin_reservation_date}};
        write_output(output_file, format_flag, result_acc, output_array, 2, state);

      } else {
        output_key_value output_array[] = {
            {"id", reservation_id}, {"date", begin_reservation_date}, {"type", "reservation"}};
        write_output(output_file, format_flag, result_acc, output_array, 3, state);
      }

      reservations_i++;
      result_acc++;
      free(begin_reservation_date);
      if (begin_flight_date) {
        free(begin_flight_date);
      }
    }
  }
  if (array_of_flights) {
    g_array_free(array_of_flights, TRUE);
  }

  if (array_of_reservations) {
    g_array_free(array_of_reservations, TRUE);
  }

  fclose(output_file);

  return 0;
}
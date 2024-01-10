#include "queries/query_2.h"
#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "catalogs_creator/users_catalog.h"
#include "datatypes/datatypes.h"
#include "utils/convert_string_to_seconds.h"
#include "utils/extract_date_without_time.h"
#include "write_output/write_output.h"

int query_2(Catalogs catalogs, int command_number, bool format_flag, char* id, char* optional) {
  FILE* output_file = create_output_file(command_number);
  User user = get_user_by_id(catalogs->users, id);
  if (user == NULL || !user_get_is_active(user)) {
    fclose(output_file);
    return 0;
  }
  int result_acc = 1;
  if (optional == NULL) {
    RelationArray flights_array = user_get_flights(user);
    if (!user_get_flights_sorted(flights_array)) {
      user_sort_flights_array(flights_array);
    }

    RelationArray reservations_array = user_get_reservations(user);
    if (!user_get_reservations_sorted(reservations_array)) {
      user_sort_reservations_array(reservations_array);
    }
    GArray* array_of_flights = user_get_flights_array(flights_array);
    GArray* array_of_reservations = user_get_reservations_array(reservations_array);

    guint flights_i = 0;
    guint reservations_i = 0;
    while (flights_i < array_of_flights->len && reservations_i < array_of_reservations->len) {
      Flight flight = g_array_index(array_of_flights, Flight, flights_i);
      Reservation reservation = g_array_index(array_of_reservations, Reservation, reservations_i);
      char* begin_flight_date = flight_get_begin_date(flight);
      char* begin_reservation_date = reservation_get_begin_date(reservation);
      int date_cmp =
          (int)(convert_string_to_seconds(begin_reservation_date) - convert_string_to_seconds(begin_flight_date));
      if (date_cmp <= 0) {
        char* flight_id = flight_get_id(flight);
        char* begin_flight_date_without_time = extract_date_without_time(begin_flight_date);
        output_key_value output_array[] = {
            {"id", flight_id}, {"date", begin_flight_date_without_time}, {"type", "flight"}};
        write_output(output_file, format_flag, result_acc, output_array, 3);
        free(flight_id);
        free(begin_flight_date_without_time);
        free(begin_reservation_date);
        result_acc++;
        flights_i++;
      } else {
        char* reservation_id = reservation_get_id(reservation);
        output_key_value output_array[] = {
            {"id", reservation_id}, {"date", begin_reservation_date}, {"type", "reservation"}};
        write_output(output_file, format_flag, result_acc, output_array, 3);
        reservations_i++;
        result_acc++;
        free(reservation_id);
        free(begin_flight_date);
        free(begin_reservation_date);
      }
    }
    if (flights_i == array_of_flights->len) {
      for (guint i = reservations_i; i < array_of_reservations->len; i++) {
        Reservation reservation = g_array_index(array_of_reservations, Reservation, i);
        char* begin_date = reservation_get_begin_date(reservation);
        char* reservation_id = reservation_get_id(reservation);
        output_key_value output_array[] = {{"id", reservation_id}, {"date", begin_date}, {"type", "reservation"}};
        write_output(output_file, format_flag, result_acc, output_array, 3);
        result_acc++;
        free(begin_date);
        free(reservation_id);
      }

    }

    else {
      for (guint i = flights_i; i < array_of_flights->len; i++) {
        Flight flight = g_array_index(array_of_flights, Flight, i);
        char* begin_date = flight_get_begin_date(flight);
        char* begin_date_without_time = extract_date_without_time(begin_date);
        char* flight_id = flight_get_id(flight);
        output_key_value output_array[] = {{"id", flight_id}, {"date", begin_date_without_time}, {"type", "flight"}};
        write_output(output_file, format_flag, result_acc, output_array, 3);
        result_acc++;
        free(begin_date_without_time);
        free(flight_id);
      }
    }

  } else if (!strcmp("flights", optional)) {
    RelationArray flights_array = user_get_flights(user);
    if (!user_get_flights_sorted(flights_array)) {
      user_sort_flights_array(flights_array);
    }
    GArray* array_of_flights = user_get_flights_array(flights_array);
    for (guint i = 0; i < array_of_flights->len; i++) {
      Flight flight = g_array_index(array_of_flights, Flight, i);
      char* begin_date = flight_get_begin_date(flight);
      char* begin_date_without_time = extract_date_without_time(begin_date);
      char* flight_id = flight_get_id(flight);
      output_key_value output_array[] = {{"id", flight_id}, {"date", begin_date_without_time}};
      write_output(output_file, format_flag, result_acc, output_array, 2);
      result_acc++;
      free(begin_date_without_time);
      free(flight_id);
    }
  } else {
    RelationArray reservations_array = user_get_reservations(user);
    if (!user_get_reservations_sorted(reservations_array)) {
      user_sort_reservations_array(reservations_array);
    }
    GArray* array_of_reservations = user_get_reservations_array(reservations_array);
    for (guint i = 0; i < array_of_reservations->len; i++) {
      Reservation reservation = g_array_index(array_of_reservations, Reservation, i);
      char* begin_date = reservation_get_begin_date(reservation);
      char* reservation_id = reservation_get_id(reservation);
      output_key_value output_array[] = {{"id", reservation_id}, {"date", begin_date}};
      write_output(output_file, format_flag, result_acc, output_array, 2);
      result_acc++;
      free(begin_date);
      free(reservation_id);
    }
  }

  fclose(output_file);
  return 0;
}
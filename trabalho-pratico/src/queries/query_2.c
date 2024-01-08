#include "queries/query_2.h"
#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "catalogs_creator/users_catalog.h"
#include "datatypes/datatypes.h"
#include "utils/convert_string_to_seconds.h"
#include "utils/extract_date_without_time.h"
#include "write_output/write_output.h"

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

gint compare_flights_dates(gconstpointer a, gconstpointer b) {
  Flight flight_1 = *(Flight*)a;
  Flight flight_2 = *(Flight*)b;

  char* begin_date_1 = flight_get_begin_date(flight_1);
  char* begin_date_2 = flight_get_begin_date(flight_2);

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

int query_2(Catalogs catalogs, int command_number, bool format_flag, char* id, char* optional) {

  printf("I'm in query_2\n");
  FILE* output_file = create_output_file(command_number);
  User user = get_user_by_id(catalogs->users, id);
  if (user == NULL || !user_is_active(user)) {
    fclose(output_file);
    return 0;
  }
  int result_acc = 1;
  if (optional == NULL) {
    RelationArray flights_array = user_get_flights(user);
    if (!flights_array->is_sorted) {
      g_array_sort(flights_array->values, compare_flights_dates);
      flights_array->is_sorted = 1;
    }

    RelationArray reservations_array = user_get_reservations(user);
    if (!reservations_array->is_sorted) {
      g_array_sort(reservations_array->values, compare_reservations_dates);
      reservations_array->is_sorted = 1;
    }

    guint flights_i = 0;
    guint reservations_i = 0;
    while (flights_i < flights_array->values->len && reservations_i < reservations_array->values->len) {
      Flight flight = g_array_index(flights_array->values, Flight, flights_i);
      Reservation reservation = g_array_index(reservations_array->values, Reservation, reservations_i);
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
    if (flights_i == flights_array->values->len) {
      for (guint i = reservations_i; i < reservations_array->values->len; i++) {
        Reservation reservation = g_array_index(reservations_array->values, Reservation, i);
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
      for (guint i = flights_i; i < flights_array->values->len; i++) {
        Flight flight = g_array_index(flights_array->values, Flight, i);
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
    if (!flights_array->is_sorted) {
      g_array_sort(flights_array->values, compare_flights_dates);
      flights_array->is_sorted = 1;
    }
    for (guint i = 0; i < flights_array->values->len; i++) {
      Flight flight = g_array_index(flights_array->values, Flight, i);
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
    if (!reservations_array->is_sorted) {
      g_array_sort(reservations_array->values, compare_reservations_dates);
      reservations_array->is_sorted = 1;
    }
    for (guint i = 0; i < reservations_array->values->len; i++) {
      Reservation reservation = g_array_index(reservations_array->values, Reservation, i);
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
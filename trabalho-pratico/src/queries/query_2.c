#include "queries/query_2.h"
#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>
#include "catalogs_setup/users_catalog.h"
#include "utils/convert_string_to_seconds.h"
#include "utils/extract_date_without_time.h"
#include "write_output/write_output.h"

//! @brief Retrieves the scheduled departure date of a flight
char* get_flight_date(char* flight_id, GHashTable* flights) {
  FlightSchema flight = g_hash_table_lookup(flights, flight_id);
  return (flight->schedule_departure_date);
}

/**
 * @brief Retrieves user reservations and flights from catalogs
 *
 * Retrieves user reservations and flights based on the provided user ID from the catalogs.
 *
 * @param id The ID of the user to retrieve reservations and flights for
 * @param CATALOGS The catalogs struct created by the function `catalogs_creator()`
 * @return GList* Returns a linked list containing user reservations and flights
 */
GList* get_user_reservations_and_flights(char* id, Catalogs CATALOGS) {
  GList* user_reservations_and_flights = NULL;
  // UserReservationsFlights new_user_reservation_and_flight  = malloc(sizeof(userReservationsFlights));
  GHashTableIter iter;
  gpointer key, value;

  g_hash_table_iter_init(&iter, CATALOGS->passengers);
  while (g_hash_table_iter_next(&iter, &key, &value)) {
    PassengerSchema passenger = (PassengerSchema)value;
    if (g_strcmp0(passenger->user_id, id) == 0) {
      UserReservationsFlights new_user_reservation_and_flight = malloc(sizeof(struct userReservationsFlights));
      new_user_reservation_and_flight->id = strdup(passenger->flight_id);
      new_user_reservation_and_flight->type = strdup("flight");
      new_user_reservation_and_flight->start_date = strdup(get_flight_date(passenger->flight_id, CATALOGS->flights));
      user_reservations_and_flights = g_list_append(user_reservations_and_flights, new_user_reservation_and_flight);
    }
  }

  g_hash_table_iter_init(&iter, CATALOGS->reservations);
  while (g_hash_table_iter_next(&iter, &key, &value)) {
    ReservationSchema reservation = (ReservationSchema)value;

    if (g_strcmp0(reservation->user_id, id) == 0) {
      UserReservationsFlights new_user_reservation_and_flight2 = malloc(sizeof(struct userReservationsFlights));
      new_user_reservation_and_flight2->id = strdup(reservation->id);
      new_user_reservation_and_flight2->type = strdup("reservation");
      new_user_reservation_and_flight2->start_date = strdup(reservation->begin_date);
      user_reservations_and_flights = g_list_append(user_reservations_and_flights, new_user_reservation_and_flight2);
    }
  }
  return user_reservations_and_flights;
}

//! @brief Compares dates in the UserReservationsFlights struct
gint compare_dates(gconstpointer a, gconstpointer b) {
  UserReservationsFlights schemaA = (UserReservationsFlights)a;
  UserReservationsFlights schemaB = (UserReservationsFlights)b;

  int date_cmp = (int)(convert_string_to_seconds(schemaB->start_date) - convert_string_to_seconds(schemaA->start_date));
  if (date_cmp != 0) {
    return date_cmp;
  } else {
    if (!strcmp("reservation", schemaA->type) && !strcmp("reservation", schemaB->type)) {
      return (strcmp(schemaA->id, schemaB->id));
    } else if (!strcmp("reservation", schemaA->type) && !strcmp("flight", schemaB->type)) {
      return (strcmp(schemaA->id + 4, schemaB->id));
    } else if (!(strcmp("flight", schemaA->type) && !strcmp("reservation", schemaB->type))) {
      return (strcmp(schemaA->id, schemaB->id + 4));
    } else {
      return (strcmp(schemaA->id, schemaB->id));
    }
  }
}

//! @brief Frees memory allocated for UserReservationsFlights struct
void free_reservations_and_flights(gpointer data) {
  UserReservationsFlights item = (UserReservationsFlights)data;
  free(item->id);
  free(item->start_date);
  free(item->type);
  free(item);
}

int query_2(Catalogs CATALOGS, int command_number, bool format_flag, char* id, char* optional) {
  FILE* output_file = create_output_file(command_number);
  User user = get_user_by_id(CATALOGS->users, id);
  if (user == NULL || !user->account_status) {
    fclose(output_file);
    return 0;
  }

  GList* user_reservations_and_flights = get_user_reservations_and_flights(id, CATALOGS);
  user_reservations_and_flights = g_list_sort(user_reservations_and_flights, compare_dates);
  int result_acc = 1;

  for (GList* iterator = user_reservations_and_flights; iterator != NULL; iterator = iterator->next) {
    UserReservationsFlights user_stats = (UserReservationsFlights)iterator->data;
    if (optional == NULL) {
      if (!strcmp("flight", user_stats->type)) {
        char* new_date = extract_date_without_time(user_stats->start_date);
        output_key_value output_array[] = {{"id", user_stats->id}, {"date", new_date}, {"type", user_stats->type}};
        write_output(output_file, format_flag, result_acc, output_array, 3);
        free(new_date);
        result_acc++;

      } else {
        output_key_value output_array[] = {
            {"id", user_stats->id}, {"date", user_stats->start_date}, {"type", user_stats->type}};
        write_output(output_file, format_flag, result_acc, output_array, 3);
        result_acc++;
      }
    } else if (!strcmp(optional, "reservations")) {
      if (!strcmp(user_stats->type, "reservation")) {
        output_key_value output_array[] = {{"id", user_stats->id}, {"date", user_stats->start_date}};
        write_output(output_file, format_flag, result_acc, output_array, 2);

        result_acc++;
      } else {
      }
    } else {
      if (!strcmp(user_stats->type, "flight")) {
        char* new_date = extract_date_without_time(user_stats->start_date);
        output_key_value output_array[] = {{"id", user_stats->id}, {"date", new_date}};
        write_output(output_file, format_flag, result_acc, output_array, 2);
        result_acc++;
        free(new_date);
      }
    }
  }

  g_list_free_full(user_reservations_and_flights, free_reservations_and_flights);
  fclose(output_file);

  return 0;
}
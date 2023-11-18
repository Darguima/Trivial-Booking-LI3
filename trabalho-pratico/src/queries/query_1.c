#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <utils/number_to_string.h>
#include "ctype.h"
#include "utils/calculate_stats.h"
#include "write_output/write_output.h"

//! @brief Checks if a user exists in the user table
int is_user(GHashTable* user_table, char* id) {
  UserSchema user = g_hash_table_lookup(user_table, id);
  return (user == NULL) ? 0 : 1;
}

//! @brief Checks if a flight exists in the flights table
int is_flight(GHashTable* flights_table, char* id) {
  FlightSchema flight = g_hash_table_lookup(flights_table, id);
  return (flight == NULL) ? 0 : 1;
}

//! @brief Checks if a reservation exists in the reservations table
int is_reservation(GHashTable* reservations_table, char* id) {
  ReservationSchema reservation = g_hash_table_lookup(reservations_table, id);
  return (reservation == NULL) ? 0 : 1;
}

//! @brief Writes user data to an output file
int write_user_data(GHashTable* user_table, char* id, FILE* output_file, bool format_flag) {
  UserSchema user = g_hash_table_lookup(user_table, id);
  if (user->account_status) {
    char* number_of_flights = int_to_string(user->number_of_flights);
    char* number_of_reservations = int_to_string(user->number_of_reservations);
    char* total_spent = double_to_string(user->total_spent, 3);
    char* user_age = int_to_string(user->age);
    output_key_value output_array[] = {{"name", user->name},
                                       {"sex", user->sex},
                                       {"age", user_age},
                                       {"country_code", user->country_code},
                                       {"passport", user->passport},
                                       {"number_of_flights", number_of_flights},
                                       {"number_of_reservations", number_of_reservations},
                                       {"total_spent", total_spent}};

    write_output(output_file, format_flag, 1, output_array, 8);
    free(number_of_flights);
    free(number_of_reservations);
    free(total_spent);
    free(user_age);
  };
  return 0;
}

//! @brief Writes flight data to an output file
int write_flight_data(GHashTable* flights_table, char* id, FILE* output_file, bool format_flag) {
  FlightSchema flight = g_hash_table_lookup(flights_table, id);
  char* number_of_passengers = int_to_string(flight->number_of_passengers);
  char* delay = int_to_string((int)flight->delay);
  output_key_value output_array[] = {{"airline", flight->airline},
                                     {"plane_model", flight->plane_model},
                                     {"origin", flight->origin},
                                     {"destination", flight->destination},
                                     {"schedule_departure_date", flight->schedule_departure_date},
                                     {"schedule_arrival_date", flight->schedule_arrival_date},
                                     {"passengers", number_of_passengers},
                                     {"delay", delay}};
  write_output(output_file, format_flag, 1, output_array, 8);
  free(number_of_passengers);
  free(delay);

  return 0;
}

//! @brief Writes reservation data to an output file
int write_reservation_data(GHashTable* reservation_table, char* id, FILE* output_file, bool format_flag) {
  ReservationSchema reservation = g_hash_table_lookup(reservation_table, id);
  char* total_price = double_to_string(reservation->total_price, 3);
  char* hotel_stars = int_to_string(reservation->hotel_stars);
  char* nights = int_to_string(get_days_difference(reservation->begin_date, reservation->end_date));
  output_key_value output_array[] = {{"hotel_id", reservation->hotel_id},
                                     {"hotel_name", reservation->hotel_name},
                                     {"hotel_stars", hotel_stars},
                                     {"begin_date", reservation->begin_date},
                                     {"end_date", reservation->end_date},
                                     {"includes_breakfast", (reservation->includes_breakfast) ? "True" : "False"},
                                     {"nights", nights},
                                     {"total_price", total_price}};
  write_output(output_file, format_flag, 1, output_array, 8);

  free(total_price);
  free(hotel_stars);
  free(nights);

  return 0;
}

int query_1(Catalogs CATALOGS, int command_number, bool format_flag, char* id) {
  FILE* output_file = create_output_file(command_number);
  if (is_user(CATALOGS->users, id)) {
    write_user_data(CATALOGS->users, id, output_file, format_flag);
  }

  if (is_flight(CATALOGS->flights, id)) {
    write_flight_data(CATALOGS->flights, id, output_file, format_flag);
  }

  if (is_reservation(CATALOGS->reservations, id)) {
    write_reservation_data(CATALOGS->reservations, id, output_file, format_flag);
  }

  close_output_file(output_file);
  return 0;
}
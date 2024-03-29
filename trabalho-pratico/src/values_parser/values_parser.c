#include <catalogs_creator/airports_catalog.h>
#include <catalogs_creator/catalogs_creator.h>
#include <datatypes/datatypes.h>
#include <entities/airport_entity.h>
#include <entities/flight_entity.h>
#include <entities/hotel_entity.h>
#include <entities/reservation_entity.h>
#include <entities/user_entity.h>
#include <glib.h>
#include <string.h>
#include <utils/calculate_stats.h>
#include <values_parser/verify_values.h>
#include "utils/string_to_int.h"

int values_parser_users(char** user_values, Catalogs catalogs) {
  if (!strcmp(user_values[0], "") || !strcmp(user_values[1], "") || !strcmp(user_values[3], "") ||
      !strcmp(user_values[5], "") || !strcmp(user_values[6], "") || !strcmp(user_values[8], "") ||
      !strcmp(user_values[10], "") || !verify_user_country_code(user_values[7]) || !verify_date(user_values[4]) ||
      !verify_date(user_values[9]) || !verify_account_status(user_values[11]) ||
      !verify_account_email(user_values[2]) || !verify_are_dates_in_order(user_values[4], user_values[9])) {
    return 1;
  }

  create_new_user(catalogs->users, user_values);

  return 0;
}

int values_parser_flights(char** flight_values, Catalogs catalogs) {
  if (!strcmp(flight_values[0], "") || !strcmp(flight_values[1], "") || !strcmp(flight_values[2], "") ||
      !strcmp(flight_values[10], "") || !strcmp(flight_values[11], "") || !verify_if_is_digit(flight_values[3]) ||
      (!verify_airport_name(flight_values[4]) || !verify_airport_name(flight_values[5])) ||
      (!verify_date(flight_values[6]) || !verify_date(flight_values[7]) || !verify_date(flight_values[8]) ||
       !verify_date(flight_values[9])) ||
      !verify_are_dates_in_order(flight_values[6], flight_values[7]) ||
      !verify_are_dates_in_order(flight_values[8], flight_values[9])) {
    return 1;
  }

  Flight flight = create_new_flight(catalogs->flights, flight_values);
  airport_insert_new_flight(catalogs->airports, flight);

  return 0;
}

int values_parser_passengers(char** passengers_values, Catalogs catalogs) {
  if (strcmp(passengers_values[0], "") == 0 || strcmp(passengers_values[1], "") == 0) {
    return 1;
  }

  Flight flight = get_flight_by_id(catalogs->flights, string_to_int(passengers_values[0]));
  User user = get_user_by_id(catalogs->users, passengers_values[1]);

  if (user == NULL || flight == NULL) {
    return 1;
  }

  flight_increment_passengers(flight, 1);
  user_add_flight(user, flight);

  char* flight_departure_date = flight_get_schedule_departure_date(flight);

  char* airport_id_o = flight_get_origin_airport_id(flight);
  Airport airport_o = get_airport_by_id(catalogs->airports, airport_id_o);
  airport_increment_passengers(airport_o, flight_departure_date, 1);

  char* airport_id_d = flight_get_destination_airport_id(flight);
  Airport airport_d = get_airport_by_id(catalogs->airports, airport_id_d);
  airport_increment_passengers(airport_d, flight_departure_date, 1);

  g_free(airport_id_o);
  g_free(airport_id_d);
  g_free(flight_departure_date);

  return 0;
}

int values_parser_reservations(char** reservations_values, Catalogs catalogs) {
  if (!strcmp(reservations_values[0], "") || !strcmp(reservations_values[1], "") ||
      !strcmp(reservations_values[2], "") || !strcmp(reservations_values[3], "") ||
      !strcmp(reservations_values[6], "") || !verify_hotel_rating(reservations_values[12]) ||
      !verify_hotel_rating_stars(reservations_values[4]) || !verify_if_is_digit(reservations_values[5]) ||
      !verify_if_is_digit_non_zero(reservations_values[9]) || !verify_breakfast(reservations_values[10]) ||
      !verify_date(reservations_values[7]) || !verify_date(reservations_values[8]) ||
      !verify_are_dates_in_order(reservations_values[7], reservations_values[8])) {
    return 1;
  }

  User user = get_user_by_id(catalogs->users, reservations_values[1]);
  if (user == NULL) {
    return 1;
  }

  Reservation new_reservation = create_new_reservation(catalogs->reservations, reservations_values);
  hotel_insert_new_reservation(catalogs->hotels, new_reservation);

  user_increment_total_spent(user, reservation_get_total_price(new_reservation));
  user_add_reservation(user, new_reservation);

  return 0;
}

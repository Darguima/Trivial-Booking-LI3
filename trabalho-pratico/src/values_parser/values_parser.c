#include <datatypes/datatypes.h>
#include <glib.h>
#include <store_catalog/store_catalog.h>
#include <string.h>
#include <values_parser/create_new_structs.h>
#include <values_parser/verify_values.h>

int values_parser_users(char** user_values, Catalogs catalog) {
  if (!strcmp(user_values[0], "") || !strcmp(user_values[1], "") ||
      !strcmp(user_values[3], "") || !strcmp(user_values[5], "") ||
      !strcmp(user_values[6], "") || !strcmp(user_values[8], "") ||
      !strcmp(user_values[10], "") ||
      !verify_user_country_code(user_values[7]) ||
      !verify_date(user_values[4]) || !verify_date(user_values[9]) ||
      !verify_account_status(user_values[11]) ||
      !verify_account_email(user_values[2]) ||
      !verify_are_dates_in_order(user_values[4], user_values[9])) {
    return 1;
  }

  UserSchema new_user = create_new_user(user_values);
  store_catalog_user(new_user, catalog->users);

  return 0;
}

int values_parser_flights(char** flight_values, Catalogs catalog) {
  if (!strcmp(flight_values[0], "") || !strcmp(flight_values[1], "") ||
      !strcmp(flight_values[2], "") || !strcmp(flight_values[10], "") ||
      !strcmp(flight_values[11], "") || !verify_if_is_digit(flight_values[3]) ||
      (!verify_airport_name(flight_values[4]) ||
       !verify_airport_name(flight_values[5])) ||
      (!verify_date(flight_values[6]) || !verify_date(flight_values[7]) ||
       !verify_date(flight_values[8]) || !verify_date(flight_values[9])) ||
      !verify_are_dates_in_order(flight_values[6], flight_values[7]) ||
      !verify_are_dates_in_order(flight_values[8], flight_values[9])) {
    return 1;
  }

  FlightSchema new_flight = create_new_flight(flight_values);
  store_catalog_flight(new_flight, catalog->flights);

  return 0;
}

int values_parser_passengers(char** passengers_values, Catalogs catalog) {
  if (strcmp(passengers_values[0], "") == 0 ||

      strcmp(passengers_values[1], "") == 0) {
    return 1;
  }

  UserSchema user = g_hash_table_lookup(catalog->users, passengers_values[1]);

  FlightSchema flight =
      g_hash_table_lookup(catalog->flights, passengers_values[0]);

  if (user == NULL || flight == NULL) {
    return 1;
  }

  return 0;
}

int values_parser_reservations(char** reservations_values, Catalogs catalog) {
  if (!strcmp(reservations_values[0], "") ||
      !strcmp(reservations_values[1], "") ||
      !strcmp(reservations_values[2], "") ||
      !strcmp(reservations_values[3], "") ||
      !strcmp(reservations_values[6], "") ||
      !verify_hotel_rating(reservations_values[12]) ||
      !verify_hotel_rating_stars(reservations_values[4]) ||
      !verify_if_is_digit(reservations_values[5]) ||
      !verify_if_is_digit_non_zero(reservations_values[9]) ||
      !verify_breakfast(reservations_values[10]) ||
      !verify_date(reservations_values[7]) ||
      !verify_date(reservations_values[8]) ||
      !verify_are_dates_in_order(reservations_values[7],
                                 reservations_values[8])) {
    return 1;
  }

  UserSchema user = g_hash_table_lookup(catalog->users, reservations_values[1]);
  if (user == NULL) {
    return 1;
  }

  ReservationSchema new_reservation =
      create_new_reservation(reservations_values);
  store_catalog_reservation(new_reservation, catalog->reservations);

  return 0;
}

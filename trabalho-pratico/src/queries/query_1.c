#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <utils/number_to_string.h>
#include "catalogs_setup/catalogs_setup.h"
#include "catalogs_setup/users_catalog.h"
#include "ctype.h"
#include "entities/flight_entity.h"
#include "entities/passenger_entity.h"
#include "entities/user_entity.h"
#include "utils/calculate_stats.h"
#include "write_output/write_output.h"

int query_1(Catalogs catalogs, int command_number, bool format_flag, char* id) {
  printf("I'm in query_1\n");
  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(id);

  printf("Example ==============\n");

  // from catalogs_setup/users_catalog.h
  User user_test = get_user_by_id(catalogs->users, "TomNunes92");

  if (user_test == NULL) {
    printf("user_test is NULL\n");
  } else {
    // from entities/user_entity.h
    char* user_id = user_get_id(user_test);
    char* user_name = user_get_name(user_test);
    printf("user_id: %s\n", user_id);
    printf("user_name: %s\n", user_name);
    free(user_id);
    free(user_name);
  }

  // from catalogs_setup/flights_catalog.h
  Flight flight_test = get_flight_by_id(catalogs->flights, "0000000001");

  if (flight_test == NULL) {
    printf("flight_test is NULL\n");
  } else {
    // from entities/flight_entity.h
    char* flight_id = flight_get_id(flight_test);
    int flight_seats = flight_get_total_seats(flight_test);
    printf("flight_id: %s\n", flight_id);
    printf("flight_total_seats: %i\n", flight_seats);
    free(flight_id);
  }

  // from catalogs_setup/reservations_catalog.h
  Reservation reservation_test = get_reservation_by_id(catalogs->reservations, "Book0000000021");

  if (reservation_test == NULL) {
    printf("reservation_test is NULL\n");
  } else {
    // from entities/reservation_entity.h
    char* reservation_id = reservation_get_id(reservation_test);
    double reservation_price = reservation_get_total_price(reservation_test);
    printf("reservation_id: %s\n", reservation_id);
    printf("reservation_total_price: %f\n", reservation_price);
    free(reservation_id);
  }

  // from catalogs_setup/passengers_catalog.h
  Passenger passenger_test = get_passenger_by_id(catalogs->passengers, "0000000001_MaurAntunes1651");

  if (passenger_test == NULL) {
    printf("passenger_test is NULL\n");
  } else {
    // from entities/passenger_entity.h
    char* passenger_user_id = passenger_get_user_id(passenger_test);
    char* passenger_flight_id = passenger_get_flight_id(passenger_test);
    printf("passenger_user_id: %s\n", passenger_user_id);
    printf("passenger_flight_id: %s\n", passenger_flight_id);
    free(passenger_user_id);
    free(passenger_flight_id);
  }

  printf("======================\n");

  return 0;
}
#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include <utils/number_to_string.h>
#include "catalogs_creator/catalogs_creator.h"
#include "catalogs_creator/users_catalog.h"
#include "ctype.h"
#include "datatypes/datatypes.h"
#include "entities/flight_entity.h"
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

  // from catalogs_creator/users_catalog.h
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

  // from catalogs_creator/flights_catalog.h
  Flight flight_test = get_flight_by_id(catalogs->flights, 0000000001);

  if (flight_test == NULL) {
    printf("flight_test is NULL\n");
  } else {
    // from entities/flight_entity.h
    int flight_id = flight_get_id(flight_test);
    int flight_seats = flight_get_total_seats(flight_test);
    printf("flight_id: %d\n", flight_id);
    printf("flight_total_seats: %i\n", flight_seats);
  }

  // from catalogs_creator/reservations_catalog.h
  Reservation reservation_test = get_reservation_by_id(catalogs->reservations, 0000000021);

  if (reservation_test == NULL) {
    printf("reservation_test is NULL\n");
  } else {
    // from entities/reservation_entity.h
    int reservation_id = reservation_get_id(reservation_test);
    double reservation_price = reservation_get_total_price(reservation_test);
    printf("reservation_id: %d\n", reservation_id);
    printf("reservation_total_price: %f\n", reservation_price);
  }

  return 0;
}
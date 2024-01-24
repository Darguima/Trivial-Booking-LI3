#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include <utils/number_to_string.h>
#include "catalogs_creator/airports_catalog.h"
#include "catalogs_creator/catalogs_creator.h"
#include "catalogs_creator/hotels_catalog.h"
#include "catalogs_creator/users_catalog.h"
#include "ctype.h"
#include "datatypes/datatypes.h"
#include "entities/airport_entity.h"
#include "entities/flight_entity.h"
#include "entities/hotel_entity.h"
#include "entities/user_entity.h"
#include "utils/calculate_stats.h"
#include "utils/string_to_int.h"
#include "values_parser/verify_values.h"
#include "write_output/write_output.h"
#include "state/state.h"

bool verify_if_is_reservation(char* id) {
  if (strncmp(id, "Book", 4) == 0) {
    return (verify_if_is_digit(id + 4));
  }
  return false;
}

void write_user_data(char* id, Catalogs catalogs, FILE* output_file, bool format_flag, State state) {
  User user = get_user_by_id(catalogs->users, id);
  if (user == NULL || !user_get_is_active(user)) {
    return;
  }

  char* number_of_flights = int_to_string(user_get_number_of_flights(user));
  char* number_of_reservations = int_to_string(user_get_number_of_reservations(user));
  char* total_spent = double_to_string(user_get_total_spent(user), 3);
  char* user_age = int_to_string(user_get_age(user));
  char* country_code = user_get_country_code(user);
  char* passport = user_get_passport(user);
  char* sex = user_get_sex(user);
  char* name = user_get_name(user);

  output_key_value output_array[] = {{"name", name},
                                     {"sex", sex},
                                     {"age", user_age},
                                     {"country_code", country_code},
                                     {"passport", passport},
                                     {"number_of_flights", number_of_flights},
                                     {"number_of_reservations", number_of_reservations},
                                     {"total_spent", total_spent}};

  write_output(output_file, format_flag, 1, output_array, 8, State state);
  free(number_of_flights);
  free(number_of_reservations);
  free(total_spent);
  free(user_age);
  free(passport);
  free(country_code);
  free(sex);
  free(name);
}

void write_reservation_data(char* id, Catalogs catalogs, FILE* output_file, bool format_flag) {
  int id_int = string_to_int(id);

  Reservation reservation = get_reservation_by_id(catalogs->reservations, id_int);
  if (reservation == NULL) {
    return;
  }
  char* total_price = double_to_string(reservation_get_total_price(reservation), 3);
  char* hotel_stars = int_to_string(reservation_get_hotel_stars(reservation));
  char* begin_date = reservation_get_begin_date(reservation);
  char* end_date = reservation_get_end_date(reservation);
  char* nights = int_to_string(get_days_difference(begin_date, end_date));
  char* hotel_id = reservation_get_hotel_id(reservation);
  char* hotel_name = reservation_get_hotel_name(reservation);
  bool includes_breakfast = reservation_get_breakfast(reservation);

  output_key_value output_array[] = {
      {"hotel_id", hotel_id},       {"hotel_name", hotel_name},
      {"hotel_stars", hotel_stars}, {"begin_date", begin_date},
      {"end_date", end_date},       {"includes_breakfast", includes_breakfast ? "True" : "False"},
      {"nights", nights},           {"total_price", total_price}};
  write_output(output_file, format_flag, 1, output_array, 8, State state);

  free(total_price);
  free(hotel_stars);
  free(nights);
  free(begin_date);
  free(end_date);
  free(hotel_id);
  free(hotel_name);
}

void write_flight_data(char* id, Catalogs catalogs, FILE* output_file, bool format_flag) {
  int id_int = string_to_int(id);

  Flight flight = get_flight_by_id(catalogs->flights, id_int);
  if (flight == NULL) {
    return;
  }

  char* number_of_passengers = int_to_string(flight_get_number_of_passengers(flight));
  char* delay = int_to_string((int)flight_get_delay(flight));
  char* airline = flight_get_airline(flight);
  char* plane_model = flight_get_plane_model(flight);
  char* origin = flight_get_origin(flight);
  char* destination = flight_get_destination(flight);
  char* schedule_departure_date = flight_get_schedule_departure_date(flight);
  char* schedule_arrival_date = flight_get_schedule_arrival_date(flight);

  output_key_value output_array[] = {{"airline", airline},
                                     {"plane_model", plane_model},
                                     {"origin", origin},
                                     {"destination", destination},
                                     {"schedule_departure_date", schedule_departure_date},
                                     {"schedule_arrival_date", schedule_arrival_date},
                                     {"passengers", number_of_passengers},
                                     {"delay", delay}};
  write_output(output_file, format_flag, 1, output_array, 8, State state);
  free(number_of_passengers);
  free(delay);
  free(airline);
  free(plane_model);
  free(origin);
  free(destination);
  free(schedule_arrival_date);
  free(schedule_departure_date);
}

int query_1(Catalogs catalogs, int command_number, bool format_flag, char* id) {
  FILE* output_file = create_output_file(command_number);

  if (verify_if_is_digit(id)) {
    write_flight_data(id, catalogs, output_file, format_flag);
  }

  else if (verify_if_is_reservation(id)) {
    write_reservation_data(id, catalogs, output_file, format_flag);
  }

  else {
    write_user_data(id, catalogs, output_file, format_flag);
  }

  close_output_file(output_file);

  return 0;
}
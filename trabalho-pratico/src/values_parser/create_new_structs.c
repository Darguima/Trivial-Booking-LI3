#include <datatypes/datatypes.h>
#include <glib.h>
#include "utils/calculate_stats.h"
#include "utils/convert_string_to_seconds.h"
#include "utils/string_to_int.h"

UserSchema create_new_user(char** user_values) {
  UserSchema new_user = g_malloc(sizeof(struct userSchema));
  new_user->id = g_strdup(user_values[0]);
  new_user->name = g_strdup(user_values[1]);
  new_user->email = g_strdup(user_values[2]);
  new_user->phone_number = g_strdup(user_values[3]);
  new_user->birth_date = g_strdup(user_values[4]);
  new_user->sex = g_strdup(user_values[5]);
  new_user->passport = g_strdup(user_values[6]);
  new_user->country_code = g_strdup(user_values[7]);
  new_user->address = g_strdup(user_values[8]);
  new_user->account_creation = g_strdup(user_values[9]);
  new_user->pay_method = g_strdup(user_values[10]);
  new_user->account_status = g_strdup(user_values[11]);
  new_user->age = calculate_user_age(user_values[4]);
  new_user->total_spent = 0;
  new_user->number_of_flights = 0;
  new_user->number_of_reservations = 0;

  return new_user;
}

FlightSchema create_new_flight(char** flight_values) {
  FlightSchema new_flight = g_malloc(sizeof(struct flightSchema));
  new_flight->id = g_strdup(flight_values[0]);
  new_flight->airline = g_strdup(flight_values[1]);
  new_flight->plane_model = g_strdup(flight_values[2]);
  new_flight->total_seats = string_to_int(flight_values[3]);
  new_flight->origin = g_strdup(flight_values[4]);
  new_flight->destination = g_strdup(flight_values[5]);
  new_flight->schedule_departure_date = g_strdup(flight_values[6]);
  new_flight->real_departure_date = g_strdup(flight_values[8]);
  new_flight->schedule_arrival_date = g_strdup(flight_values[7]);
  new_flight->real_arrival_date = g_strdup(flight_values[9]);
  new_flight->pilot = g_strdup(flight_values[10]);
  new_flight->copilot = g_strdup(flight_values[11]);
  new_flight->notes = g_strdup(flight_values[12]);
  new_flight->number_of_passengers = 0;
  new_flight->delay = (long)difftime(convert_string_to_seconds(new_flight->real_departure_date),
                                     convert_string_to_seconds(new_flight->schedule_departure_date));
  /*
  Atrasos de um avião são calculados a partir da diferença entre a data estimada
  de partida (schedule_departure_date) e a data real de partida
  (real_departure_date);
  */
  return new_flight;
}

ReservationSchema create_new_reservation(char** reservation_values) {
  ReservationSchema new_reservation = g_malloc(sizeof(struct reservationSchema));
  new_reservation->id = g_strdup(reservation_values[0]);
  new_reservation->user_id = g_strdup(reservation_values[1]);
  new_reservation->hotel_id = g_strdup(reservation_values[2]);
  new_reservation->hotel_name = g_strdup(reservation_values[3]);
  new_reservation->hotel_stars = string_to_int(reservation_values[4]);
  new_reservation->city_tax = string_to_int(reservation_values[5]);
  new_reservation->address = g_strdup(reservation_values[6]);
  new_reservation->begin_date = g_strdup(reservation_values[7]);
  new_reservation->end_date = g_strdup(reservation_values[8]);
  new_reservation->price_per_night = string_to_int(reservation_values[9]);
  new_reservation->includes_breakfast = g_strdup(reservation_values[10]);
  new_reservation->room_details = g_strdup(reservation_values[11]);
  new_reservation->rating = g_strdup(reservation_values[12]);
  new_reservation->comment = g_strdup(reservation_values[13]);
  new_reservation->total_price = calculate_total_spent(new_reservation->begin_date, new_reservation->end_date,
                                                       new_reservation->city_tax, new_reservation->price_per_night);
  return new_reservation;
}
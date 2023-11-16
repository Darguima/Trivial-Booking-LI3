#include <datatypes/datatypes.h>
#include <glib.h>
#include "utils/calculate_stats.h"
#include "utils/convert_string_to_seconds.h"
#include "utils/string_to_int.h"

PassengerSchema create_new_passenger(char** passenger_values) {
  PassengerSchema new_passenger = malloc(sizeof(struct passengerSchema));
  new_passenger->flight_id = strdup(passenger_values[0]);
  new_passenger->user_id = strdup(passenger_values[1]);
  return new_passenger;
}

UserSchema create_new_user(char** user_values) {
  UserSchema new_user = malloc(sizeof(struct userSchema));
  new_user->id = strdup(user_values[0]);
  new_user->name = strdup(user_values[1]);
  new_user->email = strdup(user_values[2]);
  new_user->phone_number = strdup(user_values[3]);
  new_user->birth_date = strdup(user_values[4]);
  new_user->sex = strdup(user_values[5]);
  new_user->passport = strdup(user_values[6]);
  new_user->country_code = strdup(user_values[7]);
  new_user->address = strdup(user_values[8]);
  new_user->account_creation = strdup(user_values[9]);
  new_user->pay_method = strdup(user_values[10]);
  new_user->account_status = strdup(user_values[11]);
  new_user->age = calculate_user_age(user_values[4]);
  new_user->total_spent = 0;
  new_user->number_of_flights = 0;
  new_user->number_of_reservations = 0;

  return new_user;
}

FlightSchema create_new_flight(char** flight_values) {
  FlightSchema new_flight = malloc(sizeof(struct flightSchema));
  new_flight->id = strdup(flight_values[0]);
  new_flight->airline = strdup(flight_values[1]);
  new_flight->plane_model = strdup(flight_values[2]);
  new_flight->total_seats = string_to_int(flight_values[3]);
  new_flight->origin = strdup(flight_values[4]);
  new_flight->destination = strdup(flight_values[5]);
  new_flight->schedule_departure_date = strdup(flight_values[6]);
  new_flight->real_departure_date = strdup(flight_values[8]);
  new_flight->schedule_arrival_date = strdup(flight_values[7]);
  new_flight->real_arrival_date = strdup(flight_values[9]);
  new_flight->pilot = strdup(flight_values[10]);
  new_flight->copilot = strdup(flight_values[11]);
  new_flight->notes = strdup(flight_values[12]);
  new_flight->number_of_passengers = 0;
  new_flight->delay = (long)difftime(convert_string_to_seconds(new_flight->real_departure_date),
                                     convert_string_to_seconds(new_flight->schedule_departure_date));

  return new_flight;
}

ReservationSchema create_new_reservation(char** reservation_values) {
  ReservationSchema new_reservation = malloc(sizeof(struct reservationSchema));
  new_reservation->id = strdup(reservation_values[0]);
  new_reservation->user_id = strdup(reservation_values[1]);
  new_reservation->hotel_id = strdup(reservation_values[2]);
  new_reservation->hotel_name = strdup(reservation_values[3]);
  new_reservation->hotel_stars = string_to_int(reservation_values[4]);
  new_reservation->city_tax = string_to_int(reservation_values[5]);
  new_reservation->address = strdup(reservation_values[6]);
  new_reservation->begin_date = strdup(reservation_values[7]);
  new_reservation->end_date = strdup(reservation_values[8]);
  new_reservation->price_per_night = string_to_int(reservation_values[9]);
  new_reservation->includes_breakfast = strdup(reservation_values[10]);
  new_reservation->room_details = strdup(reservation_values[11]);
  new_reservation->rating = strdup(reservation_values[12]);
  new_reservation->comment = strdup(reservation_values[13]);
  new_reservation->total_price = calculate_total_spent(new_reservation->begin_date, new_reservation->end_date,
                                                       new_reservation->city_tax, new_reservation->price_per_night);
  return new_reservation;
}
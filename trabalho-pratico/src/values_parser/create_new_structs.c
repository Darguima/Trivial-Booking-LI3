#include <datatypes/datatypes.h>
#include <glib.h>
#include "utils/calculate_stats.h"
#include "utils/convert_string_to_seconds.h"
#include "utils/includes_breakfast.h"
#include "utils/is_active.h"
#include "utils/string_to_int.h"
#include "utils/string_to_upper.h"

PassengerSchema create_new_passenger(char** passenger_values) {
  PassengerSchema new_passenger = malloc(sizeof(struct passengerSchema));
  new_passenger->flight_id = strdup(passenger_values[0]);
  new_passenger->user_id = strdup(passenger_values[1]);
  return new_passenger;
}

FlightSchema create_new_flight(char** flight_values) {
  FlightSchema new_flight = malloc(sizeof(struct flightSchema));
  new_flight->id = strdup(flight_values[0]);
  new_flight->airline = strdup(flight_values[1]);
  new_flight->plane_model = strdup(flight_values[2]);
  new_flight->total_seats = string_to_int(flight_values[3]);
  new_flight->origin = string_to_upper(strdup(flight_values[4]));
  new_flight->destination = string_to_upper(strdup(flight_values[5]));
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
  new_reservation->includes_breakfast = includes_breakfast(reservation_values[10]);
  new_reservation->room_details = strdup(reservation_values[11]);
  new_reservation->rating = strdup(reservation_values[12]);
  new_reservation->comment = strdup(reservation_values[13]);
  new_reservation->total_price = calculate_total_spent(new_reservation->begin_date, new_reservation->end_date,
                                                       new_reservation->city_tax, new_reservation->price_per_night);
  return new_reservation;
}
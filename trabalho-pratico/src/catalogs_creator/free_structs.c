#include <datatypes/datatypes.h>
#include <glib.h>

void free_user_struct(gpointer value) {
  UserSchema user = (UserSchema)value;

  free(user->id);
  free(user->name);
  free(user->email);
  free(user->phone_number);
  free(user->birth_date);
  free(user->sex);
  free(user->passport);
  free(user->country_code);
  free(user->address);
  free(user->account_creation);
  free(user->pay_method);
  free(user->account_status);

  free(user);
}

void free_flight_struct(gpointer value) {
  FlightSchema flight = (FlightSchema)value;

  free(flight->id);
  free(flight->airline);
  free(flight->plane_model);
  // free(flight->total_seats);
  free(flight->origin);
  free(flight->destination);
  free(flight->schedule_departure_date);
  free(flight->schedule_arrival_date);
  free(flight->real_departure_date);
  free(flight->real_arrival_date);
  free(flight->pilot);
  free(flight->copilot);
  free(flight->notes);

  free(flight);
}

void free_passengers_struct(gpointer value) {
  PassengerSchema passenger = (PassengerSchema)value;

  free(passenger->flight_id);
  free(passenger->user_id);

  free(passenger);
}

void free_reservation_struct(gpointer value) {
  ReservationSchema reservation = (ReservationSchema)value;

  free(reservation->id);
  free(reservation->user_id);
  free(reservation->hotel_id);
  free(reservation->hotel_name);
  // free(reservation->hotel_stars);
  // free(reservation->city_tax);
  free(reservation->address);
  free(reservation->begin_date);
  free(reservation->end_date);
  // free(reservation->price_per_night);
  free(reservation->includes_breakfast);
  free(reservation->room_details);
  free(reservation->rating);
  free(reservation->comment);

  free(reservation);
}
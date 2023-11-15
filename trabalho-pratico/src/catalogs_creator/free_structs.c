#include <datatypes/datatypes.h>
#include <glib.h>

void free_user_struct(gpointer value) {
  UserSchema user = (UserSchema)value;

  g_free(user->id);
  g_free(user->name);
  g_free(user->email);
  g_free(user->phone_number);
  g_free(user->birth_date);
  g_free(user->sex);
  g_free(user->passport);
  g_free(user->country_code);
  g_free(user->address);
  g_free(user->account_creation);
  g_free(user->pay_method);
  g_free(user->account_status);

  g_free(user);
}

void free_flight_struct(gpointer value) {
  FlightSchema flight = (FlightSchema)value;

  g_free(flight->id);
  g_free(flight->airline);
  g_free(flight->plane_model);
  // g_free(flight->total_seats);
  g_free(flight->origin);
  g_free(flight->destination);
  g_free(flight->schedule_departure_date);
  g_free(flight->schedule_arrival_date);
  g_free(flight->real_departure_date);
  g_free(flight->real_arrival_date);
  g_free(flight->pilot);
  g_free(flight->copilot);
  g_free(flight->notes);

  g_free(flight);
}

void free_reservation_struct(gpointer value) {
  ReservationSchema reservation = (ReservationSchema)value;

  g_free(reservation->id);
  g_free(reservation->user_id);
  g_free(reservation->hotel_id);
  g_free(reservation->hotel_name);
  // g_free(reservation->hotel_stars);
  // g_free(reservation->city_tax);
  g_free(reservation->address);
  g_free(reservation->begin_date);
  g_free(reservation->end_date);
  // g_free(reservation->price_per_night);
  g_free(reservation->includes_breakfast);
  g_free(reservation->room_details);
  g_free(reservation->rating);
  g_free(reservation->comment);

  g_free(reservation);
}
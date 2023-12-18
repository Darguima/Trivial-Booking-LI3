#include <datatypes/datatypes.h>
#include <glib.h>

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
  // free(reservation->includes_breakfast);
  free(reservation->room_details);
  free(reservation->rating);
  free(reservation->comment);

  free(reservation);
}
#include <datatypes/datatypes.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

int store_catalog_user(UserSchema user, GHashTable* users_catalog) {
  g_hash_table_insert(users_catalog, user->id, user);

  printf("[store_catalog_user] Stored %s\n", user->id);
  return 0;
}

int store_catalog_flight(FlightSchema flight, GHashTable* flights_catalog) {
  g_hash_table_insert(flights_catalog, flight->id, flight);

  printf("[store_catalog_flight] Stored %s\n", flight->id);
  return 0;
}

int store_catalog_passenger(PassengerSchema passenger,
                            GHashTable* passengers_catalog) {
  if (passenger->flight_id == NULL || passengers_catalog == NULL) {
  }
  return 0;
}

int store_catalog_reservation(ReservationSchema reservation,
                              GHashTable* reservations_catalog) {
  g_hash_table_insert(reservations_catalog, g_strdup(reservation->id),
                      reservation);

  printf("[store_catalog_reservation] Stored %s\n", reservation->id);
  return 0;
}

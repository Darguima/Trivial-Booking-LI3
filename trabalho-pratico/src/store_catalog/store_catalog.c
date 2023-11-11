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
  g_hash_table_insert(flights_catalog, GINT_TO_POINTER(flight->id), flight);

  printf("[store_catalog_flight] Stored %i\n", flight->id);
  return 0;
}

int store_catalog_passenger(PassengerSchema passenger,
                            GHashTable* passengers_catalog) {
  // Concatenate the flight_id and user_id in a string and use it as an id
  size_t id_str_length = (size_t)snprintf(
      NULL, 0, "%d_%s", passenger->flight_id, passenger->user_id);
  char* id = (char*)malloc(id_str_length + 1);
  snprintf(id, id_str_length + 1, "%d_%s", passenger->flight_id,
           passenger->user_id);

  g_hash_table_insert(passengers_catalog, id, passenger);

  printf("[store_catalog_passenger] Stored %s\n", id);
  return 0;
}

int store_catalog_reservation(ReservationSchema reservation,
                              GHashTable* reservations_catalog) {
  g_hash_table_insert(reservations_catalog, reservation->id, reservation);

  printf("[store_catalog_reservation] Stored %s\n", reservation->id);
  return 0;
}

#include <datatypes/datatypes.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils/concatenate_string.h"

int store_catalog_passenger(PassengerSchema passenger, GHashTable* passengers_catalog) {
  char* array[3] = {passenger->flight_id, "_", passenger->user_id};
  char* key = concatenate_string(array, 3);
  g_hash_table_insert(passengers_catalog, key, passenger);

  return 0;
}

int store_catalog_reservation(ReservationSchema reservation, GHashTable* reservations_catalog) {
  g_hash_table_insert(reservations_catalog, reservation->id, reservation);

  return 0;
}

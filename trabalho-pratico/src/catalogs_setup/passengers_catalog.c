#include "catalogs_setup/passengers_catalog.h"
#include <stdlib.h>
#include "entities/passenger_entity.h"
#include "utils/concatenate_string.h"

struct passengers_catalog {
  GHashTable* passengers_hash_table;
};

PassengersCatalog passengers_catalog_create() {
  PassengersCatalog passengers_catalog = malloc(sizeof(struct passengers_catalog));

  passengers_catalog->passengers_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_passenger);

  return passengers_catalog;
}

void passengers_catalog_free(PassengersCatalog passengers_catalog) {
  g_hash_table_destroy(passengers_catalog->passengers_hash_table);

  free(passengers_catalog);
}

void insert_passenger(PassengersCatalog passengers_catalog, Passenger passenger) {
  char* flight_id = passenger_get_flight_id(passenger);
  char* user_id = passenger_get_user_id(passenger);

  char* array[3] = {flight_id, "_", user_id};
  char* key = concatenate_string(array, 3);

  free(flight_id);
  free(user_id);

  g_hash_table_insert(passengers_catalog->passengers_hash_table, key, passenger);
}

Passenger get_passenger_by_id(PassengersCatalog passengers_catalog, char* passenger_id) {
  return (Passenger)g_hash_table_lookup(passengers_catalog->passengers_hash_table, passenger_id);
}

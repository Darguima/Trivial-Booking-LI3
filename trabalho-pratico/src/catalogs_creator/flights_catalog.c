#include "catalogs_creator/flights_catalog.h"
#include <stdlib.h>
#include "entities/flight_entity.h"

struct flights_catalog {
  GHashTable* flights_hash_table;
};

FlightsCatalog flights_catalog_create() {
  FlightsCatalog flights_catalog = malloc(sizeof(struct flights_catalog));

  flights_catalog->flights_hash_table = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, free_flight);

  return flights_catalog;
}

void flights_catalog_free(FlightsCatalog flights_catalog) {
  g_hash_table_destroy(flights_catalog->flights_hash_table);

  free(flights_catalog);
}

void insert_flight(FlightsCatalog flights_catalog, Flight flight) {
  g_hash_table_insert(flights_catalog->flights_hash_table, GINT_TO_POINTER(flight_get_id(flight)), flight);
}

Flight get_flight_by_id(FlightsCatalog flights_catalog, int flight_id) {
  return (Flight)g_hash_table_lookup(flights_catalog->flights_hash_table, GINT_TO_POINTER(flight_id));
}

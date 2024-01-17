#include "catalogs_creator/airports_catalog.h"
#include <stdlib.h>
#include "entities/airport_entity.h"

struct airports_catalog {
  GHashTable* airports_hash_table;
};

AirportsCatalog airports_catalog_create() {
  AirportsCatalog airports_catalog = malloc(sizeof(struct airports_catalog));

  airports_catalog->airports_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_airport);

  return airports_catalog;
}

void airports_catalog_free(AirportsCatalog airports_catalog) {
  g_hash_table_destroy(airports_catalog->airports_hash_table);

  free(airports_catalog);
}

void insert_airport(AirportsCatalog airports_catalog, Airport airport) {
  g_hash_table_insert(airports_catalog->airports_hash_table, airport_get_id(airport), airport);
}

Airport get_airport_by_id(AirportsCatalog airports_catalog, char* airport_id) {
  return (Airport)g_hash_table_lookup(airports_catalog->airports_hash_table, airport_id);
}

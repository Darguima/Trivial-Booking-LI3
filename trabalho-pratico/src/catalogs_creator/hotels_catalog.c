#include "catalogs_creator/hotels_catalog.h"
#include <stdlib.h>
#include "entities/hotel_entity.h"

struct hotels_catalog {
  GHashTable* hotels_hash_table;
};

HotelsCatalog hotels_catalog_create() {
  HotelsCatalog hotels_catalog = malloc(sizeof(struct hotels_catalog));

  hotels_catalog->hotels_hash_table = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, free_hotel);

  return hotels_catalog;
}

void hotels_catalog_free(HotelsCatalog hotels_catalog) {
  g_hash_table_destroy(hotels_catalog->hotels_hash_table);

  free(hotels_catalog);
}

void insert_hotel(HotelsCatalog hotels_catalog, Hotel hotel) {
  g_hash_table_insert(hotels_catalog->hotels_hash_table, GINT_TO_POINTER(hotel_get_id(hotel)), hotel);
}

Hotel get_hotel_by_id(HotelsCatalog hotels_catalog, int hotel_id) {
  return (Hotel)g_hash_table_lookup(hotels_catalog->hotels_hash_table, GINT_TO_POINTER(hotel_id));
}

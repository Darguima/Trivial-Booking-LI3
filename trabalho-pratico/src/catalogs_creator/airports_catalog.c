#include "catalogs_creator/airports_catalog.h"
#include <stdlib.h>
#include "entities/airport_entity.h"
#include "utils/compare_glib_keys.h"

struct airports_catalog {
  GHashTable* airports_hash_table;
  GArray* airports_median_array;
};

AirportsCatalog airports_catalog_create() {
  AirportsCatalog airports_catalog = malloc(sizeof(struct airports_catalog));

  airports_catalog->airports_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_airport);
  airports_catalog->airports_median_array = g_array_new(FALSE, FALSE, sizeof(Airport));

  return airports_catalog;
}

void airports_catalog_free(AirportsCatalog airports_catalog) {
  g_hash_table_destroy(airports_catalog->airports_hash_table);
  // g_tree_destroy(airports_catalog->airports_median_array);

  free(airports_catalog);
}

void insert_airport(AirportsCatalog airports_catalog, Airport airport) {
  g_hash_table_insert(airports_catalog->airports_hash_table, airport_get_id(airport), airport);
}

void airports_create_aux_data_structs(AirportsCatalog airports_catalog) {
  GHashTableIter iter;
  gpointer key, value;
  g_hash_table_iter_init(&iter, airports_catalog->airports_hash_table);
  while (g_hash_table_iter_next(&iter, &key, &value)) {
    Airport airport = (Airport)value;

    long median_delay = airport_get_median_delay(airport);
    if (median_delay == -1)
      continue;

    g_array_append_val(airports_catalog->airports_median_array, airport);
  }

  g_array_sort_with_data(airports_catalog->airports_median_array, compare_airports_by_median_delay, NULL);
}

Airport get_airport_by_id(AirportsCatalog airports_catalog, char* airport_id) {
  return (Airport)g_hash_table_lookup(airports_catalog->airports_hash_table, airport_id);
}

GList* get_top_N_airports_median_delay(AirportsCatalog airports_catalog, int N) {
  GList* top_N_airports_median_list = NULL;

  Airport airport = NULL;
  for (int i = 0; i < (int)airports_catalog->airports_median_array->len && i < N; i++) {
    airport = g_array_index(airports_catalog->airports_median_array, Airport, i);
    top_N_airports_median_list = g_list_prepend(top_N_airports_median_list, airport);
  }

  top_N_airports_median_list = g_list_reverse(top_N_airports_median_list);

  return top_N_airports_median_list;
}

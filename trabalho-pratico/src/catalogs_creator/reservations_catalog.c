#include "catalogs_creator/reservations_catalog.h"
#include <stdlib.h>
#include "entities/reservation_entity.h"

struct reservations_catalog {
  GHashTable* reservations_hash_table;
};

ReservationsCatalog reservations_catalog_create() {
  ReservationsCatalog reservations_catalog = malloc(sizeof(struct reservations_catalog));

  reservations_catalog->reservations_hash_table =
      g_hash_table_new_full(g_str_hash, g_str_equal, free, free_reservation);

  return reservations_catalog;
}

void reservations_catalog_free(ReservationsCatalog reservations_catalog) {
  g_hash_table_destroy(reservations_catalog->reservations_hash_table);

  free(reservations_catalog);
}

void insert_reservation(ReservationsCatalog reservations_catalog, Reservation reservation) {
  g_hash_table_insert(reservations_catalog->reservations_hash_table, reservation_get_id(reservation), reservation);
}

Reservation get_reservation_by_id(ReservationsCatalog reservations_catalog, char* reservation_id) {
  return (Reservation)g_hash_table_lookup(reservations_catalog->reservations_hash_table, reservation_id);
}

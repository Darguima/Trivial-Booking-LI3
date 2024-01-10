#include "catalogs_creator/reservations_catalog.h"
#include <stdlib.h>
#include "entities/reservation_entity.h"

struct reservations_catalog {
  GArray* reservations_array;
};

ReservationsCatalog reservations_catalog_create() {
  ReservationsCatalog reservations_catalog = malloc(sizeof(struct reservations_catalog));

  reservations_catalog->reservations_array = g_array_new(false, false, sizeof(Reservation));
  g_array_set_clear_func(reservations_catalog->reservations_array, (GDestroyNotify)free_reservation);

  return reservations_catalog;
}

void reservations_catalog_free(ReservationsCatalog reservations_catalog) {
  g_array_free(reservations_catalog->reservations_array, true);

  free(reservations_catalog);
}

void insert_reservation(ReservationsCatalog reservations_catalog, Reservation reservation) {
  g_array_insert_val(reservations_catalog->reservations_array, (guint)reservation_get_id(reservation), reservation);
}

Reservation get_reservation_by_id(ReservationsCatalog reservations_catalog, int reservation_id) {
  if ((guint)reservation_id >= reservations_catalog->reservations_array->len) {
    return NULL;
  }

  return g_array_index(reservations_catalog->reservations_array, Reservation, reservation_id);
}

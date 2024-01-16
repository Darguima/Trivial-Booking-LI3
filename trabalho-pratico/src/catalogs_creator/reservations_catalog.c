#include "catalogs_creator/reservations_catalog.h"
#include <stdlib.h>
#include "entities/reservation_entity.h"
#include "utils/compare_tree_str_keys.h"

struct reservations_catalog {
  GArray* reservations_array;
  GTree* reservations_begin_date_tree;
};

ReservationsCatalog reservations_catalog_create() {
  ReservationsCatalog reservations_catalog = malloc(sizeof(struct reservations_catalog));

  reservations_catalog->reservations_array = g_array_new(false, true, sizeof(Reservation));
  g_array_set_clear_func(reservations_catalog->reservations_array, (GDestroyNotify)free_reservation);

  reservations_catalog->reservations_begin_date_tree = g_tree_new_full(compare_tree_str_keys, NULL, g_free, NULL);

  return reservations_catalog;
}

void reservations_catalog_free(ReservationsCatalog reservations_catalog) {
  g_array_free(reservations_catalog->reservations_array, true);
  g_tree_destroy(reservations_catalog->reservations_begin_date_tree);

  free(reservations_catalog);
}

void insert_reservation(ReservationsCatalog reservations_catalog, Reservation reservation) {
  g_array_insert_val(reservations_catalog->reservations_array, (guint)reservation_get_id(reservation), reservation);
  g_tree_insert(reservations_catalog->reservations_begin_date_tree, reservation_get_begin_date(reservation),
                reservation);
}

Reservation get_reservation_by_id(ReservationsCatalog reservations_catalog, int reservation_id) {
  if ((guint)reservation_id >= reservations_catalog->reservations_array->len) {
    return NULL;
  }

  return g_array_index(reservations_catalog->reservations_array, Reservation, reservation_id);
}

GList* get_reservations_by_begin_date_range(ReservationsCatalog reservations_catalog,
                                            char* date_begin,
                                            char* date_end) {
  GTreeNode* reservation_node = g_tree_lower_bound(reservations_catalog->reservations_begin_date_tree, date_begin);

  if (reservation_node == NULL) {
    return NULL;
  }

  Reservation reservation = (Reservation)g_tree_node_value(reservation_node);
  char* reservation_begin_date = reservation_get_begin_date(reservation);

  GList* reservations_list = NULL;

  while (strcmp(reservation_begin_date, date_end) <= 0) {
    reservations_list = g_list_append(reservations_list, reservation);

    reservation_node = g_tree_node_next(reservation_node);
    if (reservation_node == NULL) {
      break;
    }

    reservation = (Reservation)g_tree_node_value(reservation_node);
    free(reservation_begin_date);
    reservation_begin_date = reservation_get_begin_date(reservation);
  }

  free(reservation_begin_date);

  return reservations_list;
}

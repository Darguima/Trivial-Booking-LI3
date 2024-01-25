#include "catalogs_creator/reservations_catalog.h"
#include <stdlib.h>
#include "entities/reservation_entity.h"
#include "utils/compare_datatypes.h"
#include "utils/find_tree_nodes_inside_date_range.h"
#include "utils/string_to_int.h"

struct reservations_catalog {
  GArray* reservations_array;
  GTree* reservations_begin_date_tree;
};

ReservationsCatalog reservations_catalog_create() {
  ReservationsCatalog reservations_catalog = malloc(sizeof(struct reservations_catalog));

  reservations_catalog->reservations_array = g_array_new(false, true, sizeof(Reservation));
  g_array_set_clear_func(reservations_catalog->reservations_array, (GDestroyNotify)free_reservation);

  reservations_catalog->reservations_begin_date_tree = g_tree_new_full(compare_string, NULL, g_free, NULL);

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
  return find_tree_nodes_inside_date_range(reservations_catalog->reservations_begin_date_tree,
                                           (char* (*)(void*))reservation_get_begin_date, date_begin, date_end);
}

int get_first_reservation_year(ReservationsCatalog reservations_catalog) {
  GTreeNode* node = g_tree_node_first(reservations_catalog->reservations_begin_date_tree);
  Reservation reservation = g_tree_node_value(node);
  char* begin_date = reservation_get_begin_date(reservation);
  char year[] = {begin_date[0], begin_date[1], begin_date[2], begin_date[3]};
  free(begin_date);
  return string_to_int(year);
}

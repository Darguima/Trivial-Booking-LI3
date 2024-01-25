#include "catalogs_creator/flights_catalog.h"
#include <stdlib.h>
#include "entities/flight_entity.h"
#include "utils/compare_datatypes.h"
#include "utils/find_tree_nodes_inside_date_range.h"
#include "utils/string_to_int.h"

struct flights_catalog {
  GArray* flights_array;
  GTree* flights_schedule_dep_tree;
};

FlightsCatalog flights_catalog_create() {
  FlightsCatalog flights_catalog = malloc(sizeof(struct flights_catalog));

  flights_catalog->flights_array = g_array_new(false, true, sizeof(Flight));
  g_array_set_clear_func(flights_catalog->flights_array, (GDestroyNotify)free_flight);

  flights_catalog->flights_schedule_dep_tree = g_tree_new_full(compare_string, NULL, g_free, NULL);

  return flights_catalog;
}

void flights_catalog_free(FlightsCatalog flights_catalog) {
  g_array_free(flights_catalog->flights_array, true);
  g_tree_destroy(flights_catalog->flights_schedule_dep_tree);

  free(flights_catalog);
}

void insert_flight(FlightsCatalog flights_catalog, Flight flight) {
  g_array_insert_val(flights_catalog->flights_array, (guint)flight_get_id(flight), flight);
  g_tree_insert(flights_catalog->flights_schedule_dep_tree, flight_get_schedule_departure_date(flight), flight);
}

Flight get_flight_by_id(FlightsCatalog flights_catalog, int flight_id) {
  if ((guint)flight_id >= flights_catalog->flights_array->len) {
    return NULL;
  }

  return g_array_index(flights_catalog->flights_array, Flight, flight_id);
}

GList* get_flights_by_schedule_dep_range(FlightsCatalog flights_catalog, char* date_begin, char* date_end) {
  return find_tree_nodes_inside_date_range(flights_catalog->flights_schedule_dep_tree,
                                           (char* (*)(void*))flight_get_schedule_departure_date, date_begin, date_end);
}

int get_first_flight_year(FlightsCatalog flights_catalog) {
  GTreeNode* node = g_tree_node_first(flights_catalog->flights_schedule_dep_tree);
  Flight flight = g_tree_node_value(node);
  char* schedule_departure_date = flight_get_schedule_departure_date(flight);
  char year[] = {schedule_departure_date[0], schedule_departure_date[1], schedule_departure_date[2],
                 schedule_departure_date[3]};
  free(schedule_departure_date);
  return string_to_int(year);
}

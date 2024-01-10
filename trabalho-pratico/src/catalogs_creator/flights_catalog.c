#include "catalogs_creator/flights_catalog.h"
#include <stdlib.h>
#include "entities/flight_entity.h"

struct flights_catalog {
  GArray* flights_array;
};

FlightsCatalog flights_catalog_create() {
  FlightsCatalog flights_catalog = malloc(sizeof(struct flights_catalog));

  flights_catalog->flights_array = g_array_new(false, true, sizeof(Flight));
  g_array_set_clear_func(flights_catalog->flights_array, (GDestroyNotify)free_flight);

  return flights_catalog;
}

void flights_catalog_free(FlightsCatalog flights_catalog) {
  g_array_free(flights_catalog->flights_array, true);

  free(flights_catalog);
}

void insert_flight(FlightsCatalog flights_catalog, Flight flight) {
  g_array_insert_val(flights_catalog->flights_array, (guint)flight_get_id(flight), flight);
}

Flight get_flight_by_id(FlightsCatalog flights_catalog, int flight_id) {
  if ((guint)flight_id >= flights_catalog->flights_array->len) {
    return NULL;
  }

  return g_array_index(flights_catalog->flights_array, Flight, flight_id);
}

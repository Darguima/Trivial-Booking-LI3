#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "catalogs_creator/airports_catalog.h"
#include "entities/flight_entity.h"
#include "utils/calculate_stats.h"
#include "utils/compare_datatypes.h"
#include "utils/is_active.h"
#include "utils/string_to_int.h"

struct airport {
  char* id;
  RelationArray flights;
  RelationArray delays;
  GHashTable* passengers_by_year;
};

Airport create_new_airport(AirportsCatalog airports_catalog, char* airport_id) {
  Airport new_airport = malloc(sizeof(struct airport));

  RelationArray flights = malloc(sizeof(struct relationArray));
  flights->values = g_array_new(FALSE, FALSE, sizeof(Flight));
  flights->is_sorted = false;

  RelationArray delays = malloc(sizeof(struct relationArray));
  delays->values = g_array_new(FALSE, FALSE, sizeof(long));
  delays->is_sorted = false;

  new_airport->id = g_strdup(airport_id);
  new_airport->flights = flights;
  new_airport->delays = delays;
  new_airport->passengers_by_year = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, free);

  insert_airport(airports_catalog, new_airport);

  return new_airport;
}

void free_airport(gpointer value) {
  Airport airport = (Airport)value;

  g_free(airport->id);

  g_array_free(airport->flights->values, true);
  g_free(airport->flights);

  g_array_free(airport->delays->values, true);
  g_free(airport->delays);

  g_hash_table_destroy(airport->passengers_by_year);

  free(airport);
}

char* airport_get_id(Airport airport) {
  return g_strdup(airport->id);
}

GArray* airport_get_flights(Airport airport) {
  if (!airport->flights->is_sorted) {
    g_array_sort(airport->flights->values, compare_flights_by_sched_dep_date);
    airport->flights->is_sorted = true;
  }
  return g_array_copy(airport->flights->values);
}

long airport_get_median_delay(Airport airport) {
  if (airport->delays->values->len == 0) {
    return -1;
  }

  if (airport->delays->is_sorted == false) {
    g_array_sort_with_data(airport->delays->values, compare_long, NULL);
    airport->delays->is_sorted = true;
  }

  guint half_size = airport->delays->values->len / 2;

  long median_delay = g_array_index(airport->delays->values, long, half_size);

  if (airport->delays->values->len % 2 == 0) {
    median_delay = (median_delay + g_array_index(airport->delays->values, long, half_size - 1)) / 2;
  }

  return median_delay;
}

GList* airport_get_active_years(Airport airport) {
  return g_hash_table_get_keys(airport->passengers_by_year);
}

void airport_insert_new_flight(AirportsCatalog airports_catalog, Flight flight) {
  char* airport_id_o = flight_get_origin_airport_id(flight);
  Airport airport_o = get_airport_by_id(airports_catalog, airport_id_o);
  if (airport_o == NULL) {
    airport_o = create_new_airport(airports_catalog, airport_id_o);
  }

  char* airport_id_d = flight_get_destination_airport_id(flight);
  Airport airport_d = get_airport_by_id(airports_catalog, airport_id_d);
  if (airport_d == NULL) {
    airport_d = create_new_airport(airports_catalog, airport_id_d);
  }

  long delay = flight_get_delay(flight);

  g_array_append_val(airport_o->flights->values, flight);
  g_array_append_val(airport_o->delays->values, delay);

  g_free(airport_id_o);
  g_free(airport_id_d);
}

int airport_get_passenger_by_year(Airport airport, int year) {
  int* current_passengers = g_hash_table_lookup(airport->passengers_by_year, GINT_TO_POINTER(year));

  return current_passengers == NULL ? -1 : *current_passengers;
}

void airport_increment_passengers(Airport airport, char* date, int passengers) {
  char date_copy[] = {date[0], date[1], date[2], date[3]};
  int date_int = string_to_int(date_copy);

  int* current_passengers = g_hash_table_lookup(airport->passengers_by_year, GINT_TO_POINTER(date_int));

  if (current_passengers == NULL) {
    current_passengers = malloc(sizeof(int));
    *current_passengers = 0;
    g_hash_table_insert(airport->passengers_by_year, GINT_TO_POINTER(date_int), current_passengers);
  }

  *current_passengers += passengers;
}

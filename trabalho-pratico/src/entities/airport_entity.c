#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "catalogs_creator/airports_catalog.h"
#include "entities/flight_entity.h"
#include "utils/calculate_stats.h"
#include "utils/compare_datatypes.h"
#include "utils/is_active.h"
#include "utils/string_to_int.h"

typedef struct passengersPerYear {
  int year;
  int passengers;
}* PassengersPerYear;

struct airport {
  char* id;
  RelationArray flights;
  RelationList passengers;
  RelationArray delays;
};

Airport create_new_airport(AirportsCatalog airports_catalog, char* airport_id) {
  Airport new_airport = malloc(sizeof(struct airport));

  RelationArray flights = malloc(sizeof(struct relationArray));
  flights->values = g_array_new(FALSE, FALSE, sizeof(Flight));
  flights->is_sorted = false;

  RelationArray delays = malloc(sizeof(struct relationArray));
  delays->values = g_array_new(FALSE, FALSE, sizeof(long));
  delays->is_sorted = false;

  RelationList passengers = malloc(sizeof(struct relationList));
  passengers->values = NULL;
  passengers->is_sorted = false;

  new_airport->id = g_strdup(airport_id);
  new_airport->flights = flights;
  new_airport->delays = delays;
  new_airport->passengers = passengers;

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

  g_list_free_full(airport->passengers->values, free);
  g_free(airport->passengers);

  free(airport);
}

char* airport_get_id(Airport airport) {
  return g_strdup(airport->id);
}

int airport_get_passengers(Airport airport, int year) {
  for (GList* node = airport->passengers->values; node != NULL; node = node->next) {
    PassengersPerYear passengers_per_year = (PassengersPerYear)node->data;
    if (passengers_per_year->year == year) {
      return passengers_per_year->passengers;
    }
  }

  return -1;
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

void airport_increment_passengers(Airport airport, char* date, int passengers) {
  char date_copy[] = {date[0], date[1], date[2], date[3]};
  int date_int = string_to_int(date_copy);

  GList* node;
  for (node = airport->passengers->values; node != NULL; node = node->next) {
    PassengersPerYear passengers_per_year = (PassengersPerYear)node->data;
    if (passengers_per_year->year == date_int) {
      passengers_per_year->passengers += passengers;
      return;
    }
  }

  PassengersPerYear passengers_per_year = malloc(sizeof(struct passengersPerYear));
  passengers_per_year->year = date_int;
  passengers_per_year->passengers = passengers;
  airport->passengers->values = g_list_append(airport->passengers->values, passengers_per_year);
}

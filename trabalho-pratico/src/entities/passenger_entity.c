#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "catalogs_creator/passengers_catalog.h"
#include "utils/calculate_stats.h"
#include "utils/is_active.h"

struct passenger {
  char* flight_id;
  char* user_id;
};

Passenger create_new_passenger(PassengersCatalog passengers_catalog, char** passenger_values) {
  Passenger new_passenger = malloc(sizeof(struct passenger));

  new_passenger->flight_id = strdup(passenger_values[0]);
  new_passenger->user_id = strdup(passenger_values[1]);

  insert_passenger(passengers_catalog, new_passenger);

  return new_passenger;
}

void free_passenger(gpointer value) {
  Passenger passenger = (Passenger)value;

  free(passenger->flight_id);
  free(passenger->user_id);

  free(passenger);
}

char* passenger_get_user_id(Passenger passenger) {
  return g_strdup(passenger->user_id);
}

char* passenger_get_flight_id(Passenger passenger) {
  return g_strdup(passenger->flight_id);
}

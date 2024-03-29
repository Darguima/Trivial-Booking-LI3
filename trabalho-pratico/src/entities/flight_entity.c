#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "catalogs_creator/flights_catalog.h"
#include "utils/convert_string_to_seconds.h"
#include "utils/string_to_int.h"
#include "utils/string_to_upper.h"

struct flight {
  int id;
  char* airline;
  char* plane_model;
  int total_seats;
  char* origin;
  char* destination;
  char* schedule_departure_date;
  char* schedule_arrival_date;
  char* real_departure_date;
  char* real_arrival_date;
  // char* pilot;
  // char* copilot;
  // char* notes;
  int number_of_passengers;
  long delay;
};

Flight create_new_flight(FlightsCatalog flights_catalog, char** flight_values) {
  Flight new_flight = malloc(sizeof(struct flight));

  new_flight->id = string_to_int(flight_values[0]);
  new_flight->airline = g_strdup(flight_values[1]);
  new_flight->plane_model = g_strdup(flight_values[2]);
  new_flight->total_seats = string_to_int(flight_values[3]);
  new_flight->origin = string_to_upper(strdup(flight_values[4]));
  new_flight->destination = string_to_upper(strdup(flight_values[5]));
  new_flight->schedule_departure_date = g_strdup(flight_values[6]);
  new_flight->real_departure_date = g_strdup(flight_values[8]);
  new_flight->schedule_arrival_date = g_strdup(flight_values[7]);
  new_flight->real_arrival_date = g_strdup(flight_values[9]);
  new_flight->number_of_passengers = 0;
  new_flight->delay = (long)difftime(convert_string_to_seconds(new_flight->real_departure_date),
                                     convert_string_to_seconds(new_flight->schedule_departure_date));

  insert_flight(flights_catalog, new_flight);

  return new_flight;
}

void free_flight(Flight* value) {
  Flight flight = *value;

  if (flight == NULL) {
    return;
  }

  g_free(flight->airline);
  g_free(flight->plane_model);
  g_free(flight->origin);
  g_free(flight->destination);
  g_free(flight->schedule_departure_date);
  g_free(flight->schedule_arrival_date);
  g_free(flight->real_departure_date);
  g_free(flight->real_arrival_date);

  g_free(flight);
}

int flight_get_id(Flight flight) {
  return flight->id;
}

int flight_get_total_seats(Flight flight) {
  return flight->total_seats;
}

char* flight_get_origin_airport_id(Flight flight) {
  return g_strdup(flight->origin);
}

char* flight_get_destination_airport_id(Flight flight) {
  return g_strdup(flight->destination);
}

int flight_get_number_of_passengers(Flight flight) {
  return flight->number_of_passengers;
}

long flight_get_delay(Flight flight) {
  return flight->delay;
}

char* flight_get_schedule_departure_date(Flight flight) {
  return g_strdup(flight->schedule_departure_date);
}

char* flight_get_airline(Flight flight) {
  return g_strdup(flight->airline);
}

char* flight_get_plane_model(Flight flight) {
  return g_strdup(flight->plane_model);
}

char* flight_get_origin(Flight flight) {
  return g_strdup(flight->origin);
}

char* flight_get_destination(Flight flight) {
  return g_strdup(flight->destination);
}

char* flight_get_schedule_arrival_date(Flight flight) {
  return g_strdup(flight->schedule_arrival_date);
}

void flight_increment_passengers(Flight flight, int number_of_passengers) {
  flight->number_of_passengers += number_of_passengers;
}

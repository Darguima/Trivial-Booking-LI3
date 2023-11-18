#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>
#include "utils/convert_string_to_seconds.h"
#include "write_output/write_output.h"

//! @brief Compares two flights to sort them first by schedule departure date and then by ID if the departure date is
//! the same
gint compare_flights_order(gconstpointer a, gconstpointer b) {
  FlightSchema flightA = (FlightSchema)a;
  FlightSchema flightB = (FlightSchema)b;

  int date_comp = g_strcmp0(flightB->schedule_departure_date, flightA->schedule_departure_date);

  if (date_comp != 0) {
    return date_comp;
  }

  return g_strcmp0(flightA->id, flightB->id);
}

//! @brief Retrieves a list of flights associated with a specific airport within a given time range.
GList* get_flights_by_airport_and_time(GHashTable* flights_table,
                                       const char* airport,
                                       char* begin_date,
                                       char* end_date) {
  GList* result = NULL;
  GHashTableIter iter;
  gpointer key, value;

  g_hash_table_iter_init(&iter, flights_table);
  while (g_hash_table_iter_next(&iter, &key, &value)) {
    FlightSchema flight = (FlightSchema)value;

    int departure_difference =
        (int)(convert_string_to_seconds(flight->schedule_departure_date) - convert_string_to_seconds(begin_date));
    int arrive_difference =
        (int)(convert_string_to_seconds(flight->schedule_arrival_date) - convert_string_to_seconds(end_date));

    if (g_strcmp0(flight->origin, airport) == 0 && departure_difference >= 0 && arrive_difference <= 0) {
      result = g_list_append(result, flight);
    }
  }

  return result;
}

int query_5(Catalogs CATALOGS, int command_number, bool format_flag, char* name, char* begin_date, char* end_date) {
  GList* flights = get_flights_by_airport_and_time(CATALOGS->flights, name, begin_date, end_date);

  flights = g_list_sort(flights, compare_flights_order);

  FILE* output_file = create_output_file(command_number);

  int results_acc = 1;
  for (GList* iterator = flights; iterator != NULL; iterator = iterator->next, results_acc++) {
    FlightSchema flight = (FlightSchema)iterator->data;

    output_key_value output_array[] = {{"id", flight->id},
                                       {"schedule_departure_date", flight->schedule_departure_date},
                                       {"destination", flight->destination},
                                       {"airline", flight->airline},
                                       {"plane_model", flight->plane_model}};

    write_output(output_file, format_flag, results_acc, output_array, 5);
  }

  g_list_free(flights);
  close_output_file(output_file);

  return 0;
}
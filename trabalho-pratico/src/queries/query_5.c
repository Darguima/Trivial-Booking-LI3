#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "entities/airport_entity.h"
#include "utils/convert_string_to_seconds.h"
#include "write_output/write_output.h"

int query_5(Catalogs catalogs, int command_number, bool format_flag, char* name, char* begin_date, char* end_date) {
  FILE* output_file = create_output_file(command_number);
  Airport airport = get_airport_by_id(catalogs->airports, name);
  GArray* array_of_flights = airport_get_flights(airport);

  int results_acc = 1;
  for (guint i = 0; i < array_of_flights->len; i++) {
    Flight flight = g_array_index(array_of_flights, Flight, i);
    char* schedule_departure_date = flight_get_schedule_departure_date(flight);
    int departure_difference_begin =
        (int)(convert_string_to_seconds(schedule_departure_date) - convert_string_to_seconds(begin_date));
    if (departure_difference_begin < 0) {
      i++;
      free(schedule_departure_date);
      continue;
    }
    int departure_difference_end =
        (int)(convert_string_to_seconds(schedule_departure_date) - convert_string_to_seconds(end_date));
    if (departure_difference_end <= 0) {
      char flight_id[11];
      sprintf(flight_id, "%010d", flight_get_id(flight));
      char* destination = flight_get_destination(flight);
      char* airline = flight_get_airline(flight);
      char* plane_model = flight_get_plane_model(flight);
      output_key_value output_array[] = {{"id", flight_id},
                                         {"schedule_departure_date", schedule_departure_date},
                                         {"destination", destination},
                                         {"airline", airline},
                                         {"plane_model", plane_model}};
      write_output(output_file, format_flag, results_acc, output_array, 5);
      free(destination);
      free(airline);
      free(plane_model);
      results_acc++;
    }

    free(schedule_departure_date);
    if (departure_difference_end > 0) {
      break;
    }
  }
  g_array_free(array_of_flights, TRUE);
  close_output_file(output_file);
  return 0;
}
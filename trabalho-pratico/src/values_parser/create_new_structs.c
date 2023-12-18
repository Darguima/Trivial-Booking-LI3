#include <datatypes/datatypes.h>
#include <glib.h>
#include "utils/calculate_stats.h"
#include "utils/includes_breakfast.h"
#include "utils/is_active.h"
#include "utils/string_to_int.h"

PassengerSchema create_new_passenger(char** passenger_values) {
  PassengerSchema new_passenger = malloc(sizeof(struct passengerSchema));
  new_passenger->flight_id = strdup(passenger_values[0]);
  new_passenger->user_id = strdup(passenger_values[1]);
  return new_passenger;
}

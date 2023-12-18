#include <datatypes/datatypes.h>
#include <glib.h>

void free_passengers_struct(gpointer value) {
  PassengerSchema passenger = (PassengerSchema)value;

  free(passenger->flight_id);
  free(passenger->user_id);

  free(passenger);
}

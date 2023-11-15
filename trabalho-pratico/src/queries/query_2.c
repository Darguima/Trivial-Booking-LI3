#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>

int query_2(Catalogs CATALOGS,
            int command_number,
            bool field,
            char* id,
            char* flights,
            char* reservations) {
  printf("I'm in query_2\n");

  UNUSED(CATALOGS);
  UNUSED(command_number);
  UNUSED(field);
  UNUSED(id);
  UNUSED(flights);
  UNUSED(reservations);

  return 0;
}
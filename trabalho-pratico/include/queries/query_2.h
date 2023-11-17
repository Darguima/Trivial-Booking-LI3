#ifndef QUERY_2_H
#define QUERY_2_H

#include <datatypes/datatypes.h>

typedef struct userReservationsFlights {
  char* id;
  char* type;
  char* start_date;
}* UserReservationsFlights;

int query_2(Catalogs CATALOGS, int command_number, bool format_flag, char* id, char* optional);

#endif
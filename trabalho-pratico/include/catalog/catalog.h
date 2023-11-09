#ifndef CATALOG_H
#define CATALOG_H 

#include <datatypes/datatypes.h>

int catalog_users(UserSchema user);
int catalog_flights(FlightSchema flight);
int catalog_passengers(PassengerSchema passenger);
int catalog_reservations(ReservationSchema reservation);

#endif
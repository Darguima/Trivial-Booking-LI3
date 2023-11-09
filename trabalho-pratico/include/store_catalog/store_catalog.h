#ifndef CATALOG_H
#define CATALOG_H 

#include <datatypes/datatypes.h>

int store_catalog_user(UserSchema user);
int store_catalog_flight(FlightSchema flight);
int store_catalog_passenger(PassengerSchema passenger);
int store_catalog_reservation(ReservationSchema reservation);

#endif
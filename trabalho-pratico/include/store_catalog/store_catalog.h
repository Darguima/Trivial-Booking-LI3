#ifndef CATALOG_H
#define CATALOG_H

#include <datatypes/datatypes.h>
#include <glib.h>

int store_catalog_user(UserSchema user, GHashTable* users_catalog);
int store_catalog_flight(FlightSchema flight, GHashTable* flights_catalog);
int store_catalog_passenger(PassengerSchema passenger, GHashTable* passengers_catalog);
int store_catalog_reservation(ReservationSchema reservation, GHashTable* reservations_catalog);

#endif
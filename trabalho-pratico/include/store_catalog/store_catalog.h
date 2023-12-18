//! @file

#ifndef CATALOG_H
#define CATALOG_H

#include <datatypes/datatypes.h>
#include <glib.h>

/*
 * @brief Stores a passenger in the passengers catalog HashTable.
 *
 * @param passenger Passenger struct to be stored.
 * @param passengers_catalog Passengers catalog.
 * @return int 0 if success.
 */
int store_catalog_passenger(PassengerSchema passenger, GHashTable* passengers_catalog);

/*
 * @brief Stores a reservation in the reservations catalog HashTable.
 *
 * @param reservation Reservation struct to be stored.
 * @param reservations_catalog Reservations catalog.
 * @return int 0 if success.
 */
int store_catalog_reservation(ReservationSchema reservation, GHashTable* reservations_catalog);

#endif
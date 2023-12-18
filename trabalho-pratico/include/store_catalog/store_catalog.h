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

#endif
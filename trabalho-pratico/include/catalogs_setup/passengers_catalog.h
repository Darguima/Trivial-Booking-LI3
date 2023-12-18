//! @file
#ifndef PASSENGERS_CATALOG_H
#define PASSENGERS_CATALOG_H

#include <glib.h>
#include "entities/passenger_entity.h"

//! The passengers catalog
typedef struct passengers_catalog* PassengersCatalog;

/**
 * @brief Will create the catalog to store passengers
 *
 * @return PassengersCatalog
 */
PassengersCatalog passengers_catalog_create();

/**
 * @brief This function free the passenger catalogs, including their content (structs stored)
 *
 * @param PassengersCatalog The passenger catalogs struct
 */
void passengers_catalog_free(PassengersCatalog passengers_catalog);

/**
 * @brief Will insert the given passenger on the passengers catalog
 *
 * @param PassengersCatalog The passengers catalog
 * @param Passenger The passenger to be inserted
 */
void insert_passenger(PassengersCatalog, Passenger);

/**
 * @brief Will search by the passenger on the catalog. Will return NULL if not found
 *
 * @param passengers_catalog The passengers catalog
 * @param passenger_id The passenger id
 * @return Passenger | NULL
 */
Passenger get_passenger_by_id(PassengersCatalog passengers_catalog, char* passenger_id);

#endif
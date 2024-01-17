//! @file
#ifndef FLIGHTS_CATALOG_H
#define FLIGHTS_CATALOG_H

#include <glib.h>
#include "entities/flight_entity.h"

typedef struct flight* Flight;

//! The flights catalog
typedef struct flights_catalog* FlightsCatalog;

/**
 * @brief Will create the catalog to store flights
 *
 * @return FlightsCatalog
 */
FlightsCatalog flights_catalog_create();

/**
 * @brief This function free the flight catalogs, including their content (structs stored)
 *
 * @param FlightsCatalog The flight catalogs struct
 */
void flights_catalog_free(FlightsCatalog flights_catalog);

/**
 * @brief Will insert the given flight on the flights catalog
 *
 * @param FlightsCatalog The flights catalog
 * @param Flight The flight to be inserted
 */
void insert_flight(FlightsCatalog flights_catalog, Flight flight);

/**
 * @brief Will search by the flight on the catalog. Will return NULL if not found
 *
 * @param flights_catalog The flights catalog
 * @param flight_id The flight id
 * @return Flight | NULL
 */
Flight get_flight_by_id(FlightsCatalog flights_catalog, int flight_id);

/**
 * @brief Will return a list of flights that are in the given schedule departure date range
 *
 * @param flights_catalog The flights catalog
 * @param date_begin The begin date
 * @param date_end The end date
 * @return GList* The list of flights
 */
GList* get_flights_by_schedule_dep_range(FlightsCatalog flights_catalog, char* date_begin, char* date_end);

#endif
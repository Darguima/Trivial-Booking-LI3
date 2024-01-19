//! @file
#ifndef AIRPORTS_CATALOG_H
#define AIRPORTS_CATALOG_H

#include <glib.h>
#include "entities/airport_entity.h"

typedef struct airport* Airport;

//! The airports catalog
typedef struct airports_catalog* AirportsCatalog;

/**
 * @brief Will create the catalog to store airports
 *
 * @return AirportsCatalog
 */
AirportsCatalog airports_catalog_create();

/**
 * @brief This function free the airport catalogs, including their content (structs stored)
 *
 * @param AirportsCatalog The airport catalogs struct
 */
void airports_catalog_free(AirportsCatalog airports_catalog);

/**
 * @brief Will insert the given airport on the airports catalog
 *
 * @param AirportsCatalog The airports catalog
 * @param Airport The airport to be inserted
 */
void insert_airport(AirportsCatalog, Airport);

/**
 * @brief Will create the aux data structures to be used on the queries
 *
 * @param airports_catalog The airports catalog
 */
void airports_create_aux_data_structs(AirportsCatalog airports_catalog);

/**
 * @brief Will search by the airport on the catalog. Will return NULL if not found
 *
 * @param airports_catalog The airports catalog
 * @param airport_id The airport id
 * @return Airport | NULL
 */
Airport get_airport_by_id(AirportsCatalog airports_catalog, char* airport_id);

/**
 * @brief Will return the top N airports with the highest median delay
 *
 * @param airports_catalog The airports catalog
 * @param N The number of airports to return
 * @return Airport
 */
GList* get_top_N_airports_median_delay(AirportsCatalog airports_catalog, int N);

#endif
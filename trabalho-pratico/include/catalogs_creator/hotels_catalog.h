//! @file
#ifndef HOTELS_CATALOG_H
#define HOTELS_CATALOG_H

#include <glib.h>
#include "entities/hotel_entity.h"

//! The hotels catalog
typedef struct hotels_catalog* HotelsCatalog;

/**
 * @brief Will create the catalog to store hotels
 *
 * @return HotelsCatalog
 */
HotelsCatalog hotels_catalog_create();

/**
 * @brief This function free the hotel catalogs, including their content (structs stored)
 *
 * @param HotelsCatalog The hotel catalogs struct
 */
void hotels_catalog_free(HotelsCatalog hotels_catalog);

/**
 * @brief Will insert the given hotel on the hotels catalog
 *
 * @param HotelsCatalog The hotels catalog
 * @param Hotel The hotel to be inserted
 */
void insert_hotel(HotelsCatalog, Hotel);

/**
 * @brief Will search by the hotel on the catalog. Will return NULL if not found
 *
 * @param hotels_catalog The hotels catalog
 * @param hotel_id The hotel id
 * @return Hotel | NULL
 */
Hotel get_hotel_by_id(HotelsCatalog hotels_catalog, int hotel_id);

#endif
//! @file
#ifndef RESERVATIONS_CATALOG_H
#define RESERVATIONS_CATALOG_H

#include <glib.h>
#include "entities/reservation_entity.h"

typedef struct reservation* Reservation;

//! The reservations catalog
typedef struct reservations_catalog* ReservationsCatalog;

/**
 * @brief Will create the catalog to store reservations
 *
 * @return ReservationsCatalog
 */
ReservationsCatalog reservations_catalog_create();

/**
 * @brief This function free the reservation catalogs, including their content (structs stored)
 *
 * @param ReservationsCatalog The reservation catalogs struct
 */
void reservations_catalog_free(ReservationsCatalog reservations_catalog);

/**
 * @brief Will insert the given reservation on the reservations catalog
 *
 * @param ReservationsCatalog The reservations catalog
 * @param Reservation The reservation to be inserted
 */
void insert_reservation(ReservationsCatalog reservations_catalogs, Reservation reservation);

/**
 * @brief Will search by the reservation on the catalog. Will return NULL if not found
 *
 * @param reservations_catalog The reservations catalog
 * @param reservation_id The reservation id
 * @return Reservation | NULL
 */
Reservation get_reservation_by_id(ReservationsCatalog reservations_catalog, int reservation_id);

/**
 * @brief Will return a list of reservations that begin between the given dates
 *
 * @param reservations_catalog The reservations catalog
 * @param date_begin The begin date
 * @param date_end The end date
 * @return GList* The list of reservations
 */
GList* get_reservations_by_begin_date_range(ReservationsCatalog reservations_catalog, char* date_begin, char* date_end);

#endif
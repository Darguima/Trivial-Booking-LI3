//! @file
#ifndef CATALOGS_CREATOR_H
#define CATALOGS_CREATOR_H

#include <glib.h>
#include "catalogs_creator/flights_catalog.h"
#include "catalogs_creator/hotels_catalog.h"
#include "catalogs_creator/passengers_catalog.h"
#include "catalogs_creator/reservations_catalog.h"
#include "catalogs_creator/users_catalog.h"

//! All the entities catalogs pointers in one struct
typedef struct catalogs {
  UsersCatalog users;
  FlightsCatalog flights;
  HotelsCatalog hotels;
  ReservationsCatalog reservations;
  PassengersCatalog passengers;
}* Catalogs;

/**
 * @brief This function will create and store the entities catalogs inside a struct
 *
 * @return Catalogs (* struct catalogs)
 */
Catalogs catalogs_creator();

/**
 * @brief This function free all the catalogs, including their content (structs stored)
 *
 * @param CATALOGS The catalogs struct created by the function `catalogs_creator()`
 */
void free_catalogs(Catalogs catalogs);

#endif
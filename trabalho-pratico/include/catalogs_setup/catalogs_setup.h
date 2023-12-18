//! @file
#ifndef CATALOGS_SETUP_H
#define CATALOGS_SETUP_H

#include <glib.h>
#include "catalogs_setup/users_catalog.h"

//! All the HashTables pointers in one struct
typedef struct catalogs {
  UsersCatalog users;

  //! Flights without refactoring
  GHashTable* flights;
  //! Passengers without refactoring
  GHashTable* passengers;
  //! Reservations without refactoring
  GHashTable* reservations;
}* Catalogs;

/**
 * @brief This function will create and store the entities catalogs inside a struct
 *
 * @return Catalogs (* struct catalogs)
 */
Catalogs catalogs_setup();

/**
 * @brief This function free all the catalogs, including their content (structs stored)
 *
 * @param CATALOGS The catalogs struct created by the function `catalogs_creator()`
 */
void free_catalogs(Catalogs catalogs);

#endif
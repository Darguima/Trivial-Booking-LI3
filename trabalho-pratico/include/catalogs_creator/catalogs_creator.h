//! @file
#ifndef CATALOGS_CREATOR_H
#define CATALOGS_CREATOR_H

#include "datatypes/datatypes.h"

/**
 * @brief This function will create the catalogs Hash Tables inside a struct
 *
 * @return Catalogs (* struct catalogs)
 */
Catalogs catalogs_creator();

/**
 * @brief This function free all the catalogs, including their content (structs stored)
 *
 * @param CATALOGS The catalogs struct created by the function `catalogs_creator()`
 * @return 0 if the catalogs were filled successfully
 */
int free_catalogs(Catalogs catalogs);

#endif
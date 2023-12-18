//! @file
#ifndef USERS_CATALOG_H
#define USERS_CATALOG_H

#include <glib.h>
#include "entities/user_entity.h"

//! The users catalog
typedef struct users_catalog {
  GHashTable* users_hash_table;
}* UsersCatalog;

/**
 * @brief Will create the catalog to store users
 *
 * @return UsersCatalog
 */
UsersCatalog users_catalog_create();

/**
 * @brief This function free the user catalogs, including their content (structs stored)
 *
 * @param UsersCatalog The user catalogs struct
 */
void users_catalog_free(UsersCatalog users_catalog);

/**
 * @brief Will insert the given user on the users catalog
 *
 * @param UsersCatalog The users catalog
 * @param User The user to be inserted
 */
void insert_user(UsersCatalog, User);

/**
 * @brief Will search by the user on the catalog. Will return NULL if not found
 *
 * @param users_catalog The users catalog
 * @param user_id The user id
 * @return User | NULL
 */
User get_user_by_id(UsersCatalog users_catalog, char* user_id);

#endif
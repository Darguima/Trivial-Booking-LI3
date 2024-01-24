//! @file
#ifndef USERS_CATALOG_H
#define USERS_CATALOG_H

#include <glib.h>
#include "entities/user_entity.h"

//! The users catalog
typedef struct users_catalog* UsersCatalog;

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
void insert_user(UsersCatalog users_catalogs, User users);

/**
 * @brief Will search by the user on the catalog. Will return NULL if not found
 *
 * @param users_catalog The users catalog
 * @param user_id The user id
 * @return User | NULL
 */
User get_user_by_id(UsersCatalog users_catalog, char* user_id);

/**
 * @brief Will return a list of users that were created between the given dates
 *
 * @param users_catalog The users catalog
 * @param date_begin The begin date
 * @param date_end The end date
 * @return GList* The list of users
 */
GList* get_users_by_account_creation_range(UsersCatalog users_catalog, char* date_begin, char* date_end);

GList* get_users_by_prefix(UsersCatalog users_catalog, const char* prefix);

#endif
//! @file
#ifndef USER_ENTITY_H
#define USER_ENTITY_H

#include <stdbool.h>
#include "catalogs_setup/users_catalog.h"

//! User Entity
typedef struct user {
  char* id;
  char* name;
  char* email;
  char* phone_number;
  char* birth_date;
  char* sex;
  char* passport;
  char* country_code;
  char* address;
  char* account_creation;
  char* pay_method;
  bool account_status;
  double total_spent;
  int age;
  int number_of_flights;
  int number_of_reservations;
}* User;

/**
 * @brief Will create a new user entity struct and store it in the users catalog
 *
 * @param UsersCatalog The users catalog
 * @param user_values The data of the user, on a string array
 */
void create_new_user(UsersCatalog users_catalog, char** user_values);

#endif

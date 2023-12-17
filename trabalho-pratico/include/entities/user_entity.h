//! @file
#ifndef USER_ENTITY_H
#define USER_ENTITY_H

#include <stdbool.h>
#include "catalogs_setup/users_catalog.h"

typedef struct users_catalog* UsersCatalog;

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
 * This function takes an array of strings containing user data and creates a new user schema.
 * The order of values in the array should match the expected order:
 * [id, name, email, phone_number, birth_date, sex, passport, country_code, address, account_creation, pay_method,
 * account_status].
 *
 * @param UsersCatalog The users catalog
 * @param user_values An array of strings containing user data.
 */
void create_new_user(UsersCatalog users_catalog, char** user_values);

/**
 * @brief Increments the total number of reservations for a user
 *
 * @param user The user to increment the number of reservations
 * @param number_of_reservations The number of reservations to increment
 */
void user_increment_reservations(User user, int number_of_reservations);

/**
 * @brief Increments the total number of flights for a user
 *
 * @param user The user to increment the number of flights
 * @param number_of_flights The number of flights to increment
 */
void user_increment_flights(User user, int number_of_flights);

/**
 * @brief Increments the total amount spent by a user due to a reservation
 *
 * @param user The user to increment the total amount spent
 * @param total_reservation_price The total amount spent to increment
 */
void user_increment_total_spent(User user, double total_reservation_price);

#endif

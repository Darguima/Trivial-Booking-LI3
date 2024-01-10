//! @file
#ifndef USER_ENTITY_H
#define USER_ENTITY_H

#include <stdbool.h>
#include "catalogs_creator/flights_catalog.h"
#include "catalogs_creator/reservations_catalog.h"
#include "catalogs_creator/users_catalog.h"

typedef struct users_catalog* UsersCatalog;

typedef struct user_flights* UserFlights;

typedef struct user_reservations* UserReservations;

//! User Entity
typedef struct user* User;

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
User create_new_user(UsersCatalog users_catalog, char** user_values);

/**
 * @brief Will free the memory allocated for a user entity
 *
 * @param value The user entity to free
 */
void free_user(gpointer value);

/**
 * @brief Will return the id from the given user
 *
 * @param user The user to get the id from
 * @return char* The id from the given user
 */
char* user_get_id(User user);

/**
 * @brief Will return the name from the given user
 *
 * @param user The user to get the id from
 * @return char* The name from the given user
 */
char* user_get_name(User user);

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

void user_add_flight(User user, Flight flight);

void user_add_reservation(User user, Reservation reservation);

#endif

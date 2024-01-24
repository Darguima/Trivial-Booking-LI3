//! @file
#ifndef USER_ENTITY_H
#define USER_ENTITY_H

#include <stdbool.h>
#include "catalogs_creator/flights_catalog.h"
#include "catalogs_creator/reservations_catalog.h"
#include "catalogs_creator/users_catalog.h"
#include "datatypes/datatypes.h"

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

void user_arroz(UsersCatalog user_catalog);

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

int user_get_number_of_flights(User user);

bool user_get_is_active(User user);

int user_get_number_of_reservations(User user);

double user_get_total_spent(User user);

int user_get_age(User user);

char* user_get_sex(User user);

char* user_get_country_code(User user);

char* user_get_passport(User user);

GArray* user_get_reservations(User user);

/**
 * @brief Will return the account creation from the given user
 *
 * @param user The user to get the account creation from
 * @return char* The account creation from the given user
 */
char* user_get_account_creation(User user);

GArray* user_get_flights(User user);

/**
 * @brief Increments the total amount spent by a user due to a reservation
 *
 * @param user The user to increment the total amount spent
 * @param total_reservation_price The total amount spent to increment
 */
void user_increment_total_spent(User user, double total_reservation_price);

/**
 * @brief Will add a flight to the given user
 *
 * @param user The user to add the flight
 * @param flight The flight to add to the user
 */
void user_add_flight(User user, Flight flight);

/**
 * @brief Will add a reservation to the given user
 *
 * @param user The user to add the reservation
 * @param reservation The reservation to add to the user
 */
void user_add_reservation(User user, Reservation reservation);

#endif

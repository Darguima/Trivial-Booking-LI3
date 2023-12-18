//! @file
#ifndef PASSENGER_ENTITY_H
#define PASSENGER_ENTITY_H

#include <stdbool.h>
#include "catalogs_creator/passengers_catalog.h"

typedef struct passengers_catalog* PassengersCatalog;

//! Passenger Entity
typedef struct passenger* Passenger;

/**
 * @brief Will create a new passenger entity struct and store it in the passengers catalog
 *
 * This function takes an array of strings containing passenger data and creates a new passenger schema.
 * The order of values in the array should match the expected order:
 * [id, name, email, phone_number, birth_date, sex, passport, country_code, address, account_creation, pay_method,
 * account_status].
 *
 * @param PassengersCatalog The passengers catalog
 * @param passenger_values An array of strings containing passenger data.
 */
Passenger create_new_passenger(PassengersCatalog passengers_catalog, char** passenger_values);

/**
 * @brief Will free the memory allocated for a passenger entity
 *
 * @param value The passenger entity to free
 */
void free_passenger(gpointer value);

/**
 * @brief Will return the user id of a passenger
 *
 * @param passenger The passenger entity
 * @return char*
 */
char* passenger_get_user_id(Passenger passenger);

/**
 * @brief Will return the flight id of a passenger
 *
 * @param passenger The passenger entity
 * @return char*
 */
char* passenger_get_flight_id(Passenger passenger);

#endif

//! @file
#ifndef airport_ENTITY_H
#define airport_ENTITY_H

#include <stdbool.h>
#include "catalogs_creator/airports_catalog.h"
#include "entities/flight_entity.h"

typedef struct airports_catalog* AirportsCatalog;

//! Airport Entity
typedef struct airport* Airport;

/**
 * @brief Will create a new airport entity struct and store it in the airports catalog
 *
 * This function takes an array of strings containing airport data and creates a new airport schema.
 * The order of values in the array should match the expected order:
 * [id, name, email, phone_number, birth_date, sex, passport, country_code, address, account_creation, pay_method,
 * account_status].
 *
 * @param AirportsCatalog The airports catalog
 * @param airport_values An array of strings containing airport data.
 */
Airport create_new_airport(AirportsCatalog airports_catalog, char* airport_id);

/**
 * @brief Will free the memory allocated for a airport entity
 *
 * @param value The airport entity to free
 */
void free_airport(gpointer value);

/**
 * @brief Will return the id from the given airport
 *
 * @param airport The airport to get the id from
 * @return char* The id from the given airport
 */
char* airport_get_id(Airport airport);

/**
 * @brief Will return the passengers count from the given airport
 *
 * @param airport The airport to get the passengers count from
 * @param year The year to get the passengers count from
 * @return int The passengers count from the given airport
 */
int airport_get_passengers(Airport airport, int year);

GArray* airport_get_flights(Airport airport);

/**
 * @brief Will return the median delay from the given airport
 *
 * @param airport The airport to get the median delay from
 * @return long The median delay from the given airport
 */
long airport_get_median_delay(Airport airport);

/**
 * @brief Will return the active years from the given airport, based on passengers
 *
 * @param airport The airport to get the active years from
 * @return GList* The active years from the given airport
 */

/**
 * @brief Will return the passengers of the airport on the given year
 *
 * @param airport The airport to get the passengers number
 * @param passengers The number of passengers on the given airport on the given year
 */
int airport_get_passenger_by_year(Airport airport, int year);

/**
 * @brief Will insert the given flight on the airport flights array
 *
 * @param airports_catalog The airports catalog
 * @param flight The flight to be inserted
 */
void airport_insert_new_flight(AirportsCatalog airports_catalog, Flight flight);

/**
 * @brief Will increment the passengers count on the given airport
 *
 * @param airport The airport to increment the passengers count
 * @param passengers The number of passengers to increment
 */
void airport_increment_passengers(Airport airport, char* date, int passengers);

#endif

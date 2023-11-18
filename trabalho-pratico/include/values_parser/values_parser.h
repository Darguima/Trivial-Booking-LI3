//! @file
#ifndef VALUES_PARSER_H
#define VALUES_PARSER_H

#include "datatypes/datatypes.h"

/**
 * @brief Parses and validates user-related data, creates a new user, and stores it in the catalogs
 *
 * Validates user data elements and creates a new user if the data is valid. Then, it stores
 * the new user in the catalogs.
 *
 * @param user_values An array containing user data elements to be parsed and validated
 * @param catalogs The catalogs containing hash tables to store the user data
 * @return int Returns 0 if the user data is successfully parsed and stored; otherwise, returns 1 for invalid data
 */
int values_parser_users(char** user_values, Catalogs catalogs);

/**
 * @brief Parses and validates flight-related data, creates a new flight, and stores it in the catalogs
 *
 * Validates flight data elements and creates a new flight if the data is valid. Then, it stores
 * the new flight in the catalogs.
 *
 * @param flight_values An array containing flight data elements to be parsed and validated
 * @param catalogs The catalogs containing hash tables to store the flight data
 * @return int Returns 0 if the flight data is successfully parsed and stored; otherwise, returns 1 for invalid data
 */
int values_parser_flights(char** flight_values, Catalogs catalogs);

/**
 * @brief Parses and validates passenger-related data, creates a new passenger, and stores it in the catalogs
 *
 * Validates passenger data elements and creates a new passenger if the data is valid. Then, it stores
 * the new passenger in the catalogs and updates related flight and user information.
 *
 * @param passengers_values An array containing passenger data elements to be parsed and validated
 * @param catalogs The catalogs containing hash tables to store the passenger data
 * @return int Returns 0 if the passenger data is successfully parsed and stored; otherwise, returns 1 for invalid data
 */
int values_parser_passengers(char** passengers_values, Catalogs catalogs);

/**
 * @brief Parses and validates reservation-related data, creates a new reservation, and stores it in the catalogs
 *
 * Validates reservation data elements and creates a new reservation if the data is valid. Then, it stores
 * the new reservation in the catalogs and updates related user information.
 *
 * @param reservations_values An array containing reservation data elements to be parsed and validated
 * @param catalogs The catalogs containing hash tables to store the reservation data
 * @return int Returns 0 if the reservation data is successfully parsed and stored; otherwise, returns 1 for invalid
 * data
 */
int values_parser_reservations(char** reservations_values, Catalogs catalogs);

#endif
//! @file
#ifndef VALUES_PARSER_H
#define VALUES_PARSER_H

#include "datatypes/datatypes.h"

/**
 * @brief Adds user data from a parsed CSV line to the user catalog.
 *
 * This function takes an array of strings containing parsed values from a CSV line representing user data.
 * It checks if the values are valid and, if so, adds the user to the user catalog.
 *
 * @param values An array of strings containing the parsed values from a CSV line.
 * @param catalog The catalogs structure containing the user catalog.
 * @return An integer indicating success (1) or failure (0).
 */
int values_parser_users(char** values, Catalogs catalog);

/**
 * @brief Adds flight data from a parsed CSV line to the flight catalog.
 *
 * This function takes an array of strings containing parsed values from a CSV line representing flight data.
 * It checks if the values are valid and, if so, adds the flight to the flight catalog.
 *
 * @param values An array of strings containing the parsed values from a CSV line.
 * @param catalog The catalogs structure containing the flight catalog.
 * @return An integer indicating success (1) or failure (0).
 */

int values_parser_flights(char** values, Catalogs catalog);

/**
 * @brief Adds passenger data from a parsed CSV line to the passenger catalog.
 *
 * This function takes an array of strings containing parsed values from a CSV line representing passenger data.
 * It checks if the values are valid and, if so, adds the passenger to the passenger catalog.
 *
 * @param values An array of strings containing the parsed values from a CSV line.
 * @param catalog The catalogs structure containing the passenger catalog.
 * @return An integer indicating success (1) or failure (0).
 */
int values_parser_passengers(char** values, Catalogs catalog);

/**
 * @brief Adds reservation data from a parsed CSV line to the reservation catalog.
 *
 * This function takes an array of strings containing parsed values from a CSV line representing reservation data.
 * It checks if the values are valid and, if so, adds the reservation to the reservation catalog.
 *
 * @param values An array of strings containing the parsed values from a CSV line.
 * @param catalog The catalogs structure containing the reservation catalog.
 * @return An integer indicating success (1) or failure (0).
 */
int values_parser_reservations(char** values, Catalogs catalog);

#endif
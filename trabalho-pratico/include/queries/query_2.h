//! @file
#ifndef QUERY_2_H
#define QUERY_2_H

#include <datatypes/datatypes.h>

/**
 * @brief Represents a data structure for user reservations and flights.
 *
 * This structure is used to store information about user reservations and flights,
 * including an identifier (id), a type ("flight" or "reservation"), and a start date.
 */
typedef struct userReservationsFlights {
  char* id;          //!< Identifier for the reservation or flight.
  char* type;        //!< Type of the reservation or flight.
  char* start_date;  //!< Start date of the reservation or flight.
}* UserReservationsFlights;

/**
 * @brief Executes query 2 based on the provided ID and optional parameter
 *
 * Executes query 2 by retrieving user reservations and flights based on the ID,
 * sorting them, and writing the relevant data to the output file based on the optional parameter.
 *
 * @param CATALOGS The catalogs struct created by the function `catalogs_creator()`
 * @param command_number The number associated with the command
 * @param format_flag Flag indicating the output format
 * @param id The ID used to retrieve information from the catalogs
 * @param optional Optional parameter indicating specific data to write to the output file
 * @return int Returns 0 upon successful execution of query 2
 */

int query_2(Catalogs CATALOGS, int command_number, bool format_flag, char* id, char* optional);

#endif
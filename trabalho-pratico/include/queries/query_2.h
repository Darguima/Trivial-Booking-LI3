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
 * @brief Executes Query 2 based on the provided parameters.
 *
 * This function performs Query 2 on the passengers hash table and reservations hash table within given catalogs,
 * retrieving all reservations and flights made by a specified user. The results are written to an output file with a
 * name based on the command number.
 *
 * @param CATALOGS The catalogs structure containing hash tables for users, flights, and reservations.
 * @param command_number The command number specifying the name of the output file.
 * @param format_flag A flag indicating the desired output format (e.g., true for formatted output, false for raw data).
 * @param id The ID of the user for whom reservations and flights are to be retrieved.
 * @param optional A char* parameter specifying the desired output (e.g., "reservations" for only reservations,
 *                 "flights" for only flights, or NULL for both reservations and flights).
 * @return 0 on success, 1 on failure.
 *
 */
int query_2(Catalogs CATALOGS, int command_number, bool format_flag, char* id, char* optional);

#endif
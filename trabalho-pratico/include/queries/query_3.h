//! @file
#ifndef QUERY_3_H
#define QUERY_3_H

#include <datatypes/datatypes.h>

/**
 * @brief Executes Query 3 based on the provided parameters.
 *
 * This function performs Query 3 on the reservation hash table within the given catalogs, calculating the average
 * rating of a specified hotel based on the ratings from reservations associated with that hotel. The results are
 * written to an output file with a name based on the command number.
 *
 * @param CATALOGS The catalogs structure containing hash tables for users, flights, and reservations.
 * @param command_number The command number specifying the name of the output file.
 * @param format_flag A flag indicating the desired output format (e.g., true for formatted output, false for raw data).
 * @param id The ID of the hotel for which the average rating is to be calculated.
 * @return Returns 0 if the query is executed successfully, or a non-zero value if an error occurs.
 *
 */
int query_3(Catalogs CATALOGS, int command_number, bool format_flag, char* id);

#endif
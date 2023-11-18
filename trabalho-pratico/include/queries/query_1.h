
//! @file
#ifndef QUERY_1_H
#define QUERY_1_H

#include <datatypes/datatypes.h>

/**
 * @brief Executes Query 1 based on the provided parameters.
 *
 * This function performs Query 1 on the given catalogs, extracting statistics for a specific entity (flight,
 * reservation, or user) that is saved in a specific Hash Table. identified by the provided ID. The extracted
 * information is written to an output file with a name based on the command number.
 *
 * @param CATALOGS The catalogs structure containing hash tables for users, flights, and reservations.
 * @param command_number The command number specifying the name of the output file.
 * @param format_flag A flag indicating the desired output format (e.g., true for formatted output, false for raw data).
 * @param id The ID of the entity for which statistics are to be extracted.
 * @return Returns 0 if the query is executed successfully, or a non-zero value if an error occurs.
 */
int query_1(Catalogs CATALOGS, int command_number, bool format_flag, char* id);

#endif
//! @file
#ifndef QUERY_8_H
#define QUERY_8_H

#include <datatypes/datatypes.h>

/**
 * @brief Executes Query 8 based on the provided parameters.
 *
 * This function performs Query 8 on the reservation hash table within the given catalogs,
 * calculating the total revenue for a specific hotel within the specified date range.
 * The results are written to an output file with a name based on the command number.
 *
 * @param CATALOGS The catalogs structure containing hash tables for users, flights, and reservations.
 * @param command_number The command number specifying the name of the output file.
 * @param format_flag A flag indicating the desired output format (e.g., true for formatted output, false for raw data).
 * @param name The name or identifier of the hotel for which revenue is to be calculated.
 * @param begin_date The start date of the range for calculating revenue.
 * @param end_date The end date of the range for calculating revenue.
 * @return 0 on success, 1 on failure.
 */
int query_8(Catalogs CATALOGS, int command_number, bool format_flag, char* name, char* begin_date, char* end_date);

#endif
//! @file
#ifndef QUERY_5_H
#define QUERY_5_H

#include <datatypes/datatypes.h>

/**
 * @brief Executes query 5 to retrieve flights by airport and time range
 *
 * Executes query 5 to obtain and sort flights associated with a specific airport within
 * a specified time range, writing flight details to the output file.
 *
 * @param CATALOGS The catalogs struct created by the function `catalogs_creator()`
 * @param command_number The number associated with the command
 * @param format_flag Flag indicating the output format
 * @param name The airport name to search flights from
 * @param begin_date The start date of the time range
 * @param end_date The end date of the time range
 * @return int Returns 0 upon successful execution of query 5
 */
int query_5(Catalogs CATALOGS, int command_number, bool format_flag, char* name, char* begin_date, char* end_date);

#endif

//! @file
#ifndef QUERY_1_H
#define QUERY_1_H

#include <datatypes/datatypes.h>

/**
 * @brief Executes query 1 based on the provided ID
 *
 * Executes query 1 by checking if the ID corresponds to a user, flight, or reservation,
 * and writes the associated data to the output file.
 *
 * @param CATALOGS The catalogs struct created by the function `catalogs_creator()`
 * @param command_number The number associated with the command
 * @param format_flag Flag indicating the output format
 * @param id The ID used to retrieve information from the catalogs
 * @return int Returns 0 upon successful execution of query 1
 */

int query_1(Catalogs CATALOGS, int command_number, bool format_flag, char* id);

#endif
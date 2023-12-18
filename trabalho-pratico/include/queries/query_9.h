//! @File
#ifndef QUERY_9_H
#define QUERY_9_H

#include <catalogs_creator/catalogs_creator.h>

/**
 * @brief Executes query 9 to retrieve users with names starting with a specified prefix
 *
 * Executes query 9 to retrieve and write users whose names start with the given prefix
 * to an output file, sorted based on their names and IDs.
 *
 * @param catalogs The catalogs created by the function `catalogs_creator()`
 * @param command_number The number associated with the command
 * @param format_flag Flag indicating the output format
 * @param prefix The prefix used to filter users by name
 * @return int Returns 0 upon successfully executing query 9
 */
int query_9(Catalogs catalogs, int command_number, bool format_flag, const char* prefix);

#endif
//! @file
#ifndef QUERY_3_H
#define QUERY_3_H

#include <catalogs_creator/catalogs_creator.h>
#include "state/state.h"

/**
 * @brief Executes query 3 to retrieve the average rating of a hotel
 *
 * Executes query 3 by calculating the average rating of a hotel and writing it to the output file.
 *
 * @param CATALOGS The catalogs struct created by the function `catalogs_creator()`
 * @param command_number The number associated with the command
 * @param format_flag Flag indicating the output format
 * @param id The ID of the hotel to retrieve the average rating for
 * @return int Returns 0 upon successful execution of query 3
 */
int query_3(Catalogs CATALOGS, int command_number, bool format_flag, char* id, State* state);

#endif
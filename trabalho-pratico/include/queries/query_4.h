//! @file
#ifndef QUERY_4_H
#define QUERY_4_H

#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>

/**
 * @brief Executes query 4 to retrieve hotel reservations sorted by date and ID
 *
 * Executes query 4 by retrieving reservations for a specified hotel, sorting them by date and ID,
 * and writing the relevant data to the output file.
 *
 * @param catalogs The catalogs struct created by the function `catalogs_creator()`
 * @param command_number The number associated with the command
 * @param format_flag Flag indicating the output format
 * @param hotel_id The ID of the hotel to retrieve reservations for
 * @return int Returns 0 upon successful execution of query 4
 */
int query_4(Catalogs catalogs, int command_number, bool format_flag, char* hotel_id);

#endif
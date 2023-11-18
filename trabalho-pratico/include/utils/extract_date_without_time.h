//! @file
#ifndef EXTRACT_DATE_WITHOUT_TIME_H
#define EXTRACT_DATE_WITHOUT_TIME_H

/**
 * @brief Extracts the date part from a string containing date and time
 *
 * Extracts the date part from a string that contains both date and time,
 * returning only the date portion.
 *
 * @param date_with_time The string containing date and time information
 * @return char* Returns the extracted date; returns NULL on error or if no time is found
 */
char* extract_date_without_time(char* date_with_time);

#endif
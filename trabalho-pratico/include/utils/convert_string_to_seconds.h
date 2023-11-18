//! @file
#ifndef CONVERT_STRING_TO_SECONDS_H
#define CONVERT_STRING_TO_SECONDS_H
#include <time.h>

/**
 * @brief Converts a date/time string to a time_t value
 *
 * Converts a date/time string in the format "YYYY/MM/DD HH:MM:SS" or "YYYY/MM/DD" to a time_t value,
 * representing the number of seconds since the Epoch (00:00:00 UTC on January 1, 1970).
 *
 * @param dateString The string containing the date/time information
 * @return time_t Returns the converted time as a time_t value; returns -1 on failure
 */
time_t convert_string_to_seconds(char* dateString);

#endif
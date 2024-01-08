//! @file
#ifndef CALCULATE_STATS_H
#define CALCULATE_STATS_H

#include <datatypes/datatypes.h>

/**
 * @brief Calculates the difference in days between two dates
 *
 * Calculates the difference in days between two given dates.
 *
 * @param date1 First date for comparison
 * @param date2 Second date for comparison
 * @return int Returns the difference in days between the two dates
 */
int get_days_difference(char* date1, char* date2);

/**
 * @brief Calculates the total amount spent based on dates, city tax, and price per night
 *
 * Calculates the total amount spent considering the duration of stay, city tax, and price per night.
 *
 * @param date1 Start date of the stay
 * @param date2 End date of the stay
 * @param city_tax The city tax percentage
 * @param price_per_night The price per night of stay
 * @return double Returns the total amount spent for the stay
 */
double calculate_total_spent(char* date1, char* date2, int city_tax, int price_per_night);

/**
 * @brief Calculates the age of a user based on their birth date
 *
 * Calculates the age of a user based on their birth date compared to the default date.
 *
 * @param birth_date The birth date of the user in the format "YYYY/MM/DD"
 * @return int Returns the calculated age of the user
 */
int calculate_user_age(char* birth_date);
#endif
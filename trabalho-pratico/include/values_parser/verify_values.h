//! @file
#ifndef VERIFY_VALUES_H
#define VERIFY_VALUES_H

#include <stdbool.h>

/**
 * @brief Verifies if the dates are in order.
 * @param date1 First date.
 * @param date2 Second date.
 * @return True if the dates are in order, false otherwise.
 */
bool verify_are_dates_in_order(char* date1, char* date2);

/**
 * @brief Verifies if string is a valid email.
 * @param email Email to be verified.
 * @return True if the email is valid, false otherwise.
 */
bool verify_account_email(char* email);

/**
 * @brief Verifies if string is a valid status.
 *
 * Valid status are: "active", "inactive".
 *
 * @param status Status string to be verified.
 * @return True if the status is valid, false otherwise.
 */
bool verify_account_status(char* status);

/**
 * @brief Verifies if the country code is valid.
 *
 * A country code is valid if it is a 2 alpha chars.
 *
 * @param country_code Country code string to be verified.
 * @return True if the country code is valid, false otherwise.
 */
bool verify_user_country_code(char* country_code);

/**
 * @brief Verifies if the date is valid.
 *
 * Accepts dates in the format: "YYYY-MM-DD" and "YYYY/MM/DD HH:MM:SS".
 *
 * @param date Date string to be verified.
 * @return True if the date is valid, false otherwise.
 */
bool verify_date(char* date);

/**
 * @brief Verifies if the airport name is valid.
 *
 * A airport name (code) is valid if it is a 3 alpha chars.
 *
 * @param airport_name Airport name string to be verified.
 * @return True if the airport name is valid, false otherwise.
 */
bool verify_airport_name(char* airport_name);

/**
 * @brief Verifies if char is a number.
 *
 * @param digit Char to be verified.
 * @return True if the char is a number, false otherwise.
 */
bool verify_if_is_digit(char* digit);

/**
 * @brief Verifies if the breakfast string is valid.
 *
 * A valid breakfast string is: "true", "t", "1", "false", "f", "0", "".
 *
 * @param breakfast Breakfast string to be verified.
 * @return True if the breakfast string is valid, false otherwise.
 */
bool verify_breakfast(char* breakfast);

/**
 * @brief Verifies if digit is non zero.
 *
 * @param new_digit Digit to be verified.
 * @return True if the digit is non zero, false otherwise.
 */
bool verify_if_is_digit_non_zero(char* new_digit);

/**
 * @brief Verifies if the hotel rating stars are valid.
 *
 * Valid hotel rating stars are: "1", "2", "3", "4", "5".
 *
 * @param word Hotel rating stars string to be verified.
 * @return True if the hotel rating stars are valid, false otherwise.
 */
bool verify_hotel_rating_stars(char* word);

/**
 * @brief Verifies if the hotel rating is valid.
 *
 * Valid hotel rating are: "", "1", "2", "3", "4", "5".
 *
 * @param word Hotel rating string to be verified.
 * @return True if the hotel rating is valid, false otherwise.
 */
bool verify_hotel_rating(char* word);

#endif
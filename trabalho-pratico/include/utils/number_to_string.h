//! @file
#ifndef NUMBER_TO_STRING_H
#define NUMBER_TO_STRING_H
/**
 * @brief Converts an integer to a string
 *
 * Converts an integer to a string representation.
 *
 * @param number The integer value to be converted
 * @return char* Returns the string representation of the integer
 */
char* int_to_string(int number);

/**
 * @brief Converts a double to a string with specified precision
 *
 * Converts a double to a string representation with a specified precision.
 *
 * @param number The double value to be converted
 * @param precision The number of decimal places in the resulting string
 * @return char* Returns the string representation of the double with specified precision
 */
char* double_to_string(double number, int precision);

#endif
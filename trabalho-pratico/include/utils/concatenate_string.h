//! @file
#ifndef CONCATENATE_STRING_H
#define CONCATENATE_STRING_H

/**
 * @brief Concatenates an array of strings into a single string
 *
 * Concatenates an array of strings into a single string, allocating memory
 * for the result and handling memory allocation errors.
 *
 * @param strings Array of strings to be concatenated
 * @param length Number of strings in the array
 * @return char* Returns the concatenated string
 */
char* concatenate_string(char** strings, int length);

#endif

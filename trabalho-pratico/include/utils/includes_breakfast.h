//! @file
#ifndef INCLUDES_BREAKFAST_H
#define INCLUDES_BREAKFAST_H

#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Checks if a string represents a true/false breakfast status
 *
 * Converts the input string to lowercase and checks if it represents a true or false breakfast status.
 *
 * @param breakfast_stat The input string indicating the breakfast status
 * @return bool Returns true if the input indicates breakfast is included; otherwise, false
 */
bool includes_breakfast(char* breakfast_stat);

#endif
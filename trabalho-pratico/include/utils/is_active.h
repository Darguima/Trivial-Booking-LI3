//! @file
#ifndef IS_ACTIVE_H
#define IS_ACTIVE_H

#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Checks if a string represents an active status
 *
 * Verifies whether the input string represents an active status ("active").
 *
 * @param status The input string indicating the status
 * @return bool Returns true if the status is "active"; otherwise, false
 */
bool is_active(char* status);

#endif
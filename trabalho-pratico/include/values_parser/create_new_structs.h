//! @file
#ifndef CREATE_NEW_STRUCTS_H
#define CREATE_NEW_STRUCTS_H

/**
 * @brief Creates a new passenger schema using the provided array of passenger values.
 *
 * This function takes an array of strings containing passenger data and creates a new passenger schema.
 * The order of values in the array should match the expected order: [flight_id, user_id].
 *
 * @param passengers_values An array of strings containing passenger data.
 * @return A newly allocated PassengerSchema structure initialized with the provided values.
 */
PassengerSchema create_new_passenger(char** passengers_values);

#endif
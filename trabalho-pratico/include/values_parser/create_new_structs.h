//! @file
#ifndef CREATE_NEW_STRUCTS_H
#define CREATE_NEW_STRUCTS_H

/**
 * @brief Creates a new reservation schema using the provided array of reservation values.
 *
 * This function takes an array of strings containing reservation data and creates a new reservation schema.
 * The order of values in the array should match the expected order:
 * [id, user_id, hotel_id, hotel_name, hotel_stars, city_tax, address, begin_date, end_date, price_per_night,
 * includes_breakfast, room_details, rating, comment].
 *
 * @param reservation_values An array of strings containing reservation data.
 * @return A newly allocated ReservationSchema structure initialized with the provided values.
 */
ReservationSchema create_new_reservation(char** reservation_values);

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
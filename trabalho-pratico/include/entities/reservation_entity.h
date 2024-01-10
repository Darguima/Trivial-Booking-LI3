//! @file
#ifndef RESERVATION_ENTITY_H
#define RESERVATION_ENTITY_H

#include <stdbool.h>
#include "catalogs_creator/reservations_catalog.h"

typedef struct reservations_catalog* ReservationsCatalog;

//! Reservation Entity
typedef struct reservation* Reservation;

/**
 * @brief Will create a new reservation entity struct and store it in the reservations catalog
 *
 * This function takes an array of strings containing reservation data and creates a new reservation schema.
 * The order of values in the array should match the expected order:
 * [id, user_id, hotel_id, hotel_name, hotel_stars, city_tax, address, begin_date, end_date, price_per_night,
 * includes_breakfast, room_details, rating, comment].
 *
 * @param ReservationsCatalog The reservations catalog
 * @param reservation_values An array of strings containing reservation data.
 */
Reservation create_new_reservation(ReservationsCatalog reservations_catalog, char** reservation_values);

/**
 * @brief Will free the memory allocated for a reservation entity
 *
 * @param value The reservation entity to free
 */
void free_reservation(gpointer value);

/**
 * @brief Will return the id from the given reservation
 *
 * @param reservation The reservation to get the id from
 * @return char* The id from the given reservation
 */
char* reservation_get_id(Reservation reservation);

/**
 * @brief Will return the id from the hotel from the given reservation
 *
 * @param reservation The reservation to get the Hotel id from
 * @return char* The id from the hotel that receive the given reservation
 */
char* reservation_get_hotel_id(Reservation reservation);

/**
 * @brief Will return the name from the hotel from the given reservation
 *
 * @param reservation The reservation to get the Hotel name from
 * @return char* The name from the hotel that receive the given reservation
 */
char* reservation_get_hotel_name(Reservation reservation);

/**
 * @brief Will return the rating from the given reservation
 *
 * @param reservation The reservation to get the rating from
 * @return int The rating from the given reservation
 */
char reservation_get_rating(Reservation reservation);

/**
 * @brief Will return the total price from the given reservation
 *
 * @param reservation The reservation to get the total price from
 * @return double The total price from the given reservation
 */
double reservation_get_total_price(Reservation reservation);

#endif

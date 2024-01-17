//! @file
#ifndef hotel_ENTITY_H
#define hotel_ENTITY_H

#include <stdbool.h>
#include "catalogs_creator/hotels_catalog.h"
#include "entities/reservation_entity.h"

typedef struct hotels_catalog* HotelsCatalog;

//! Hotel Entity
typedef struct hotel* Hotel;

/**
 * @brief Will create a new hotel entity struct and store it in the hotels catalog
 *
 * This function takes an array of strings containing hotel data and creates a new hotel schema.
 * The order of values in the array should match the expected order:
 * [id, name, email, phone_number, birth_date, sex, passport, country_code, address, account_creation, pay_method,
 * account_status].
 *
 * @param HotelsCatalog The hotels catalog
 * @param hotel_values An array of strings containing hotel data.
 */
Hotel create_new_hotel(HotelsCatalog hotels_catalog, char** hotel_values);

/**
 * @brief Will free the memory allocated for a hotel entity
 *
 * @param value The hotel entity to free
 */
void free_hotel(gpointer value);

/**
 * @brief Will return the id from the given hotel
 *
 * @param hotel The hotel to get the id from
 * @return char* The id from the given hotel
 */
int hotel_get_id(Hotel hotel);

/**
 * @brief Will return the name from the given hotel
 *
 * @param hotel The hotel to get the id from
 * @return char* The name from the given hotel
 */
char* hotel_get_name(Hotel hotel);

/**
 * @brief Will return the rating from the given hotel
 *
 * @param hotel The hotel to get the id from
 * @return char* The rating from the given hotel
 */
int hotel_get_rating(Hotel hotel);

/**
 * @brief Get the array of reservations for a given hotel.
 *
 * This function returns a GArray pointer containing the reservations
 * associated with the specified hotel.
 *
 * @param hotel The hotel for which reservations are to be retrieved.
 * @return A GArray pointer containing the reservations of the hotel.
 */

GArray* hotel_get_reservations(Hotel hotel);

/**
 * @brief Get the total revenue of a hotel for a specified date range.
 *
 * This function calculates and returns the total revenue of the specified hotel
 * for the given date range.
 *
 * @param hotel The hotel for which total revenue is to be calculated.
 * @param begin_date The start date of the date range in the format "yyyy/mm/dd".
 * @param end_date The end date of the date range in the format "yyyy/mm/dd".
 * @return The total revenue of the hotel for the specified date range.
 */
int hotel_get_total_revenue(Hotel hotel, char* begin_date, char* end_date);

/**
 * @brief Insert a new reservation on the given hotel
 *
 * @param reservation The reservation to be inserted
 */
void hotel_insert_new_reservation(HotelsCatalog hotels_catalog, Reservation reservation);

#endif

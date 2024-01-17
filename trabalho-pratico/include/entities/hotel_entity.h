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
double hotel_get_rating(Hotel hotel);

/**
 * @brief Insert a new reservation on the given hotel
 *
 * @param reservation The reservation to be inserted
 */
void hotel_insert_new_reservation(HotelsCatalog hotels_catalog, Reservation reservation);

#endif

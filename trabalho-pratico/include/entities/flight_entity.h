//! @file
#ifndef flight_ENTITY_H
#define flight_ENTITY_H

#include <stdbool.h>
#include "catalogs_creator/flights_catalog.h"

typedef struct flights_catalog* FlightsCatalog;

//! Flight Entity
typedef struct flight* Flight;

/**
 * @brief Will create a new flight entity struct and store it in the flights catalog
 *
 * This function takes an array of strings containing flight data and creates a new flight schema.
 * The order of values in the array should match the expected order:
 * [id, airline, plane_model, total_seats, origin, destination, schedule_departure_date, schedule_arrival_date,
 * real_departure_date, real_arrival_date, pilot, copilot, notes].
 *
 * @param FlightsCatalog The flights catalog
 * @param flight_values An array of strings containing flight data.
 */
Flight create_new_flight(FlightsCatalog flights_catalog, char** flight_values);

/**
 * @brief Will free the memory allocated for a flight entity
 *
 * @param value The flight entity to free
 */
void free_flight(Flight* value);

/**
 * @brief Will return the id from the given flight
 *
 * @param flight The flight to get the id from
 * @return char* The id from the given flight
 */
int flight_get_id(Flight flight);

char* flight_get_schedule_departure_date(Flight flight);

/**
 * @brief Will return the total seats from the given flight
 *
 * @param flight The flight to get the id from
 * @return int The total seats from the given flight
 */
int flight_get_total_seats(Flight flight);

int flight_get_number_of_passengers(Flight flight);

long flight_get_delay(Flight flight);

char* flight_get_plane_model(Flight flight);

char* flight_get_airline(Flight flight);

char* flight_get_origin(Flight flight);

char* flight_get_destination(Flight flight);

char* flight_get_schedule_arrival_date(Flight flight);

/**
 * @brief Will return the airline from the given flight
 *
 * @param flight The flight to get the airline from
 * @return char* The airline from the given flight
 */
void flight_increment_seat(Flight flight, int number_of_seats);

#endif

//! @file
#include <glib.h>

/*
 * @brief This function will free the memory allocated for the reservation struct.
 *
 * @param value The reservation struct.
 */
void free_reservation_struct(gpointer value);

/*
 * @brief This function will free the memory allocated for the passenger struct.
 *
 * @param value The passenger struct.
 */
void free_passengers_struct(gpointer value);
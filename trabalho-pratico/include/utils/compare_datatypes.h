#ifndef COMPARE_DATATYPES_H
#define COMPARE_DATATYPES_H

#include <datatypes/datatypes.h>
#include <glib.h>
#include <string.h>

/**
 * @brief Will compare (with strcmp) the keys of two nodes
 *
 * @param a pointer to one node
 * @param b pointer to another node
 * @param user_data not used
 * @return Negative value if a < b; zero if a = b; positive value if a > b.
 */
gint compare_string(gconstpointer a, gconstpointer b, gpointer user_data);

/**
 * @brief Will compare the keys of two nodes
 *
 * @param a pointer to one node
 * @param b pointer to another node
 * @param user_data not used
 * @return Negative value if a < b; zero if a = b; positive value if a > b.
 */
gint compare_long(gconstpointer a, gconstpointer b, gpointer user_data);

/**
 * @brief Will compare the median delay of two airports. Will use the id of the airports as a tie breaker.
 *
 * @param a pointer to one airport
 * @param b pointer to another airport
 * @return Negative value if a < b; zero if a = b; positive value if a > b.
 */
gint compare_airports_by_median_delay(gconstpointer a, gconstpointer b);

/**
 * @brief Will compare the passengers of two airports on a given year. Will use the id of the airports as a tie breaker.
 *
 * @param a pointer to one airport
 * @param b pointer to another airport
 * @param user_data pointer to the year to compare
 * @return Negative value if a < b; zero if a = b; positive value if a > b.
 */
gint compare_airports_by_passengers(gconstpointer a, gconstpointer b, gpointer user_data);

/**
 * @brief Will compare the dates of two flights. Will use the id of the flights as a tie breaker.
 *
 * @param a pointer to one flight
 * @param b pointer to another flight
 * @return Negative value if a < b; zero if a = b; positive value if a > b.
 */
gint compare_flights_by_sched_dep_date(gconstpointer a, gconstpointer b);

/**
 * @brief Will compare the dates of two reservations. Will use the id of the reservations as a tie breaker.
 *
 * @param a pointer to one reservation
 * @param b pointer to another reservation
 * @return Negative value if a < b; zero if a = b; positive value if a > b.
 */
gint compare_reservations_by_begin_date(gconstpointer a, gconstpointer b);

/**
 * @brief Will compare the users names. Will use the id of the users as a tie breaker.
 *
 * @param a pointer to one user
 * @param b pointer to another user
 * @return Negative value if a < b; zero if a = b; positive value if a > b.
 */
gint compare_users_by_name(gconstpointer a, gconstpointer b, gpointer user_data);

#endif
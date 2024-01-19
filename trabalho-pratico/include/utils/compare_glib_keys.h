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
gint compare_str_keys(gconstpointer a, gconstpointer b, gpointer user_data);

/**
 * @brief Will compare the keys of two nodes
 *
 * @param a pointer to one node
 * @param b pointer to another node
 * @param user_data not used
 * @return Negative value if a < b; zero if a = b; positive value if a > b.
 */
gint compare_long_keys(gconstpointer a, gconstpointer b, gpointer user_data);

/**
 * @brief Will compare the median delay of two airports. Will use the id of the airports as a tie breaker.
 *
 * @param a pointer to one airport
 * @param b pointer to another airport
 * @param user_data not used
 * @return Negative value if a < b; zero if a = b; positive value if a > b.
 */
gint compare_airports_by_median_delay(gconstpointer a, gconstpointer b, gpointer user_data);
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
gint compare_tree_str_keys(gconstpointer a, gconstpointer b, gpointer user_data);
#include <glib.h>

/**
 * @brief Find the elements on the tree that are inside the given date range
 *
 * The node key need be the date
 *
 * @param tree Tree to search
 * @param get_date Function that returns the date of the node
 * @param date_begin Date begin of the range
 * @param date_end Date end of the range
 *
 * @return GList* Returns a list with the entities inside the date range
 */
GList* find_tree_nodes_inside_date_range(GTree* tree, char* (*get_date)(void*), char* date_begin, char* date_end);

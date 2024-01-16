#include <glib.h>

GList* find_tree_nodes_inside_date_range(GTree* tree, char* (*get_date)(void*), char* date_begin, char* date_end) {
  GTreeNode* node = g_tree_lower_bound(tree, date_begin);

  if (node == NULL) {
    return NULL;
  }

  void* entity = g_tree_node_value(node);
  char* account_creation = get_date(entity);

  GList* r_list = NULL;

  while (strcmp(account_creation, date_end) <= 0) {
    r_list = g_list_append(r_list, entity);

    node = g_tree_node_next(node);
    if (node == NULL) {
      break;
    }

    entity = g_tree_node_value(node);
    free(account_creation);
    account_creation = get_date(entity);
  }

  free(account_creation);

  return r_list;
}
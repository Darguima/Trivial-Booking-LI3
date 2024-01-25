#include "catalogs_creator/users_catalog.h"
#include <stdlib.h>
#include "datatypes/datatypes.h"
#include "entities/user_entity.h"
#include "utils/compare_datatypes.h"
#include "utils/find_tree_nodes_inside_date_range.h"

struct users_catalog {
  GHashTable* users_hash_table;
  GTree* users_account_creation_tree;
  GTree* users_name_tree;
};

UsersCatalog users_catalog_create() {
  UsersCatalog users_catalog = malloc(sizeof(struct users_catalog));

  users_catalog->users_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_user);
  users_catalog->users_account_creation_tree = g_tree_new_full(compare_string, NULL, g_free, NULL);
  users_catalog->users_name_tree = g_tree_new_full(compare_users_by_name, users_catalog, g_free, NULL);

  return users_catalog;
}

void users_catalog_free(UsersCatalog users_catalog) {
  g_hash_table_destroy(users_catalog->users_hash_table);
  g_tree_destroy(users_catalog->users_account_creation_tree);
  g_tree_destroy(users_catalog->users_name_tree);

  free(users_catalog);
}

void insert_user(UsersCatalog users_catalog, User user) {
  g_hash_table_insert(users_catalog->users_hash_table, user_get_id(user), user);
  g_tree_insert(users_catalog->users_account_creation_tree, user_get_account_creation(user), user);
  g_tree_insert(users_catalog->users_name_tree, user_get_id(user), user);
}

User get_user_by_id(UsersCatalog users_catalog, char* user_id) {
  return (User)g_hash_table_lookup(users_catalog->users_hash_table, user_id);
}

GList* get_users_by_account_creation_range(UsersCatalog users_catalog, char* date_begin, char* date_end) {
  return find_tree_nodes_inside_date_range(users_catalog->users_account_creation_tree,
                                           (char* (*)(void*))user_get_account_creation, date_begin, date_end);
}

GList* get_users_by_prefix(UsersCatalog catalog, const char* prefix) {
  GList* result = NULL;
  GTreeNode* node = g_tree_node_first(catalog->users_name_tree);

  while (node != NULL) {
    User user = g_tree_node_value(node);
    char* user_name = user_get_name(user);
    if (prefix[0] > user_name[0]) {
      free(user_name);
      node = g_tree_node_next(node);
      continue;
    } else if (user_get_is_active(user) && (strncmp(prefix, user_name, strlen(prefix)) == 0)) {
      (result) = g_list_append(result, user);
    } else if (prefix[0] < user_name[0]) {
      free(user_name);
      break;
    }
    node = g_tree_node_next(node);
    free(user_name);
  }

  return result;
}
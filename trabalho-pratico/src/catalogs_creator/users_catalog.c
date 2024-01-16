#include "catalogs_creator/users_catalog.h"
#include <stdlib.h>
#include <string.h>
#include "entities/user_entity.h"
#include "utils/compare_tree_str_keys.h"

struct users_catalog {
  GHashTable* users_hash_table;
  GTree* users_account_creation_tree;
};

UsersCatalog users_catalog_create() {
  UsersCatalog users_catalog = malloc(sizeof(struct users_catalog));

  users_catalog->users_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_user);
  users_catalog->users_account_creation_tree = g_tree_new_full(compare_tree_str_keys, NULL, g_free, NULL);

  return users_catalog;
}

void users_catalog_free(UsersCatalog users_catalog) {
  g_hash_table_destroy(users_catalog->users_hash_table);
  g_tree_destroy(users_catalog->users_account_creation_tree);

  free(users_catalog);
}

void insert_user(UsersCatalog users_catalog, User user) {
  g_hash_table_insert(users_catalog->users_hash_table, user_get_id(user), user);
  g_tree_insert(users_catalog->users_account_creation_tree, user_get_account_creation(user), user);
}

User get_user_by_id(UsersCatalog users_catalog, char* user_id) {
  return (User)g_hash_table_lookup(users_catalog->users_hash_table, user_id);
}

GList* get_users_by_account_creation_range(UsersCatalog users_catalog, char* date_begin, char* date_end) {
  GTreeNode* user_node = g_tree_lower_bound(users_catalog->users_account_creation_tree, date_begin);

  if (user_node == NULL) {
    return NULL;
  }

  User user = (User)g_tree_node_value(user_node);
  char* user_account_creation = user_get_account_creation(user);

  GList* users_list = NULL;

  while (strcmp(user_account_creation, date_end) <= 0) {
    users_list = g_list_append(users_list, user);

    user_node = g_tree_node_next(user_node);
    if (user_node == NULL) {
      break;
    }

    user = (User)g_tree_node_value(user_node);
    free(user_account_creation);
    user_account_creation = user_get_account_creation(user);
  }

  free(user_account_creation);

  return users_list;
}

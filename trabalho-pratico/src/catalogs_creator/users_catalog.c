#include "catalogs_creator/users_catalog.h"
#include <stdlib.h>
#include "datatypes/datatypes.h"
#include "entities/user_entity.h"
#include "locale.h"
#include "utils/compare_datatypes.h"
#include "utils/find_tree_nodes_inside_date_range.h"

struct users_catalog {
  GHashTable* users_hash_table;
  GTree* users_account_creation_tree;
  GTree* users_name_tree;
};

gint compare_names(gconstpointer a, gconstpointer b, gpointer user_data) {
  UsersCatalog users_catalog = (UsersCatalog)user_data;
  const char* id_1 = (const char*)a;
  const char* id_2 = (const char*)b;
  setlocale(LC_COLLATE, "en_US.UTF-8");

  User user_1 = get_user_by_id(users_catalog, (char*)id_1);
  User user_2 = get_user_by_id(users_catalog, (char*)id_2);
  char* name_1 = user_get_name(user_1);
  char* name_2 = user_get_name(user_2);
  int name_comp = strcoll(name_1, name_2);
  free(name_1);
  free(name_2);
  if (name_comp != 0) {
    return name_comp;
  }
  return strcoll(id_1, id_2);
}
UsersCatalog users_catalog_create() {
  UsersCatalog users_catalog = malloc(sizeof(struct users_catalog));

  users_catalog->users_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_user);
  users_catalog->users_account_creation_tree = g_tree_new_full(compare_string, NULL, g_free, NULL);
  users_catalog->users_name_tree = g_tree_new_full(compare_names, users_catalog, g_free, NULL);

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

// gboolean find_entities_callback(gpointer key, gpointer value, gpointer user_data) {
//   UNUSED(key);
//   CallbackData* data = (CallbackData*)user_data;
//   User user = (User)value;
//   char* user_name = user_get_name(user);

//   if (data->prefix[0] > user_name[0]) {
//     free(user_name);
//     return FALSE;
//   } else if ((strncmp(data->prefix, user_name, strlen(data->prefix)) == 0) && user_get_is_active(user)) {
//     *(data->result) = g_list_append(*(data->result), value);
//   } else if (data->prefix[0] < user_name[0]) {
//     free(user_name);
//     return TRUE;
//   }
//   free(user_name);
//   return FALSE;
// }

// GList* find_entities_with_prefix(GTree* tree, const char* prefix) {
//   GList* result = NULL;

//   gpointer user_data[] = {&result, (gpointer)prefix};
//   g_tree_foreach(tree, find_entities_callback, user_data);

//   return result;
// }

GList* get_users_by_prefix(UsersCatalog catalog, const char* prefix) {
  GList* result = NULL;
  GTreeNode* node = g_tree_node_first(catalog->users_name_tree);

  while (node != NULL) {
    User user = g_tree_node_value(node);
    char* user_name = user_get_name(user);
    if (prefix[0] > user_name[0]) {
      // do nothing
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
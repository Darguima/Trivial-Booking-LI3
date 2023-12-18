#include "catalogs_setup/users_catalog.h"
#include <stdlib.h>
#include "entities/user_entity.h"

struct users_catalog {
  GHashTable* users_hash_table;
};

UsersCatalog users_catalog_create() {
  UsersCatalog users_catalog = malloc(sizeof(struct users_catalog));

  users_catalog->users_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_user);

  return users_catalog;
}

void users_catalog_free(UsersCatalog users_catalog) {
  g_hash_table_destroy(users_catalog->users_hash_table);

  free(users_catalog);
}

void insert_user(UsersCatalog users_catalog, User user) {
  g_hash_table_insert(users_catalog->users_hash_table, user_get_id(user), user);
}

User get_user_by_id(UsersCatalog users_catalog, char* user_id) {
  return (User)g_hash_table_lookup(users_catalog->users_hash_table, user_id);
}

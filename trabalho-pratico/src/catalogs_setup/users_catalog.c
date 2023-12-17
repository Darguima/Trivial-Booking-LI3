#include "catalogs_setup/users_catalog.h"
#include <stdlib.h>
#include "entities/user_entity.h"

void free_user_struct(gpointer value) {
  User user = (User)value;

  free(user->id);
  free(user->name);
  free(user->email);
  free(user->phone_number);
  free(user->birth_date);
  free(user->sex);
  free(user->passport);
  free(user->country_code);
  free(user->address);
  free(user->account_creation);
  free(user->pay_method);
  // free(user->account_status);

  free(user);
}

UsersCatalog users_catalog_create() {
  UsersCatalog users_catalog = malloc(sizeof(struct users_catalog));

  users_catalog->users_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, free_user_struct);

  return users_catalog;
}

void insert_user(UsersCatalog users_catalog, User user) {
  g_hash_table_insert(users_catalog->users_hash_table, user->id, user);
}

User get_user_by_id(UsersCatalog users_catalog, char* user_id) {
  return (User)g_hash_table_lookup(users_catalog->users_hash_table, user_id);
}

#include <datatypes/datatypes.h>
#include <glib.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/calculate_stats.h"
#include "write_output/write_output.h"

void setLocale() {
  setlocale(LC_COLLATE, "en_US.UTF-8");
}

GList* getUsersWithPrefix(GHashTable* user_table, const char* prefix) {
  GList* result = NULL;
  GHashTableIter iter;
  gpointer key, value;

  g_hash_table_iter_init(&iter, user_table);
  while (g_hash_table_iter_next(&iter, &key, &value)) {
    UserSchema user = (UserSchema)value;
    if (user->account_status == true) {
      if (strcoll(prefix, user->name) == 0) {
        result = g_list_append(result, user);
      }
    }
  }

  return result;
}

int compare_users_order(gconstpointer a, gconstpointer b) {
  UserSchema userA = (UserSchema)a;
  UserSchema userB = (UserSchema)b;

  int name_comp = strcoll(userA->name, userB->name);

  if (name_comp != 0) {
    return name_comp;
  }

  return strcoll(userA->id, userB->id);
}

int query_9(Catalogs catalogs, int command_number, bool format_flag, const char* prefix) {
  setLocale();  // Definir o locale

  GList* usersWithPrefix = getUsersWithPrefix(catalogs->users, prefix);

  usersWithPrefix = g_list_sort(usersWithPrefix, compare_users_order);

  FILE* output_file = create_output_file(command_number);

  int results_acc = 0;
  for (GList* iterator = usersWithPrefix; iterator != NULL; iterator = iterator->next) {
    UserSchema user = (UserSchema)iterator->data;

    output_key_value output_array[] = {{"id", user->id}, {"name", user->name}};

    write_output(output_file, format_flag, ++results_acc, output_array, 2);
  }

  g_list_free(usersWithPrefix);
  close_output_file(output_file);

  return 0;
}
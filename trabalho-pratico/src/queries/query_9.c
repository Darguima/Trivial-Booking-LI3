#include <catalogs_creator/catalogs_creator.h>
#include <glib.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes/datatypes.h"
#include "utils/calculate_stats.h"
#include "write_output/write_output.h"

int query_9(Catalogs catalogs, int command_number, bool format_flag, const char* prefix) {
  FILE* output_file = create_output_file(command_number);
  GList* user_results = get_users_by_prefix(catalogs->users, prefix);
  int results_acc = 1;
  for (GList* iterator = user_results; iterator != NULL;) {
    User user = (User)iterator->data;
    char* user_name = user_get_name(user);
    char* user_id = user_get_id(user);
    output_key_value output_array[] = {{"id", user_id}, {"name", user_name}};
    results_acc++;
    write_output(output_file, format_flag, results_acc, output_array, 2);

    free(user_id);
    free(user_name);
    GList* next_iterator = iterator->next;

    user_results = g_list_remove_link(user_results, iterator);
    g_list_free_1(iterator);

    iterator = next_iterator;
  }
  g_list_free(user_results);
  close_output_file(output_file);
  return 0;
}

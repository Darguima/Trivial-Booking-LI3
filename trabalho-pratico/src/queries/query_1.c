#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <utils/number_to_string.h>
#include "catalogs_setup/catalogs_setup.h"
#include "catalogs_setup/users_catalog.h"
#include "ctype.h"
#include "entities/user_entity.h"
#include "utils/calculate_stats.h"
#include "write_output/write_output.h"

int query_1(Catalogs catalogs, int command_number, bool format_flag, char* id) {
  printf("I'm in query_1\n");
  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(id);

  printf("Example ==============\n");

  // from catalogs_setup/users_catalog.h
  User user_test = get_user_by_id(catalogs->users, "TomNunes92");

  // from entities/user_entity.h
  char* user_id = user_get_id(user_test);
  char* user_name = user_get_name(user_test);
  printf("user_id: %s\n", user_id);
  printf("user_name: %s\n", user_name);
  free(user_id);
  free(user_name);

  printf("======================\n");

  return 0;
}
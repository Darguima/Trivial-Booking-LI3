#include <stdio.h>
#include <stdlib.h>
#include "catalogs_setup/users_catalog.h"
#include "utils/calculate_stats.h"
#include "utils/is_active.h"

void create_new_user(UsersCatalog users_catalog, char** user_values) {
  User new_user = malloc(sizeof(struct user));

  new_user->id = strdup(user_values[0]);
  new_user->name = strdup(user_values[1]);
  new_user->email = strdup(user_values[2]);
  new_user->phone_number = strdup(user_values[3]);
  new_user->birth_date = strdup(user_values[4]);
  new_user->sex = strdup(user_values[5]);
  new_user->passport = strdup(user_values[6]);
  new_user->country_code = strdup(user_values[7]);
  new_user->address = strdup(user_values[8]);
  new_user->account_creation = strdup(user_values[9]);
  new_user->pay_method = strdup(user_values[10]);
  new_user->account_status = is_active(user_values[11]);
  new_user->age = calculate_user_age(user_values[4]);
  new_user->total_spent = 0;
  new_user->number_of_flights = 0;
  new_user->number_of_reservations = 0;

  insert_user(users_catalog, new_user);
}
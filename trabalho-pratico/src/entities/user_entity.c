#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "catalogs_setup/users_catalog.h"
#include "utils/calculate_stats.h"
#include "utils/is_active.h"

struct user {
  char* id;
  char* name;
  char* email;
  char* phone_number;
  char* birth_date;
  char* sex;
  char* passport;
  char* country_code;
  char* address;
  char* account_creation;
  char* pay_method;
  bool account_status;
  double total_spent;
  int age;
  int number_of_flights;
  int number_of_reservations;
};

void create_new_user(UsersCatalog users_catalog, char** user_values) {
  User new_user = malloc(sizeof(struct user));

  new_user->id = g_strdup(user_values[0]);
  new_user->name = g_strdup(user_values[1]);
  new_user->email = g_strdup(user_values[2]);
  new_user->phone_number = g_strdup(user_values[3]);
  new_user->birth_date = g_strdup(user_values[4]);
  new_user->sex = g_strdup(user_values[5]);
  new_user->passport = g_strdup(user_values[6]);
  new_user->country_code = g_strdup(user_values[7]);
  new_user->address = g_strdup(user_values[8]);
  new_user->account_creation = g_strdup(user_values[9]);
  new_user->pay_method = g_strdup(user_values[10]);
  new_user->account_status = is_active(user_values[11]);
  new_user->age = calculate_user_age(user_values[4]);
  new_user->total_spent = 0;
  new_user->number_of_flights = 0;
  new_user->number_of_reservations = 0;

  insert_user(users_catalog, new_user);
}

void free_user(gpointer value) {
  User user = (User)value;

  g_free(user->id);
  g_free(user->name);
  g_free(user->email);
  g_free(user->phone_number);
  g_free(user->birth_date);
  g_free(user->sex);
  g_free(user->passport);
  g_free(user->country_code);
  g_free(user->address);
  g_free(user->account_creation);
  g_free(user->pay_method);

  free(user);
}

char* user_get_id(User user) {
  return g_strdup(user->id);
}

char* user_get_name(User user) {
  return g_strdup(user->name);
}

void user_increment_reservations(User user, int number_of_reservations) {
  user->number_of_reservations += number_of_reservations;
}

void user_increment_flights(User user, int number_of_flights) {
  user->number_of_flights += number_of_flights;
}

void user_increment_total_spent(User user, double total_reservation_price) {
  user->total_spent += (double)total_reservation_price;
}
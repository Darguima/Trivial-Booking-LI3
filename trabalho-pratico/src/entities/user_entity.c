#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "catalogs_creator/flights_catalog.h"
#include "catalogs_creator/reservations_catalog.h"
#include "catalogs_creator/users_catalog.h"
#include "utils/calculate_stats.h"
#include "utils/compare_datatypes.h"
#include "utils/is_active.h"

struct user {
  char* id;
  char* name;
  // char* email;
  // char* phone_number;
  // char* birth_date;
  char* sex;
  char* passport;
  char* country_code;
  // char* address;
  char* account_creation;
  // char* pay_method;
  bool account_status;
  double total_spent;
  int age;
  RelationArray flights;
  RelationArray reservations;
};

User create_new_user(UsersCatalog users_catalog, char** user_values) {
  User new_user = malloc(sizeof(struct user));
  RelationArray flights = malloc(sizeof(struct relationArray));
  flights->values = g_array_new(FALSE, FALSE, sizeof(Flight));
  flights->is_sorted = false;
  RelationArray reservations = malloc(sizeof(struct relationArray));
  reservations->values = g_array_new(FALSE, FALSE, sizeof(Reservation));
  reservations->is_sorted = false;

  new_user->id = g_strdup(user_values[0]);
  new_user->name = g_strdup(user_values[1]);
  // new_user->birth_date = g_strdup(user_values[4]);
  new_user->sex = g_strdup(user_values[5]);
  new_user->passport = g_strdup(user_values[6]);
  new_user->country_code = g_strdup(user_values[7]);
  new_user->account_creation = g_strdup(user_values[9]);
  new_user->account_status = is_active(user_values[11]);
  new_user->age = calculate_user_age(user_values[4]);
  new_user->total_spent = 0;
  new_user->flights = flights;
  new_user->reservations = reservations;

  insert_user(users_catalog, new_user);

  return new_user;
}

void free_user(gpointer value) {
  User user = (User)value;

  g_free(user->id);
  g_free(user->name);
  g_free(user->sex);
  g_free(user->passport);
  g_free(user->country_code);
  g_free(user->account_creation);
  g_array_free(user->flights->values, TRUE);
  g_array_free(user->reservations->values, TRUE);
  g_free(user->flights);
  g_free(user->reservations);

  free(user);
}

char* user_get_id(User user) {
  return g_strdup(user->id);
}

char* user_get_name(User user) {
  return g_strdup(user->name);
}

int user_get_number_of_flights(User user) {
  return (int)user->flights->values->len;
}

int user_get_number_of_reservations(User user) {
  return (int)user->reservations->values->len;
}

double user_get_total_spent(User user) {
  return user->total_spent;
}

int user_get_age(User user) {
  return user->age;
}

char* user_get_sex(User user) {
  return g_strdup(user->sex);
}

char* user_get_country_code(User user) {
  return g_strdup(user->country_code);
}

char* user_get_passport(User user) {
  return g_strdup(user->passport);
}

char* user_get_account_creation(User user) {
  return g_strdup(user->account_creation);
}

void user_add_flight(User user, Flight flight) {
  g_array_append_val(user->flights->values, flight);
  user->flights->is_sorted = false;
}

bool user_get_is_active(User user) {
  return user->account_status;
}

void user_add_reservation(User user, Reservation reservation) {
  g_array_append_val(user->reservations->values, reservation);
  user->reservations->is_sorted = false;
}

GArray* user_get_reservations(User user) {
  if (!user->reservations->is_sorted) {
    g_array_sort(user->reservations->values, compare_reservations_by_begin_date);
    user->reservations->is_sorted = true;
  }
  return g_array_copy(user->reservations->values);
}

GArray* user_get_flights(User user) {
  if (!user->flights->is_sorted) {
    g_array_sort(user->flights->values, compare_flights_by_sched_dep_date);
    user->flights->is_sorted = true;
  }
  return g_array_copy(user->flights->values);
}

void user_increment_total_spent(User user, double total_reservation_price) {
  user->total_spent += (double)total_reservation_price;
}
#include <glib.h>
#include <stdio.h>
#include "catalogs_creator/free_structs.h"
#include "datatypes/datatypes.h"

Catalogs catalogs_creator() {
  GHashTable* hash_table_users = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, free_user_struct);
  GHashTable* hash_table_flights = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, free_flight_struct);
  GHashTable* hash_table_passengers = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_passengers_struct);
  GHashTable* hash_table_reservations = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, free_reservation_struct);

  Catalogs catalogs = (Catalogs)malloc(sizeof(struct catalogs));
  catalogs->users = hash_table_users;
  catalogs->flights = hash_table_flights;
  catalogs->passengers = hash_table_passengers;
  catalogs->reservations = hash_table_reservations;

  printf("[STATUS] - Catalogs created\n");

  return catalogs;
}

int free_catalogs(Catalogs catalogs) {
  g_hash_table_destroy(catalogs->users);
  g_hash_table_destroy(catalogs->flights);
  g_hash_table_destroy(catalogs->passengers);
  g_hash_table_destroy(catalogs->reservations);

  free(catalogs);

  printf("[STATUS] - Catalogs freed\n");

  return 0;
}
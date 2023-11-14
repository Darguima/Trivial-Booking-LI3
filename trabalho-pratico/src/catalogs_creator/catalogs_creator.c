#include <glib.h>
#include <stdio.h>
#include "datatypes/datatypes.h"

// To free the hash table:
// g_hash_table_destroy(hash_table);

Catalogs catalogs_creator() {
  GHashTable* hash_table_users = g_hash_table_new(g_str_hash, g_str_equal);
  GHashTable* hash_table_flights = g_hash_table_new(g_str_hash, g_str_equal);
  GHashTable* hash_table_passengers = g_hash_table_new(g_str_hash, g_str_equal);
  GHashTable* hash_table_reservations =
      g_hash_table_new(g_str_hash, g_str_equal);

  Catalogs CATALOGS = (Catalogs)malloc(sizeof(struct catalogs));
  CATALOGS->users = hash_table_users;
  CATALOGS->flights = hash_table_flights;
  CATALOGS->passengers = hash_table_passengers;
  CATALOGS->reservations = hash_table_reservations;

  return CATALOGS;
}
#include "catalogs_setup/catalogs_setup.h"
#include <stdio.h>
#include <stdlib.h>
#include "catalogs_creator/catalogs_creator.h"
#include "catalogs_setup/reservations_catalog.h"
#include "catalogs_setup/users_catalog.h"

Catalogs catalogs_setup() {
  Catalogs catalogs = malloc(sizeof(struct catalogs));

  catalogs->users = users_catalog_create();
  catalogs->flights = flights_catalog_create();
  catalogs->reservations = reservations_catalog_create();

  // Using the deprecated way to create catalogs
  // Because the new way was not implemented yet for this entities
  Catalogs deprecated_catalog = catalogs_creator();
  catalogs->passengers = deprecated_catalog->passengers;
  free(deprecated_catalog);

  printf("[STATUS] - Catalogs created\n");

  return catalogs;
}

void free_catalogs(Catalogs catalogs) {
  users_catalog_free(catalogs->users);
  flights_catalog_free(catalogs->flights);
  reservations_catalog_free(catalogs->reservations);

  // Using the deprecated way to free catalogs
  g_hash_table_destroy(catalogs->passengers);

  free(catalogs);

  printf("[STATUS] - Catalogs freed\n");
}
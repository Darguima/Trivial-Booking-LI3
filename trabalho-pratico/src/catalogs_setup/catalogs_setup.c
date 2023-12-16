#include "catalogs_setup/catalogs_setup.h"
#include <stdio.h>
#include <stdlib.h>
#include "catalogs_creator/catalogs_creator.h"

Catalogs catalogs_setup() {
  Catalogs catalogs = malloc(sizeof(struct catalogs));

  catalogs->users = users_catalog_create();

  // Using the deprecated way to create catalogs
  // Because the new way was not implemented yet for this entities
  Catalogs deprecated_catalog = catalogs_creator();
  catalogs->flights = deprecated_catalog->flights;
  catalogs->passengers = deprecated_catalog->passengers;
  catalogs->reservations = deprecated_catalog->reservations;

  printf("[STATUS] - Catalogs created\n");

  return catalogs;
}

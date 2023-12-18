#include "catalogs_creator/catalogs_creator.h"
#include <stdio.h>
#include <stdlib.h>
#include "catalogs_creator/flights_catalog.h"
#include "catalogs_creator/passengers_catalog.h"
#include "catalogs_creator/reservations_catalog.h"
#include "catalogs_creator/users_catalog.h"

Catalogs catalogs_creator() {
  Catalogs catalogs = malloc(sizeof(struct catalogs));

  catalogs->users = users_catalog_create();
  catalogs->flights = flights_catalog_create();
  catalogs->passengers = passengers_catalog_create();
  catalogs->reservations = reservations_catalog_create();

  printf("[STATUS] - Catalogs created\n");

  return catalogs;
}

void free_catalogs(Catalogs catalogs) {
  users_catalog_free(catalogs->users);
  flights_catalog_free(catalogs->flights);
  passengers_catalog_free(catalogs->passengers);
  reservations_catalog_free(catalogs->reservations);

  free(catalogs);

  printf("[STATUS] - Catalogs freed\n");
}
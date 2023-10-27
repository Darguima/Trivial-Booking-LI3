#include "catalog/catalog.h"
#include <stdio.h>

int parser() {
  printf("I'm in parser\n");
  catalogFlights();
  catalogPassengers();
  catalogReservations();
  catalogUsers();
  return 0;
}
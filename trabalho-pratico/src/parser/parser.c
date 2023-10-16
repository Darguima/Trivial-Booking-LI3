#include <stdio.h>
#include "catalog/catalog.h"

int parser () {
  printf("I'm in parser\n");
  catalogFlights();
  catalogPassengers();
  catalogReservations();
  catalogUsers();
  return 0;
}
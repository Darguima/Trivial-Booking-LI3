#ifndef CATALOG_FILLER_H
#define CATALOG_FILLER_H

#include <stdio.h>

#define USER_MAXSIZE 12
#define FLIGHT_MAXSIZE 13
#define RESERVATIONS_MAXSIZE 14
#define PASSENGERS_MAXSIZE 2

int catalog_filler ( char *folder_destination ) ;

char *get_full_destination (char *destination , const char *filename)

#endif
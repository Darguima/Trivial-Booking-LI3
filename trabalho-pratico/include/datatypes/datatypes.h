//! @file
#ifndef DATATYPES_H
#define DATATYPES_H

#include <glib.h>
#include <stdbool.h>
#include <time.h>
// TODO: Remove me after the Refactor for encapsulation
#include "catalogs_setup/catalogs_setup.h"

#define UNUSED(x) (void)(x)

// Catalogs management

#define USERS_DATASET_COLUMNS 12
#define FLIGHTS_DATASET_COLUMNS 13
#define RESERVATIONS_DATASET_COLUMNS 14
#define PASSENGERS_DATASET_COLUMNS 2

typedef enum { USERS, FLIGHTS, PASSENGERS, RESERVATIONS } schema_name;

#endif
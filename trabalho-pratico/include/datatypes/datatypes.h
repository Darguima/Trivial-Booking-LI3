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

// TODO: Remove me after the Refactor for encapsulation
typedef struct user UserSchema;
typedef struct flight FlightSchema;

//! Passengers - relations between flights and users
typedef struct passengerSchema {
  //! Flight id, from the flightSchema
  char* flight_id;
  //! User id, from the userSchema
  char* user_id;
}* PassengerSchema;

//! Reservations and hotel info
typedef struct reservationSchema {
  //! ID for the reservation, unique
  char* id;
  char* user_id;
  char* hotel_id;
  char* hotel_name;
  //! Hotels starts 1-5
  int hotel_stars;
  int city_tax;
  char* address;
  char* begin_date;
  char* end_date;
  int price_per_night;
  bool includes_breakfast;
  char* room_details;
  //! the rating given by the user 1-5 or an empty string
  char* rating;
  char* comment;
  double total_price;
}* ReservationSchema;

#endif
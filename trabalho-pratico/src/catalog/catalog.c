#include <datatypes/datatypes.h>
#include <stdio.h>
#include <stdlib.h>

int catalog_users(UserSchema user) {
  printf("\n\n\n");

  printf("I'm in catalogUsers.\nThis is some of my data:\n");

  printf("\nName - %s", user.name);
  printf("\nID - %s", user.id);
  printf("\nPassport - %s", user.passport);
  printf("\nPhone Number - %s", user.phone_number);

  printf("\n\n\n");

  return 0;
}

int catalog_flights(FlightSchema flight) {
  printf("\n\n\n");

  printf("I'm in catalogflights.\nThis is some of my data:\n");

  printf("\nPilot Name - %s", flight.pilot);
  printf("\nID - %i", flight.id);

  printf("\n\n\n");

  return 0;
}

int catalog_passengers(PassengerSchema passenger) {
  printf("\n\n\n");

  printf("I'm in catalogpassengers.\nThis is some of my data:\n");

  printf("\nFlightID - %d", passenger.flight_id);
  printf("\nUser ID - %s", passenger.user_id);

  printf("\n\n\n");

  return 0;
}

int catalog_reservations(ReservationSchema reservation) {
  printf("\n\n\n");

  printf("I'm in catalogreservations.\nThis is some of my data:\n");

  printf("\nName - %s", reservation.hotel_name);
  printf("\nID - %s", reservation.id);
  printf("\nAddress - %s", reservation.address);

  printf("\n\n\n");

  return 0;
}

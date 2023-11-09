#include <datatypes/datatypes.h>
#include <stdio.h>
#include <stdlib.h>

int store_catalog_user(UserSchema user) {
  printf("\n\n\n");

  printf("I'm in catalogUsers.\nThis is some of my data:\n");

  printf("\nName - %s", user.name);
  printf("\nID - %s", user.id);
  printf("\nPassport - %s", user.passport);
  printf("\nPhone Number - %s", user.phone_number);

  printf("Fake Stored\n\n\n");

  return 0;
}

int store_catalog_flight(FlightSchema flight) {
  printf("\n\n\n");

  printf("I'm in catalogFlights.\nThis is some of my data:\n");

  printf("\nPilot Name - %s", flight.pilot);
  printf("\nID - %i", flight.id);

  printf("Fake stored\n\n\n");

  return 0;
}

int store_catalog_passenger(PassengerSchema passenger) {
  printf("\n\n\n");

  printf("I'm in catalogPassengers.\nThis is some of my data:\n");

  printf("\nFlightID - %d", passenger.flight_id);
  printf("\nUser ID - %s", passenger.user_id);

  printf("Fake stored\n\n\n");

  return 0;
}

int store_catalog_reservation(ReservationSchema reservation) {
  printf("\n\n\n");

  printf("I'm in catalogReservations.\nThis is some of my data:\n");

  printf("\nName - %s", reservation.hotel_name);
  printf("\nID - %s", reservation.id);
  printf("\nAddress - %s", reservation.address);

  printf("Fake stored\n\n\n");

  return 0;
}

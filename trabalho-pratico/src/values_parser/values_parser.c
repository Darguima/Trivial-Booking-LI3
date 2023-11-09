#include <stdio.h>
#include <store_catalog/store_catalog.h>

int values_parser_users(char **values) {
  printf("I'm in values_parser_users\n");
  printf("First String received: %s\n", values[0]);

  // Create a fake user and pass it to the catalog function
  UserSchema fake_user;
  fake_user.id = "1";
  fake_user.name = "John Doe";
  fake_user.email = "john.doe@example.com";
  fake_user.phone_number = "123456789";
  fake_user.birth_date = time(NULL); // Set to current time
  fake_user.sex = MALE;
  fake_user.passport = "AB123456";
  fake_user.country_code = "US";
  fake_user.address = "123 Main St, City";
  fake_user.account_creation = time(NULL); // Set to current time
  fake_user.pay_method = CASH;
  fake_user.account_status = ACTIVE;

  store_catalog_user(fake_user);

  return 0;
}

int values_parser_flights(char **values) {
  printf("I'm in values_parser_flights\n");
  printf("First String received: %s\n", values[0]);

  // Create a fake flight and pass it to the catalog function
  FlightSchema fake_flight;
  fake_flight.id = 1;
  fake_flight.airline = "Fake Airlines";
  fake_flight.plane_model = "F123";
  fake_flight.total_seats = 200;
  fake_flight.origin = "Airport A";
  fake_flight.destination = "Airport B";
  fake_flight.schedule_departure_date = time(NULL); // Set to current time
  fake_flight.schedule_arrival_date = time(NULL);   // Set to current time
  fake_flight.real_departure_date = time(NULL);     // Set to current time
  fake_flight.real_arrival_date = time(NULL);       // Set to current time
  fake_flight.pilot = "Captain Fake";
  fake_flight.copilot = "First Officer Fake";
  fake_flight.notes = "This is a fake flight.";

  store_catalog_flight(fake_flight);

  return 0;
}

int values_parser_passengers(char **values) {
  printf("I'm in values_parser_passengers\n");
  printf("First String received: %s\n", values[0]);

  // Create a fake passenger and pass it to the catalog function
  PassengerSchema fake_passenger;
  fake_passenger.flight_id = 1;
  fake_passenger.user_id = "1";

  store_catalog_passenger(fake_passenger);

  return 0;
}

int values_parser_reservations(char **values) {
  printf("I'm in values_parser_reservations\n");
  printf("First String received: %s\n", values[0]);

  // Create a fake reservation and pass it to the catalog function
  ReservationSchema fake_reservation;
  fake_reservation.id = "123";
  fake_reservation.user_id = "1";
  fake_reservation.hotel_id = "456";
  fake_reservation.hotel_name = "Fake Hotel";
  fake_reservation.hotel_stars = 5;
  fake_reservation.city_tax = 10;
  fake_reservation.address = "456 Hotel St, City";
  fake_reservation.begin_date = time(NULL); // Set to current time
  fake_reservation.end_date = time(NULL);   // Set to current time
  fake_reservation.price_per_night = 100;
  fake_reservation.includes_breakfast = true;
  fake_reservation.room_details = "Fake Room";
  fake_reservation.rating = 4;
  fake_reservation.comment = "This is a fake reservation.";

  store_catalog_reservation(fake_reservation);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <store_catalog/store_catalog.h>

int values_parser_users(char** values, GHashTable* users_catalog) {
  printf("[values_parser_users] String Test: %s\n", values[0]);

  // Create a fake user and pass it to the catalog function
  UserSchema fake_user = (UserSchema)malloc(sizeof(struct userSchema));
  fake_user->id = "AlícSá-Mendes";
  fake_user->name = "Alícia Sá-Mendes";
  fake_user->email = "alícsá-mendes@li3.pt";
  fake_user->phone_number = "(351) 259 545 254";
  fake_user->birth_date = time(NULL);  // Set to current time
  fake_user->sex = FEMALE;
  fake_user->passport = "CA279133";
  fake_user->country_code = "PT";
  fake_user->address = "Avenida Gabriela Guerreiro, 42518-827 Rio Maior";
  fake_user->account_creation = time(NULL);  // Set to current time
  fake_user->pay_method = DEBIT_CARD;
  fake_user->account_status = ACTIVE;

  store_catalog_user(fake_user, users_catalog);

  return 0;
}

int values_parser_flights(char** values, GHashTable* flights_catalog) {
  printf("[values_parser_flights] String Test: %s\n", values[0]);

  // Create a fake flight and pass it to the catalog function
  FlightSchema fake_flight = (FlightSchema)malloc(sizeof(struct flightSchema));
  fake_flight->id = 1;
  fake_flight->airline = "Fake Airlines";
  fake_flight->plane_model = "F123";
  fake_flight->total_seats = 200;
  fake_flight->origin = "Airport A";
  fake_flight->destination = "Airport B";
  fake_flight->schedule_departure_date = time(NULL);  // Set to current time
  fake_flight->schedule_arrival_date = time(NULL);    // Set to current time
  fake_flight->real_departure_date = time(NULL);      // Set to current time
  fake_flight->real_arrival_date = time(NULL);        // Set to current time
  fake_flight->pilot = "Captain Fake";
  fake_flight->copilot = "First Officer Fake";
  fake_flight->notes = "This is a fake flight.";

  store_catalog_flight(fake_flight, flights_catalog);

  return 0;
}

int values_parser_passengers(char** values, GHashTable* passengers_catalog) {
  printf("[values_parser_passengers] String Test: %s\n", values[0]);

  // Create a fake passenger and pass it to the catalog function
  PassengerSchema fake_passenger =
      (PassengerSchema)malloc(sizeof(struct passengerSchema));
  fake_passenger->flight_id = 1;
  fake_passenger->user_id = "1";

  store_catalog_passenger(fake_passenger, passengers_catalog);

  return 0;
}

int values_parser_reservations(char** values,
                               GHashTable* reservations_catalog) {
  printf("[values_parser_reservations] String Test: %s\n", values[0]);

  // Create a fake reservation and pass it to the catalog function
  ReservationSchema fake_reservation =
      (ReservationSchema)malloc(sizeof(struct reservationSchema));
  fake_reservation->id = "123";
  fake_reservation->user_id = "1";
  fake_reservation->hotel_id = "456";
  fake_reservation->hotel_name = "Fake Hotel";
  fake_reservation->hotel_stars = 5;
  fake_reservation->city_tax = 10;
  fake_reservation->address = "456 Hotel St, City";
  fake_reservation->begin_date = time(NULL);  // Set to current time
  fake_reservation->end_date = time(NULL);    // Set to current time
  fake_reservation->price_per_night = 100;
  fake_reservation->includes_breakfast = true;
  fake_reservation->room_details = "Fake Room";
  fake_reservation->rating = 4;
  fake_reservation->comment = "This is a fake reservation.";

  store_catalog_reservation(fake_reservation, reservations_catalog);

  return 0;
}

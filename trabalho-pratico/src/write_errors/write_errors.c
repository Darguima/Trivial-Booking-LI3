#include <ctype.h>
#include <datatypes/datatypes.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

void init_errors_files() {
  FILE* users_errors = fopen("Resultados/users_errors.csv", "w");
  fprintf(users_errors,
          "id;name;email;phone_number;birth_date;sex;passport;country_code;"
          "address;account_creation;pay_method;account_status\n");
  fclose(users_errors);

  FILE* flights_errors = fopen("Resultados/flights_errors.csv", "w");
  fprintf(flights_errors,
          "id;airline;plane_model;total_seats;origin;destination;schedule_"
          "departure_date;schedule_arrival_date;real_departure_date;real_"
          "arrival_date;pilot;copilot;notes\n");
  fclose(flights_errors);

  FILE* reservations_errors = fopen("Resultados/reservations_errors.csv", "w");
  fprintf(reservations_errors,
          "id;user_id;hotel_id;hotel_name;hotel_stars;city_tax;address;begin_"
          "date;end_date;price_per_night;includes_breakfast;room_details;"
          "rating;comment\n");
  fclose(reservations_errors);

  FILE* passengers_errors = fopen("Resultados/passengers_errors.csv", "w");
  fprintf(passengers_errors, "flight_id;user_id\n");
  fclose(passengers_errors);
}

void write_reservations_errors(char** line_elements) {
  FILE* reservations_errors = fopen("Resultados/reservations_errors.csv", "a+");
  fprintf(reservations_errors, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
          line_elements[0], line_elements[1], line_elements[2],
          line_elements[3], line_elements[4], line_elements[5],
          line_elements[6], line_elements[7], line_elements[8],
          line_elements[9], line_elements[10], line_elements[11],
          line_elements[12], line_elements[13]);
  fclose(reservations_errors);
  return;
}

void write_passengers_errors(char** line_elements) {
  FILE* passengers_errors = fopen("Resultados/passengers_errors.csv", "a+");
  fprintf(passengers_errors, "%s;%s\n", line_elements[0], line_elements[1]);
  fclose(passengers_errors);
  return;
}

void write_flights_errors(char** line_elements) {
  FILE* flights_errors = fopen("Resultados/flights_errors.csv", "a+");
  fprintf(flights_errors, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
          line_elements[0], line_elements[1], line_elements[2],
          line_elements[3], line_elements[4], line_elements[5],
          line_elements[6], line_elements[7], line_elements[8],
          line_elements[9], line_elements[10], line_elements[11],
          line_elements[12]);
  fclose(flights_errors);
  return;
}

void write_users_errors(char** line_elements) {
  FILE* users_error = fopen("Resultados/users_errors.csv", "a++");
  fprintf(users_error, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
          line_elements[0], line_elements[1], line_elements[2],
          line_elements[3], line_elements[4], line_elements[5],
          line_elements[6], line_elements[7], line_elements[8],
          line_elements[9], line_elements[10], line_elements[11]);
  fclose(users_error);
  return;
}
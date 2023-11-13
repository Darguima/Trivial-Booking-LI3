#include <ctype.h>
#include <datatypes/datatypes.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <store_catalog/store_catalog.h>
#include <string.h>
#include <time.h>

long convertStringToSeconds(char* dateString) {
  struct tm timeStruct = {0};

  if (sscanf(dateString, "%d/%d/%d %d:%d:%d", &timeStruct.tm_year,
             &timeStruct.tm_mon, &timeStruct.tm_mday, &timeStruct.tm_hour,
             &timeStruct.tm_min, &timeStruct.tm_sec) == 6) {
    timeStruct.tm_year -= 1900;
    timeStruct.tm_mon -= 1;

    return mktime(&timeStruct);
  } else if (sscanf(dateString, "%d/%d/%d", &timeStruct.tm_year,
                    &timeStruct.tm_mon, &timeStruct.tm_mday) == 3) {
    timeStruct.tm_year -= 1900;
    timeStruct.tm_mon -= 1;

    timeStruct.tm_hour = 0;
    timeStruct.tm_min = 0;
    timeStruct.tm_sec = 0;

    return mktime(&timeStruct);
  }

  return -1;
}

long verify_dates_difference(char* date1, char* date2) {
  if (date1 != NULL && date2 != NULL) {
    // Converter strings de data para struct tm
    long timestamp1 = convertStringToSeconds(date1);
    long timestamp2 = convertStringToSeconds(date2);

    return (timestamp2 > timestamp1);
  }

  return 0;
}

int verify_account_email(char* email) {
  if (email != NULL) {
    size_t at_positon = 0;
    size_t dot_positon = 0;
    for (size_t i = 0; i < strlen(email); i++) {
      if (email[i] == '@') {
        at_positon = i;
        break;
      }
    }
    if (at_positon <= 0) {
      return 0;
    }
    for (size_t j = at_positon; j < strlen(email); j++) {
      if (email[j] == '.') {
        dot_positon = j;
        break;
      }
    }
    if (dot_positon <= at_positon + 2 || strlen(email) - dot_positon < 3) {
      return 0;
    }

    if (dot_positon <= at_positon) {
      return 0;
    }
    return 1;
  }
  return 0;
}

int verify_account_status(char* status) {
  if (status != NULL) {
    size_t len = strlen(status);
    char* lowercase_status = malloc(len + 1);
    if (lowercase_status == NULL) {
      return 0;
    }

    for (size_t i = 0; i < len; i++) {
      lowercase_status[i] = (char)tolower(status[i]);
    }
    lowercase_status[len] = '\0';

    int result = (strcmp(lowercase_status, "active") == 0 ||
                  strcmp(lowercase_status, "inactive") == 0);

    free(lowercase_status);

    return result;
  }
  return 0;
}

int verify_user_country_code(char* country_code) {
  if (country_code != NULL && strlen(country_code) == 2 &&
      isalpha(country_code[0]) && isalpha(country_code[1])) {
    return 1;
  }

  return 0;
}

int verify_date(char* date) {
  int year, month, day, hour, minute, second;
  int result = sscanf(date, "%4d/%2d/%2d %2d:%2d:%2d", &year, &month, &day,
                      &hour, &minute, &second);

  if (result == 3 && strlen(date) == 10) {  // Formato mais básico
    if (year >= 1000 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 &&
        day <= 31) {
      return 1;
    }
  } else if (result == 6) {  // Formato com horas
    if (year >= 1000 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 &&
        day <= 31 && hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 &&
        second >= 0 && second <= 59 && date[10] != '~') {
      return 1;
    }
  }

  return 0;
}

UserSchema create_new_user(char** user_values) {
  UserSchema new_user = malloc(sizeof(struct userSchema));
  new_user->id = g_strdup(user_values[0]);
  new_user->name = g_strdup(user_values[1]);
  new_user->email = g_strdup(user_values[2]);
  new_user->phone_number = g_strdup(user_values[3]);
  new_user->birth_date = g_strdup(user_values[4]);
  new_user->sex = g_strdup(user_values[5]);
  new_user->passport = g_strdup(user_values[6]);
  new_user->country_code = g_strdup(user_values[7]);
  new_user->address = g_strdup(user_values[8]);
  new_user->account_creation = g_strdup(user_values[9]);
  new_user->pay_method = g_strdup(user_values[10]);
  new_user->account_status = g_strdup(user_values[11]);

  return new_user;
}

int values_parser_users(char** user_values, Catalogs catalog) {
  if (strcmp(user_values[0], "") == 0) {
    return 1;
  }

  if (strcmp(user_values[1], "") == 0) {
    return 1;
  }

  if (strcmp(user_values[3], "") == 0) {
    return 1;
  }

  if (strcmp(user_values[5], "") == 0) {
    return 1;
  }

  if (strcmp(user_values[6], "") == 0) {
    return 1;
  }

  if (strcmp(user_values[8], "") == 0) {
    return 1;
  }

  if (strcmp(user_values[10], "") == 0) {
    return 1;
  }

  if (!verify_user_country_code(user_values[7])) {
    return 1;
  }

  if (!verify_date(user_values[4]) || !verify_date(user_values[9])) {
    return 1;
  }

  if (!verify_account_status(user_values[11])) {
    return 1;
  }

  if (!verify_account_email(user_values[2])) {
    return 1;
  }

  if (!verify_dates_difference(user_values[4], user_values[9])) {
    return 1;
  }
  UserSchema new_user = create_new_user(user_values);
  store_catalog_user(new_user, catalog->users);

  return 0;
}

int verify_airport_name(char* airport_name) {
  if (airport_name != NULL) {
    if (strlen(airport_name) == 3) {
      if (isalpha(airport_name[0]) && isalpha(airport_name[1]) &&
          isalpha(airport_name[2])) {
        return 1;
      }
    } else {
      return 0;
    }
  }

  return 0;
}

int is_digit(char new_char) {
  return (new_char >= '0' && new_char <= '9');
}

int verify_if_is_digit(char* digit) {
  if (digit != NULL) {
    for (size_t i = 0; i < strlen(digit); i++) {
      if (!isdigit(digit[i])) {
        return 0;
      }
    }
    return 1;
  }

  return 0;
}

int string_to_int(char* total) {
  int value = 0;
  for (int i = 0; total[i] != '\0'; i++) {
    value *= 10;
    value += total[i] - '0';
  }
  return value;
}

FlightSchema create_new_flight(char** flight_values) {
  FlightSchema new_flight = malloc(sizeof(struct flightSchema));
  new_flight->id = g_strdup(flight_values[0]);
  new_flight->airline = g_strdup(flight_values[1]);
  new_flight->plane_model = g_strdup(flight_values[2]);
  new_flight->total_seats = string_to_int(flight_values[3]);
  new_flight->origin = g_strdup(flight_values[4]);
  new_flight->destination = g_strdup(flight_values[5]);
  new_flight->schedule_departure_date = g_strdup(flight_values[6]);
  new_flight->real_departure_date = g_strdup(flight_values[7]);
  new_flight->schedule_arrival_date = g_strdup(flight_values[8]);
  new_flight->real_arrival_date = g_strdup(flight_values[9]);
  new_flight->pilot = g_strdup(flight_values[10]);
  new_flight->copilot = g_strdup(flight_values[11]);
  new_flight->notes = g_strdup(flight_values[12]);

  return new_flight;
}

int values_parser_flights(char** flight_values, Catalogs catalog) {
  if (strcmp(flight_values[0], "") == 0) {
    return 1;
  }

  if (strcmp(flight_values[1], "") == 0) {
    return 1;
  }

  if (strcmp(flight_values[2], "") == 0) {
    return 1;
  }

  if (strcmp(flight_values[10], "") == 0) {
    return 1;
  }

  if (strcmp(flight_values[11], "") == 0) {
    return 1;
  }

  if (!verify_if_is_digit(flight_values[3])) {
    return 1;
  }
  if (!verify_airport_name(flight_values[4]) ||
      !verify_airport_name(flight_values[5])) {
    return 1;
  }

  if (!verify_date(flight_values[6]) || !verify_date(flight_values[7]) ||
      !verify_date(flight_values[8]) || !verify_date(flight_values[9])) {
    return 1;
  }

  if (!verify_dates_difference(flight_values[6], flight_values[7])) {
    return 1;
  }

  if (!verify_dates_difference(flight_values[8], flight_values[9])) {
    return 1;
  }
  FlightSchema new_flight = create_new_flight(flight_values);
  store_catalog_flight(new_flight, catalog->flights);

  return 0;
}

int values_parser_passengers(char** passengers_values, Catalogs catalog) {
  if (strcmp(passengers_values[0], "") == 0 ||
      strcmp(passengers_values[0], "") == 0) {
    return 1;
  }

  UserSchema user = g_hash_table_lookup(catalog->users, passengers_values[1]);
  ReservationSchema reservation =
      g_hash_table_lookup(catalog->reservations, passengers_values[0]);
  if (user == NULL || reservation == NULL) {
    return 1;
  }

  return 0;
}

int verify_breakfast(char* breakfast) {
  if (breakfast != NULL) {
    size_t len = strlen(breakfast);
    char* lowercase_status = malloc(len + 1);
    for (size_t i = 0; i < len; i++) {
      lowercase_status[i] = (char)tolower(breakfast[i]);
    }
    lowercase_status[len] = '\0';
    int result = (strcmp(lowercase_status, "t") == 0 ||
                  strcmp(lowercase_status, "f") == 0 ||
                  strcmp(lowercase_status, "") == 0 ||
                  strcmp(lowercase_status, "true") == 0 ||
                  strcmp(lowercase_status, "false") == 0 ||
                  strcmp(lowercase_status, "1") == 0 ||
                  strcmp(lowercase_status, "0") == 0);
    free(lowercase_status);
    return result;
  }
  return 0;
}

int verify_if_is_digit_non_zero(char* new_digit) {
  if (new_digit != NULL) {
    if (strlen(new_digit) == 1 && strcmp(new_digit, "0") == 0) {
      return 0;
    }
    if (strcmp(new_digit, "") == 0) {
      return 0;
    } else {
      return (verify_if_is_digit(new_digit));
    }
  }
  return 0;
}

int check_char(char value) {
  return (value >= '1' && value <= '5');
}

int check_hotel_rating_stars(char* word) {
  if (word != NULL) {
    if (strlen(word) == 1) {
      return (check_char(word[0]));
    }
    return 0;
  }
  return 0;
}

int check_hotel_rating(char* word) {
  if (word != NULL) {
    if (strcmp(word, "") == 0) {
      return 1;
    } else {
      return check_hotel_rating_stars(word);
    }
  }
  return 0;
}

/*
 char* id;          // identificador da reserva;
  char* user_id;     // identificador do utilizador;
  char* hotel_id;    // identificador do hotel;
  char* hotel_name;  // nome do hotel;
  int hotel_stars;   // número de estrelas do hotel;
  int city_tax;      // percentagem do imposto da cidade (sobre o valor total);
  char* address;     // morada do hotel;
  char* begin_date;  // data de início;
  char* end_date;    // data de fim;
  int price_per_night;      // preço por noite;
  bool includes_breakfast;  // se a reserva inclui pequeno-almoço;
  char* room_details;       // detalhes sobre o quarto;
  char* rating;             // classificação atribuída pelo utilizador;
  char* comment;




*/
ReservationSchema create_new_reservation(char** reservation_values) {
  ReservationSchema new_reservation = malloc(sizeof(struct reservationSchema));
  new_reservation->id = g_strdup(reservation_values[0]);
  new_reservation->user_id = g_strdup(reservation_values[1]);
  new_reservation->hotel_id = g_strdup(reservation_values[2]);
  new_reservation->hotel_name = g_strdup(reservation_values[3]);
  new_reservation->hotel_stars = string_to_int(reservation_values[4]);
  new_reservation->city_tax = string_to_int(reservation_values[5]);
  new_reservation->address = g_strdup(reservation_values[6]);
  new_reservation->begin_date = g_strdup(reservation_values[7]);
  new_reservation->end_date = g_strdup(reservation_values[8]);
  new_reservation->price_per_night = string_to_int(reservation_values[9]);
  new_reservation->includes_breakfast = g_strdup(reservation_values[10]);
  new_reservation->room_details = g_strdup(reservation_values[11]);
  new_reservation->rating = g_strdup(reservation_values[12]);
  new_reservation->comment = g_strdup(reservation_values[13]);
  return new_reservation;
}

int values_parser_reservations(char** reservations_values, Catalogs catalog) {
  if (strcmp(reservations_values[0], "") == 0) {
    return 1;
  }

  if (strcmp(reservations_values[1], "") == 0) {
    return 1;
  }

  if (strcmp(reservations_values[2], "") == 0) {
    return 1;
  }

  if (strcmp(reservations_values[3], "") == 0) {
    return 1;
  }

  if (strcmp(reservations_values[6], "") == 0) {
    return 1;
  }
  if (!check_hotel_rating(reservations_values[12]) ||
      !check_hotel_rating_stars(reservations_values[4])) {
    return 1;
  }

  if (!verify_if_is_digit(reservations_values[5])) {
    return 1;
  }

  if (!verify_if_is_digit_non_zero(reservations_values[9])) {
    return 1;
  }

  if (!verify_breakfast(reservations_values[10])) {
    return 1;
  }

  if (!verify_date(reservations_values[7]) ||
      !verify_date(reservations_values[8])) {
    return 1;
  }

  if (!verify_dates_difference(reservations_values[7],
                               reservations_values[8])) {
    return 1;
  }

  UserSchema user = g_hash_table_lookup(catalog->users, reservations_values[1]);
  if (user == NULL) {
    return 1;
  }

  ReservationSchema new_reservation =
      create_new_reservation(reservations_values);
  store_catalog_reservation(new_reservation, catalog->reservations);

  return 0;
}

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <store_catalog/store_catalog.h>
#include <string.h>
#include <time.h>
#include <glib.h>


/*
As datas devem seguir o formato aaaa/MM/dd;.
• As datas com tempo devem seguir o formato aaaa/MM/dd hh:mm:ss;
• Os resultados representados por números decimais deverão ser arredondados a três casas
na parte decimal;
Os seguintes restantes campos têm que ter tamanho superior a zero:
– Utilizador: id, name, phone_number, sex, passport, address, pay_method

As datas/datas com tempo de fim não poderão ser superiores às datas de início. Nos utilizado-
res, o birth_date tem que vir antes de account_creation;

• O email de um utilizador tem que ter o seguinte formato: “<username>@<domain>.<TLD>”.
O <username> e o <domain> têm que ter pelo menos tamanho 1; O <TLD> tem que ter pelo
menos tamanho 2. Exemplo de erros: @email.com, john@.pt, john@email.a, john@email,pt,
john.email.pt, . . . ;

• O country_code de um utilizador deverá ser formado por duas letras;
• O account_status de um utilizador deverá ter o valor “active” ou “inactive”, sendo que dife-
rentes combinações de maiúsculas e minúsculas também são válidas (e.g., “Active”, “aCtive”,
e “INACTIVE” também são válidos);

 char *id;                      // identificador do usuário; 0
  char *name;                    // nome; 1
  char *email;                   // email; 2
  char *phone_number;            // número de telemóvel; 3
  time_t birth_date;             // data de nascimento; 4
  sex sex;                       // sexo; 5
  char *passport;                // passaporte; 6
  char *country_code;            // código de país; 7
  char *address;                 // endereço do usuário; 8
  time_t account_creation;       // data de criação da conta; 9
  pay_method pay_method;         // método de pagamento; 10
  account_status account_status;



*/

int convertStringToSeconds(char *dateString) {
  struct tm timeStruct = {0};

  if (sscanf(dateString, "%d/%d/%d %d:%d:%d", &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday, &timeStruct.tm_hour, &timeStruct.tm_min, &timeStruct.tm_sec) == 6) {

    timeStruct.tm_year -= 1900;
    timeStruct.tm_mon -= 1;

    return mktime(&timeStruct);
  } else if (sscanf(dateString, "%d/%d/%d", &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday) == 3) {

    timeStruct.tm_year -= 1900;
    timeStruct.tm_mon -= 1;

    timeStruct.tm_hour = 0;
    timeStruct.tm_min = 0;
    timeStruct.tm_sec = 0;

    return mktime(&timeStruct);
  }

  return -1;
}

int verify_dates_difference(char *date1, char *date2) {
  if (date1 != NULL && date2 != NULL) {
    // Converter strings de data para struct tm
    int timestamp1 = convertStringToSeconds(date1);
    int timestamp2 = convertStringToSeconds(date2);

    return (timestamp2 > timestamp1);
  }

  return 0;
}

int verify_account_email(char *email) {

  if (email != NULL) {
    int at_positon = -1;
    int dot_positon = -1;
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

int verify_account_status(char *status) {
  if (status != NULL) {
    size_t len = strlen(status);
    char *lowercase_status = malloc(len + 1);
    if (lowercase_status == NULL) {

      return 0;
    }

    for (size_t i = 0; i < len; i++) {
      lowercase_status[i] = tolower(status[i]);
    }
    lowercase_status[len] = '\0';

    int result = (strcmp(lowercase_status, "active") == 0 || strcmp(lowercase_status, "inactive") == 0);

    free(lowercase_status);

    return result;
  }
  return 0;
}

int verify_user_country_code(char *country_code) {

  if (country_code != NULL && strlen(country_code) == 2 && isalpha(country_code[0]) && isalpha(country_code[1])) {
    return 1;
  }

  return 0;
}

int verify_date(char *date) {
  int year, month, day, hour, minute, second;
  int result = sscanf(date, "%4d/%2d/%2d %2d:%2d:%2d", &year, &month, &day, &hour, &minute, &second);

  if (result == 3 && strlen(date) == 10) { // Formato mais básico
    if (year >= 1000 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
      return 1;
    }
  } else if (result == 6) { // Formato com horas
    if (year >= 1000 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= 31 && hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 &&
        second <= 59 && date[10] != '~') {
      return 1;
    }
  }

  return 0;
}

int values_parser_users(char **user_values,  GHashTable* users_catalog) {

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


  return 0;
}


int verify_airport_name(char *airport_name) {
  if (airport_name != NULL) {
    if (strlen(airport_name) == 3) {
      if (isalpha(airport_name[0]) && isalpha(airport_name[1]) && isalpha(airport_name[2])) {
        return 1;
      }
    } else {
      return 0;
    }
  }


  return 0;
}


int is_digit(char new_char) { return (new_char >= '0' && new_char <= '9'); }

int verify_if_is_digit(char *digit) {
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

int values_parser_flights(char **flight_values ,  GHashTable* flights_catalog) {

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
  if (!verify_airport_name(flight_values[4]) || !verify_airport_name(flight_values[5])) {
    return 1;
  }

  if (!verify_date(flight_values[6]) || !verify_date(flight_values[7]) || !verify_date(flight_values[8]) || !verify_date(flight_values[9])) {
    return 1;
  }

  if (!verify_dates_difference(flight_values[6], flight_values[7])) {
    return 1;
  }

  if (!verify_dates_difference(flight_values[8], flight_values[9])) {
    return 1;
  }


  return 0;
}


int values_parser_passengers(char **passengers_values) {

  if (strcmp(passengers_values[0], "") == 0 || strcmp(passengers_values[0], "") == 0) {
    return 1;
  }
  return 0;
}

/*
–

– 10 includes_breakfast – se a reserva inclui pequeno-almoço;



– Reserva: id, user_id, hotel_id, hotel_name, address

Para valores falsos, “f ”, “false”, “0”, e
“” (string vazia); Para valores verdadeiros, “t”, “true”, e “1”.
*/

int verify_breakfast(char *breakfast) {
  if (breakfast != NULL) {
    size_t len = strlen(breakfast);
    char *lowercase_status = malloc(len + 1);
    for (size_t i = 0; i < len; i++) {
      lowercase_status[i] = tolower(breakfast[i]);
    }
    lowercase_status[len] = '\0';
    int result = (strcmp(lowercase_status, "t") == 0 || strcmp(lowercase_status, "f") == 0 || strcmp(lowercase_status, "") == 0 || strcmp(lowercase_status, "true") == 0 ||
                  strcmp(lowercase_status, "false") == 0 || strcmp(lowercase_status, "1") == 0 || strcmp(lowercase_status, "0") == 0);
    free(lowercase_status);
    return result;
  }
  return 0;
}

int verify_if_is_digit_non_zero(char *new_digit) {
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

int check_char(char value) { return (value >= '1' && value <= '5'); }

int check_hotel_rating_stars(char *word) {
  if (word != NULL) {
    if (strlen(word) == 1) {
      return (check_char(word[0]));
    }
    return 0;
  }
  return 0;
}

int check_hotel_rating(char *word) {
  if (word != NULL) {
    if (strcmp(word, "") == 0) {
      return 1;
    } else {
      return check_hotel_rating_stars(word);
    }
  }
  return 0;
}

int values_parser_reservations(char **reservations_values , GHashTable* reservations_catalog) {
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
  if (!check_hotel_rating(reservations_values[12]) || !check_hotel_rating_stars(reservations_values[4])) {
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

  if (!verify_date(reservations_values[7]) || !verify_date(reservations_values[8])) {
    return 1;
  }

  if (!verify_dates_difference(reservations_values[7], reservations_values[8])) {
    return 1;
  }



  return 0;
}

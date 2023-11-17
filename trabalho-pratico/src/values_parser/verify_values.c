#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/convert_string_to_seconds.h"
#include "utils/is_digit.h"
#include "utils/string_to_lower.h"

bool verify_are_dates_in_order(char* date1, char* date2) {
  if (date1 != NULL && date2 != NULL) {
    long timestamp1 = convert_string_to_seconds(date1);
    long timestamp2 = convert_string_to_seconds(date2);

    return (timestamp2 > timestamp1);
  }

  return false;
}

bool verify_account_email(char* email) {
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
      return false;
    }

    for (size_t j = at_positon; j < strlen(email); j++) {
      if (email[j] == '.') {
        dot_positon = j;
        break;
      }
    }

    if (dot_positon <= at_positon + 2 || strlen(email) - dot_positon < 3) {
      return false;
    }

    if (dot_positon <= at_positon) {
      return false;
    }

    return true;
  }

  return true;
}

bool verify_account_status(char* status) {
  if (status != NULL) {
    char* lowercase_status = strdup(status);
    string_to_lower(lowercase_status);

    int result = (!strcmp(lowercase_status, "active") || !strcmp(lowercase_status, "inactive"));

    free(lowercase_status);

    return result;
  }
  return false;
}

bool verify_user_country_code(char* country_code) {
  if (country_code != NULL && strlen(country_code) == 2 && isalpha(country_code[0]) && isalpha(country_code[1])) {
    return true;
  }

  return false;
}

bool verify_date(char* date) {
  int year, month, day, hour, minute, second;
  int result = sscanf(date, "%4d/%2d/%2d %2d:%2d:%2d", &year, &month, &day, &hour, &minute, &second);

  if (result == 3 && strlen(date) == 10) {  // Formato mais básico
    if (year >= 1000 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
      return true;
    }
  } else if (result == 6) {  // Formato com horas
    if (year >= 1000 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= 31 && hour >= 0 && hour <= 23 &&
        minute >= 0 && minute <= 59 && second >= 0 && second <= 59 && date[10] != '~') {
      return true;
    }
  }

  return false;
}

bool verify_airport_name(char* airport_name) {
  if (airport_name != NULL) {
    if (strlen(airport_name) == 3) {
      if (isalpha(airport_name[0]) && isalpha(airport_name[1]) && isalpha(airport_name[2])) {
        return true;
      }
    } else {
      return false;
    }
  }

  return false;
}

bool verify_if_is_digit(char* digit) {
  if (digit != NULL) {
    for (size_t i = 0; i < strlen(digit); i++) {
      if (!isdigit(digit[i])) {
        return false;
      }
    }
    return true;
  }

  return false;
}

bool verify_breakfast(char* breakfast) {
  if (breakfast != NULL) {
    char* lowercase_breakfast = strdup(breakfast);
    string_to_lower(lowercase_breakfast);

    int result =
        (!strcmp(lowercase_breakfast, "t") || !strcmp(lowercase_breakfast, "f") || !strcmp(lowercase_breakfast, "") ||
         !strcmp(lowercase_breakfast, "true") || !strcmp(lowercase_breakfast, "false") ||
         !strcmp(lowercase_breakfast, "1") || !strcmp(lowercase_breakfast, "0"));

    free(lowercase_breakfast);
    return result;
  }
  return false;
}

bool verify_if_is_digit_non_zero(char* new_digit) {
  if (new_digit != NULL) {
    if ((strlen(new_digit) && !strcmp(new_digit, "0"))) {
      return false;
    }
    if (!strcmp(new_digit, "")) {
      return false;
    } else {
      return (verify_if_is_digit(new_digit));
    }
  }
  return false;
}

bool check_rating_char(char value) {
  return (value >= '1' && value <= '5');
}

bool verify_hotel_rating_stars(char* word) {
  if (word != NULL) {
    if (strlen(word) == 1) {
      return (check_rating_char(word[0]));
    }
    return false;
  }
  return false;
}

bool verify_hotel_rating(char* word) {
  if (word != NULL) {
    if (!strcmp(word, "")) {
      return true;
    } else {
      return verify_hotel_rating_stars(word);
    }
  }
  return false;
}
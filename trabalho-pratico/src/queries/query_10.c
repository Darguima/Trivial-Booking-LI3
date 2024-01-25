#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "utils/calculate_days_of_a_month.h"
#include "utils/min.h"
#include "utils/number_to_string.h"
#include "utils/string_to_int.h"
#include "write_output/write_output.h"

typedef enum type { YEAR, MONTH, DAY } Type;

char* extract_date_info(char* date, Type type) {
  char* r = malloc(sizeof(char) * 7);
  if (type == YEAR) {
    r[0] = date[0];
    r[1] = date[1];
    r[2] = date[2];
    r[3] = date[3];
    r[4] = '\0';
  } else if (type == MONTH) {
    r[0] = date[5];
    r[1] = date[6];
    r[2] = '\0';
  } else if (type == DAY) {
    r[0] = date[8];
    r[1] = date[9];
    r[2] = '\0';
  }

  int r_int = string_to_int(r);
  free(r);
  char* r_str = int_to_string(r_int);

  return r_str;
}

void increase_date(char* date, Type type) {
  if (type == YEAR) {
    char year_str[] = {date[0], date[1], date[2], date[3], '\0'};
    int year = string_to_int(year_str);
    year++;
    date[0] = (char)(year / 1000) + '0';
    date[1] = (char)((year % 1000) / 100) + '0';
    date[2] = (char)((year % 100) / 10) + '0';
    date[3] = (char)(year % 10) + '0';
  } else if (type == MONTH) {
    char month_str[] = {date[5], date[6], '\0'};
    int month = string_to_int(month_str);
    month++;
    date[5] = (char)(month / 10) + '0';
    date[6] = (char)(month % 10) + '0';
  } else {
    char day_str[] = {date[8], date[9], '\0'};
    int day = string_to_int(day_str);
    day++;
    date[8] = (char)(day / 10) + '0';
    date[9] = (char)(day % 10) + '0';
  }
}

int query_10(Catalogs catalogs, int command_number, bool format_flag, char* year, char* month) {
  FILE* output_file = create_output_file(command_number);
  Type range_type = year == NULL ? YEAR : month == NULL ? MONTH : DAY;
  char* range_type_str = range_type == YEAR ? "year" : range_type == MONTH ? "month" : "day";

  char* begin_date = malloc(sizeof(char) * 11);
  char* end_date = malloc(sizeof(char) * 11);

  if (range_type == YEAR) {
    int first_user_year = get_user_first_account_creation_year(catalogs->users);
    int first_flight_year = get_first_flight_year(catalogs->flights);
    int first_reservation_year = get_first_reservation_year(catalogs->reservations);
    int first_year = min(first_user_year, min(first_flight_year, first_reservation_year));

    sprintf(begin_date, "%d/01/01", first_year);
    sprintf(end_date, "9999/12/31");
  } else if (range_type == MONTH) {
    sprintf(begin_date, "%s/01/01", year);
    sprintf(end_date, "%s/12/31", year);
  } else {
    int year_int = string_to_int(year);
    int month_int = string_to_int(month);

    int days_in_month = calculate_days_of_a_month(year_int, month_int);

    sprintf(begin_date, "%s/%s/01", year, month);
    sprintf(end_date, "%s/%s/%d", year, month, days_in_month);
  }

  GList* users = get_users_by_account_creation_range(catalogs->users, begin_date, end_date);
  GList* flights = get_flights_by_schedule_dep_range(catalogs->flights, begin_date, end_date);
  GList* reservations = get_reservations_by_begin_date_range(catalogs->reservations, begin_date, end_date);

  int results_acc = 1;
  char* upper_board_date = malloc(sizeof(char) * 11);
  strcpy(upper_board_date, begin_date);
  increase_date(upper_board_date, range_type);
  for (; users != NULL || flights != NULL || reservations != NULL; increase_date(upper_board_date, range_type)) {
    int users_count = 0;
    int flights_count = 0;
    int reservation_count = 0;
    int passengers_count = 0;

    while (users != NULL) {
      User user = users->data;
      char* user_account_date = user_get_account_creation(user);
      int cmp = strcmp(user_account_date, upper_board_date);
      free(user_account_date);

      if (cmp > 0) {
        break;
      }

      users_count++;
      GList* current = users;
      users = g_list_remove_link(users, current);
      g_list_free_1(current);
    }

    while (flights != NULL) {
      Flight flight = flights->data;
      char* flight_dep_date = flight_get_schedule_departure_date(flight);

      int cmp = strcmp(flight_dep_date, upper_board_date);

      free(flight_dep_date);

      if (cmp > 0) {
        break;
      }

      flights_count++;
      passengers_count += flight_get_number_of_passengers(flight);
      GList* current = flights;
      flights = g_list_remove_link(flights, current);
      g_list_free_1(current);
    }

    while (reservations != NULL) {
      Reservation reservation = reservations->data;
      char* reservation_begin_date = reservation_get_begin_date(reservation);

      int cmp = strcmp(reservation_begin_date, upper_board_date);
      free(reservation_begin_date);

      if (cmp > 0) {
        break;
      }

      reservation_count++;
      GList* current = reservations;
      reservations = g_list_remove_link(reservations, current);
      g_list_free_1(current);
    }

    char* users_count_str = int_to_string(users_count);
    char* flights_count_str = int_to_string(flights_count);
    char* passengers_count_str = int_to_string(passengers_count);
    char* reservation_count_str = int_to_string(reservation_count);
    char* date = extract_date_info(begin_date, range_type);
    increase_date(begin_date, range_type);

    output_key_value output_array[] = {{range_type_str, date},         {"users", users_count_str},
                                       {"flights", flights_count_str}, {"passengers", passengers_count_str},
                                       {"unique_passengers", "0"},     {"reservations", reservation_count_str}};
    write_output(output_file, format_flag, results_acc, output_array, 6);
    results_acc++;

    free(users_count_str);
    free(flights_count_str);
    free(reservation_count_str);
    free(passengers_count_str);
    free(date);
  }

  free(begin_date);
  free(end_date);
  free(upper_board_date);

  close_output_file(output_file);
  return 0;
}
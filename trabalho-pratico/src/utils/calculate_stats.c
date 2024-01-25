#include <datatypes/datatypes.h>
#include <stdio.h>
#include <time.h>
#include "utils/convert_string_to_seconds.h"

#define DEFAULT_DATE "2023/10/01"

int get_days_difference(char* date1, char* date2) {
  int year, month, day, year1, month1, day1;
  int result = sscanf(date1, "%4d/%2d/%2d", &year, &month, &day);
  if (result != 3) {
    return -1;
  };
  int result2 = sscanf(date2, "%4d/%2d/%2d", &year1, &month1, &day1);
  if (result2 != 3) {
    return -1;
  };
  return day1 - day;
}

double calculate_total_spent(char* date1, char* date2, int city_tax, int price_per_night) {
  double total_spent;
  int total_days = get_days_difference(date1, date2);
  double city_tax_increment = ((double)price_per_night * total_days / 100) * city_tax;
  total_spent = (price_per_night * total_days) + city_tax_increment;
  return total_spent;
}

int calculate_user_age(char* birth_date) {
  const char* default_date = DEFAULT_DATE;
  int year, month, day, birth_date_year, birth_date_month, birth_date_day;
  int result = sscanf(default_date, "%4d/%2d/%2d", &year, &month, &day);
  if (result != 3) {
    return -1;
  };
  int result2 = sscanf(birth_date, "%4d/%2d/%2d", &birth_date_year, &birth_date_month, &birth_date_day);
  if (result2 != 3) {
    return -1;
  }
  int age = year - birth_date_year;

  if (month < birth_date_month) {
    age--;
  } else if (month == birth_date_month) {
    if (day < birth_date_day) {
      age--;
    }
  }

  return age;
}

int get_days_difference_inside_range(char* begin_date, char* end_date, char* date1, char* date2) {
  time_t time_date1 = convert_string_to_seconds(date1);
  time_t time_date2 = convert_string_to_seconds(date2);
  time_t time_interval_start = convert_string_to_seconds(begin_date);
  time_t time_interval_end = convert_string_to_seconds(end_date);
  if (time_date1 >= time_interval_start && time_date2 <= time_interval_end) {
    int days_difference = get_days_difference(date1, date2);
    free(date1);
    free(date2);
    return days_difference;
  }

  if (time_date1 <= time_interval_start && time_date2 >= time_interval_end) {
    free(date1);
    free(date2);
    int days_difference = (int)((time_interval_end - time_interval_start) / (60 * 60 * 24)) + 1;
    if (time_date2 == time_interval_end) {
      days_difference--;
    }
    return days_difference;
  }

  if (time_date1 < time_interval_start && time_date2 >= time_interval_start && time_date2 <= time_interval_end) {
    free(date1);
    free(date2);
    int days_difference = (int)((time_date2 - time_interval_start) / (60 * 60 * 24));
    return days_difference;
  }

  if (time_date1 >= time_interval_start && time_date1 <= time_interval_end && time_date2 > time_interval_end) {
    free(date1);
    free(date2);
    int days_difference = (int)((time_interval_end - time_date1) / (60 * 60 * 24)) + 1;

    return days_difference;
  }
  return 0;
}

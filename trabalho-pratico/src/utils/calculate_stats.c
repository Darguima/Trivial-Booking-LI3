#include <datatypes/datatypes.h>
#include <stdio.h>
#include <time.h>

#define DEFAULT_DATE "2023/10/01"

void increment_total_reservations(UserSchema user) {
  user->number_of_reservations += 1;
}

void increment_total_flights(UserSchema user) {
  user->number_of_flights += 1;
}

void increment_user_total_spent(UserSchema user,
                                double total_reservation_price) {
  user->total_spent += (double)total_reservation_price;
}

void increment_seat(FlightSchema flight) {
  flight->number_of_passengers += 1;
}

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

double calculate_total_spent(char* date1,
                             char* date2,
                             int city_tax,
                             int price_per_night) {
  double total_spent;
  int total_days = get_days_difference(date1, date2);
  double city_tax_increment =
      ((double)price_per_night * total_days / 100) * city_tax;
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
  int result2 = sscanf(birth_date, "%4d/%2d/%2d", &birth_date_year,
                       &birth_date_month, &birth_date_day);
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
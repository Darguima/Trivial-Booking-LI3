int calculate_days_of_a_month(int year, int month) {
  if (month == 2) {
    if (year % 4 == 0) {
      return 29;
    } else {
      return 28;
    }
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30;
  } else {
    return 31;
  }
}
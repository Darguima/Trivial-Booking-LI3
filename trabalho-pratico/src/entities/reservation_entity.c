#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "catalogs_creator/reservations_catalog.h"
#include "utils/calculate_stats.h"
#include "utils/includes_breakfast.h"
#include "utils/string_to_int.h"

struct reservation {
  int id;
  char* reservation_id;
  char* hotel_id;
  char* hotel_name;
  int hotel_stars;
  int city_tax;
  // char* address;
  char* begin_date;
  char* end_date;
  int price_per_night;
  bool includes_breakfast;
  // char* room_details;
  char rating;
  // char* comment;
  double total_price;
};

Reservation create_new_reservation(ReservationsCatalog reservations_catalog, char** reservation_values) {
  Reservation new_reservation = malloc(sizeof(struct reservation));

  new_reservation->id = string_to_int(reservation_values[0]);
  new_reservation->hotel_id = strdup(reservation_values[2]);
  new_reservation->hotel_name = strdup(reservation_values[3]);
  new_reservation->hotel_stars = string_to_int(reservation_values[4]);
  new_reservation->city_tax = string_to_int(reservation_values[5]);
  new_reservation->begin_date = strdup(reservation_values[7]);
  new_reservation->end_date = strdup(reservation_values[8]);
  new_reservation->price_per_night = string_to_int(reservation_values[9]);
  new_reservation->includes_breakfast = includes_breakfast(reservation_values[10]);
  new_reservation->rating = *(reservation_values[12]);
  new_reservation->total_price = calculate_total_spent(new_reservation->begin_date, new_reservation->end_date,
                                                       new_reservation->city_tax, new_reservation->price_per_night);

  insert_reservation(reservations_catalog, new_reservation);

  return new_reservation;
}

void free_reservation(Reservation* value) {
  Reservation reservation = *value;

  if (reservation == NULL) {
    return;
  }

  free(reservation->hotel_id);
  free(reservation->hotel_name);
  free(reservation->begin_date);
  free(reservation->end_date);

  free(reservation);
}

int reservation_get_id(Reservation reservation) {
  return reservation->id;
}

char* reservation_get_begin_date(Reservation reservation) {
  return g_strdup(reservation->begin_date);
}

char* reservation_get_end_date(Reservation reservation) {
  return g_strdup(reservation->end_date);
}

char* reservation_get_hotel_id(Reservation reservation) {
  return g_strdup(reservation->hotel_id);
}

char* reservation_get_hotel_name(Reservation reservation) {
  return g_strdup(reservation->hotel_name);
}

bool reservation_get_breakfast(Reservation reservation) {
  return reservation->includes_breakfast;
}

char reservation_get_rating(Reservation reservation) {
  return reservation->rating;
}

double reservation_get_total_price(Reservation reservation) {
  return reservation->total_price;
}

int reservation_get_hotel_stars(Reservation reservation) {
  return reservation->hotel_stars;
}

int reservation_get_revenue(Reservation reservation, char* begin_date, char* end_date) {
  int revenue = 0;
  if (strcmp(reservation->end_date, begin_date) >= 0 && strcmp(reservation->begin_date, end_date) <= 0) {
    revenue += reservation->price_per_night * get_days_difference_inside_range(begin_date, end_date,
                                                                               reservation_get_begin_date(reservation),
                                                                               reservation_get_end_date(reservation));
  }
  return revenue;
}

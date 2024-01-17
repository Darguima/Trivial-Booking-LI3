#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "catalogs_creator/hotels_catalog.h"
#include "datatypes/datatypes.h"
#include "entities/reservation_entity.h"
#include "utils/string_to_int.h"

struct hotel {
  int id;
  char* name;
  int rating_sum;
  RelationArray reservations;
};

Hotel create_new_hotel(HotelsCatalog hotels_catalog, char** hotel_values) {
  Hotel new_hotel = malloc(sizeof(struct hotel));

  RelationArray reservations = malloc(sizeof(struct relationArray));
  reservations->values = g_array_new(FALSE, FALSE, sizeof(Reservation));
  reservations->is_sorted = false;

  new_hotel->id = string_to_int(hotel_values[0]);
  new_hotel->name = g_strdup(hotel_values[1]);
  new_hotel->rating_sum = 0;
  new_hotel->reservations = reservations;

  insert_hotel(hotels_catalog, new_hotel);

  return new_hotel;
}

void free_hotel(gpointer value) {
  Hotel hotel = (Hotel)value;

  g_free(hotel->name);
  g_array_free(hotel->reservations->values, true);
  g_free(hotel->reservations);

  free(hotel);
}

int hotel_get_id(Hotel hotel) {
  return hotel->id;
}

char* hotel_get_name(Hotel hotel) {
  return g_strdup(hotel->name);
}

int hotel_get_rating(Hotel hotel) {
  return (hotel->rating_sum / (int)hotel->reservations->values->len);
}

GArray* hotel_get_reservations(Hotel hotel) {
  return g_array_copy(hotel->reservations->values);
}

int hotel_get_total_revenue(Hotel hotel, char* begin_date, char* end_date) {
  int total_revenue = 0;

  for (guint i = 0; i < hotel->reservations->values->len; i++) {
    Reservation reservation = g_array_index(hotel->reservations->values, Reservation, i);
    total_revenue += reservation_get_revenue(reservation, begin_date, end_date);
  }

  return total_revenue;
}

void hotel_insert_new_reservation(HotelsCatalog hotels_catalog, Reservation reservation) {
  char* hotel_id = reservation_get_hotel_id(reservation);
  char* hotel_name = reservation_get_hotel_name(reservation);

  Hotel hotel = get_hotel_by_id(hotels_catalog, string_to_int(hotel_id));
  if (hotel == NULL) {
    hotel = create_new_hotel(hotels_catalog, (char*[]){hotel_id, hotel_name});
  }

  hotel->rating_sum += reservation_get_rating(reservation) - '0';
  g_array_append_val(hotel->reservations->values, reservation);

  free(hotel_id);
  free(hotel_name);
}

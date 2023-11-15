#ifndef CALCULATE_STATS_H
#define CALCULATE_STATS_H

#include <datatypes/datatypes.h>
void increment_total_reservations(UserSchema user);

void increment_total_flights(UserSchema user);

void increment_seat(FlightSchema flight);

void increment_user_total_spent(UserSchema user,
                                double total_reservation_price);

double calculate_total_spent(char* date1,
                             char* date2,
                             int city_tax,
                             int price_per_night);
int calculate_user_age(char* birth_date);
#endif
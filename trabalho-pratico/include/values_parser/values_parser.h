#ifndef VALUES_PARSER_H
#define VALUES_PARSER_H

int values_parser_users(char** values, GHashTable* users_catalog);
int values_parser_flights(char** values, GHashTable* flights_catalog);
int values_parser_passengers(char** values, GHashTable* passengers_catalog);
int values_parser_reservations(char** values, GHashTable* reservations_catalog);

#endif
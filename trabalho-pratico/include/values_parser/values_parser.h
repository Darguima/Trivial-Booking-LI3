#ifndef VALUES_PARSER_H
#define VALUES_PARSER_H

int values_parser_users(char** values, Catalogs catalog);
int values_parser_flights(char** values, Catalogs catalog);
int values_parser_passengers(char** values, Catalogs catalog);
int values_parser_reservations(char** values, Catalogs catalog);

#endif
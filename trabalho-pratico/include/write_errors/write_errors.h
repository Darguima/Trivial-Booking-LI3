#ifndef WRITE_ERRORS_H
#define WRITE_ERRORS_H

void init_errors_files();

void write_reservations_errors(char** line_elements);

void write_users_errors(char** line_elements);

void write_passengers_errors(char** line_elements);

void write_flights_errors(char** line_elements);

#endif
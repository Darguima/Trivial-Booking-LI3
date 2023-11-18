//! file

#ifndef WRITE_ERRORS_H
#define WRITE_ERRORS_H

/**
 * @brief Initializes the error files for reservations, users, passengers, and flights.
 *
 * This function initializes the error files for each type of schema (reservations, users, passengers, and flights).
 * The error files are CSV files named typeofschema_errors.csv, where typeofschema corresponds to reservations, users,
 * passengers, or flights. These files are used to store lines from the original CSV files that contain errors. The
 * function also writes the header line specifying the parameters for each type of schema.
 *
 * @note This function should be called before using any of the write_errors functions.
 */
void init_errors_files();

/**
 * @brief Writes a line with errors from a reservations CSV file to the reservations_errors.csv file.
 *
 * This function writes a line with errors from a reservations CSV file to the reservations_errors.csv file.
 * The entire line is specified in the line_elements parameter.
 *
 * @param line_elements The entire line with errors from the reservations CSV file.
 */
void write_reservations_errors(char** line_elements);

/**
 * @brief Writes a line with errors from a users CSV file to the users_errors.csv file.
 *
 * This function writes a line with errors from a users CSV file to the users_errors.csv file.
 * The entire line is specified in the line_elements parameter.
 *
 * @param line_elements The entire line with errors from the users CSV file.
 */
void write_users_errors(char** line_elements);

/**
 * @brief Writes a line with errors from a passengers CSV file to the passengers_errors.csv file.
 *
 * This function writes a line with errors from a passengers CSV file to the passengers_errors.csv file.
 * The entire line is specified in the line_elements parameter.
 *
 * @param line_elements The entire line with errors from the passengers CSV file.
 */
void write_passengers_errors(char** line_elements);

/**
 * @brief Writes a line with errors from a flights CSV file to the flights_errors.csv file.
 *
 * This function writes a line with errors from a flights CSV file to the flights_errors.csv file.
 * The entire line is specified in the line_elements parameter.
 *
 * @param line_elements The entire line with errors from the flights CSV file.
 */
void write_flights_errors(char** line_elements);

#endif
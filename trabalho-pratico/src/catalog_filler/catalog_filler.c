#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "catalogs_creator/catalogs_creator.h"
#include "datatypes/datatypes.h"
#include "file_parser/file_parser.h"
#include "write_errors/write_errors.h"

char* get_full_path(char* folder_path, const char* filename) {
  size_t len_filename = strlen(filename);
  size_t len_folder_path = strlen(folder_path);

  char* full_filename =
      malloc(sizeof(char) * (len_folder_path + len_filename + 1));

  strcpy(full_filename, folder_path);
  strcat(full_filename, filename);

  return full_filename;
}

int catalog_filler(char* dataset_folder_path, Catalogs CATALOGS) {
  // Opening all the files
  char* users_filename = get_full_path(dataset_folder_path, "/users.csv");
  FILE* users = fopen(users_filename, "r");

  char* flights_filename = get_full_path(dataset_folder_path, "/flights.csv");
  FILE* flights = fopen(flights_filename, "r");

  char* passengers_filename =
      get_full_path(dataset_folder_path, "/passengers.csv");
  FILE* passengers = fopen(passengers_filename, "r");

  char* reservations_filename =
      get_full_path(dataset_folder_path, "/reservations.csv");
  FILE* reservations = fopen(reservations_filename, "r");

  if (users == NULL || flights == NULL || passengers == NULL ||
      reservations == NULL) {
    return -1;
  }

  init_errors_files();  // Add headers to csv error files

  // Calling respective parsers

  file_parser(users, CATALOGS, USERS, dataset_folder_path);
  file_parser(flights, CATALOGS, FLIGHTS, dataset_folder_path);
  file_parser(reservations, CATALOGS, RESERVATIONS, dataset_folder_path);
  file_parser(passengers, CATALOGS, PASSENGERS, dataset_folder_path);

  // Cleaning up

  free(users_filename);
  free(flights_filename);
  free(reservations_filename);
  free(passengers_filename);

  fclose(users);
  fclose(flights);
  fclose(reservations);
  fclose(passengers);

  return 0;
}

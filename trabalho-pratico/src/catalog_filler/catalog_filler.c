#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  free(users_filename);
  free(flights_filename);
  free(passengers_filename);
  free(reservations_filename);

  init_errors_files();  // Add headers to csv error files

  if (users != NULL) {
    file_parser(users, CATALOGS, USERS, dataset_folder_path);
    fclose(users);
  }

  if (flights != NULL) {
    file_parser(flights, CATALOGS, FLIGHTS, dataset_folder_path);
    fclose(flights);
  }

  if (reservations != NULL) {
    file_parser(reservations, CATALOGS, RESERVATIONS, dataset_folder_path);
    fclose(reservations);
  }

  if (passengers != NULL) {
    file_parser(passengers, CATALOGS, PASSENGERS, dataset_folder_path);
    fclose(passengers);
  }

  bool is_dataset_path_valid = users != NULL && flights != NULL &&
                               passengers != NULL && reservations != NULL;

  if (is_dataset_path_valid) {
    printf("[STATUS] - Catalogs filled\n");
  }

  return is_dataset_path_valid ? 0 : -1;
}

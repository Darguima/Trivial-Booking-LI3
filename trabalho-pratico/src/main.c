#include <stdio.h>
#include "catalog_filler/catalog_filler.h"
#include "catalogs_creator/catalogs_creator.h"
#include "datatypes/datatypes.h"
#include "output/batch.h"
#include "output/interactive.h"
#include "values_parser/values_parser.h"  // Delete me when possible

int main(int argc, char** argv) {
  if (argc != 1 && argc != 3) {
    printf("Your arguments are wrong!\n");
    printf("You passed %d arguments.\n", argc - 1);
    printf("For interactive mode dont't pass any argument.\n");
    printf("For batch mode pass 2 arguments:\n");
    printf("\t- the dataset folder path\n");
    printf("\t- the queries file path\n");
    fprintf(stderr, "[ERROR] - Invalid params\n");
    return -1;
  }

  char* dataset_folder_path;
  if (argc == 1) {
    // ask user the input - 2nd phase
    dataset_folder_path = "./dataset/data";
  } else {
    dataset_folder_path = argv[1];
  }

  printf("[INFO] - Dataset folder path: %s\n", dataset_folder_path);

  char* queries_file_path = "not needed";
  if (argc == 3) {
    queries_file_path = argv[2];
  }

  printf("[INFO] - Queries file path: %s\n", queries_file_path);

  Catalogs CATALOGS = catalogs_creator();

  printf("[STATUS] - Catalogs created\n");

  int catalog_fill_status = catalog_filler(dataset_folder_path, CATALOGS);
  if (catalog_fill_status == -1) {
    fprintf(stderr, "[ERROR] - Invalid dataset path\n");
    return -1;
  }

  printf("[STATUS] - Catalogs filled\n");

  /*
   * DELETE ME AFTER HERE =================================================
   */

  UserSchema test_struct_pointer_user =
      (UserSchema)g_hash_table_lookup(CATALOGS->users, "AlícSá-Mendes");
  FlightSchema test_struct_pointer_flight =
      (FlightSchema)g_hash_table_lookup(CATALOGS->flights, GINT_TO_POINTER(1));
  ReservationSchema test_struct_pointer_reservation =
      (ReservationSchema)g_hash_table_lookup(CATALOGS->reservations, "11");
  PassengerSchema test_struct_pointer_passenger =
      (PassengerSchema)g_hash_table_lookup(CATALOGS->passengers, "1_1");

  printf("\n\n");

  if (test_struct_pointer_user != NULL) {
    printf("[main - user] %s\n", test_struct_pointer_user->name);
  } else {
    printf("[main - test] not found user\n");
  }

  if (test_struct_pointer_flight != NULL) {
    printf("[main - flight] %s\n", test_struct_pointer_flight->airline);
  } else {
    printf("[main - test] not found flight\n");
  }

  if (test_struct_pointer_reservation != NULL) {
    printf("[main - reservation] %s\n",
           test_struct_pointer_reservation->hotel_name);
  } else {
    printf("[main - test] not found reservation\n");
  }

  if (test_struct_pointer_passenger != NULL) {
    printf("[main - passenger] %i\n", test_struct_pointer_passenger->flight_id);
  } else {
    printf("[main - test] not found passenger\n");
  }

  // return 0;

  // DELETE ME UNTIL HERE =================================================

  if (argc == 3) {
    batch();
    printf("Args: '%s' & '%s'.\n", argv[1], argv[2]);
  } else if (argc == 1) {
    printf("Entered in Interactive Mode\n");
    interactive();
  }

  return 0;
}
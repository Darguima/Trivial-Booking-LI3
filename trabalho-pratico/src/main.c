#include <stdio.h>
#include "catalogs_creator/catalogs_creator.h"
#include "datatypes/datatypes.h"
#include "file_parser/file_parser.h"
#include "interpreter/interpreter.h"
#include "output/batch.h"
#include "output/interactive.h"
#include "values_parser/values_parser.h"  // Delete me when possible

int main(int argc, char** argv) {
  Catalogs CATALOGS = catalogs_creator();

  /*
   * DELETE ME AFTER HERE =================================================
   * Just to test CATALOG and use the var.
   * Delete this section of code after the variable be passed to bash and
   * interpreter
   */

  char** fake_string_array = malloc(1 * sizeof(char*));
  fake_string_array[0] = "fake string";

  values_parser_users(fake_string_array, CATALOGS->users);
  values_parser_flights(fake_string_array, CATALOGS->flights);
  values_parser_reservations(fake_string_array, CATALOGS->reservations);
  values_parser_passengers(fake_string_array, CATALOGS->passengers);

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

  // DELETE ME UNTIL HERE =================================================

  // Add catalogs filler manager here

  if (argc == 3) {
    interpreter();
    batch();
    printf("Args: '%s' & '%s'.\n", argv[1], argv[2]);
  } else if (argc == 1) {
    interpreter();
    printf("Entered in Interactive Mode\n");
    interactive();
  } else {
    printf(
        "Call the program with 2 params (dataset & queries file) to batch "
        "mode.\n");
    printf("Call the program without params to interactive mode.\n");
    fprintf(stderr, "[ERROR] Invalid params\n");
    return 1;
  }

  return 0;
}
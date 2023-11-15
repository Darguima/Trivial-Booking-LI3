#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>

int query_3(Catalogs CATALOGS, int command_number, bool field, char* id) {
  printf("I'm in query_3\n");

  UNUSED(CATALOGS);
  UNUSED(command_number);
  UNUSED(field);
  UNUSED(id);

  return 0;
}
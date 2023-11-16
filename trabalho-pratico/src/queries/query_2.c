#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>

int query_2(Catalogs CATALOGS, int command_number, bool format_flag, char* id, char* optional) {
  printf("I'm in query_2\n");

  UNUSED(CATALOGS);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(id);
  UNUSED(optional);

  return 0;
}
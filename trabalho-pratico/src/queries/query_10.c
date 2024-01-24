#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "state/state.h"

int query_10(Catalogs catalogs, int command_number, bool format_flag, char* year, char* month, State state) {
  printf("I'm in query_10\n");
  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(year);
  UNUSED(month);
  return 0;
}
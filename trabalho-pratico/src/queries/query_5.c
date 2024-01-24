#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "utils/convert_string_to_seconds.h"
#include "write_output/write_output.h"
#include "state/state.h"

int query_5(Catalogs catalogs, int command_number, bool format_flag, char* name, char* begin_date, char* end_date, State state) {
  printf("I'm in query_5\n");
  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(name);
  UNUSED(begin_date);
  UNUSED(end_date);

  return 0;
}
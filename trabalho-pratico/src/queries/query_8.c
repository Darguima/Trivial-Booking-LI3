#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "utils/convert_string_to_seconds.h"
#include "utils/number_to_string.h"
#include "write_output/write_output.h"

int query_8(Catalogs catalogs, int command_number, bool format_flag, char* name, char* begin_date, char* end_date) {
  printf("I'm in query_8\n");

  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(name);
  UNUSED(begin_date);
  UNUSED(end_date);
  return 0;
}
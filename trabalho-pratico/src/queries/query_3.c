#include <catalogs_creator/catalogs_creator.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "utils/number_to_string.h"
#include "utils/string_to_int.h"
#include "write_output/write_output.h"

int query_3(Catalogs catalogs, int command_number, bool format_flag, char* id) {
  printf("I'm in query_3\n");
  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(id);

  return 0;
}
#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <utils/number_to_string.h>
#include "ctype.h"
#include "entities/user_entity.h"
#include "utils/calculate_stats.h"
#include "write_output/write_output.h"

int query_1(Catalogs catalogs, int command_number, bool format_flag, char* id) {
  printf("I'm in query_1\n");
  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(id);

  return 0;
}
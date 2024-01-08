#include <catalogs_creator/catalogs_creator.h>
#include <glib.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes/datatypes.h"
#include "utils/calculate_stats.h"
#include "write_output/write_output.h"

int query_9(Catalogs catalogs, int command_number, bool format_flag, const char* prefix) {
  printf("I'm in query_9\n");

  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(prefix);
  return 0;
}

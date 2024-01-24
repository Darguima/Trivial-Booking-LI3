#include <catalogs_creator/catalogs_creator.h>
#include <glib.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes/datatypes.h"
#include "state/state.h"
#include "utils/calculate_stats.h"
#include "write_output/write_output.h"

#define UNUSED(x) (void)(x)

int query_9(Catalogs catalogs, int command_number, bool format_flag, const char* prefix, State* state) {
  printf("I'm in query_9\n");

  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(prefix);
  UNUSED(state);
  return 0;
}

#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include "catalogs_creator/catalogs_creator.h"
#include "datatypes/datatypes.h"
#include "state/state.h"
#include "utils/number_to_string.h"
#include "write_output/write_output.h"
#define UNUSED(x) (void)(x)

int query_4(Catalogs catalogs, int command_number, bool format_flag, char* hotel_id, State* state) {
  printf("I'm in query_4\n");
  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(hotel_id);
  UNUSED(state);

  return 0;
}
#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include "datatypes/datatypes.h"
#include "utils/number_to_string.h"
#include "write_output/write_output.h"

#include "catalogs_creator/catalogs_creator.h"
#include "datatypes/datatypes.h"

int query_4(Catalogs catalogs, int command_number, bool format_flag, char* hotel_id) {
  printf("I'm in query_4\n");
  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(hotel_id);

  return 0;
}
#include "queries/query_2.h"
#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>
#include "catalogs_setup/users_catalog.h"
#include "utils/convert_string_to_seconds.h"
#include "utils/extract_date_without_time.h"
#include "write_output/write_output.h"

int query_2(Catalogs catalogs, int command_number, bool format_flag, char* id, char* optional) {
  printf("I'm in query_2\n");
  UNUSED(catalogs);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(id);
  UNUSED(optional);

  return 0;
}
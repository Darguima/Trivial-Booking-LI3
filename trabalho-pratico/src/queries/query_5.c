#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>

int query_5(Catalogs CATALOGS,
            int command_number,
            bool format_flag,
            char* name,
            char* begin_date,
            char* end_date) {
  printf("I'm in query_5\n");

  UNUSED(CATALOGS);
  UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(name);
  UNUSED(begin_date);
  UNUSED(end_date);

  return 0;
}
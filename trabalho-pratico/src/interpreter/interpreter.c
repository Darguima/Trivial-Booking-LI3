#include <stdbool.h>
#include <stdio.h>
#include "queries/query_1.h"
#include "queries/query_10.h"
#include "queries/query_2.h"
#include "queries/query_3.h"
#include "queries/query_4.h"
#include "queries/query_5.h"
#include "queries/query_6.h"
#include "queries/query_7.h"
#include "queries/query_8.h"
#include "queries/query_9.h"

#include <datatypes/datatypes.h>

int interpreter(char* batch_line, Catalogs CATALOGS) {
  printf("I'm in interpreter\n");

  if (batch_line && CATALOGS) {
    /* code */
  }

  return 0;
}
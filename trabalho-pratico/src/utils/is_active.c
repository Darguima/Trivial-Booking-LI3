#include <ctype.h>
#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include "utils/string_to_lower.h"

bool is_active(char* status) {
  if (status != NULL) {
    char* lowerStr = strdup(status);
    string_to_lower(lowerStr);

    size_t len = strlen(lowerStr);
    lowerStr[len] = '\0';

    int result = (!strcmp(lowerStr, "active"));

    free(lowerStr);

    return result;
  }
  return -1;
}
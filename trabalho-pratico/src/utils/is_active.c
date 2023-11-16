#include <ctype.h>
#include <glib.h>
#include <stdbool.h>
#include <stdio.h>

bool is_active(char* status) {
  if (status != NULL) {
    size_t len = strlen(status);
    char* lowercase_status = malloc(len + 1);

    if (lowercase_status == NULL) {
      return false;
    }

    for (size_t i = 0; i < len; i++) {
      lowercase_status[i] = (char)tolower(status[i]);
    }

    lowercase_status[len] = '\0';

    int result = (!strcmp(lowercase_status, "active"));

    free(lowercase_status);

    return result;
  }
  return -1;
}
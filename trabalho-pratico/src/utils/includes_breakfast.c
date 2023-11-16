#include <ctype.h>
#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool includes_breakfast(char* breakfast_stat) {
  size_t len = strlen(breakfast_stat);

  char* lowerStr = (char*)malloc(len + 1);
  if (lowerStr == NULL) {
    fprintf(stderr, "Error allocating memory!\n");
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < len; i++) {
    lowerStr[i] = (char)tolower(breakfast_stat[i]);
  }
  lowerStr[len] = '\0';

  if (g_strcmp0(lowerStr, "true") == 0 || g_strcmp0(lowerStr, "1") == 0 || g_strcmp0(lowerStr, "t") == 0) {
    free(lowerStr);
    return true;
  }

  if (g_strcmp0(lowerStr, "false") == 0 || g_strcmp0(lowerStr, "0") == 0 || g_strcmp0(lowerStr, "f") == 0 || len == 0) {
    free(lowerStr);
    return false;
  }

  free(lowerStr);
  return false;
}
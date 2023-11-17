#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* extract_date_without_time(char* date_with_time) {
  char* space_position = strchr(date_with_time, ' ');
  if (space_position != NULL) {
    size_t date_length = (size_t)(space_position - date_with_time);
    char* date_only = (char*)malloc(date_length + 1);
    if (date_only != NULL) {
      strncpy(date_only, date_with_time, date_length);
      date_only[date_length] = '\0';

      return date_only;
    } else {
      fprintf(stderr, "Error allocating memory!\n");
      return NULL;
    }
  }
  return date_with_time;
}

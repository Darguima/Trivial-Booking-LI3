#include <stdio.h>
#include <time.h>

time_t convert_string_to_seconds(char* dateString) {
  struct tm timeStruct = {0};

  if (sscanf(dateString, "%d/%d/%d %d:%d:%d", &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday,
             &timeStruct.tm_hour, &timeStruct.tm_min, &timeStruct.tm_sec) == 6) {
    timeStruct.tm_year -= 1900;
    timeStruct.tm_mon -= 1;

    return mktime(&timeStruct);
  } else if (sscanf(dateString, "%d/%d/%d", &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday) == 3) {
    timeStruct.tm_year -= 1900;
    timeStruct.tm_mon -= 1;

    timeStruct.tm_hour = 0;
    timeStruct.tm_min = 0;
    timeStruct.tm_sec = 0;

    return mktime(&timeStruct);
  }

  return -1;
}
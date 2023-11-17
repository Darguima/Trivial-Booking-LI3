#include <ctype.h>
#include <string.h>

char* string_to_lower(char* string) {
  for (size_t i = 0; i < strlen(string); i++) {
    string[i] = (char)tolower(string[i]);
  }

  return string;
}
#include <ctype.h>
#include <string.h>

char* string_to_upper(char* string) {
  for (size_t i = 0; i < strlen(string); i++) {
    string[i] = (char)toupper(string[i]);
  }

  return string;
}
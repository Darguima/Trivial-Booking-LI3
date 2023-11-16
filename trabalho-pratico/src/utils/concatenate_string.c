#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenate_string(char** strings, int length) {
  // Calculate the total length of the concatenated string
  size_t total_length = 1;  // Start with 1 for the null terminator

  for (int i = 0; i < length; ++i) {
    total_length += strlen(strings[i]);
  }

  // Allocate memory for the concatenated string
  char* result = (char*)malloc(total_length);

  // Check if the allocation was successful
  if (result == NULL) {
    fprintf(stderr, "Error allocating memory\n");
    exit(EXIT_FAILURE);
  }

  // Copy each string to the result
  strcpy(result, strings[0]);

  for (int i = 1; i < length; ++i) {
    strcat(result, strings[i]);
  }

  return result;
}
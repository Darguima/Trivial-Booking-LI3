#include <stdio.h>
#include <stdlib.h>

char* int_to_string(int number) {
  char* string = malloc(sizeof(char) * 10);
  sprintf(string, "%d", number);
  return string;
}

char* double_to_string(double number, int precision) {
  char* string = malloc(sizeof(char) * 10);
  sprintf(string, "%.*f", precision, number);
  return string;
}
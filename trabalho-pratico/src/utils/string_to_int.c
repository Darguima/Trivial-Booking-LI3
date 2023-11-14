int string_to_int(char* total) {
  int value = 0;
  for (int i = 0; total[i] != '\0'; i++) {
    value *= 10;
    value += total[i] - '0';
  }
  return value;
}
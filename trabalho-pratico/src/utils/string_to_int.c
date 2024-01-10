int string_to_int(char* total) {
  int value = 0;
  for (int i = 0; total[i] != '\0'; i++) {
    if (total[i] < '0' || total[i] > '9') {
      continue;
    }

    value *= 10;
    value += total[i] - '0';
  }
  return value;
}
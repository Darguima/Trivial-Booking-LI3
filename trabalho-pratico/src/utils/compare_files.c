#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/print_and_write.h"

void compare_files(int file_number, char* queries_expected_file_path) {
  char filename[100];
  snprintf(filename, sizeof(filename), "./Resultados/command%d_output.txt", file_number);
  size_t path_length = (size_t)snprintf(NULL, 0, "%s/command%d_output.txt", queries_expected_file_path, file_number);
  char* filename1 = (char*)malloc(path_length + 1);
  snprintf(filename1, path_length + 1, "%s/command%d_output.txt", queries_expected_file_path, file_number);

  FILE* file1 = fopen(filename, "r");
  FILE* file2 = fopen(filename1, "r");

  FILE* outputFile = fopen("./Resultados/tests_results.txt", "a");
  if (file1 == NULL || file2 == NULL) {
    print_and_write(outputFile, "One of the files does not exist!\n");
    print_and_write(outputFile, "Test %d failed: The files do not match.\n\n", file_number);
    free(filename1);
    if (file1 != NULL) {
      fclose(file1);
    }
    if (file2 != NULL) {
      fclose(file2);
    }
    print_and_write(outputFile, "------------------------\n");
    fclose(outputFile);
    return;
  }

  int equal = 1;
  char line1[1000], line2[1000];
  int line_number = 1;
  char* a;
  char* b;

  while ((a = fgets(line1, sizeof(line1), file1)) != NULL && (b = fgets(line2, sizeof(line2), file2)) != NULL) {
    if (strcmp(line1, line2) != 0) {
      equal = 0;
      print_and_write(outputFile, "Different lines at line: %d\n", line_number);
      print_and_write(outputFile, "Output File:\n%s", line1);
      print_and_write(outputFile, "Expected File:\n%s", line2);
    }

    line_number++;
  }

  // Verificar se um dos arquivos tem mais linhas que o outro
  if (equal && a != NULL) {
    print_and_write(outputFile, "The expected file has less lines than the output file!\n");
    print_and_write(outputFile, "Line missing in the expected file: %s\n", line1);
    equal = 0;
  } else if (equal && fgets(line2, sizeof(line2), file2) != NULL) {
    print_and_write(outputFile, "The expected file has more lines than the output file\n");
    print_and_write(outputFile, "Unexpected line: %s\n", line2);
    equal = 0;
  }

  if (equal) {
    print_and_write(outputFile, "Test %d passed: The files have the same content.\n", file_number);
  } else {
    print_and_write(outputFile, "Test %d failed: The files do not match.\n", file_number);
  }
  print_and_write(outputFile, "------------------------\n");

  fclose(file1);
  fclose(file2);
  fclose(outputFile);
  free(filename1);
}
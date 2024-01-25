#include <glib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "catalog_filler/catalog_filler.h"
#include "catalogs_creator/catalogs_creator.h"
#include "datatypes/datatypes.h"
#include "start_tests.h"
#include "utils/calculate_execution_stats.h"
#include "utils/compare_files.h"
#include "utils/print_and_write.h"
#include "utils/print_invalid_path_error.h"

int main(int argc, char** argv) {
  setlocale(LC_COLLATE, "en_US.UTF-8");
  if (argc != 4) {
    printf("Your arguments are wrong!\n");
    printf("You passed %d arguments.\n", argc - 1);
    printf("You need 3 arguments!\n");
    printf("The dataset folder path , the queries file path and the expected output folder path!\n");
    printf("Try again!\n");
    fprintf(stderr, "[ERROR] - Invalid params\n");
    return -1;
  }

  Catalogs catalogs = catalogs_creator();

  char* dataset_folder_path = argv[1];

  clock_t catalog_time_start = start_timer();
  int catalog_fill_status = catalog_filler(dataset_folder_path, catalogs);
  if (catalog_fill_status == -1) {
    print_invalid_path_error("dataset");
    free_catalogs(catalogs);
    printf("Try again!\n");
    return -1;
  }

  double elapsed_time_catalogs = stop_timer(catalog_time_start);

  char* expected_output_folder_path = argv[3];

  char* queries_path = argv[2];

  FILE* file = fopen(queries_path, "r");

  if (file == NULL) {
    print_invalid_path_error("queries file");
    free_catalogs(catalogs);
    printf("Try again!\n\n");
    return -1;
  }
  fclose(file);

  FILE* arquivo = fopen("./Resultados/tests_results.txt", "w");
  fclose(arquivo);

  printf("\nWelcome to the testing program! Let's ensure everything is working smoothly.\n\n");

  printf(
      "I will execute each query one by one and compare the results with the expected files.You will be able to check "
      "also the execution time of each query!\n\n");

  printf("Press enter to start!\n");
  getchar();

  printf("--------------- Starting Tests ---------------\n\n");

  clock_t timer_start = start_timer();
  start_tests(catalogs, queries_path, expected_output_folder_path);

  printf("\n--------------- Ending Tests ---------------\n\n");

  calculate_memory_usage();
  free_catalogs(catalogs);

  double elapsed_time = stop_timer(timer_start);

  arquivo = fopen("./Resultados/tests_results.txt", "a");

  print_and_write(arquivo, "Execution Time: %.6f seconds [Filling Catalogs + Queries Tests]\n",
                  elapsed_time + elapsed_time_catalogs);
  fclose(arquivo);

  printf(
      "A file [tests_results.txt] has been generated in the Resultados directory for you to review the test "
      "results!\n\n");

  printf("Press enter to exit!\n");
  getchar();
  return 0;
}

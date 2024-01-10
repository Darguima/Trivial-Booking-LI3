#include <stdio.h>
#include "catalog_filler/catalog_filler.h"
#include "catalogs_creator/catalogs_creator.h"
#include "output/batch.h"
#include "output/interactive.h"
#include "sys/resource.h"
#include "utils/print_invalid_path_error.h"

int main(int argc, char** argv) {
  struct timespec start, end;
  double elapsed;
  // Start time
  clock_gettime(CLOCK_REALTIME, &start);

  if (argc != 1 && argc != 3) {
    printf("Your arguments are wrong!\n");
    printf("You passed %d arguments.\n", argc - 1);
    printf("For interactive mode dont't pass any argument.\n");
    printf("For batch mode pass 2 arguments:\n");
    printf("\t- the dataset folder path\n");
    printf("\t- the queries file path\n");
    fprintf(stderr, "[ERROR] - Invalid params\n");
    return -1;
  }

  char* dataset_folder_path;
  if (argc == 1) {
    // ask user the input - 2nd phase
    dataset_folder_path = "./dataset/data";
  } else {
    dataset_folder_path = argv[1];
  }

  printf("[INFO] - Dataset folder path: %s\n", dataset_folder_path);

  char* queries_file_path = "not needed";
  if (argc == 3) {
    queries_file_path = argv[2];
  }

  printf("[INFO] - Queries file path: %s\n", queries_file_path);

  Catalogs catalogs = catalogs_creator();

  int catalog_fill_status = catalog_filler(dataset_folder_path, catalogs);
  if (catalog_fill_status == -1) {
    print_invalid_path_error("dataset");
    free_catalogs(catalogs);
    return -1;
  }

  if (argc == 3) {
    int batch_exit_code = batch(queries_file_path, catalogs);

    if (batch_exit_code == -1) {
      print_invalid_path_error("queries file");
      free_catalogs(catalogs);
      return -1;
    }

  } else if (argc == 1) {
    interactive();
  }

  struct rusage r_usage_end;
  getrusage(RUSAGE_SELF, &r_usage_end);

  // Calcular e imprimir o uso total de memória
  long memory_used_kb = r_usage_end.ru_maxrss;
  printf("Total memory used: %ld KB\n", memory_used_kb);

  free_catalogs(catalogs);

  clock_gettime(CLOCK_REALTIME, &end);
  // Elapsed time
  elapsed = (double)(end.tv_sec - start.tv_sec) + ((double)(end.tv_nsec - start.tv_nsec)) / 1e9;
  printf("Elapsed time: %.6f seconds\n", elapsed);

  return 0;
}
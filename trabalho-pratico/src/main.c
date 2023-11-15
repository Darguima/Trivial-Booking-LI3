#include <stdio.h>
#include "catalog_filler/catalog_filler.h"
#include "catalogs_creator/catalogs_creator.h"
#include "datatypes/datatypes.h"
#include "output/batch.h"
#include "output/interactive.h"

int main(int argc, char** argv) {
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
    fprintf(stderr, "[ERROR] - Invalid dataset path\n");
    free_catalogs(catalogs);
    return -1;
  }

  if (argc == 3) {
    batch(queries_file_path, catalogs);
    printf("Args: '%s' & '%s'.\n", argv[1], argv[2]);
  } else if (argc == 1) {
    interactive();
  }

  free_catalogs(catalogs);

  return 0;
}
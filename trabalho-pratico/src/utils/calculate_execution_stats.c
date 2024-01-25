#include <stdio.h>
#include <sys/resource.h>
#include <time.h>
#include "utils/print_and_write.h"

clock_t start_timer() {
  return clock();
}

double stop_timer(clock_t start_time) {
  clock_t end_time = clock();
  double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  return elapsed_time;
}

void calculate_memory_usage() {
  struct rusage r_usage;
  getrusage(RUSAGE_SELF, &r_usage);
  FILE* arquivo = fopen("./Resultados/tests_results.txt", "a");
  print_and_write(arquivo, "Memory usage: %ld KB\n", r_usage.ru_maxrss);
  fclose(arquivo);
}
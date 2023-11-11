#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parse_line(char* line, int max_size) {
  char** line_elements = malloc(sizeof(char*) * max_size);
  int i = 0;
  char* string;

  while ((string = strsep(&line, ";")) != NULL) {
    line_elements[i] = string;
    i++;
  }

  return (line_elements);
}

void file_parser(FILE* file, int max_size) {
  char* line = NULL;
  size_t line_size = 0;

  getline(&line, &line_size,
          file);  // necessário para avançar a primeira linha , onde está o
                  // identificador de cada "elemento"

  while (getline(&line, &line_size, file) != -1) {
    int line_len = strlen(line);
    line[line_len - 1] = '\0';  // ultimo char da linha será um \0
    char** line_elements = parse_line(line, max_size);
    // build(line_elements, catalog) a partir daqui ja temos os elementos
    // separados , agora temos de chamar a funcao para adicionar estes elementos
    // na respectiva hash table, desde que corretamente validados.
    free(line_elements);
  }

  free(line);
}
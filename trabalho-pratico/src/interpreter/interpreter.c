#include <stdbool.h>
#include <stdio.h>
#include "queries/query_1.h"
#include "queries/query_10.h"
#include "queries/query_2.h"
#include "queries/query_3.h"
#include "queries/query_4.h"
#include "queries/query_5.h"
#include "queries/query_6.h"
#include "queries/query_7.h"
#include "queries/query_8.h"
#include "queries/query_9.h"

#include <datatypes/datatypes.h>

char** tokenizer(char* line, int* params_array_length) {
  size_t length = strlen(line);
  char** pointers_list = malloc(sizeof(char*) * length);

  int pointers_list_length = 0;

  int i = 0;
  if (line[0] != ' ' && line[0] != '\0') {
    pointers_list[0] = line;  // line ou &(line[0])
    pointers_list_length++;
    i++;
  }

  while (line[i] != '\0') {
    if (line[i] == ' ') {
      line[i] = '\0';  // replace spaces with \0

      if (line[i + 1] != ' ' && line[i + 1] != '\0') {
        pointers_list[pointers_list_length] = &(line[i + 1]);
        pointers_list_length++;
      }
    }
    i++;
  }

  // Clean memory allocated to array
  // Parse to ""

  (*params_array_length) = pointers_list_length;
  return pointers_list;
}

int interpreter(char* batch_line, int command_number, Catalogs CATALOGS) {
  int params_array_length = 0;
  // string de strings que contém os parametros a usar
  char** tokenized_params = tokenizer(batch_line, &params_array_length);

  int query_number;
  char field_string[3];  // este char vai ser "  " ou "F "

  sscanf(batch_line, "%d %2s", &query_number,
         field_string);  // copia os números para query_number e dois chars para field_string

  bool has_f = field_string[0] == 'F';  // compara-se pois esse valor só pode ser 'F' ou ' '

  switch (query_number) {
    case 1:
      query_1(CATALOGS, command_number, has_f, tokenized_params[1]);
      break;
    case 2:
      query_2(CATALOGS, command_number, has_f, tokenized_params[1],
              params_array_length == 3 ? tokenized_params[2] : NULL);
      break;
    case 3:
      query_3(CATALOGS, command_number, has_f, tokenized_params[1]);
      break;
    case 4:
      query_4(CATALOGS, command_number, has_f, tokenized_params[1]);
      break;
    case 5:
      query_5(CATALOGS, command_number, has_f, tokenized_params[1], tokenized_params[2], tokenized_params[3]);
      break;
    case 6:
      query_6(CATALOGS, command_number, has_f, tokenized_params[1], tokenized_params[2]);

      break;
      // case 7:
      //   break;
      // case 8:
      //   break;
      // case 9:
      //   break;
      // case 10:
      //   break;
  }

  free(tokenized_params);

  return 0;
}
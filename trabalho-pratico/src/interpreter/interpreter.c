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
#include "state/state.h"

#include <catalogs_creator/catalogs_creator.h>

/**
 * @brief Tokenizes the input line into an array of pointers to tokens
 *
 * This function tokenizes the input line based on spaces and double quotes.
 * It modifies the input line in place and returns an array of pointers to tokens.
 *
 * @param line The input line to be tokenized
 * @param params_array_length Pointer to an integer where the length of the resulting array will be stored
 * @return char** Array of pointers to the tokens extracted from the input line
 */
char** tokenizer(char* line, int* params_array_length) {
  size_t length = strlen(line);
  char** pointers_list = malloc(sizeof(char*) * length);

  int pointers_list_length = 0;
  bool in_aspas = false;

  int i = 0;
  if (line[0] != ' ' && line[0] != '\0') {
    pointers_list[0] = line;  // line ou &(line[0])
    pointers_list_length++;
    i++;
  }

  // 5 LIS "begin  date" "this is end   date"
  // tem de dividir isto na lista de apontadores(*5, *b, *t)
  // o *b aponta para begin  date e o *t aponta para  this is end   date

  while (line[i] != '\0') {
    if (line[i] == '\"') {
      in_aspas = !in_aspas;
      line[i] = '\0';
      i++;
      continue;
    }

    if (line[i] == ' ' && !in_aspas) {
      line[i] = '\0';
      i++;
      continue;
    }

    if (line[i - 1] == '\0') {
      pointers_list[pointers_list_length] = &(line[i]);
      pointers_list_length++;
    }
    i++;
  }

  (*params_array_length) = pointers_list_length;

  char** tokenized = malloc(sizeof(char*) * ((long unsigned int)pointers_list_length + 1));
  for (int j = 0; j < pointers_list_length; j++) {
    tokenized[j] = pointers_list[j];
  }

  free(pointers_list);

  return tokenized;
}

int interpreter(char* batch_line, int command_number, Catalogs CATALOGS, State state) {
  int params_array_length = 0;
  // string de strings que contém os parametros a usar
  char** tokenized_params = tokenizer(batch_line, &params_array_length);

  int query_number;

  char field_string[3] = "__";  // este char vai ser "  " ou "F "

  sscanf(batch_line, "%d %2s", &query_number, field_string);
  // copia os números para query_number e dois chars para field_string

  bool has_f = field_string[0] == 'F';
  // compara-se pois esse valor só pode ser 'F' ou ' '

  switch (query_number) {
    case 1:
      if (params_array_length != 2) {
        break;
      }
      query_1(CATALOGS, command_number, has_f, tokenized_params[1], state);
      break;
    case 2:
      if (params_array_length < 2 || params_array_length > 3) {
        break;
      }
      query_2(CATALOGS, command_number, has_f, tokenized_params[1],
              params_array_length == 3 ? tokenized_params[2] : NULL, state);
      break;
    case 3:
      if (params_array_length != 2) {
        break;
      }
      query_3(CATALOGS, command_number, has_f, tokenized_params[1], state);
      break;
    case 4:
      if (params_array_length != 2) {
        break;
      }
      query_4(CATALOGS, command_number, has_f, tokenized_params[1], state);
      break;
    case 5:
      if (params_array_length != 4) {
        break;
      }
      query_5(CATALOGS, command_number, has_f, tokenized_params[1], tokenized_params[2], tokenized_params[3], state);
      break;
    case 6:
      if (params_array_length != 2) {
        break;
      }
      query_6(CATALOGS, command_number, has_f, tokenized_params[1], tokenized_params[2], state);

      break;
    case 7:
      if (params_array_length != 2) {
        break;
      }
      query_7(CATALOGS, command_number, has_f, tokenized_params[1], state);
      break;
    case 8:
      if (params_array_length != 4) {
        break;
      }
      query_8(CATALOGS, command_number, has_f, tokenized_params[1], tokenized_params[2], tokenized_params[3], state);
      break;
    case 9:
      if (params_array_length != 2) {
        break;
      }
      query_9(CATALOGS, command_number, has_f, tokenized_params[1], state);
      break;
    case 10:
      if (params_array_length > 3) {
        break;
      }
      query_10(CATALOGS, command_number, has_f, params_array_length >= 2 ? tokenized_params[1] : NULL,
               params_array_length == 3 ? tokenized_params[3] : NULL, state);
      break;
  }

  free(tokenized_params);

  return 0;
}
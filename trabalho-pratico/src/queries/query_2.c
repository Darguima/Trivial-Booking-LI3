#include <datatypes/datatypes.h>
#include <stdbool.h>
#include <stdio.h>
#include "write_output/write_output.h"

char* extract_date_without_time(const char* date_with_time) {
  char* space_position = strchr(date_with_time, ' ');
  if (space_position != NULL) {
    size_t date_length = (size_t)(space_position - date_with_time);
    char* date_only = (char*)malloc(date_length + 1);
    if (date_only != NULL) {
      strncpy(date_only, date_with_time, date_length);
      date_only[date_length] = '\0';

      return date_only;
    } else {
      fprintf(stderr, "Error allocating memory!\n");
      return NULL;
    }
  }
  return NULL;
}
// temos 3 casos , vamos ter o caso de apenas ser flight , apenas ser reservations ou ambos. para flights criar uma
// funcao q vai buscar os flights e os compara por data (ignorando segundos e minutos etc) ou por reservas ou ambos,
// criando uma struct com tipo, begin date e id. para datas sem segundos e minutos e horas
// na query 4 do number to string , dando free depois no fim , ou seja char * new time = extract_date_without_time
// (flight->...) no fim do print no ficheiro , dar free do new time

int query_2(Catalogs CATALOGS, int command_number, bool format_flag, char* id, char* optional) {
  FILE* output_file = create_output_file(command_number);

  UNUSED(CATALOGS);
  // UNUSED(command_number);
  UNUSED(format_flag);
  UNUSED(id);
  UNUSED(optional);
  fclose(output_file);

  return 0;
}
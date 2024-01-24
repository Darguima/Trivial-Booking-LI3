#include <ncurses.h>
#include "catalogs_creator/catalogs_creator.h"

#ifndef ___State_H___
#define ___State_H___

#define MAX_PATH_LENGTH 200
#define MAX_INPUT_LENGTH 50
#define MAX_STRINGS 1000
#define MAX_STRING_LENGTH 200
typedef enum scene {
  Menu,
  Input,
  Erase_Path,
  Valid_Path,
  Invalid_Path,
  Erase_Input,
  Loading_Input,
  Results,
  Prev_Results,
  Next_Results,
  Help,
  Help_Info_Input,
  Query_1,
  Query_2,
  Query_3,
  Query_4,
  Query_5,
  Query_6,
  Query_7,
  Query_8,
  Query_9,
  Query_10,
  About,
  Exit,
} Scene;

typedef struct state {
  Scene sceneAtual;
  WINDOW* ncurses_screen;
  char userPath[MAX_PATH_LENGTH];
  char userInput[MAX_INPUT_LENGTH];
  Catalogs catalog;
  char results[MAX_STRINGS][MAX_STRING_LENGTH];
  int results_count;  // numero de resultados escritos até ao momento
  int pages;          // numero maximo de paginas quando forem dados os resultados
  int current_page;
  int results_per_page;  // resultados mostrados por cada pagina para ajudar na paginação

} State;

State create_state(WINDOW* window);

#endif

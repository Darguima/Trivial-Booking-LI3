#include "state/state.h"
#include <ncurses.h>
#include <string.h>

#define UNUSED(x) (void)(x)

State create_state(WINDOW* window) {
  UNUSED(window);
  State state;
  state.sceneAtual = Menu;
  strcpy(state.userPath, "");
  strcpy(state.userInput, "");
  state.catalog = catalogs_creator();

   for (int i = 0; i < MAX_STRINGS; i++) {
    memset(state.resultss[i], 0, sizeof(state.results[i]));
  }

  return state;
}

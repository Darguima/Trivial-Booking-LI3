#include "state/state.h"
#include <ncurses.h>
#include <string.h>
#include "catalogs_creator/catalogs_creator.h"

#define UNUSED(x) (void)(x)

State create_state(WINDOW* window) {
  UNUSED(window);
  State state;
  state.sceneAtual = Menu;
  strcpy(state.userPath, "");
  strcpy(state.userInput, "");
  state.catalog = catalogs_creator();

  for (int i = 0; i < MAX_STRINGS; i++) {
    memset(state.results[i], 0, sizeof(state.results[i]));
  }

  return state;
}

void free_state(State* state) {
  free_catalogs(state->catalog);

  for (int i = 0; i < MAX_STRINGS; i++) {
    // Libere cada string dentro do array de resultados
    free(state->results[i]);
  }
}

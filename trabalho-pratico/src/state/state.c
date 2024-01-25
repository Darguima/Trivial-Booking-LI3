#include "state/state.h"
#include <ncurses.h>
#include <string.h>
#include "catalogs_creator/catalogs_creator.h"
#include "write_output/write_output.h"
#include <stdlib.h>

#define UNUSED(x) (void)(x)

State create_state(WINDOW* window) {
  UNUSED(window);

  State state = malloc(sizeof(struct state));

  state->sceneAtual = Menu;
  state->user_path = NULL;
  state->user_input = NULL;
  state->catalog = catalogs_creator();
  state->results = g_array_new(FALSE, FALSE, sizeof(output_key_value));

  return state;
}

void free_state(State state) {
  free_catalogs(state->catalog);
  g_array_free(state->results, TRUE);
  free(state->user_path);
  free(state->user_input);
}

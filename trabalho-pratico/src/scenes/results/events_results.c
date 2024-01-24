#include <ncurses.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void events_results(State* state) {
  int key = getch();

  switch (key) {
    case 27:
      state->sceneAtual = Menu;
      break;

    case KEY_LEFT:
      state->sceneAtual = Prev_Results;
      break;

    case KEY_RIGHT:
      state->sceneAtual = Next_Results;
      break;
  }
}
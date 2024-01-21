#include <ncurses.h>
#include <stdlib.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void eventosSair(State* state) {
  UNUSED(state);

  int key = getch();

  switch (key) {
    case 'm':
      state->sceneAtual = Menu;
      break;

    case 'q':
      endwin();
      exit(0);
      break;
  }
}
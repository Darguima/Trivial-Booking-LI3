#include <ncurses.h>
#include <stdlib.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void eventosSair(State* state) {
  UNUSED(state);

  int key = getch();

  switch (key) {
    case 'M':
    case 'm':
      state->sceneAtual = Menu;
      break;
    case 'Q':
    case 'q':
      endwin();
      exit(0);
      break;
  }
}
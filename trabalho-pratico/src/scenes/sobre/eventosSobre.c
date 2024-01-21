#include <ncurses.h>
#include "state/state.h"

void eventosSobre(State* state) {
  int key = getch();

  switch (key) {
    case 'm':
      state->sceneAtual = Menu;
      break;
  }
}
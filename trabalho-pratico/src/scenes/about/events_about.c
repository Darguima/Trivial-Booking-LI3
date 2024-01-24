#include <ncurses.h>
#include "state/state.h"

void events_about(State* state) {
  int key = getch();

  switch (key) {
    case 27:
      state->sceneAtual = Menu;
      break;
  }
}
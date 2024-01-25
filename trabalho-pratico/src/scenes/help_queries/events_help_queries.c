#include <ncurses.h>
#include "state/state.h"

void events_help_queries(State state) {
  int key = getch();

  switch (key) {
    case 27:
      state->sceneAtual = Help;
      break;
  }
}
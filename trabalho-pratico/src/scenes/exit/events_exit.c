#include <ncurses.h>
#include <stdlib.h>
#include "state/state.h"
#define UNUSED(x) (void)(x)

void events_exit(WINDOW* window, State state) {
  UNUSED(state);

  int key = getch();

  switch (key) {
    case 27:
      state->sceneAtual = Menu;
      break;
    case KEY_ENTER:
    case '\n':
    case '\r':
      free_state(state);
      endwin();
      delwin(window);
      exit(0);
      break;
  }
}
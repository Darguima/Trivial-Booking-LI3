#include <ncurses.h>
#include "state/state.h"

void events_menu(State* state) {
  int key = getch();

  switch (key) {
    case '1':
      state->sceneAtual = Input;
      break;

    case '2':
      state->sceneAtual = Help;
      break;

    case '3':
      state->sceneAtual = About;
      break;

    case '4':
    case 'q':
    case 'Q':
      state->sceneAtual = Exit;
      break;
  }
}

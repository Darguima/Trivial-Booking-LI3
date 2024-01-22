#include <ncurses.h>
#include "state/state.h"

void eventosMenu(State* state) {
  int key = getch();

  switch (key) {
    case '1':
      state->sceneAtual = Input;
      break;

    case '2':
      state->sceneAtual = Ajuda;
      break;

    case '3':
      state->sceneAtual = Sobre;
      break;

    case '4':
    case 'q':
    case 'Q':
      state->sceneAtual = Sair;
      break;
  }
}
#include <ncurses.h>
#include "state/state.h"

void eventosAjudaQueries(State* state) {
  int key = getch();

  switch (key) {
    case 'M':
    case 'm':
      state->sceneAtual = Ajuda;
      break;
  }
}
#include "state/state.h"
#include <ncurses.h>

#define UNUSED(x) (void)(x)

State criarEstado(WINDOW* window) {
  UNUSED(window);
  State state;
  state.sceneAtual = Menu;

  return state;
}

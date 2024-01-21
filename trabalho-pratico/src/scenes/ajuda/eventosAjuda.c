#include <ncurses.h>
#include <stdlib.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void eventosAjuda(State* state) {
  UNUSED(state);

  int key = getch();

  switch (key) {
    case 'm':
      state->sceneAtual = Menu;
      break;
    case 'i':
      state->sceneAtual = AjudaInfoInput;
      break;
    case '1':
      state->sceneAtual = Query1;
      break;
    case '2':
      state->sceneAtual = Query2;
      break;
    case '3':
      state->sceneAtual = Query3;
      break;
    case '4':
      state->sceneAtual = Query4;
      break;
    case '5':
      state->sceneAtual = Query5;
      break;
    case '6':
      state->sceneAtual = Query6;
      break;
    case '7':
      state->sceneAtual = Query7;
      break;
    case '8':
      state->sceneAtual = Query8;
      break;
    case '9':
      state->sceneAtual = Query9;
      break;
    case '0':
      state->sceneAtual = Query10;
      break;
  }
}
#include <ncurses.h>
#include <stdlib.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void events_help(State state) {
  UNUSED(state);

  int key = getch();

  switch (key) {
    case 27:
      state->sceneAtual = Menu;
      break;
    case 'I':
    case 'i':
      state->sceneAtual = Help_Info_Input;
      break;
    case '1':
      state->sceneAtual = Query_1;
      break;
    case '2':
      state->sceneAtual = Query_2;
      break;
    case '3':
      state->sceneAtual = Query_3;
      break;
    case '4':
      state->sceneAtual = Query_4;
      break;
    case '5':
      state->sceneAtual = Query_5;
      break;
    case '6':
      state->sceneAtual = Query_6;
      break;
    case '7':
      state->sceneAtual = Query_7;
      break;
    case '8':
      state->sceneAtual = Query_8;
      break;
    case '9':
      state->sceneAtual = Query_9;
      break;
    case '0':
      state->sceneAtual = Query_10;
      break;
  }
}
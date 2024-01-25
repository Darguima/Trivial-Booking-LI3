#include <ncurses.h>
#include <string.h>
#include "interpreter/interpreter.h"
#include "state/state.h"

#define MAX_PATH_LENGTH 200

void events_user_input(State state) {
  int key = getch();

  switch (key) {
    case 27:
      state->sceneAtual = Menu;

      break;
    case KEY_ENTER:
    case '\n':
    case '\r':
      interpreter(state->user_input, 1, state->catalog, state);
      state->sceneAtual = Results;
      break;

    case KEY_BACKSPACE:
    case 127:
      if (strlen(state->user_input) > 0) {
        state->user_input[strlen(state->user_input) - 1] = '\0';
      }
      state->sceneAtual = Erase_Input;
      break;

    default:
      if (strlen(state->user_input) < MAX_PATH_LENGTH - 1) {
        strncat(state->user_input, (const char*)&key, 1);
      }
      break;
  }
}
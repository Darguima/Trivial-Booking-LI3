#include <ncurses.h>
#include <string.h>
#include "interpreter/interpreter.h"
#include "state/state.h"

#define MAX_PATH_LENGTH 200

void events_user_input(State* state) {
  int key = getch();

  switch (key) {
    case 27:
      memset(state->userInput, 0, sizeof(state->userInput));
      memset(state->userInput, 0, sizeof(state->userPath));
      state->sceneAtual = Menu;

      break;
    case KEY_ENTER:
    case '\n':
    case '\r':
      interpreter(state->userInput, 1, state->catalog, state);
      state->sceneAtual = Results;
      break;

    case KEY_BACKSPACE:
    case 127:
      if (strlen(state->userInput) > 0) {
        state->userInput[strlen(state->userInput) - 1] = '\0';
      }
      state->sceneAtual = Erase_Input;
      break;

    default:
      if (strlen(state->userInput) < MAX_PATH_LENGTH - 1) {
        strncat(state->userInput, (const char*)&key, 1);
      }
      break;
  }
}
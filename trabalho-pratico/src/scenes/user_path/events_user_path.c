#include <ncurses.h>
#include <string.h>
#include "catalog_filler/catalog_filler.h"
#include "state/state.h"

#define MAX_PATH_LENGTH 200

void events_user_path(State* state) {
  int catalog_fill_status;

  int key = getch();

  switch (key) {
    case 27:
      memset(state->userPath, 0, sizeof(state->userPath));
      memset(state->userPath, 0, sizeof(state->userInput));
      state->sceneAtual = Menu;

      break;

    case KEY_ENTER:
    case '\n':
    case '\r':
      catalog_fill_status = catalog_filler(state->userPath, state->catalog);
      if (catalog_fill_status == -1) {
        state->sceneAtual = Invalid_Path;
      } else {
        state->sceneAtual = Valid_Path;
      }

      break;

    case KEY_BACKSPACE:
    case 127:
      if (strlen(state->userPath) > 0) {
        state->userPath[strlen(state->userPath) - 1] = '\0';
      }
      state->sceneAtual = Erase_Path;
      break;

    default:
      if (strlen(state->userPath) < MAX_PATH_LENGTH - 1) {
        strncat(state->userPath, (const char*)&key, 1);
      }
      break;
  }
}
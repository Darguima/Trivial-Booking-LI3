#include <ncurses.h>
#include <string.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void draw_user_path(WINDOW* window, State* state, int evento) {
  UNUSED(window);

  int nrows, ncols;
  getmaxyx(window, nrows, ncols);

  int y = (nrows / 2) - 4;
  int x = (ncols / 2) - 2;

  box(window, 0, 0);

  mvprintw(2, 3, "  ___                   _   ");
  mvprintw(3, 3, " |_ _|_ __  _ __  _   _| |_ ");
  mvprintw(4, 3, "  | || '_ \\| '_ \\| | | | __|");
  mvprintw(5, 3, "  | || | | | |_) | |_| | |_ ");
  mvprintw(6, 3, " |___|_| |_| .__/ \\__,_|\\__|");
  mvprintw(7, 3, "           |_|              ");

  mvaddstr(y, x - 17, "Insere um path para o dataset pretendido");

  switch (evento) {
    case 0:  //
      mvprintw(y + 5, x - 5, "Path inserido: %s", state->userPath);
      break;
    case 1:  // indica um path invalido
      mvprintw(y + 5, x - 5, "Path inserido: %s", state->userPath);
      mvprintw(y + 6, x - 5, "Path invalido");
      break;
    case 2:  // apaga
      mvprintw(y + 5, x - 5, "Path inserido: %s   ", state->userPath);
      break;
  }

  mvprintw(nrows - 4, 2, "Pressiona [Enter] quando acabares de inserir o path");
  mvprintw(nrows - 2, 2, "Pressiona [ESC] para voltar ao menu anterior");
}
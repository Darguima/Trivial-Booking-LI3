#include <ncurses.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void desenhaSair(WINDOW* window, State* state) {
  UNUSED(window);
  UNUSED(state);

  int nrows, ncols;
  getmaxyx(window, nrows, ncols);

  int y = (nrows / 2) - 4;
  int x = (ncols / 2) - 2;

  box(window, 0, 0);

  mvaddstr(y, x - 4, "Desejas sair?");

  mvprintw(2, 3, "  ____        _      ");
  mvprintw(3, 3, " / ___|  __ _(_)_ __ ");
  mvprintw(4, 3, " \\___ \\ / _` | | '__|");
  mvprintw(5, 3, "  ___) | (_| | | |   ");
  mvprintw(6, 3, " |____/ \\__,_|_|_|   ");

  mvaddstr(nrows - 4, 2, "Pressiona [Q] para sair");
  mvaddstr(nrows - 2, 2, "Pressiona [M] para voltar ao menu anterior");
}

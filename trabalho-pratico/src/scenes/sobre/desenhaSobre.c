#include <ncurses.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void desenhaSobre(WINDOW* window, State* state) {
  UNUSED(window);
  UNUSED(state);

  int nrows, ncols;
  getmaxyx(window, nrows, ncols);

  int y = (nrows / 2) - 4;
  int x = (ncols / 2) - 2;

  box(window, 0, 0);

  mvwprintw(window, y - 1, x - 20, "Trivial Booking e uma app top");
  mvwprintw(window, y, x - 20, "Feita na linguagem de programacao C");

  mvprintw(2, 3, "  ____        _              ");
  mvprintw(3, 3, " / ___|  ___ | |__  _ __ ___ ");
  mvprintw(4, 3, " \\___ \\ / _ \\| '_ \\| '__/ _ \\ ");
  mvprintw(5, 3, "  ___) | (_) | |_) | | |  __/");
  mvprintw(6, 3, " |____/ \\___/|_.__/|_|  \\___|");

  mvwprintw(window, y + 8, x - 12, "Dario Guimaraes      Afonso Pedreira");
  mvwprintw(window, y + 10, x - 12, "Hugo Rauber    ");

  mvaddstr(nrows - 2, 2, "Pressiona [M] para voltar ao menu anterior");
}
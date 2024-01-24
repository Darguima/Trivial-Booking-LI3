#include <ncurses.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void draw_about(WINDOW* window, State* state) {
  UNUSED(window);
  UNUSED(state);

  int nrows, ncols;
  getmaxyx(window, nrows, ncols);

  int y = (nrows / 2);
  int x = (ncols / 2);

  box(window, 0, 0);

  mvwprintw(window, y - 1, x - 24, "Trivial Booking e um sistema de booking no qual");
  mvwprintw(window, y, x - 29, "o utilizador pode inserir inputs atraves de uma interface.");
  mvwprintw(window, y + 2, x - 18, "Feito em linguagem de programacao C.");

  mvprintw(2, 3, "  ____        _              ");
  mvprintw(3, 3, " / ___|  ___ | |__  _ __ ___ ");
  mvprintw(4, 3, " \\___ \\ / _ \\| '_ \\| '__/ _ \\ ");
  mvprintw(5, 3, "  ___) | (_) | |_) | | |  __/");
  mvprintw(6, 3, " |____/ \\___/|_.__/|_|  \\___|");

  mvwprintw(window, y + 8, x - 18, "Dario Guimaraes      Afonso Pedreira");
  mvwprintw(window, y + 10, x - 5, "Hugo Rauber");

  mvaddstr(nrows - 2, 2, "Pressiona [ESC] para voltar ao menu anterior");
}
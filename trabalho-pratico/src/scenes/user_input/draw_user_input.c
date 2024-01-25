#include <math.h>
#include <ncurses.h>
#include <string.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void draw_user_input(WINDOW* window, State state, int evento) {
  UNUSED(window);

  int nrows, ncols;
  getmaxyx(window, nrows, ncols);

  int y = (nrows / 2);
  int x = (ncols / 2);

  box(window, 0, 0);

  mvprintw(2, 3, "  ___                   _   ");
  mvprintw(3, 3, " |_ _|_ __  _ __  _   _| |_ ");
  mvprintw(4, 3, "  | || '_ \\| '_ \\| | | | __|");
  mvprintw(5, 3, "  | || | | | |_) | |_| | |_ ");
  mvprintw(6, 3, " |___|_| |_| .__/ \\__,_|\\__|");
  mvprintw(7, 3, "           |_|              ");

  mvaddstr(y, x - 17, "Aqui deves inserir um input valido");
  mvaddstr(y + 1, x - 29, "Para informacoes sobre as queries, vai ao menu (3.Sobre)");
  mvprintw(y + 3, x - 25, "Path: %s", state->user_path);
  mvprintw(y + 5, x - 20, "Introduz um input para as queries valido:");

  switch (evento) {
    case 0:
      mvprintw(y + 7, x - 5, "Input inserido: %s", state->user_input);
      break;
    case 1:
      mvprintw(y + 7, x - 5, "Input inserido: %s", state->user_input);
      mvprintw(y + 8, x - 5, "A carregar resultados");
      state->results_per_page = nrows - 6;
      state->pages = (int)ceil((double)state->results_per_page / state->results_count);
      break;
    case 2:  // apaga
      mvprintw(y + 7, x - 5, "Input inserido: %s   ", state->user_input);
      break;
  }

  mvprintw(nrows - 4, 2, "Pressiona [Enter] quando acabares de inserir o input");
  mvprintw(nrows - 2, 2, "Pressiona [ESC] para voltar ao menu anterior");
}
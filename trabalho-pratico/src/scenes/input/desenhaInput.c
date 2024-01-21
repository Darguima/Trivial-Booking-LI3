#include <ncurses.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void desenhaInput(WINDOW* window, State* state) {
  UNUSED(window);
  UNUSED(state);

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

  mvaddstr(y, x - 17, "Aqui vao aparecer informacoes sobre as queries");
  mvaddstr(y + 1, x - 25, "Um pequeno resumo do que cada uma faz e se tem ou nao, o bool F");
  mvaddstr(y + 3, x - 5, "Aqui e dado o input");

  mvaddstr(nrows - 2, 2, "Pressiona [M] para voltar ao menu anterior");
}

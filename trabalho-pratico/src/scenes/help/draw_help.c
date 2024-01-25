#include <ncurses.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void draw_help(WINDOW* window, State* state) {
  UNUSED(state);

  int nrows, ncols;
  getmaxyx(window, nrows, ncols);

  int y = (nrows / 2);
  int x = (ncols / 2);

  box(window, 0, 0);

  mvprintw(y - 8, x - 26, "Aqui podes consultar o que cada uma das 10 queries faz.");
  mvprintw(y - 6, x - 28, "Tambem podes perceber como trabalhar com o modo interactive.");
  mvprintw(y - 2, x - 10, "Queries disponiveis:");

  int queryNumber = 1;

  for (int i = 0; i < 5; ++i) {
    mvprintw(y + (i * 2) + 2, x - 20, "%d - Query %d", queryNumber, queryNumber);
    queryNumber++;
  }

  queryNumber = 6;

  for (int i = 0; i < 4; ++i) {
    mvprintw(y + (i * 2) + 2, x + 10, "%d - Query %d", queryNumber, queryNumber);
    queryNumber++;
  }

  mvprintw(y + 10, x + 10, "0 - Query %d", queryNumber);

  wrefresh(window);

  mvprintw(2, 3, "    _     _           _       ");
  mvprintw(3, 3, "   / \\   (_)_   _  __| | __ _ ");
  mvprintw(4, 3, "  / _ \\  | | | | |/ _` |/ _` |");
  mvprintw(5, 3, " / ___ \\ | | |_| | (_| | (_| |");
  mvprintw(6, 3, "/_/   \\_\\/ |\\__,_|\\__,_|\\__,_|");
  mvprintw(7, 3, "       |__/");

  mvprintw(nrows - 6, 2, "Pressiona [1]-[0] para ajuda com as queries");
  mvprintw(nrows - 4, 2, "Pressiona [I] para como inserir o input no modo interactive");
  mvprintw(nrows - 2, 2, "Pressiona [ESC] para voltar ao menu anterior");
}
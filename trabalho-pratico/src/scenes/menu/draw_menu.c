#include <ncurses.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void draw_menu(WINDOW* window, State state) {
  UNUSED(state);

  refresh();

  int nrows, ncols;
  getmaxyx(window, nrows, ncols);

  box(window, 0, 0);
  wrefresh(window);

  int y = nrows / 2;
  int x = ncols / 2;

  mvprintw(y - 11, x - 34, "  _____     _       _       _   ____              _    _                    ");
  mvprintw(y - 10, x - 34, " |_   _| __(_)_   _(_) __ _| | | __ )  ___   ___ | | _(_)_ __   __ _        ");
  mvprintw(y - 9, x - 34, "   | || '__| \\ \\ / / |/ _` | | |  _ \\ / _ \\ / _ \\| |/ / | '_ \\ / _` | ");
  mvprintw(y - 8, x - 34, "   | || |  | |\\ V /| | (_| | | | |_) | (_) | (_) |   <| | | | | (_| |      ");
  mvprintw(y - 7, x - 34, "   |_||_|  |_| \\_/ |_|\\__,_|_| |____/ \\___/ \\___/|_|\\_\\_|_| |_|\\__, |");
  mvprintw(y - 6, x - 34, "                                                                |___/       ");

  mvprintw(y, x - 9, "1.Escolher queries");
  mvprintw(y + 3, x - 4, "2.Ajuda");
  mvprintw(y + 6, x - 4, "3.Sobre");
  mvprintw(y + 9, x - 4, "4.Sair");
  mvprintw(nrows - 2, 2, "Seleciona a opcao com [1]-[4]");
}

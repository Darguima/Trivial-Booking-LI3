#include <ncurses.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void desenhaMenu(WINDOW* window, State* state) {
  UNUSED(state);

  int height = 10;
  int width = 30;

  refresh();

  box(window, 0, 0);
  wrefresh(window);

  int y = (LINES - height) / 2;
  int x = (COLS - width) / 2;

  mvprintw(y - 11, x - 22, "  _____     _       _       _   ____              _    _                    ");
  mvprintw(y - 10, x - 22, " |_   _| __(_)_   _(_) __ _| | | __ )  ___   ___ | | _(_)_ __   __ _        ");
  mvprintw(y - 9, x - 22, "   | || '__| \\ \\ / / |/ _` | | |  _ \\ / _ \\ / _ \\| |/ / | '_ \\ / _` | ");
  mvprintw(y - 8, x - 22, "   | || |  | |\\ V /| | (_| | | | |_) | (_) | (_) |   <| | | | | (_| |      ");
  mvprintw(y - 7, x - 22, "   |_||_|  |_| \\_/ |_|\\__,_|_| |____/ \\___/ \\___/|_|\\_\\_|_| |_|\\__, |");
  mvprintw(y - 6, x - 22, "                                                                |___/       ");

  mvprintw(y + 1, x + 5, "1.Escolher queries");
  mvprintw(y + 4, x + 10, "2.Ajuda");
  mvprintw(y + 7, x + 10, "3.Sobre");
  mvprintw(y + 10, x + 10, "4.Sair");
  mvprintw(LINES - 2, 2, "Seleciona a opcao com [1]-[4]");
}

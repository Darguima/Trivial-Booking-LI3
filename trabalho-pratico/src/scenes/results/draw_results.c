#include <ncurses.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void draw_results(WINDOW* window, State state, int page_pos) {
  int nrows, ncols;
  getmaxyx(window, nrows, ncols);
  UNUSED(ncols);
  box(window, 0, 0);

  switch (page_pos) {
    case -1:
      if (state->current_page > 0) {
        state->current_page--;
      }
      break;

    case 0:
    case 1:
      if (state->current_page < state->pages - 1) {
        state->current_page++;
      }
      break;
  }

  mvaddstr(nrows - 4, 2, "Pressiona as setas [LEFT]/[RIGHT] para mudar de pagina");
  mvaddstr(nrows - 2, 2, "Pressiona [ESC] para voltar ao menu principal");
}
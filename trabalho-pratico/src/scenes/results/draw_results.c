#include <ncurses.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void draw_results(WINDOW* window, State* state, int page_pos) {
  int nrows, ncols;
  getmaxyx(window, nrows, ncols);

  int y = (nrows / 2);
  int x = (ncols / 2);

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

  int start_idx = state->current_page * state->results_per_page;
  int end_idx = (state->current_page + 1) * state->results_per_page;
  end_idx = (end_idx > state->results_count) ? state->results_count : end_idx;

  for (int i = start_idx; i < end_idx; i++) {
    mvprintw(y + i - start_idx, x, "Result %d: %s", i + 1, state->results[i]);
  }

  mvaddstr(nrows - 4, 2, "Pressiona as setas [LEFT]/[RIGHT] para mudar de pagina");
  mvaddstr(nrows - 2, 2, "Pressiona [ESC] para voltar ao menu anterior");
}
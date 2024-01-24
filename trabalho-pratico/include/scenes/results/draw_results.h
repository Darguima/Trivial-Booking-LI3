#ifndef DRAW_RESULTS_H
#define DRAW_RESULTS_H

#include <ncurses.h>
#include "state/state.h"

void draw_results(WINDOW* window, State* state, int page_pos);

#endif
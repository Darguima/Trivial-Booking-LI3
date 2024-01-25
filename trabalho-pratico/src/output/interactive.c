#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "interpreter/interpreter.h"
#include "state/state.h"

#include "scenes/menu/draw_menu.h"
#include "scenes/menu/events_menu.h"

#include "scenes/help/draw_help.h"
#include "scenes/help/events_help.h"

#include "scenes/about/draw_about.h"
#include "scenes/about/events_about.h"

#include "scenes/exit/draw_exit.h"
#include "scenes/exit/events_exit.h"

#include "scenes/user_path/draw_user_path.h"
#include "scenes/user_path/events_user_path.h"

#include "scenes/user_input/draw_user_input.h"
#include "scenes/user_input/events_user_input.h"

#include "scenes/help_queries/draw_help_queries.h"
#include "scenes/help_queries/events_help_queries.h"

#include "scenes/results/draw_results.h"
#include "scenes/results/events_results.h"

int interactive() {
  printf("I'm in interactive\n");

  setlocale(LC_ALL, "");

  WINDOW* window = initscr();

  keypad(window, true);
  curs_set(0);
  cbreak();
  noecho();
  nonl();
  intrflush(stdscr, false);
  keypad(stdscr, true);

  State state = create_state(window);

  printf("teste: %d" ,state.sceneAtual);

  Scene sceneAnterior = state.sceneAtual;

  while (1) {
    if (state.sceneAtual != sceneAnterior) {
      werase(window);
      sceneAnterior = state.sceneAtual;
    }

    switch (state.sceneAtual) {
      case Menu:
        draw_menu(window, &state);
        events_menu(&state);
        break;

      case Help:
        draw_help(window, &state);
        events_help(&state);
        break;
      case Help_Info_Input:
        draw_help_queries(window, &state, 11);
        events_help_queries(&state);
        break;
      case Query_1:
        draw_help_queries(window, &state, 1);
        events_help_queries(&state);
        break;
      case Query_2:
        draw_help_queries(window, &state, 2);
        events_help_queries(&state);
        break;
      case Query_3:
        draw_help_queries(window, &state, 3);
        events_help_queries(&state);
        break;
      case Query_4:
        draw_help_queries(window, &state, 4);
        events_help_queries(&state);
        break;
      case Query_5:
        draw_help_queries(window, &state, 5);
        events_help_queries(&state);
        break;
      case Query_6:
        draw_help_queries(window, &state, 6);
        events_help_queries(&state);
        break;
      case Query_7:
        draw_help_queries(window, &state, 7);
        events_help_queries(&state);
        break;
      case Query_8:
        draw_help_queries(window, &state, 8);
        events_help_queries(&state);
        break;
      case Query_9:
        draw_help_queries(window, &state, 9);
        events_help_queries(&state);
        break;
      case Query_10:
        draw_help_queries(window, &state, 10);
        events_help_queries(&state);
        break;

      case Input:
        draw_user_path(window, &state, 0);
        events_user_path(&state);
        break;

      case Invalid_Path:
        draw_user_path(window, &state, 1);
        events_user_path(&state);
        break;

      case Erase_Path:
        draw_user_path(window, &state, 2);
        events_user_path(&state);
        break;

      case Valid_Path:  // quando o path é valido, inicializa o user input com 0(caso de inicialização)
        draw_user_input(window, &state, 0);
        events_user_input(&state);
        break;

      case Loading_Input:
        draw_user_input(window, &state, 1);
        events_user_input(&state);
        break;
        break;
      case Erase_Input:
        draw_user_input(window, &state, 2);
        events_user_input(&state);
        break;
      case Results:
        draw_results(window, &state, 0);
        events_results(&state);
        break;
      case Prev_Results:
        draw_results(window, &state, -1);
        events_results(&state);
        break;
      case Next_Results:
        draw_results(window, &state, 1);
        events_results(&state);
        break;
      case About:
        draw_about(window, &state);
        events_about(&state);
        break;

      case Exit:
        draw_exit(window, &state);
        events_exit(window, &state);
        break;
    }
    refresh();
    move(0, 0);
  }
  return 0;
}
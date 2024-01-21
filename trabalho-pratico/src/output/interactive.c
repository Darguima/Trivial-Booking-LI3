#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include "interpreter/interpreter.h"
#include "state/state.h"

#include "scenes/menu/desenhaMenu.h"
#include "scenes/menu/eventosMenu.h"

#include "scenes/ajuda/desenhaAjuda.h"
#include "scenes/ajuda/eventosAjuda.h"

#include "scenes/sobre/desenhaSobre.h"
#include "scenes/sobre/eventosSobre.h"

#include "scenes/sair/desenhaSair.h"
#include "scenes/sair/eventosSair.h"

#include "scenes/input/desenhaInput.h"
#include "scenes/input/eventosInput.h"

#include "scenes/ajudaQueries/desenhaAjudaQueries.h"
#include "scenes/ajudaQueries/eventosAjudaQueries.h"

int interactive() {
  printf("I'm in interactive (not ready)\n");

  setlocale(LC_ALL, "");

  WINDOW* window = initscr();

  keypad(window, true);
  curs_set(0);
  cbreak();
  noecho();
  nonl();
  intrflush(stdscr, false);
  keypad(stdscr, true);

  State state = criarEstado(window);

  Scene sceneAnterior = state.sceneAtual;

  while (1) {
    if (state.sceneAtual != sceneAnterior) {
      werase(window);
      sceneAnterior = state.sceneAtual;
    }

    switch (state.sceneAtual) {
      case Menu:
        desenhaMenu(window, &state);
        eventosMenu(&state);
        break;

      case Ajuda:
        desenhaAjuda(window, &state);
        eventosAjuda(&state);
        break;
      case AjudaInfoInput:
        desenhaAjudaQueries(window, &state, 11);
        eventosAjudaQueries(&state);
        break;
      case Query1:
        desenhaAjudaQueries(window, &state, 1);
        eventosAjudaQueries(&state);
        break;
      case Query2:
        desenhaAjudaQueries(window, &state, 2);
        eventosAjudaQueries(&state);
        break;
      case Query3:
        desenhaAjudaQueries(window, &state, 3);
        eventosAjudaQueries(&state);
        break;
      case Query4:
        desenhaAjudaQueries(window, &state, 4);
        eventosAjudaQueries(&state);
        break;
      case Query5:
        desenhaAjudaQueries(window, &state, 5);
        eventosAjudaQueries(&state);
        break;
      case Query6:
        desenhaAjudaQueries(window, &state, 6);
        eventosAjudaQueries(&state);
        break;
      case Query7:
        desenhaAjudaQueries(window, &state, 7);
        eventosAjudaQueries(&state);
        break;
      case Query8:
        desenhaAjudaQueries(window, &state, 8);
        eventosAjudaQueries(&state);
        break;
      case Query9:
        desenhaAjudaQueries(window, &state, 9);
        eventosAjudaQueries(&state);
        break;
      case Query10:
        desenhaAjudaQueries(window, &state, 10);
        eventosAjudaQueries(&state);
        break;

      case Input:
        desenhaInput(window, &state);
        eventosInput(&state);
        break;

      case Sobre:
        desenhaSobre(window, &state);
        eventosSobre(&state);
        break;

      case Sair:
        desenhaSair(window, &state);
        eventosSair(&state);
        break;
    }
    refresh();
    move(0, 0);
  }
  return 0;
}
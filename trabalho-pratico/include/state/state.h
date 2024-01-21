#include <ncurses.h>

#ifndef ___State_H___
#define ___State_H___

typedef enum scene {
  Menu,

  Input,
  Ajuda,
  AjudaInfoInput,
  Query1,
  Query2,
  Query3,
  Query4,
  Query5,
  Query6,
  Query7,
  Query8,
  Query9,
  Query10,
  Sobre,
  Sair,
} Scene;

typedef struct state {
  Scene sceneAtual;
  WINDOW* ncurses_screen;

} State;

State criarEstado(WINDOW* window);

#endif

#include <ncurses.h>
#include "state/state.h"

#define UNUSED(x) (void)(x)

void draw_help_queries(WINDOW* window, State* state, int query) {
  UNUSED(state);
  UNUSED(query);

  int nrows, ncols;
  getmaxyx(window, nrows, ncols);

  box(window, 0, 0);

  int innerHeight = 17;
  int innerWidth = 72;

  int innerStarty = (nrows - innerHeight) / 2;
  int innerStartx = (ncols - innerWidth) / 2;

  WINDOW* innerWin = newwin(innerHeight, innerWidth, innerStarty, innerStartx);

  box(innerWin, 0, 0);

  mvwprintw(innerWin, 7, 2, "COMANDO:");
  mvwprintw(innerWin, 10, 2, "OUTPUT:");

  switch (query) {
    case 1:
      mvwprintw(innerWin, 0, innerWidth / 2 - 5, " Query 1 ");
      mvwprintw(innerWin, 3, 2, "Lista o resumo de um utilizador, voo, ou reserva,");
      mvwprintw(innerWin, 4, 2, "consoante o identificador recebido por argumento.");
      mvwprintw(innerWin, 8, 2, "1 <ID>");
      mvwprintw(innerWin, 11, 2, "[User|Flight|Reservation]");

      break;
    case 2:
      mvwprintw(innerWin, 0, innerWidth / 2 - 5, " Query 2 ");
      mvwprintw(innerWin, 3, 2, "Lista os voos e/ou reservas de um utilizador,");
      mvwprintw(innerWin, 4, 2, "ordenados por data (da mais recente para a mais antiga).");
      mvwprintw(innerWin, 8, 2, "2 <ID> [flights|reservations]");
      mvwprintw(innerWin, 11, 2, "id;date[;type]");
      break;
    case 3:
      mvwprintw(innerWin, 0, innerWidth / 2 - 5, " Query 3 ");
      mvwprintw(innerWin, 3, 2, "Apresenta a classificacao media de um hotel,");
      mvwprintw(innerWin, 4, 2, "a partir do seu identificador.");
      mvwprintw(innerWin, 8, 2, "3 <ID>");
      mvwprintw(innerWin, 11, 2, "rating");
      break;
    case 4:
      mvwprintw(innerWin, 0, innerWidth / 2 - 5, " Query 4 ");
      mvwprintw(innerWin, 3, 2, "Lista as reservas de um hotel, ordenadas por data de inicio  ");
      mvwprintw(innerWin, 4, 2, "(da mais recente para a mais antiga).");
      mvwprintw(innerWin, 8, 2, "4 <ID>");
      mvwprintw(innerWin, 11, 2, "id;begin_date;end_date;user_id;rating;total_price");
      break;
    case 5:
      mvwprintw(innerWin, 0, innerWidth / 2 - 5, " Query 5 ");
      mvwprintw(innerWin, 3, 2, "Lista os voos com origem num dado aeroporto, entre duas datas,");
      mvwprintw(innerWin, 4, 2, "ordenados por data de partida estimada");
      mvwprintw(innerWin, 5, 2, "(da mais recente para a mais antiga).");
      mvwprintw(innerWin, 8, 2, "5 <Name> <Begin_date> <End_date>");
      mvwprintw(innerWin, 11, 2, "id;schedule_departure_date;destination;airline;plane_model");
      break;
    case 6:
      mvwprintw(innerWin, 0, innerWidth / 2 - 5, " Query 6 ");
      mvwprintw(innerWin, 3, 2, "Lista o top N aeroportos com mais passageiros,");
      mvwprintw(innerWin, 4, 2, "para um dado ano. ");
      mvwprintw(innerWin, 8, 2, "6 <Year> <N>");
      mvwprintw(innerWin, 11, 2, "name;passengers");
      break;
    case 7:
      mvwprintw(innerWin, 0, innerWidth / 2 - 5, " Query 7 ");
      mvwprintw(innerWin, 3, 2, "Lista o top N aeroportos com a maior mediana de atrasos");
      mvwprintw(innerWin, 4, 2, " ");
      mvwprintw(innerWin, 8, 2, "7 <N>");
      mvwprintw(innerWin, 11, 2, "name;median");
      break;
    case 8:
      mvwprintw(innerWin, 0, innerWidth / 2 - 5, " Query 8 ");
      mvwprintw(innerWin, 3, 2, "Apresenta a receita total de um hotel entre duas datas (inclusive), ");
      mvwprintw(innerWin, 4, 2, "a partir do seu identificador.");
      mvwprintw(innerWin, 8, 2, "8 <Id> <Begin_date> <End_date>");
      mvwprintw(innerWin, 11, 2, "revenue");
      break;
    case 9:
      mvwprintw(innerWin, 0, innerWidth / 2 - 5, " Query 9 ");
      mvwprintw(innerWin, 3, 2, "Lista todos os utilizadores cujo nome começa com o prefixo ");
      mvwprintw(innerWin, 4, 2, "passado por argumento, ordenados por nome (de forma crescente).");
      mvwprintw(innerWin, 8, 2, "9 <Prefix>");
      mvwprintw(innerWin, 11, 2, "id;name");
      break;
    case 10:
      mvwprintw(innerWin, 0, innerWidth / 2 - 5, " Query 10 ");
      mvwprintw(innerWin, 3, 2, "Apresenta varias metricas gerais da aplicacao.");
      mvwprintw(innerWin, 4, 2, " ");
      mvwprintw(innerWin, 8, 2, "10 [year [month]]");
      mvwprintw(innerWin, 11, 2, "(year|month|day);users;flights;passengers;unique_passengers;");
      mvwprintw(innerWin, 12, 2, "reservations");
      break;
    case 11:
      mvwprintw(innerWin, 0, innerWidth / 2 - 5, " Input ");
      mvwprintw(innerWin, 3, 2, "O input, no modo interactive, e semelhante ao que e feito no");
      mvwprintw(innerWin, 4, 2, "modo batch. E dada uma querie, argumentos para a mesma e");
      mvwprintw(innerWin, 5, 2, "o output sera dado consoante o que a query receber como argumento");
      mvwprintw(innerWin, 7, 2, "As informacoes sobre como funcionam as queries estao no menu");
      mvwprintw(innerWin, 8, 2, "anterior. E necessario fornecer um path para o dataset");
      mvwprintw(innerWin, 10, 2, "Ainda pode ser passada uma flag 'F', a seguir a query:  ");
      mvwprintw(innerWin, 11, 2, "<2F U000000001>, por exemplo,");
      mvwprintw(innerWin, 12, 2, "para que o output seja dado na forma de ' field: value '");
      mvwprintw(innerWin, 13, 2, "(NAO IMPLEMENTADO)");

      break;
  }

  wrefresh(window);
  wrefresh(innerWin);

  mvprintw(2, 3, " ___        __          ___                  _            ");
  mvprintw(3, 3, "|_ _|_ __  / _| ___    / _ \\ _   _  ___ _ __(_) ___  ___  ");
  mvprintw(4, 3, " | || '_ \\| |_ / _ \\  | | | | | | |/ _ \\ '__| |/ _ \\/ __| ");
  mvprintw(5, 3, " | || | | |  _| (_) | | |_| | |_| |  __/ |  | |  __/\\__ \\ ");
  mvprintw(6, 3, "|___|_| |_|_|  \\___/   \\__\\_\\\\__,_|\\___|_|  |_|\\___||___/ ");

  mvaddstr(nrows - 2, 2, "Pressiona [ESC] para voltar ao menu anterior");

  refresh();
}

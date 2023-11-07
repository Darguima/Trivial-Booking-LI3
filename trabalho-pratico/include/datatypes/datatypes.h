#include <time.h>

typedef enum { M, F } sex; //M- male, F- female

typedef enum { cash, credit_card, debit_card } pay_method;

typedef enum { active, inactive } account_status;

typedef struct usersSchema {
  char *id;
  char *name;
  char *email;
  char *phone_number; // verify if the size of an int is sufficient for phone number
  time_t birth_date;   // verify if dates are stored as numeric timestamp
  sex sex;
  char *passport;
  char *country_code;
  char *address;
  char *account_creation; // verify how should the date be stored
  pay_method pay_method;
  account_status account_status;
} UsersSchema;

typedef struct flightsSchema {
  int id;                         // identificador do voo;
  char *airline;                  // companhia aérea;
  char *plane_model;              // modelo do avião;
  int total_seats;                // número de lugares totais disponíveis;
  char *origin;                   // aeroporto de origem;
  char *destination;              // aeroporto de destino;
  time_t schedule_departure_date; // data e hora estimada de partida;
  time_t schedule_arrival_date;   // data e hora estimada de chegada;
  time_t real_departure_date;     // data e hora real de partida;
  time_t real_arrival_date;       // data e hora real de chegada;
  char *pilot;                    // nome do piloto;
  char *copilot;                  // nome do copiloto;
  char *notes;                    // observações sobre o voo.
} FlightsSchema;

typedef struct passengersSchema {
  int flight_id; // identificador do voo
  char *user_id; // identificador do utilizador
} PassengersSchema;

typedef struct reservationsSchema {
  char *id;                // identificador da reserva;
  char *user_id;           // identificador do utilizador;
  char *hotel_id;          // identificador do hotel;
  char *hotel_name;        // nome do hotel;
  int hotel_stars;         // número de estrelas do hotel;
  int city_tax;            // percentagem do imposto da cidade (sobre o valor total);
  char *address;           // morada do hotel;
  time_t begin_date;       // data de início;
  time_t end_date;         // data de fim;
  int price_per_night;     // preço por noite;
  bool includes_breakfast; // se a reserva inclui pequeno-almoço;
  char *room_details;      // detalhes sobre o quarto;
  int rating;              // classificação atribuída pelo utilizador;
  char *comment;           // comentário sobre a reserva.
} ReservationsSchema;
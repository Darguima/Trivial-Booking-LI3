#ifndef DATATYPES_H
#define DATATYPES_H

#include <glib.h>
#include <stdbool.h>
#include <time.h>

// Catalogs management

#define USERS_DATASET_COLUMNS 12
#define FLIGHTS_DATASET_COLUMNS 13
#define RESERVATIONS_DATASET_COLUMNS 14
#define PASSENGERS_DATASET_COLUMNS 2

typedef enum { USERS, FLIGHTS, PASSENGERS, RESERVATIONS } schema_name;

typedef struct catalogs {
  GHashTable* users;
  GHashTable* flights;
  GHashTable* passengers;
  GHashTable* reservations;
}* Catalogs;

// Catalogs Schemas

typedef enum { MALE, FEMALE } sex;

typedef enum { CASH, CREDIT_CARD, DEBIT_CARD } pay_method;

typedef enum { ACTIVE, INACTIVE } account_status;

typedef struct userSchema {
  char* id;                       // identificador do usuário;
  char* name;                     // nome;
  char* email;                    // email;
  char* phone_number;             // número de telemóvel;
  time_t birth_date;              // data de nascimento;
  sex sex;                        // sexo;
  char* passport;                 // passaporte;
  char* country_code;             // código de país;
  char* address;                  // endereço do usuário;
  time_t account_creation;        // data de criação da conta;
  pay_method pay_method;          // método de pagamento;
  account_status account_status;  // estado da conta;
}* UserSchema;

typedef struct flightSchema {
  int id;                          // identificador do voo;
  char* airline;                   // companhia aérea;
  char* plane_model;               // modelo do avião;
  int total_seats;                 // número de lugares totais disponíveis;
  char* origin;                    // aeroporto de origem;
  char* destination;               // aeroporto de destino;
  time_t schedule_departure_date;  // data e hora estimada de partida;
  time_t schedule_arrival_date;    // data e hora estimada de chegada;
  time_t real_departure_date;      // data e hora real de partida;
  time_t real_arrival_date;        // data e hora real de chegada;
  char* pilot;                     // nome do piloto;
  char* copilot;                   // nome do copiloto;
  char* notes;                     // observações sobre o voo.
}* FlightSchema;

typedef struct passengerSchema {
  int flight_id;  // identificador do voo
  char* user_id;  // identificador do utilizador
}* PassengerSchema;

typedef struct reservationSchema {
  char* id;           // identificador da reserva;
  char* user_id;      // identificador do utilizador;
  char* hotel_id;     // identificador do hotel;
  char* hotel_name;   // nome do hotel;
  int hotel_stars;    // número de estrelas do hotel;
  int city_tax;       // percentagem do imposto da cidade (sobre o valor total);
  char* address;      // morada do hotel;
  time_t begin_date;  // data de início;
  time_t end_date;    // data de fim;
  int price_per_night;      // preço por noite;
  bool includes_breakfast;  // se a reserva inclui pequeno-almoço;
  char* room_details;       // detalhes sobre o quarto;
  int rating;               // classificação atribuída pelo utilizador;
  char* comment;            // comentário sobre a reserva.
}* ReservationSchema;

#endif
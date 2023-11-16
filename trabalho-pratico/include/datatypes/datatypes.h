#ifndef DATATYPES_H
#define DATATYPES_H

#include <glib.h>
#include <stdbool.h>
#include <time.h>

#define UNUSED(x) (void)(x)

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

typedef struct userSchema {
  char* id;                // identificador do usuário;
  char* name;              // nome;
  char* email;             // email;
  char* phone_number;      // número de telemóvel;
  char* birth_date;        // data de nascimento;
  char* sex;               // sexo;
  char* passport;          // passaporte;
  char* country_code;      // código de país;
  char* address;           // endereço do usuário;
  char* account_creation;  // data de criação da conta;
  char* pay_method;        // método de pagamento;
  char* account_status;    // estado da conta;
  double total_spent;      // total gasto pelo utilizador em reservas.
  int age;
  int number_of_flights;
  int number_of_reservations;
}* UserSchema;

typedef struct flightSchema {
  char* id;                       // identificador do voo;
  char* airline;                  // companhia aérea;
  char* plane_model;              // modelo do avião;
  int total_seats;                // número de lugares totais disponíveis;
  char* origin;                   // aeroporto de origem;
  char* destination;              // aeroporto de destino;
  char* schedule_departure_date;  // data e hora estimada de partida;
  char* schedule_arrival_date;    // data e hora estimada de chegada;
  char* real_departure_date;      // data e hora real de partida;
  char* real_arrival_date;        // data e hora real de chegada;
  char* pilot;                    // nome do piloto;
  char* copilot;                  // nome do copiloto;
  char* notes;                    // observações sobre o voo.
  int number_of_passengers;       // numero total de pssageiros no voo
  long delay;
}* FlightSchema;

typedef struct passengerSchema {
  char* flight_id;  // identificador do voo
  char* user_id;    // identificador do utilizador
}* PassengerSchema;

typedef struct reservationSchema {
  char* id;                  // identificador da reserva;
  char* user_id;             // identificador do utilizador;
  char* hotel_id;            // identificador do hotel;
  char* hotel_name;          // nome do hotel;
  int hotel_stars;           // número de estrelas do hotel;
  int city_tax;              // percentagem do imposto da cidade (sobre o valor total);
  char* address;             // morada do hotel;
  char* begin_date;          // data de início;
  char* end_date;            // data de fim;
  int price_per_night;       // preço por noite;
  char* includes_breakfast;  // se a reserva inclui pequeno-almoço;
  char* room_details;        // detalhes sobre o quarto;
  char* rating;              // classificação atribuída pelo utilizador;
  char* comment;             // comentário sobre a reserva.
  double total_price;        // preço total da reserva
}* ReservationSchema;

#endif
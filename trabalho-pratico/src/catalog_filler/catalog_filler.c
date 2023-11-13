#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes/datatypes.h"
#include "catalogs_creator/catalogs_creator.h"
#include "catalog_filler/catalog_filler.h"
#include "file_parser/file_parser.h"

//a função catalog_filler vai receber um catalogo "conjunto" de users, flights, reservas e passageiros , e ira proceder à separação do mesmo e chamar a função de parsing para cada um
// neste momento não consigo utilizar esse tipo de dados porque não está nada definido :c, mas fica aqui um mini catalog_filler
int catalog_filler ( char *folder_destination ) {
    char *flights_filename = get_full_destination( folder_destination,"/flights.csv" );
    FILE *flights = fopen( flights_filename,"r" );
    if( flights == NULL ) {
        return -1; // se der erro, temos de dar print no terminal que algo correu mal.
    }

    char *users_filename = get_full_destination( folder_destination,"/users.csv" );
    FILE *users = fopen( users_filename,"r" );
    if( users == NULL ) {
        return -1; // se der erro, temos de dar print no terminal que algo correu mal.
    }

    char *passengers_filename = get_full_destination( folder_destination,"/passengers.csv" );
    FILE *passengers = fopen( passengers_filename,"r" );
    if( passengers == NULL ) {
        return -1; // se der erro, temos de dar print no terminal que algo correu mal.
    }

    char *reservations_filename = get_full_destination( folder_destination,"/reservations.csv" );
    FILE *reservations = fopen( reservations_filename,"r" );
    if( reservations == NULL ) {
        return -1; // se der erro, temos de dar print no terminal que algo correu mal.
    }
    
    file_parser( users,USER_MAXSIZE ); // os users apenas dependem deles proprios para serem verificados.
    file_parser( flights,FLIGHT_MAXSIZE ); // os voos tambem apenas dependem deles proprios para serem verificados.
    file_parser( reservations,RESERVATIONS_MAXSIZE ); // as reservas dependem nao so da correta inserção de dados como tambem se o user foi validado ou nao!
    file_parser( passengers,PASSENGERS_MAXSIZE ); // os passageiros de um voo dependem nao so da correta inserção de dados como tambem se o user e o voo foram validados corretamente.

    free(users_filename); // libertar espaço na memoria
    free(flights_filename);
    free(reservations_filename);
    free(passengers_filename);

    fclose(users); // é necessário fechar os ficheiros.
    fclose(flights);
    fclose(reservations);
    fclose(passengers);

    return 0;

}



char *get_full_destination (char *destination , const char *filename) {
    int len_filename = strlen( filename );
    int len_destination = strlen( destination );
    char *full_filename = malloc(sizeof( char) * ( len_destination + len_filename +1 ));
    strcpy( full_filename,destination );
    strcat( full_filename,filename );
    return full_filename;
} 
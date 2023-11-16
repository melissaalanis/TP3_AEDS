#include "lista_de_cartas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Preencher_Lista_Interativa(Lista_Cartas* lista) {
    char cores[5] = {'R', 'G', 'Y', 'B', 'P'};
    Carta carta_aux;
    int carta_numero, carta_cor;

    srand(time(NULL));

    for (int i = 0; i < Max_Tam-1; i++) {
        carta_cor = (rand() % Qtd_cores);
        if (carta_cor == 4) {
            carta_numero = ((rand()% Qtd_coringa) + 13);
        } else {
            carta_numero = (rand() % Qtd_cartas);
        }
    
        Inicializa_Carta(&carta_aux, carta_numero, cores[carta_cor]);
        lista->lista_cartas[i] = carta_aux;
    }
}


void Printar_Lista(Lista_Cartas* lista) {
    for (int i = 0; i < Max_Tam-1; i++) {
        printf("%d %c\n", lista->lista_cartas[i].numero, lista->lista_cartas[i].cor);
    }
}
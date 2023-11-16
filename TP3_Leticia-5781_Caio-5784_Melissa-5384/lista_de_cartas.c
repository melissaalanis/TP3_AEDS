#include "lista_de_cartas.h"
#include <stdlib.h>
#include <time.h>

void Adicionar_Carta_Lista(Lista_Cartas* lista, Carta *carta, int indice){
    lista -> lista_cartas[indice] = *carta;
}

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
        Adicionar_Carta_Lista(lista, &carta_aux, i);
    }
}
 
void Preencher_Lista_Arquivo(Lista_Cartas* lista, FILE* arquivo){
    int carta_numero;
    char carta_cor[10];
    for(int i = 0; i < Max_Tam-1; ){
        Carta *carta_aux;
        fscanf(arquivo, "(%s %d) ", &carta_cor, &carta_numero);
        
        if (strcmp(carta_cor, "Azul") == 0) {
            Inicializa_Carta(carta_aux, carta_numero, 'B');
        } else if (strcmp(carta_cor, "Verde") == 0) {
            Inicializa_Carta(carta_aux, carta_numero, 'G');
        } else if (strcmp(carta_cor, "Amarelo") == 0) {
            Inicializa_Carta(carta_aux, carta_numero, 'Y');
        } else if (strcmp(carta_cor, "Vermelho") == 0) {
            Inicializa_Carta(carta_aux, carta_numero, 'R');
        } else if (strcmp(carta_cor, "Preto") == 0) {
            Inicializa_Carta(carta_aux, carta_numero, 'P');
        }
        Adicionar_Carta_Lista(lista, carta_aux, i);
    }
}

void Printar_Lista(Lista_Cartas* lista) {
    Carta carta_aux;
    for (int i = 0; i < Max_Tam-1; i++) {
         carta_aux = lista-> lista_cartas[i];
         Printar_Carta(&carta_aux,lista->lista_cartas[i].numero, lista->lista_cartas[i].cor);
    }
}
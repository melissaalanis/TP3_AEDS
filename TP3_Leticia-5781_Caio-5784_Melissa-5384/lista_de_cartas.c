#include "lista_de_cartas.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

void Adicionar_Carta_Lista(Lista_Cartas* lista, Carta *carta, int indice){
    lista -> lista_cartas[indice] = *carta; // Uma carta eh adicionada na lista de cartas no indice correspondente 
} 

void Preencher_Lista_Interativa(Lista_Cartas* lista) { 
    char cores[5] = {'R', 'G', 'Y', 'B', 'P'}; // R = RED (Vermelho) || G = GREEN (Verde) || Y = YELLOW (Amarelo) || B = BLUE (Azul) || P = PRETO (Cartas coringa e +4)
    int carta_numero, carta_cor;

    srand(time(NULL)); //Gera a semente dos números aleatorios

    for (int i = 0; i < Max_Tam-1; i++) { //O for vai até "Max_Tam-1" pois Max_Tam é 11 devido ao fato de termos deixado, por segurança, uma posição a mais no vetor 
        Carta carta_aux;
        carta_cor = (rand() % Qtd_cores); //Gera um avlor de 0 a 4 - indices do vetor cores
        if (carta_cor == 4) { // Se a carta for preta - indice == 4 - seu valor so pode ser 13 ou 14
            carta_numero = ((rand()% Qtd_coringa) + 13); //O "rand()% Qtd_coringa" gera 0 ou 1, o "+13" serve para torna-lo 13 ou 14
        } else {
            carta_numero = (rand() % Qtd_cartas); //Gera um valor entre 0 e 12
        }

        //Inicializando a carta e adicionando na lista
        Inicializa_Carta(&carta_aux, carta_numero, cores[carta_cor]); 
        Adicionar_Carta_Lista(lista, &carta_aux, i);
    }
}
 
void Preencher_Lista_Arquivo(Lista_Cartas* lista, FILE* arquivo){
    int carta_numero;
    char carta_cor[10], carta_tipo[10]; //Serve para guardar a cor e o tipo de carta - coringa, +2, 0, etc - que estao como stings no arquivo
    char carta_letra_cor;

    for(int i = 0; i < Max_Tam-1; i++){
        Carta carta_aux;  
        fscanf(arquivo, " (%s %s) ", carta_cor, carta_tipo);
        //Pega a string com o nome da cor e associa a sua letra correspondente
        //R = RED (Vermelho) || G = GREEN (Verde) || Y = YELLOW (Amarelo) || B = BLUE (Azul) || P = PRETO (Cartas coringa e +4)
        if (strcmp(carta_cor, "Azul") == 0) {
            carta_letra_cor = 'B';
        } else if (strcmp(carta_cor, "Verde") == 0) {
            carta_letra_cor = 'G';
        } else if (strcmp(carta_cor, "Amarelo") == 0) {
            carta_letra_cor = 'Y';
        } else if (strcmp(carta_cor, "Vermelho") == 0) {
            carta_letra_cor = 'R';
        } else if (strcmp(carta_cor, "Preto") == 0) {
            carta_letra_cor = 'P';
        }

        //Pega o tipo da carta e associa ao numero correspondente
        if (strcmp(carta_tipo, "Coringa)") == 0) {
            carta_numero = 14;
        } else if (strcmp(carta_tipo, "+2)") == 0) {
            carta_numero = 12;
        } else if (strcmp(carta_tipo, "+4)") == 0) {
            carta_numero = 13;
        } else if (strcmp(carta_tipo, "Voltar)") == 0) {
            carta_numero = 11;
        } else if (strcmp(carta_tipo, "Pular)") == 0) {
            carta_numero = 10;
        } else if (strcmp(carta_tipo, "0)") == 0) {
            carta_numero = 0;
        } else if (strcmp(carta_tipo, "1)") == 0) {
            carta_numero = 1;
        } else if (strcmp(carta_tipo, "2)") == 0) {
            carta_numero = 2;
        } else if (strcmp(carta_tipo, "3)") == 0) {
            carta_numero = 3;
        } else if (strcmp(carta_tipo, "4)") == 0) {
            carta_numero = 4;
        } else if (strcmp(carta_tipo, "5)") == 0) {
            carta_numero = 5;
        } else if (strcmp(carta_tipo, "6)") == 0) {
            carta_numero = 6;
        } else if (strcmp(carta_tipo, "7)") == 0) {
            carta_numero = 7;
        } else if (strcmp(carta_tipo, "8)") == 0) {
            carta_numero = 8;
        } else if (strcmp(carta_tipo, "9)") == 0) {
            carta_numero = 9;
        }

        //Inicializando a carta e adicionando na lista
        Inicializa_Carta(&carta_aux, carta_numero, carta_letra_cor);
        Adicionar_Carta_Lista(lista, &carta_aux, i);
    }
}


void Printar_Lista(Lista_Cartas* lista) {
    Carta carta_aux;
    for (int i = 0; i < Max_Tam-1; i++) {
        carta_aux = lista-> lista_cartas[i];
        Printar_Carta(&carta_aux,lista->lista_cartas[i].numero, lista->lista_cartas[i].cor);
    }
}

void BubbleSort(Lista_Cartas* lista, int n) {
    int i, j;
    Carta aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < n - i; j++) {
            // Ordenar por cor primeiro
            if (lista->lista_cartas[j].valor_cor < lista->lista_cartas[j - 1].valor_cor) {
                aux = lista->lista_cartas[j];
                lista->lista_cartas[j] = lista->lista_cartas[j - 1];
                lista->lista_cartas[j - 1] = aux;
                
            } else if (lista->lista_cartas[j].valor_cor == lista->lista_cartas[j - 1].valor_cor) {// Se as cores forem iguais, ordenar por número
                if (lista->lista_cartas[j].numero < lista->lista_cartas[j - 1].numero) {
                    aux = lista->lista_cartas[j];
                    lista->lista_cartas[j] = lista->lista_cartas[j - 1];
                    lista->lista_cartas[j - 1] = aux;
                }
            }
        }
    }
}

void Selecao(Lista_Cartas*lista, int tam_vetor){
    int i, j, min; // "i" será utilizado para percorrer o vetor || "j" será utilizado para buscar o menor elemento do v. || "min" guarda o indice do menor elemento do v. na busca
    Carta carta_aux; // criando a carta aux que nos ajudará nas movimentações
    for(i=0; i < tam_vetor-1; i++) { // o i vai até tam_vetor-1, pois o ultimo elemento da seleção estará já ordenado seguindo o raciocínio do algoritmo
        min = i;
        for (j = i+1; j< tam_vetor; j++){
            if ((lista->lista_cartas[j].valor_cor) < (lista-> lista_cartas[min].valor_cor)) min = j; // procurando os "menores elementos" com base nas cores. 
            // ORDEM DAS CORES: G, Y, R, B, P;
            else if ((lista->lista_cartas[j].valor_cor) == (lista-> lista_cartas[min].valor_cor)) { // Se as cores forem iguais, comparar entao pelo valor das cartas, priorizando a menor;
                if ((lista ->lista_cartas[j].numero) < (lista->lista_cartas[min].numero)) min = j;
            }
        }
        // Após cada looping mais interno
        carta_aux = lista -> lista_cartas[min]; // a carta auxiliar recebe a menor carta do vetor no momento em q é percorrido
        lista -> lista_cartas[min] = lista ->lista_cartas[i]; // troca-se a carta de menor valor encontrada com a que é maior que ela
        lista ->lista_cartas[i] = carta_aux; // 
        }
        Printar_Lista(lista);
}

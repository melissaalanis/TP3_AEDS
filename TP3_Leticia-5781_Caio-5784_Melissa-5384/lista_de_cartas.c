#include "lista_de_cartas.h"
#include <stdlib.h>
#include <string.h>

void Adicionar_Carta_Lista(Lista_Cartas* lista, Carta *carta, int indice){
    lista -> lista_cartas[indice] = *carta; // Uma carta eh adicionada na lista de cartas no indice correspondente 
} 


void Embaralhar_Baralho(Lista_Cartas* baralho) {
    // Embaralhando o vetor de cartas usando Fisher-Yates
    srand(time(NULL)); //Inicializa a semente dos numeros aleatorios
    for (int i = Tamanho_Baralho - 1; i > 0; i--) {
        int nova_posicao = rand() % (i + 1); //Gera uma nova posicao aleatoria, vai de 0 até i
        //Troca a carta da posicao i com a nova posicao
        Carta carta_aux = baralho->baralho[i]; 
        baralho->baralho[i] = baralho->baralho[nova_posicao];
        baralho->baralho[nova_posicao] = carta_aux;
    }
}

void Carregar_Baralho_Aleatorio(Lista_Cartas* baralho){
    char cores[5] = {'R', 'G', 'Y', 'B', 'P'};
    //R = RED (Vermelho) || G = GREEN (Verde) || Y = YELLOW (Amarelo) || B = BLUE (Azul) || P = PRETO (Cartas coringa e +4)
    Carta carta_aux;
    int carta_numero;
    char carta_cor;
    int indice = 0; //indices do meu baralho

    for(int j = 0; j < Qtd_cores-1; j++){ //Gera as cores verde, vermelho, azul e amarelo
        carta_cor = cores[j];
        for (int i = 0; i < Qtd_cartas; i++){ //Gera o numero das cartas - 0 á 12
            carta_numero = i;
            Inicializa_Carta(&carta_aux, carta_numero, carta_cor);
            baralho->baralho[indice] = carta_aux; //Adiciona a carta no baralho
            indice = indice+1;
        }
        
    }    
    //Gera as cartas pretas
    carta_cor = cores[4]; 
    for (int i = 0; i < Qtd_mais_quatro ; i++){
        carta_numero = 13; //O numero do +4 é 13
        Inicializa_Carta(&carta_aux, carta_numero, carta_cor);
        baralho->baralho[indice] = carta_aux; //Adiciona a carta no baralho
        indice = indice+1;
    }

    for (int i = 0; i < Qtd_coringa; i++){
        carta_numero = 14; //O numero do coringa é 14 
        Inicializa_Carta(&carta_aux, carta_numero, carta_cor);
        baralho->baralho[indice] = carta_aux; //Adiciona a carta no baralho
        indice = indice+1;    
    }

    Embaralhar_Baralho(baralho);
}

void Preencher_Lista_Interativa(Lista_Cartas* lista) {
    for (int i=0; i<Max_Tam-1; i++){
        Adicionar_Carta_Lista(lista, &(lista->baralho[i]), i);
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
    for (int i = 0; i <Max_Tam-1; i++) { 
        carta_aux = lista-> lista_cartas[i];
        printf("[%02d]: ", i+1); //Printa o indice da carta - 0 á 10 - com dois digitos
        Printar_Carta(&carta_aux);
    }
}

void Printar_Dados(Lista_Cartas *lista, int comparacoes, int movimentacoes, double tempo_total){
    printf("Mão Final:\n");
    Printar_Lista(lista);
    //Dados calculados detro das funcoes de ordenacao
    printf("Comparações: %d, Movimentações: %d, Tempo: %lf segundos\n", comparacoes, movimentacoes, tempo_total); 
}

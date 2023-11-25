#include "Carta.h"
#include <stdio.h>
#define Max_Tam 11
#define Tamanho_Baralho 56

typedef struct {
    Carta baralho[Tamanho_Baralho];
    Carta lista_cartas[Max_Tam];
} Lista_Cartas;

void Preencher_Lista_Interativa(Lista_Cartas* lista);
void Embaralhar_Baralho(Lista_Cartas* lista);
void Carregar_Baralho_Aleatorio(Lista_Cartas* baralho);
void Preencher_Lista_Arquivo(Lista_Cartas* lista, FILE* arquivo);
void Adicionar_Carta_Lista(Lista_Cartas* lista, Carta* carta, int indice);
void Printar_Lista(Lista_Cartas* lista);
void Printar_Dados(Lista_Cartas* lista, int comparacoes, int movimentacoes, double tempo_total);
void BubbleSort(Lista_Cartas* lista, int n);
void Selecao(Lista_Cartas*lista, int tam_vetor);
void Insercao (Lista_Cartas* lista, int tam_vetor);
void Shellsort (Lista_Cartas* lista, int tam_vetor);
void Quick_Ordena(int Esq, int Dir, Lista_Cartas* lista, int *comparacoes, int *movimentacoes);
void Quick_Particao(int Esq, int Dir, int *i, int *j, Lista_Cartas* lista, int *comparacoes, int *movimentacoes);
void QuickSort(Lista_Cartas* lista, int n);
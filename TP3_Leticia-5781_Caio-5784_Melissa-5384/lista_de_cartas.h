#include "Carta.h"
#define Max_Tam 11

typedef struct {
    Carta lista_cartas[Max_Tam];
} Lista_Cartas;

void Preencher_Lista_Interativa(Lista_Cartas* lista);
void Preencher_Lista_Arquivo(Lista_Cartas* lista, FILE* arquivo);
void Adicionar_Carta_Lista(Lista_Cartas* lista, Carta* carta, int indice);
void Printar_Lista(Lista_Cartas* lista);
void Printar_Dados(Lista_Cartas* lista, int comparacoes, int movimentacoes, double tempo_total);
void BubbleSort(Lista_Cartas* lista, int n);
void Selecao(Lista_Cartas*lista, int tam_vetor);
void Insercao (Lista_Cartas* lista, int tam_vetor);
void Quick_Ordena(int Esq, int Dir, Carta* A);
void Quick_Particao(int Esq, int Dir, int *i, int *j, Carta* A);
void QuickSort(Carta* A, int n);
#include "Carta.h"
#define Max_Tam 11

typedef struct {
 Carta lista_cartas[Max_Tam];
} Lista_Cartas;

void Preencher_Lista_Interativa(Lista_Cartas* lista);
void Preencher_Lista_Arquivo(Lista_Cartas* lista);
void Printar_Lista(Lista_Cartas* lista);
#include "lista_de_cartas.h"

int main()
{
    Lista_Cartas baralho;
    Preencher_Lista_Interativa(&baralho);
    Printar_Lista(&baralho);
    return 0;
}

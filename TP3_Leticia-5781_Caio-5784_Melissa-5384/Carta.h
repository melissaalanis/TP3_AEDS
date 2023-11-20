#define True 1
#define False 0
#define Qtd_cores 5
#define Qtd_cartas 13
#define Qtd_mais_quatro 2
#define Qtd_coringa 2
#define cor_vermelha  "\x1b[41m" 
#define cor_azul  "\x1b[46m" 
#define cor_preta "\x1b[100m\x1b[97m" 
#define cor_verde "\x1b[42m" 
#define cor_amarela  "\x1b[43m" 
#define cor_branca  "\x1b[47m"
#define resetar_cor "\x1b[0m"
#include <stdio.h>

typedef struct {
    char cor; // R = vermelho, G = verde, B = azul, Y = amarelo, P = Preto
    int numero; 
    int valor_cor;
    // Valores de 0 á 9 representam os próprios números, o bloqueio vale 10, 
    //o volta vale 11, +2 vale 12, o +4 vale 13 e o coringa (escolhe cor) vale 14
} Carta;

void Inicializa_Carta(Carta* carta, int numero, char cor);
void Printar_Carta(Carta* carta);


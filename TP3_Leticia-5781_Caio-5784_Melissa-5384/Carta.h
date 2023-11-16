#define True 1
#define False 0
#define Qtd_cores 5
#define Qtd_cartas 13
#define Qtd_mais_quatro 2
#define Qtd_coringa 2

typedef struct {
    char cor; // R = vermelho, G = verde, B = azul, Y = amarelo, P = Preto
    int numero; 
    // Valores de 0 á 9 representam os próprios números, o bloqueio vale 10, 
    //o volta vale 11, +2 vale 12, o +4 vale 13 e o coringa (escolhe cor) vale 14
} Carta;

void Inicializa_Carta(Carta* carta, int numero, char cor);

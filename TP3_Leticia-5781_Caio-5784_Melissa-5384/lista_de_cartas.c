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
        printf("[%02d]: ", i+1);
        Printar_Carta(&carta_aux);
    }
}

void BubbleSort(Lista_Cartas* lista, int n) {
    clock_t tempo_inicial, tempo_final;
    double tempo_total;

    tempo_inicial = clock();  // Tempo inicial da contagem
    int comparacoes = 0;
    int movimentacoes = 0;
    int i, j;
    Carta aux;
    for (i = 0; i < n - 1; i++) {
        comparacoes++;
        for (j = 1; j < n - i; j++) {
            comparacoes++;
            if (lista->lista_cartas[j].valor_cor < lista->lista_cartas[j - 1].valor_cor) {
                // Se as cores forem diferentes, ordena por cor
                comparacoes++;
                aux = lista->lista_cartas[j]; // variável temporária aux atribui o valor do elemento na posição j do vetor
                lista->lista_cartas[j] = lista->lista_cartas[j - 1]; // Copia o valor do elemento na posição j - 1 para a posição j na lista.
                lista->lista_cartas[j - 1] = aux; // Essa linha copia o valor previamente armazenado em aux (que era o valor original do elemento na posição j) de volta para a posição j - 1 na lista
                
            } else if (lista->lista_cartas[j].valor_cor == lista->lista_cartas[j - 1].valor_cor) {
                // Se as cores forem iguais, ordenar por número
                comparacoes++;
                if (lista->lista_cartas[j].numero < lista->lista_cartas[j - 1].numero) {
                    comparacoes++;
                    aux = lista->lista_cartas[j];
                    lista->lista_cartas[j] = lista->lista_cartas[j - 1];
                    lista->lista_cartas[j - 1] = aux;
                }
            }
        movimentacoes++;
        }
    }
    tempo_final = clock(); //Marca o tempo final 
    tempo_total = (double)(tempo_final-tempo_inicial) / CLOCKS_PER_SEC; //Calcula o tempo total em segundos
    Printar_Dados(lista, comparacoes, movimentacoes, tempo_total);
}

void Selecao(Lista_Cartas*lista, int tam_vetor){
    clock_t tempo_inicial, tempo_final;
    double tempo_total;

    tempo_inicial = clock();  // Tempo inicial da contagem
    int comparacoes = 0;
    int movimentacoes = 0;
    int i, j, min; // "i" será utilizado para percorrer o vetor || "j" será utilizado para buscar o menor elemento do v. || "min" guarda o indice do menor elemento do v. na busca
    Carta carta_aux; // criando a carta aux que nos ajudará nas movimentações
    for(i=0; i < tam_vetor-1; i++) { // o i vai até tam_vetor-1, pois o ultimo elemento da seleção estará já ordenado seguindo o raciocínio do algoritmo
        min = i;
        for (j = i+1; j< tam_vetor; j++){
            comparacoes++;
            if ((lista->lista_cartas[j].valor_cor) < (lista-> lista_cartas[min].valor_cor)) {
                min = j; 
            }// procurando os "menores elementos" com base nas cores. 
            // ORDEM DAS CORES: G, Y, R, B, P;
            comparacoes++;
            if (((lista->lista_cartas[j].valor_cor) == (lista-> lista_cartas[min].valor_cor)) && ((lista ->lista_cartas[j].numero) < (lista->lista_cartas[min].numero))){ 
                // Se as cores forem iguais, mas o valor de uma for menor que o da outra (tem-se a troca);
                min = j;
                }
            }
        
        // Após cada looping mais interno
        movimentacoes++;
        carta_aux = lista -> lista_cartas[min]; // a carta auxiliar recebe a menor carta do vetor no momento em q é percorrido
        lista -> lista_cartas[min] = lista ->lista_cartas[i]; // troca-se a carta de menor valor encontrada com a que é maior que ela
        lista ->lista_cartas[i] = carta_aux;
    }
    tempo_final = clock(); //Marca o tempo final 
    tempo_total = (double)(tempo_final-tempo_inicial) / CLOCKS_PER_SEC; //Calcula o tempo total em segundos
    Printar_Dados(lista, comparacoes, movimentacoes, tempo_total);
}


void Insercao(Lista_Cartas* lista, int tam_vetor) {
    clock_t tempo_inicio, tempo_final; 
    double tempo_total;
    tempo_inicio = clock(); //Marca o tempo inicial 
    
    int i, j;
    int comparacoes = 0, movimentacoes = 0;
    Carta carta_aux;

    for (i = 1; i < tam_vetor; i++) { 
        carta_aux = lista->lista_cartas[i]; //Carta que será movida
        j = i - 1; //As comparacoes acontecem com as cartas que estão da carta_aux

        while ((j >= 0) && ((carta_aux.valor_cor < lista->lista_cartas[j].valor_cor) || ((carta_aux.valor_cor == lista->lista_cartas[j].valor_cor) && (carta_aux.numero < lista->lista_cartas[j].numero)))) {
            //Se a carta j+1 tiver uma cor maior que a da carta_aux e, ao mesmo tempo, um número maior, significa que ela tem que ser movida uma posição para a frente
            //com o objetivo de "abrir espaco" para carta_aux, pois se isso acontecer significa que carta_aux é menor que ela, o mesmo acoentce que carta j tiver a mesma 
            //cor que carta_aux, mas um numero maior
            lista->lista_cartas[j + 1] = lista->lista_cartas[j];
            j--;
            movimentacoes ++; //A cada execucao do while uma movimentacao é realizada
            comparacoes++; //A cada execucao do while uma comparacao é realizada
        }
        comparacoes++; //Essa comparacao é para quando o nao entrar no while, quando a comparacao for falsa
        
        movimentacoes++; //No final é realizado a movimentacao que coloca carta_aux no lugar certo
        lista->lista_cartas[j + 1] = carta_aux; //apos ter aberto espaco para carta_aux, colocamos ela na posicao correta, temos "j+1" porque foi necessário decrementar j 
        //na verificação do while e o ultimo j utilizado nas movimentacoes é o indice correto de carta_aux
        //printf("m%d c%d i%d\n",movimentacoes, comparacoes,i );
    }
    
    tempo_final = clock(); //Marca o tempo final 
    tempo_total = (double)(tempo_final-tempo_inicio) / CLOCKS_PER_SEC; //Calcula o tempo total em segundos
    Printar_Dados(lista, comparacoes, movimentacoes, tempo_total);

}

void Quick_Particao(int Esq, int Dir, int *i, int *j, Carta* A){
    Carta pivo, aux;
    *i = Esq; *j = Dir;
    pivo = A[(*i + *j)/2]; /* obtem o pivo x */
    do{
        while (pivo.Chave > A[*i].Chave) (*i)++;
        while (pivo.Chave < A[*j].Chave) (*j)--;
        if (*i <= *j){
            aux = A[*i]; A[*i] = A[*j]; A[*j] = aux;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);

}

void Quick_Ordena(int Esq, int Dir, Carta* A){
    int i,j;
    Quick_Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) Quick_Ordena(Esq, j, A);
    if (i < Dir) Quick_Ordena(i, Dir, A);
}

void QuickSort(Carta* A, int n){
    Quick_Ordena(0, n-1, A); 
}

void Printar_Dados(Lista_Cartas *lista, int comparacoes, int movimentacoes, double tempo_total){
    printf("Mão Final:\n");
    Printar_Lista(lista);
    printf("Comparações: %d, Movimentações: %d, Tempo: %lf segundos\n", comparacoes, movimentacoes, tempo_total);
    
}

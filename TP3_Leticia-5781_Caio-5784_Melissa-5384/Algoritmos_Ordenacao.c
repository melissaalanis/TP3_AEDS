#include "lista_de_cartas.h"

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

void Shellsort (Lista_Cartas* lista, int tam_vetor){
    clock_t tempo_inicio, tempo_final; 
    double tempo_total;
    tempo_inicio = clock(); //Marca o tempo inicial 

    int i, j;
    int h = 1;
    int comparacoes = 0, movimentacoes = 0;
    Carta aux;

    do { // Faz o cálculo do h, um elemento crucial a ser utilizado para ordenação do vetor.
        h = h * 3 + 1; // o "h" é, basicamente, uma variavel que define a distancia dos elementos a serem comparados com base no tamanho do vetor.
        comparacoes++;
    } while (h < tam_vetor);

    do
    {
        comparacoes++; //VERIFICAR SE ESSE COMPARACOES++ AQUI TA CORRETO
        h = h/3;
        for( i = h ; i < tam_vetor ; i++ )
        {
            aux = lista -> lista_cartas[i]; 
            j = i;

            /*Neste trecho, tem-se, além da comparação, a troca dos elementos que estao nos intervalos definidos por h.
            Vale salientar que estas trocas ocorrem de acordo com a prioridade da cor e, também, de acordo com os valores das cartas a serem trocadas.
            Uma carta vermelha 01 é maior do que uma verde 01, por exemplo. Logo, esse while é responsável por realizar estas verificações e as trocas,
            caso necessárias.
            */
            while ((lista->lista_cartas[j-h].valor_cor > aux.valor_cor) && (lista ->lista_cartas[j-h].numero > aux.numero))
            {
                comparacoes++;
                lista ->lista_cartas[j] = lista ->lista_cartas[j-h]; // troca elemento atual com o que está à h-ésima distância dele.
                movimentacoes++; 
                j -= h; 
                if (j < h) break; // Quando j é menor que h, isso significa que não há mais nada para ser ordenado no intervalo do momento.
            }
            comparacoes++; 
            lista -> lista_cartas[j] = aux;
        }
    } while (h != 1);

    tempo_final = clock(); //Marca o tempo final 
    tempo_total = (double)(tempo_final-tempo_inicio) / CLOCKS_PER_SEC; //Calcula o tempo total em segundos
    Printar_Dados(lista, comparacoes, movimentacoes, tempo_total);
}

void Quick_Particao(int Esq, int Dir, int *i, int *j, Lista_Cartas* lista, int *comparacoes, int *movimentacoes) {
    Carta pivo, aux;
    *i = Esq;
    *j = Dir;
    pivo = lista->lista_cartas[(*i + *j) / 2]; /* obtem o pivo x */
    do {
        while (pivo.valor_cor > lista->lista_cartas[*i].valor_cor || (pivo.valor_cor == lista->lista_cartas[*i].valor_cor && pivo.numero > lista->lista_cartas[*i].numero))
            (*i)++;  
            (*comparacoes)++;
        while (pivo.valor_cor < lista->lista_cartas[*j].valor_cor || (pivo.valor_cor == lista->lista_cartas[*j].valor_cor && pivo.numero < lista->lista_cartas[*j].numero))
            (*j)--;
            (*comparacoes)++;
        if (*i <= *j) {
            (*comparacoes)++;
            aux = lista->lista_cartas[*i];
            lista->lista_cartas[*i] = lista->lista_cartas[*j];
            lista->lista_cartas[*j] = aux;
            (*i)++;
            (*j)--;
            (*movimentacoes)++; //A cada execucao do while uma movimentacao é realizada
        }
    } while (*i <= *j);
}

void Quick_Ordena(int Esq, int Dir, Lista_Cartas* lista, int *comparacoes, int *movimentacoes) {
    int i, j;
    Quick_Particao(Esq, Dir, &i, &j, lista, comparacoes, movimentacoes); 
    // a funçao é responsavel por realmente trocar os elementos de determinada partiçao definida 
    if (Esq < j){  
        // Verifica se a posição "esquerda" é menor que a posicao "j", caso seja ordena-se os elementos a esquerda de j
        (*comparacoes)++;
        Quick_Ordena(Esq, j, lista, comparacoes, movimentacoes);}
    if (i < Dir){ 
        // Verifica se a posição "direita" é menor que a posicao "i", caso seja ordena-se os elementos a direita de i
        (*comparacoes)++;
        Quick_Ordena(i, Dir, lista, comparacoes, movimentacoes);} // Chamamos a funçao recursivamente ate a completa ordenção
}

void QuickSort(Lista_Cartas* lista, int n) {
    clock_t tempo_inicio, tempo_final; 
    double tempo_total;
    tempo_inicio = clock(); //Marca o tempo inicial 
    int comparacoes = 0;
    int movimentacoes = 0;

    Quick_Ordena(0, n - 1, lista, &comparacoes, &movimentacoes);
    tempo_final = clock(); //Marca o tempo final 
    tempo_total = (double)(tempo_final-tempo_inicio) / CLOCKS_PER_SEC; //Calcula o tempo total em segundos
    Printar_Dados(lista, comparacoes, movimentacoes, tempo_total);
}

void Constroi(Carta *lista, int *n, int *movimentacoes, int *comparacoes){
    int Esq;
    Esq = *n / 2 + 1; //Pega o meio do vetor
    while (Esq > 1){
        (*comparacoes) ++;
        Esq--;
        Refaz(Esq, *n, lista, movimentacoes, comparacoes);
    }
}

void Refaz(int Esq, int Dir, Carta *lista, int *movimentacoes, int *comparacoes){
    int j = Esq * 2;
    Carta carta_aux = lista[Esq];
    while (j <= Dir){
        (*comparacoes) ++; //comparacao do while
        
        (*comparacoes) ++; //comparacao do if

        //Verifica se o elemto j e j+1 estão posicionados corretamente, se tiverem passa para o j, ou seja, proxima comparacao
        if ((j < Dir)&&((lista[j].valor_cor < lista[j+1].valor_cor)
        ||((lista[j].valor_cor == lista[j+1].valor_cor) && 
        (lista[j].numero < lista[j+1].numero)))){
            j++;
        }

        (*comparacoes) ++; //comparacao do if
        //Se esse if for verdadeiro significa que o heap esta formado, ou seja, mior valor, que ainda não foi ordenado, esta no indice 1 
        if ((carta_aux.valor_cor >lista[j].valor_cor) || 
        ((carta_aux.valor_cor == lista[j].valor_cor) && 
        (carta_aux.numero > lista[j].numero))){
            break;
        }

        //Garante que o maior elemto está sendo movido para o indice 1
        lista[Esq] = lista[j];
        (*movimentacoes) ++;       
        
        //Passsa para a proxima verificação
        Esq = j; 
        j = Esq * 2 ;
    }
    //Move, efetivamente, a carta, garantindo que o heap seja formado
    lista[Esq] = carta_aux;
    (*movimentacoes) ++;
}

void Heapsort(Carta *lista, int *n, int *movimentacoes, int *comparacoes){ 
    int Esq, Dir;
    Carta carta_aux;
    
    Constroi(lista, n, movimentacoes, comparacoes); /* constroi o heap */
    Esq = 1; 
    Dir = *n;

    while (Dir > 1){ /* ordena o vetor */
        (*comparacoes) ++; //Comparacao do while
        
        //Essa parte é responsável por mover o elementp de maior valor, que vai esta na primeira posicao do heap
        //para o final do vetor, posicao dir
        carta_aux = lista[1]; 
        lista[1] = lista[Dir]; 
        lista[Dir] = carta_aux;

        (*movimentacoes) += 2;

        Dir--;
        Refaz(Esq, Dir, lista, movimentacoes, comparacoes); ///Apos a movimentacao o heap é refeito
    }
}

void Inicializa_Heapsort(Lista_Cartas* lista){
    Carta lista_aux[12];
    Carta carta_aux;
    int n = Max_Tam;

    //Como  o heapsort ordena a lista começando do indice 1 até n, mas a lista do tad vai de 0 até n-1
    //criei uma lita auxiliar para resolver esse problema
    for(int  i = 1; i<11; i++){
        carta_aux = lista->lista_cartas[i-1];
        lista_aux[i]=carta_aux;
    }

    int movimentacoes = 0, comparacoes = 0;

    clock_t tempo_inicio, tempo_final; 
    double tempo_total;
    tempo_inicio = clock(); //Marca o tempo inicial 
    
    Heapsort(lista_aux, &n, &movimentacoes, &comparacoes);
    
    tempo_final = clock(); //Marca o tempo final 
    tempo_total = (double)(tempo_final-tempo_inicio) / CLOCKS_PER_SEC; //Calcula o tempo total em segundos
    
    //Volta a lista_aux, agora ordenada, para o tad
    for(int  i = 1; i<11; i++){
        lista->lista_cartas[i-1] =  lista_aux[i];
    }
    
    Printar_Dados(lista, comparacoes, movimentacoes, tempo_total);

}
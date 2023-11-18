#include "lista_de_cartas.h"

void Menu(Lista_Cartas* baralho){
    printf("Mao Inicial:\n");
    Printar_Lista(baralho);
    int escolha; 

    printf("Escolha a forma como deseja ordenar as suas cartas:\n1) BubbleSort\n2) Seleção\n3) Inserção\n4) ShellSort\n5) QuickSort\n6) HeapSort\n");
    scanf("%d", &escolha);

    // FAZER UMA FUNCAO QUE PRINTE OS DADOS: mao ordenada, tempo, movimentaçoes, etc.
    switch (escolha){
    case 1:
        printf("BUBBLE:\n");
        printf("Mão Final:\n");
        BubbleSort(baralho, Max_Tam);
        Printar_Lista(baralho);
        break;
    case 2:
        printf("SELEÇÃO:\n");
        printf("Mão Final:\n");
        Selecao(baralho, Max_Tam);
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    default:
        printf("Valor Inválido :/\n");
        break;
    }
}


int main(){
    Lista_Cartas baralho;
    int opcao ,qtd;
    //criar o menu

    printf("Bem vinde ao TP3!\nSelecione o modo que deseja ordenar de acordo com o número\n1) Modo Interativo\n2) Modo Arquivo\n");
    scanf("%d", &opcao);
    if (opcao == 1){
        Preencher_Lista_Interativa(&baralho);  //Preenche a lista com numeros aleatorios
        Menu(&baralho); //a pes
    }

    else if (opcao == 2){
        FILE *arquivo;
        arquivo = fopen("ExemploTP3.txt", "r"); //Abre o arquivo para leitura  
        
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

        fscanf(arquivo, "%d", &qtd); //qtd de listas a serem ordenadas
        for (int i = 0; i<qtd; i++){
            Preencher_Lista_Arquivo(&baralho, arquivo);
            Menu(&baralho);
        }
    }

    else{
        printf("Opção inválida!");
    }
    return 0;
}
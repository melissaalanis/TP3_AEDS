#include "lista_de_cartas.h"

void Menu(Lista_Cartas* lista){
    
    int escolha; 

    printf("Escolha a forma como deseja ordenar as suas cartas:\n1) BubbleSort\n2) Seleção\n3) Inserção\n4) ShellSort\n5) QuickSort\n6) HeapSort\n");
    scanf("%d", &escolha);
    system("clear");
    printf("Mao Inicial:\n");
    Printar_Lista(lista);

    switch (escolha){
    case 1:
        printf("\nBUBBLE:\n");
        BubbleSort(lista, Max_Tam-1);
        break;
    case 2:
        printf("\nSELEÇÃO:\n");
        Selecao(lista, Max_Tam-1);
        break;
    case 3:
        printf("\nINSERÇÃO:\n");
        Insercao(lista, Max_Tam-1);
        break;
    case 4:
        printf("\nSHELL:\n");
        Insercao(lista, Max_Tam-1);
        break;
    case 5:
        printf("\nQUICK:\n");
        QuickSort(lista, Max_Tam-1);
        break;
    case 6:
        printf("\nHEAPSORT:\n");
        Inicializa_Heapsort(lista);
        break;
    default:
        printf("Valor Inválido :/\n Impossivel Ordenar!\n");
        break;
    }
}


int main(){
    Lista_Cartas lista;
    int opcao ,qtd;

    Carregar_Baralho_Aleatorio(&lista);

    printf("Bem vinde ao TP3!\nSelecione o modo que deseja ordenar de acordo com o número\n1) Modo Interativo\n2) Modo Arquivo\n");
    scanf("%d", &opcao);

    if (opcao == 1){
        Preencher_Lista_Interativa(&lista); //Preenche a lista com numeros aleatorios
        Menu(&lista); //a pes
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
            Preencher_Lista_Arquivo(&lista, arquivo);
            Menu(&lista);
            printf("Pressione Enter para continuar");
            // Limpar o buffer de entrada
            while (getchar() != '\n');

            // Aguardar Enter novamente
            getchar();
            system("clear");
        }
        printf("Todas as listas foram ordenadas :)\n");
    }

    else{
        printf("Opção inválida!");
    }
    return 0;
}
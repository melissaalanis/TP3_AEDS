#include "lista_de_cartas.h"

int main(){
    Lista_Cartas baralho;
    int opcao ,qtd;
    //criar o menu

    printf("Bem vinde ao TP3!\nSelecione o modo que deseja ordenar de acordo com o número\n1) Modo Interativo\n2) Modo Arquivo\n");
    scanf("%d", &opcao);

    if (opcao == 1){
        Preencher_Lista_Interativa(&baralho);   
    }
    else if (opcao == 2){
        FILE *arquivo;
        arquivo = fopen("ExemploTP3.txt", "r"); //Abre o arquivo para leitura  
        fscanf(arquivo, "%d", &qtd); //qtd de listas a serem ordenadas
        for (int i = 0; i<qtd; i++){
            Preencher_Lista_Arquivo(&baralho, arquivo);
        }
    }

    else{
        printf("Opção inválida!");
    }
    Printar_Lista(&baralho);
    return 0;
}
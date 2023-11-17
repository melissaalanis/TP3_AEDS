#include "Carta.h"

void Inicializa_Carta(Carta* carta, int numero, char cor){
    carta -> numero = numero;
    carta -> cor = cor;
} // Sao atribuidos a carta na inicializacao o numero dela e sua cor correspondente

void Printar_Carta(Carta* carta, int numero, char cor){
    if (carta -> cor == 'R'){
        printf(cor_vermelha "%02d" resetar_cor  "\n", carta -> numero ); //Quando a variavel cor for igual a R o fundo daquela carta sera vermelho 
    }
    else if (carta -> cor == 'G'){
        printf(cor_verde "%02d" resetar_cor  "\n" , carta -> numero);// Logo apos o numero ser printado com a cor de fundo alterada a cor é redefinida para o padrao
    }
    else if (carta -> cor == 'B'){
        printf(cor_azul "%02d" resetar_cor "\n", carta -> numero);
    }
    else if (carta -> cor == 'Y'){
        printf(cor_amarela "%02d" resetar_cor "\n", carta -> numero);// O "%02d" faz com que todos os numeros sejao exibidos com dois digitos
    }
    else if (carta -> cor == 'P'){
        if (carta -> numero == 13){
            printf("+4" "\n");
        }
        else{
            printf("%02d" resetar_cor "\n", carta -> numero);
        }
    }
}



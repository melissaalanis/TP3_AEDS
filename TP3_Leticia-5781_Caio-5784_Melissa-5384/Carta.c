#include "Carta.h"

void Inicializa_Carta(Carta* carta, int numero, char cor){ // ORDEM: G, Y, R, B, P
    carta -> numero = numero;
    carta -> cor = cor;
    if (carta -> cor == 'R'){
        carta-> valor_cor= 3;
    }
    else if (carta -> cor == 'G'){
        carta-> valor_cor= 1;
    }
    else if (carta -> cor == 'Y'){
        carta-> valor_cor= 2;
    }
    else if (carta -> cor == 'B'){
        carta-> valor_cor= 4;
    }
    else if (carta -> cor == 'P'){
        carta-> valor_cor= 5;}
} // Sao atribuidos a carta na inicializacao o numero dela e sua cor correspondente

void Printar_Carta(Carta* carta, int numero, char cor){
    if (carta -> cor == 'R'){
        if (carta -> numero == 12){
            printf(cor_vermelha "+2" resetar_cor "\n");
        }
        else{
            printf(cor_vermelha "%02d" resetar_cor  "\n", carta -> numero ); //Quando a variavel cor for igual a R o fundo daquela carta sera vermelho 
        }
    }
    else if (carta -> cor == 'G'){
        if (carta -> numero == 12){
            printf(cor_verde "+2" resetar_cor "\n");
        }
        else{
            printf(cor_verde "%02d" resetar_cor  "\n" , carta -> numero);// Logo apos o numero ser printado com a cor de fundo alterada a cor é redefinida para o padrao
        }
    }
    else if (carta -> cor == 'B'){
        if (carta -> numero == 12){
            printf(cor_azul "+2" resetar_cor "\n");
        }
        else{
            printf(cor_azul "%02d" resetar_cor "\n", carta -> numero);}
    }
    else if (carta -> cor == 'Y'){
        if (carta -> numero == 12){
            printf(cor_amarela "+2" resetar_cor "\n");
        }
        else{
            printf(cor_amarela "%02d" resetar_cor "\n", carta -> numero);// O "%02d" faz com que todos os numeros sejao exibidos com dois digitos
        }
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

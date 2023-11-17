#include "Carta.h"

void Inicializa_Carta(Carta* carta, int numero, char cor){
    carta -> numero = numero;
    carta -> cor = cor;
}

void Printar_Carta(Carta* carta, int numero, char cor){
    if (carta -> cor == 'R'){
        if((carta -> numero) < 10){
            printf(cor_vermelha "0%d" resetar_cor  "\n", carta -> numero );
        }
        else{
        printf(cor_vermelha "%d" resetar_cor  "\n", carta -> numero );
        }
    }
    else if (carta -> cor == 'G'){
        if((carta -> numero) < 10){
            printf(cor_verde "0%d" resetar_cor  "\n", carta -> numero );
        }
        else{
        printf(cor_verde "%d" resetar_cor  "\n" , carta -> numero);
        }
    }
    else if (carta -> cor == 'B'){
        if((carta -> numero) < 10){
            printf(cor_azul "0%d" resetar_cor  "\n", carta -> numero );
        }
        else{
        printf(cor_azul "%d" resetar_cor "\n", carta -> numero);
        }
    }
    else if (carta -> cor == 'Y'){
        if((carta -> numero) < 10){
            printf(cor_amarela "0%d" resetar_cor  "\n", carta -> numero );
        }
        else{
        printf(cor_amarela "%d" resetar_cor "\n", carta -> numero);
        }
    }
    else if (carta -> cor == 'P'){
        printf(cor_preta "\x1b[30m" "%d" resetar_cor "\n", carta -> numero);}
    //%02d
}

 



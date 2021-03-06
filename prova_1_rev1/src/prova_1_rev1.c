/*
 ============================================================================
 Name        : prova_1.c
 Author      : ednei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 ============================================================================
 Name        : p1.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : IFSC
 Description : Prova 01: inversão de listas encadeadas
 ============================================================================
 */

#include <stdio.h>

#include "lista_enc.h"
#include "dados.h"


int main(){
    /* Variáveis */
    lista_enc_t *minha_lista;
    lista_enc_t *minha_lista_invertida;

    minha_lista = ler_arquivo("dados.csv");

    minha_lista_invertida = inverte_lista(minha_lista);

    imprime_dados_lista(minha_lista);

    imprime_dados_lista(minha_lista_invertida);

    libera_memoria_lista(minha_lista);

    libera_memoria_lista_inv(minha_lista_invertida);


    printf("fim prog");


    return 0;
}

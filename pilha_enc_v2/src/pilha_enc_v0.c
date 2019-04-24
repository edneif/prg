/*
 ============================================================================
 Name        : Pilha_enc_v0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>


#include "dados.h"
#include "pilha.h"


int main()
{

   pilha_t *pilha;

   pilha = ler_arquivo("dados.csv");

   imprimi_dados_pilha(pilha);

   libera_memoria(pilha);

   	return 0;


   free(pilha);

    return 0;
}


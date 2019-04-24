/*
 ============================================================================
 Name        : fila_enc_v0.c
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
#include "fila.h"


int main()
{

   fila_t *fila;

   fila = ler_arquivo("dados.csv") ;

   imprimi_dados_fila(fila);

   libera_memoria(fila);

   	return 0;


   free(fila);

    return 0;
}


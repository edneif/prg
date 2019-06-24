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

   fila_t *fila1, *fila2, *fila3;

   fila1 = ler_arquivo("dados.csv");
   fila2 = ler_arquivo("dados.csv");

   fila3 = uniao(fila1,fila2,fila3);

   //imprimi_dados_fila(fila1);
   //imprimi_dados_fila(fila2);
   imprimi_dados_fila(fila3);



   libera_memoria(fila1);
   libera_memoria(fila2);




   return  0;


   free(fila1);
   free(fila2);


    return 0;
}


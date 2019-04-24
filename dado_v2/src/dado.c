/*
 ============================================================================
 Name        : dado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 ============================================================================
 Name        : dado.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //srtlen
#include "tratadado.h"



int main()
{
    int i= 0, n_linha = 0;
    int indice;
    double valor;
    char buffer[64];
    dado_t *coleta1;

    FILE *fp = fopen("dados.csv", "r");

    if (fp == NULL)
    {
        perror("Erro em main: fopen"); /* Imprime erro e aborta */
        exit(EXIT_FAILURE);
    }

    /* Manipulaçao de dados */

    fseek(fp, 10, SEEK_SET);

    while (fgets(buffer,64,fp) !=NULL) //le linha inteira
    {
        n_linha++;
    }

    fseek(fp, 10, SEEK_SET);


    coleta1 =  cria_dado_array(n_linha);


    while ( (fscanf(fp, "%d ;  %16[^;] ; %lf ", &indice, buffer , &valor) == 3 ))
    {

    	 cria_dado_linha(coleta1 , indice, buffer, valor, i);
    	 //printf ("%d %s %lf \n",indice,buffer,valor);
          i++;
     }


    i=0;
    while (i < n_linha)
    {


   	   printf ("%d %s %lf \n",acessa_dado_indice(coleta1, i), acessa_dado_dado(coleta1, i),acessa_dado_valor(coleta1, i) );

     	   i++;
    }



    // Fecha arquivo
   // fclose(fp);
    //free(coleta1);



return 0;
}

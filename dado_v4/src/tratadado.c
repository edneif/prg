/*
 * tratadado.c
 *
 *  Created on: 12 de mar de 2019
 *      Author: ednei.freiberger
 */

/*
 * tratadado.c
 *
 *  Created on: 12 de mar de 2019
 *      Author: ednei.freiberger
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tratadado.h"





struct dados
{
    int indice;
    char *dado;
    double valor;
};

struct controle
{
	dado_t *vetor;
	int n_linhas;
	FILE *fp;
};


controle_t* cria_dado_array (char *nome_arquivo)
{

	FILE *fp = abre_arquivo(nome_arquivo);  //abre aruivo

	int n_linha;

	n_linha = conta_linhas_arquivo(fp);    //conta numero de linhas

	dado_t* p = (dado_t*) malloc(sizeof(dado_t)*n_linha);

	  if (p == NULL) {
	    perror("Memoria insuficiente cria dado array!\n");
	    exit(1);
	  }

     controle_t *controle = (controle_t*) malloc(sizeof(controle_t));
     if (controle == NULL)
        {
    	    perror("Memoria insuficiente cria dado controle!\n");
    	    exit(1);
    	 }



     controle->n_linhas = n_linha;
     controle->vetor = p;
     controle->fp = fp;


	return controle;
}

void cria_dado_linha(dado_t *p, int indice, char *dado, double valor, int posicao)
{

	int tamanho=strlen(dado)+1;
	p[posicao].indice = indice;
	p[posicao].valor = valor;
    p[posicao].dado =  malloc(sizeof(char)*tamanho);
    strncpy(p[posicao].dado,dado,tamanho);


}


int acessa_dado_indice (dado_t* p,  int posicao)
{

	return  p[posicao].indice;

}

char* acessa_dado_dado (dado_t* p,  int posicao)
{

     return p[posicao].dado;

}



double acessa_dado_valor (dado_t* p,  int posicao)
{

	return p[posicao].valor;


}

FILE* abre_arquivo(char *nome_arquivo)

{

	FILE *fp = fopen(nome_arquivo, "r");

	    if (fp == NULL)
	    {
	        perror("Erro em abre arquivo: fopen"); /* Imprime erro e aborta */
	        exit(EXIT_FAILURE);
	    }

	return fp;
}

int conta_linhas_arquivo(FILE *fp)

{
	char buffer[64];
	int n_linha=0;

	fseek(fp, 10, SEEK_SET);

	while (fgets(buffer,64,fp) !=NULL) //le linha inteira
	{
	   n_linha++;
	}


return n_linha;

}

void carrega_dados_estrutura(controle_t* controle)
{
   int indice, i=0;
   char buffer[64];
   double valor;


	fseek(controle->fp, 10, SEEK_SET);


	    while ( (fscanf(controle->fp, "%d ;  %16[^;] ; %lf ", &indice, buffer , &valor) == 3 ))
	    {

	    	 cria_dado_linha(controle->vetor , indice, buffer, valor, i);
	    	 //printf ("%d %s %lf \n",indice,buffer,valor);
	          i++;


	     }


}


void imprime_dados_estrutura(controle_t* controle)
{



    int i=0;
    while (i < controle->n_linhas)
    {


   	   printf ("%d %s %lf \n",acessa_dado_indice(controle->vetor, i), acessa_dado_dado(controle->vetor, i),acessa_dado_valor(controle->vetor, i) );

     	   i++;
    }



}


void libera_memoria(controle_t* controle)
{
	int i = 0;

	while (i<controle->n_linhas)
	{
		free(controle->vetor[i].dado);
		i++;
	}

	free(controle->vetor);
	fclose(controle->fp);
	free (controle);

}

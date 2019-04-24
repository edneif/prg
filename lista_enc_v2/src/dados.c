/*
 * dado.c
 *
 *  Created on: 20 de mar de 2019
 *      Author: ednei.freiberger
 */


/* Demais includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "lista_enc.h"
#include "no.h"

struct dados
{
    int indice;
    char *dado;
    double valor;
};


/* Demais funções */




lista_enc_t *ler_arquivo(char *nome_do_arquivo){

    lista_enc_t *lista;
    dado_t* dados ;
    no_t* elemento ;


    int n_linhas, i=0;

    lista_enc_t *lista =  criar_lista_enc();  //cria lista encadeada

    FILE* fp = ler_arquivo(nome_do_arquivo);  //abre arquivo csv

    n_linhas = conta_linhas_arquivo(fp);   //conta numero linhas

    while ( i < n_linhas )
    {



          dado_t* dados = cria_dado();   //abre struct dado memoria
          cria_dado_linha(dados,i);


    	  elemento = criar_no((void*)nome_1);
    	  add_cauda(lista, elemento);
    	  i++;

    }



    puts("Hello ;-\)");

    // (...)


    return lista;
}


void imprimi_dados_lista(){


     puts("Bye ;-\)");


    // (...)



}




dado_t* cria_dado (void)
{
	dado_t* p = (dado_t*) malloc(sizeof(dado_t));

	  if (p == NULL) {
	    perror("Memoria insuficiente cria dado array!\n");
	    exit(1);
	  }



	return p;
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

void carrega_dados_estrutura(FILE *fp, dado_t *coleta, int n_linhas)
{
   int indice, i=0;
   char buffer[64];
   double valor;


	fseek(fp, 10, SEEK_SET);


	    while ( (fscanf(fp, "%d ;  %16[^;] ; %lf ", &indice, buffer , &valor) == 3 ))
	    {

	    	 cria_dado_linha(coleta , indice, buffer, valor, i);
	    	 //printf ("%d %s %lf \n",indice,buffer,valor);
	          i++;


	     }


}


void imprime_dados_estrutura(dado_t *coleta, int n_linhas)
{



    int i=0;
    while (i < n_linhas)
    {


   	   printf ("%d %s %lf \n",acessa_dado_indice(coleta, i), acessa_dado_dado(coleta, i),acessa_dado_valor(coleta, i) );

     	   i++;
    }



}


void libera_memoria(FILE *fp, dado_t *coleta, int n_linhas)
{
	int i = 0;

	while (i<n_linhas)
	{
		free(coleta[i].dado);
		i++;
	}

	free(coleta);
	fclose(fp);

}

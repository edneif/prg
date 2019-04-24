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



dado_t* cria_dado_array (int n_linhas)
{
	dado_t* p = (dado_t*) malloc(sizeof(dado_t)*n_linhas);

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





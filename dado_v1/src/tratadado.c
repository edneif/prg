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
#include "tratadado.h"




struct dados
{
    int indice;
    int dado;
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

void cria_dado_linha(dado_t* p, int* indice, int* dado, double* valor, int posicao)
{

	p[posicao].indice = *indice;
	p[posicao].dado = *dado;
	p[posicao].valor = *valor;

}

void acessa_dado (dado_t* p, int* indice, int* dado, double* valor, int posicao)
{

    *indice = p[posicao].indice;
    *dado = p[posicao].dado;
    *valor = p[posicao].valor;

}





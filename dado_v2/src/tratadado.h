/*
 * tratadado.h
 *
 *  Created on: 12 de mar de 2019
 *      Author: ednei.freiberger
 */

#ifndef TRATADADO_H_
#define TRATADADO_H_

#define TAM_BUFFER 8

typedef struct dados dado_t;


dado_t* cria_dado_array (int n_linhas);

void cria_dado_linha (dado_t *p ,int indice, char *dado, double valor, int posicao);

int acessa_dado_indice (dado_t *p, int posicao );

char* acessa_dado_dado (dado_t *p, int posicao);

double acessa_dado_valor (dado_t *p, int posicao);



#endif /* TRATADADO_H_ */

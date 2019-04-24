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

void cria_dado_linha (dado_t* p ,int indice, int dado, double valor, int posicao);

void acessa_dado(dado_t* p, int* indice, int* dado, double* valor, int posicao );




#endif /* TRATADADO_H_ */

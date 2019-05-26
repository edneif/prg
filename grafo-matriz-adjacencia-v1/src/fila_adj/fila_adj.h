/*
 * fila_adj.h
 *
 *  Created on: 26 de mai de 2019
 *      Author: ednei_000
 */

#ifndef FILA_ADJ_FILA_ADJ_H_
#define FILA_ADJ_FILA_ADJ_H_


/**********************************************************************
 Title
 Language 		C
 Author			Renan Stark a and Leonardo Benitez
 Date  			03/09/2018
 Description
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
//#define DEBUG

typedef struct filas fila_t;

/**
  * @brief Empilha um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da fila
  * @param fila: fila criada que receberá o dado.
  *
  * @retval Nenhum
  */
int dequeue(fila_t* fila);


/**
  * @brief Enfileira um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da fila
  * @param fila: fila criada que receberá o dado.
  *
  * @retval Nenhum
  */
void enqueue(fila_t* fila, int dado);


/**
  * @brief  Cria uma nova fila de números inteiros
  * @param	tamanho: tamanho da fila desejada
  *
  * @retval fila_t: ponteiro para uma nova fila
  */
fila_t* cria_fila(int tamanho);


/**
  * @brief
  * @param
  *
  * @retval
  */
int queueSize(fila_t* fila);


/**
  * @brief  Libera os dados dinâmicos da fila
  * @param	fila: fila que será liberada
  *
  * @retval Nenhum
  */
void libera_fila(fila_t* fila);



#endif /* FILA_ADJ_FILA_ADJ_H_ */

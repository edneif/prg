/*
 * pilha_adj.h
 *
 *  Created on: 26 de mai de 2019
 *      Author: ednei_000
 */

#ifndef PILHA_ADJ_PILHA_ADJ_H_
#define PILHA_ADJ_PILHA_ADJ_H_



typedef struct pilhas pilha_t;

/**
  * @brief  Cria uma nova pilha com <size> inteiros
  * @param	size
  *
  * @retval pilha_t: ponteiro para uma nova pilha
  */
pilha_t* cria_pilha (int size);


/**
  * @brief  Empilha um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da pilha
  * @param pilha: pilha criada que receberá o dado.
  *
  * @retval Nenhum
  */
void push(pilha_t *pilha, int dado);


/**
  * @brief Desempilha um inteiro.
  * @param pilha: pilha criada que retornará o dado.
  *
  * @retval int: valor inteiro do último dado empilhado.
  */
int pop(pilha_t *pilha);


/**
  * @brief Desempilha um inteiro.
  * @param pilha: pilha criada que retornará o dado.
  *
  * @retval int: valor inteiro do último dado empilhado.
  */
int stackSize (pilha_t* stack);

#endif /* PILHA_ADJ_PILHA_ADJ_H_ */

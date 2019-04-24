/*
 * lista_enc.h
 *
 *  Created on: 15 de mar de 2019
 *      Author: ednei.freiberger
 */

#ifndef LISTA_ENC_H_
#define LISTA_ENC_H_


#include "no.h"

typedef struct listas_enc lista_enc_t;

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (referência) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc(void);

/**
  * @brief  Adiciona um nó de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: nó que será adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t *elemento);



/**
  * @brief  Adiciona um nó de lista no inicio.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: nó que será adicionado na cabeça.
  *
  * @retval Nenhum
  */
void add_cabeca(lista_enc_t *lista, no_t* elemento);



/**
  * @brief  Remove um nó de lista no inicio.
  * @param	lista: lista encadeada que se deseja remover.
  *         elemento: nó que será removido da cabeça.
  *
  * @retval Nenhum
  */
void exc_cabeca(lista_enc_t *lista, no_t *elemento );



/**
  * @brief  Retorna numero elementos da lista.
  * @param	lista: lista encadeada que se deseja .
  *
  * @retval Nenhum
  */
int  qtd_elementos (lista_enc_t *lista );






/**
  * @brief  Obtém a referência do início (cabeça) da lista encadeada.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval no_t *: nó inicial (cabeça) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista);





void uni_lista (lista_enc_t *lista1, lista_enc_t *lista2, lista_enc_t *lista3 );




#endif /* LISTA_ENC_H_ */

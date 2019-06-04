#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

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
void add_cauda(lista_enc_t *lista, no_t* elemento);

/**
  * @brief  Obtém a referência do início (cabeça) da lista encadeada.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval no_t *: nó inicial (cabeça) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista);


/**
  * @brief  imprimi da lista encadeada.
  * @param	lista: lista que se deseja imprimir.
  *
  */
void imprimi_lista ( lista_enc_t * lista );


/**
  * @brief  exclue cabe�a lista encadeada.
  * @param	lista: lista que se deseja imprimir.
  *
  */
void exc_cabeca(lista_enc_t *lista);



/**
  * @brief  exclue cauda lista encadeada.
  * @param	lista: lista que se deseja imprimir.
  *
  */
void exc_cauda(lista_enc_t *lista);




void add_cabeca(lista_enc_t *lista, no_t* elemento);

int obter_tamanho(lista_enc_t * lista);

void swap_no(lista_enc_t* lista, no_t * fonte, no_t *destino);

no_t *obter_cauda(lista_enc_t *lista);

#endif // LISTA_ENC_H_INCLUDED






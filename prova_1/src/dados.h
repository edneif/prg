/*
 * seno_timestamp.h
 *
 *  Created on: Apr 10, 2019
 *      Author: xtarke
 */

#ifndef SENO_TIMESTAMP_H_
#define SENO_TIMESTAMP_H_

#include "lista_enc.h"

typedef struct dados dado_t;

/**
  * @brief  Faz a leitura do arquivo adicionando os dados em uma lista encadeada.
  * @param	nome_do_arquivo: nome e caminho do arquivo CSV a ser lido
  *
  * @retval lista_enc_t *: ponteiro (referência) da nova lista encadeada.
  */
lista_enc_t *ler_arquivo(char *nome_do_arquivo);

/**
  * @brief  Imprime os dados da lista encadeada deste módulo.
  * @param	lista: uma lista encadeada não vazia
  *
  * @retval Nenhum
  */
void imprime_dados_lista(lista_enc_t *lista);

/**
  * @brief  Liberar todos os dados e lista encadeada deste módulo
  * @param	lista: uma lista encadeada não vazia
  *
  * @retval Nenhum
  */
void liberar_dados (lista_enc_t *lista);



lista_enc_t* inverte_lista(lista_enc_t* lista, lista_enc_t *lista_inv);


void libera_memoria(lista_enc_t *lista, lista_enc_t *lista_inv);





#endif /* SENO_TIMESTAMP_H_ */

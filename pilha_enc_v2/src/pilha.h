/*
 * pilha.h
 *
 *  Created on: 22 de mar de 2019
 *      Author: ednei.freiberger
 */

#ifndef PILHA_H_
#define PILHA_H_


#define TAMANHO_DADOS_PILHA 100

typedef struct pilhas pilha_t;

/**
  * @brief  Cria uma nova pilha com TAMANHO_DADOS_PILHA inteiros
  * @param	Nenhum
  *
  * @retval pilha_t: ponteiro para uma nova pilha
  */
pilha_t * cria_pilha (void);

/**
  * @brief  Empilha um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da pilha
  * @param pilha: pilha criada que receberá o dado.
  *
  * @retval Nenhum
  */
void push(void* dado, pilha_t *pilha);

/**
  * @brief Desempilha um inteiro.
  * @param pilha: pilha criada que retornará o dado.
  *
  * @retval int: valor inteiro do último dado empilhado.
  */
void* pop(pilha_t *pilha);



/**
  * @brief Desempilha um inteiro.
  * @param pilha: pilha criada que retornará o dado.
  *
  * @retval int: valor inteiro do último dado empilhado.
  */
int le_tamanho_pilha(pilha_t *pilha);


/**
  * @brief Verifica se a pilha está vazia, se vazia retorna 1.
  * @param pilha: pilha em uso.
  *
  * @retval int: 1 = vazia 0 = não vazia.
  */
int pilha_vazia(pilha_t *pilha);


/**
  * @brief libera lista da memoria free.
  * @param pilha: pilha em uso.
  *
  */
void free_lista(pilha_t *pilha);


#endif /* PILHA_H_ */

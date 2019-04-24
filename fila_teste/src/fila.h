/*
 * fila.h
 *
 *  Created on: 22 de mar de 2019
 *      Author: ednei.freiberger
 */

#ifndef FILA_H_
#define FILA_H_


#define TAMANHO_DADOS_FILA 100

typedef struct filas fila_t;

/**
  * @brief  Cria uma nova fila com TAMANHO_DADOS_fila inteiros
  * @param	Nenhum
  *
  * @retval fila_t: ponteiro para uma nova fila
  */
fila_t * cria_fila (void);

/**
  * @brief  Empilha um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da fila
  * @param fila: fila criada que receberá o dado.
  *
  * @retval Nenhum
  */
void enqueue(void* dado, fila_t *fila);

/**
  * @brief Desempilha um inteiro.
  * @param fila: fila criada que retornará o dado.
  *
  * @retval int: valor inteiro do último dado empilhado.
  */
void* dequeue(fila_t *fila);



/**
  * @brief Desempilha um inteiro.
  * @param fila: fila criada que retornará o dado.
  *
  * @retval int: valor inteiro do último dado empilhado.
  */
int le_tamanho_fila(fila_t *fila);


/**
  * @brief Verifica se a fila está vazia, se vazia retorna 1.
  * @param fila: fila em uso.
  *
  * @retval int: 1 = vazia 0 = não vazia.
  */
int fila_vazia(fila_t *fila);


/**
  * @brief libera lista da memoria free.
  * @param fila: fila em uso.
  *
  */
void free_lista(fila_t *fila);



void uni_fila( fila_t* fila1, fila_t* fila2, fila_t* fila3);



#endif /* FILA_H_ */

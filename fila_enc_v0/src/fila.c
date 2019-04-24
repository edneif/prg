/*
 * fila.c
 *
 *  Created on: 22 de mar de 2019
 *      Author: ednei.freiberger
 */

#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"



struct filas {
	lista_enc_t *lista;
};

/**
 * @brief  Cria uma nova fila com TAMANHO_DADOS_fila inteiros
 * @param	Nenhum
 *
 * @retval fila_t: ponteiro para uma nova fila
 */
fila_t * cria_fila(void) {

	fila_t *p = (fila_t*) malloc(sizeof(fila_t));

	if (p == NULL) {
		perror("cria_fila:");
		exit(EXIT_FAILURE);
	}

	p->lista = criar_lista_enc();

	return p;
}

/**
 * @brief  Empilha um novo inteiro.
 * @param dado: inteiro a ser adicionado no topo da fila
 * @param fila: fila criada que receberá o dado.
 *
 * @retval Nenhum
 */
void enqueue(void* dado, fila_t *p) {
	no_t *no = criar_no(dado);
	add_cauda(p->lista, no);

}

/**
 * @brief Desempilha um inteiro.
 * @param fila: fila criada que retornará o dado.
 *
 * @retval int: valor inteiro do último dado empilhado.
 */
void* dequeue(fila_t *p) {

	if (p->lista == 0) {
		fprintf(stderr, "dequeue() em fila vazia!\n");
		return 0;
	}

	no_t* no = obter_cabeca(p->lista);

	void* dado = obter_dado(no);
	exc_cabeca(p->lista, no);
	free(no);

	return dado;

}

int le_tamanho_fila(fila_t *fila) {

	int tamanho = qtd_elementos(fila->lista);

	return tamanho;
}

int fila_vazia(fila_t *p)
{

	if (!qtd_elementos(p->lista))
		return 0;
	return 1;

}


void free_lista(fila_t *fila)
{

	free(fila->lista);

}



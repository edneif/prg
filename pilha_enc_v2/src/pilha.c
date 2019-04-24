/*
 * pilha.c
 *
 *  Created on: 22 de mar de 2019
 *      Author: ednei.freiberger
 */

#include "pilha.h"

#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"

struct pilhas {
	lista_enc_t *lista;
};

/**
 * @brief  Cria uma nova pilha com TAMANHO_DADOS_PILHA inteiros
 * @param	Nenhum
 *
 * @retval pilha_t: ponteiro para uma nova pilha
 */
pilha_t * cria_pilha(void) {

	pilha_t *p = (pilha_t*) malloc(sizeof(pilha_t));

	if (p == NULL) {
		perror("cria_pilha:");
		exit(EXIT_FAILURE);
	}

	p->lista = criar_lista_enc();

	return p;
}

/**
 * @brief  Empilha um novo inteiro.
 * @param dado: inteiro a ser adicionado no topo da pilha
 * @param pilha: pilha criada que receberá o dado.
 *
 * @retval Nenhum
 */
void push(void* dado, pilha_t *p) {
	no_t *no = criar_no(dado);
	add_cabeca(p->lista, no);

}

/**
 * @brief Desempilha um inteiro.
 * @param pilha: pilha criada que retornará o dado.
 *
 * @retval int: valor inteiro do último dado empilhado.
 */
void* pop(pilha_t *p) {

	if (p->lista == 0) {
		fprintf(stderr, "pop() em pilha vazia!\n");
		return 0;
	}

	no_t* no = obter_cabeca(p->lista);

	void* dado = obter_dado(no);
	exc_cabeca(p->lista, no);
	free(no);

	return dado;

}

int le_tamanho_pilha(pilha_t *pilha) {

	int tamanho = qtd_elementos(pilha->lista);

	return tamanho;
}

int pilha_vazia(pilha_t *p)
{

	if (!qtd_elementos(p->lista))
		return 0;
	return 1;

}


void free_lista(pilha_t *pilha)
{

	free(pilha->lista);

}



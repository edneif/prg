/*
 * huffman.c
 *
 *  Created on: 5 de jun de 2019
 *      Author: ednei.freiberger
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

#include "../fila/fila.h"
#include "../arvore/arvore.h"
#include "huffman.h"

//#define DEBUG

struct huffmans {
	int codchar;
	int freq; /*!< Lista encadeada que contém os dados enfileirados */
	vertice_t *vertivce;
	char *code;
};

arvore_t* huffman(void) {
	int i, tam_frase, raiz;
	int tabela_freq[255];
	char codificacao[16] = "";

	fila_t *fila, *fila_ori;
	vertice_t *vertice;
	huffman_t *huffman_ret1, *huffman_ret2, *huffman_raiz, *huffman_temp;
	arvore_t *arvore = cria_arvore(1);

	raiz = 300;

	fila = cria_fila();
	fila_ori = cria_fila();

	char frase[] = "teste tabela hofmman ok";

	//zera tabela frequencia:
	for (i = 0; i < 255; i++)
		tabela_freq[i] = 0;

	//le frase e carrega tabela_freq;
	tam_frase = sizeof(frase);
	for (i = 0; i < tam_frase - 1; i++)
		tabela_freq[frase[i]]++;

	//enche fila com valores encontrados

	for (i = 0; i < 255; i++)
		if (tabela_freq[i]) {
			huffman_t *huffman = (huffman_t*) malloc(sizeof(huffman_t));
			huffman->codchar = i;
			huffman->freq = tabela_freq[i];
			enqueue(huffman, fila);
			enqueue(huffman, fila_ori);  //guarda copia da lista

			printf("enqueue: %c Freq: %d \n ", huffman->codchar, huffman->freq);

		}

	huffman_ret1 = retorna_fila_menor(fila);
	vertice = arvore_adicionar_vertice_id(arvore, huffman_ret1->codchar);
	vertice_set_freq(vertice, huffman_ret1->freq);

#ifdef DEBUG
	printf("dequeue: %c  %d Freq: %d \n ", huffman_ret1->codchar,
			huffman_ret1->codchar, huffman_ret1->freq);
#endif // DEBUG

	while (!fila_vazia(fila)) {

		huffman_ret2 = retorna_fila_menor(fila);
		if (huffman_ret2->codchar < 300) {			//verifica se nao é raiz
			vertice = arvore_adicionar_vertice_id(arvore,
					huffman_ret2->codchar);
			vertice_set_freq(vertice, huffman_ret2->freq);
		}
#ifdef DEBUG
		printf("dequeue: %c  %d Freq: %d \n ", huffman_ret2->codchar,
				huffman_ret2->codchar, huffman_ret2->freq);
#endif // DEBUG

		huffman_raiz = malloc(sizeof(huffman_t));
		huffman_raiz->codchar = raiz;
		huffman_raiz->freq = huffman_ret1->freq + huffman_ret2->freq;

		vertice = arvore_adicionar_vertice_id(arvore, huffman_raiz->codchar);
		vertice_set_freq(vertice, huffman_raiz->freq);

#ifdef DEBUG
		printf("enqueue: %c  %d Freq: %d \n ", huffman_raiz->codchar,
				huffman_raiz->codchar, huffman_raiz->freq);
#endif // DEBUG

		arvore_adiciona_filhos(arvore, arvore_procura_vertice(arvore, raiz),
				huffman_ret2->codchar, huffman_ret1->codchar); //

		huffman_ret1 = huffman_raiz;
		raiz++;
		fflush(stdout);

	}

	arvore_set_raiz(arvore, vertice);

	//carrega codigo huffman na estrutura
	while (!fila_vazia(fila_ori)) {
		huffman_temp = dequeue(fila_ori);
		cod_huffman(arvore_procura_vertice(arvore, huffman_temp->codchar),
				arvore_get_raiz(arvore), frase[1], &codificacao);
		huffman_temp->code = codificacao;
		printf("cod char: %c  freq: %d  Cod_huff: %s \n ",
				huffman_temp->codchar, huffman_temp->freq, huffman_temp->code);
	    free(huffman_temp);
	}

	free(fila);
	free(fila_ori);
	return (arvore);

}

//---------------------------------------
//retorna o menor prioridade da fila
//retina da fila
//---------------------------------------

huffman_t* retorna_fila_menor(fila_t *fila1) {

	if (fila_vazia(fila1)) {
		perror("retorna_fila_menor: fila vazia");
		exit(EXIT_FAILURE);
	}

	fila_t *fila2;
	fila2 = cria_fila();

	huffman_t *huffman_menor_freq, *huffman_ret;

	// pega um para comparação
	huffman_ret = dequeue(fila1);
	huffman_menor_freq = huffman_ret;
	enqueue(huffman_ret, fila1);

	while (!fila_vazia(fila1)) {

		huffman_ret = dequeue(fila1);
		if (huffman_ret->freq < huffman_menor_freq->freq) {
			huffman_menor_freq = huffman_ret;

		}

		enqueue(huffman_ret, fila2);
	}

	while (!fila_vazia(fila2)) {

		huffman_ret = dequeue(fila2);

		if (!(huffman_ret == huffman_menor_freq)) {

			enqueue(huffman_ret, fila1);
		}

	}

	huffman_ret = huffman_menor_freq;
	free(fila2);
	return huffman_ret;
}

//--------------------------------------------------------------------
//
//retorna o menor prioridade da fila
//retina da fila
//
//--------------------------------------------------------------------

void cod_huffman(vertice_t* no_vert, vertice_t *raiz, char codchar,
		char* codificacao) {
	strcpy(codificacao, "");

	vertice_t *vertice_pai;

	if (!no_vert) {
		fprintf(stderr, "add_cauda: ponteiros invalidos");
		exit(EXIT_FAILURE);
	}

	while (raiz != no_vert) {
		vertice_pai = vertice_get_pai(no_vert);
		if (vertice_get_esq(vertice_pai) == no_vert) { //verifica no esquerda do pai
			//printf("esq\t");
			strcat(codificacao, "0");
		}
		if (vertice_get_dir(vertice_pai) == no_vert) { //verifica no esquerda do pai
			//printf("dir	\t");
			strcat(codificacao, "1");
		}
		no_vert = vertice_pai;

	}

}

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

#include "fila/fila.h"
#include "grafo/grafo.h"
#include "huffman.h"

#define DEBUG

struct huffmans {
	int codchar;
	int freq; /*!< Lista encadeada que cont�m os dados enfileirados */
	vertice_t *vertivce;
	char *code;
};

grafo_t* huffman(void) {
	int i, tam_frase, raiz;
	int tabela_freq[255];

	fila_t *fila;
	huffman_t *huffman_ret1, *huffman_ret2, *huffman_raiz;
	grafo_t *grafo = cria_grafo(1);

	raiz = 300;

	fila = cria_fila();

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

#ifdef DEBUG
			printf("enqueue: %c Freq: %d \n ", huffman->codchar, huffman->freq);
#endif // DEBUG

		}

	huffman_ret1 = retorna_fila_menor(fila);
	grafo_adicionar_vertice(grafo, huffman_ret1->codchar);
#ifdef DEBUG
	printf("dequeue: %c  %d Freq: %d \n ", huffman_ret1->codchar,
			huffman_ret1->codchar, huffman_ret1->freq);
#endif // DEBUG

	while (!fila_vazia(fila)) {

		huffman_ret2 = retorna_fila_menor(fila);
		if (huffman_ret2->codchar < 300)			//verifica se nao � raiz
			grafo_adicionar_vertice(grafo, huffman_ret2->codchar);
#ifdef DEBUG
		printf("dequeue: %c  %d Freq: %d \n ", huffman_ret2->codchar,
				huffman_ret2->codchar, huffman_ret2->freq);
#endif // DEBUG

		huffman_raiz = malloc(sizeof(huffman_t));
		huffman_raiz->codchar = raiz;
		huffman_raiz->freq = huffman_ret1->freq + huffman_ret1->freq;

		grafo_adicionar_vertice(grafo, huffman_raiz->codchar);

#ifdef DEBUG
		printf("enqueue: %c  %d Freq: %d \n ", huffman_raiz->codchar,
				huffman_raiz->codchar, huffman_raiz->freq);
#endif // DEBUG

		adiciona_adjacentes(grafo, procura_vertice(grafo, raiz), 4,
				huffman_ret2->codchar, 0, huffman_ret1->codchar, 1);

		huffman_ret1 = huffman_raiz;
		raiz++;
		fflush(stdout);

	}

	free(fila);
	return (grafo);

}

//retorna o menor prioridade da fila
//retina da fila

huffman_t* retorna_fila_menor(fila_t *fila1) {

	if (fila_vazia(fila1)) {
		perror("retorna_fila_menor: fila vazia");
		exit(EXIT_FAILURE);
	}

	fila_t *fila2;
	fila2 = cria_fila();

	huffman_t *huffman_menor_freq, *huffman_ret;

	// pega um para compara��o
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

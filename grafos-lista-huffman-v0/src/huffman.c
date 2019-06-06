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
	int freq; /*!< Lista encadeada que contém os dados enfileirados */
};

grafo_t* huffman(void) {
	int i, tam_frase, raiz, raiz2;
	int tabela_freq[255];

	fila_t *fila1, *fila2, *fila3;
	huffman_t *huffman_ret;
	grafo_t *grafo = cria_grafo(1);

	huffman_t *huffman_maior_freq1 = (huffman_t*) malloc(sizeof(huffman_t));
	huffman_t *huffman_maior_freq2 = (huffman_t*) malloc(sizeof(huffman_t));
	huffman_maior_freq1->freq = 0;
	huffman_maior_freq2->freq = 0;
	raiz = 300;

	fila1 = cria_fila();
	fila2 = cria_fila();
	fila3 = cria_fila();

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
			enqueue(huffman, fila1);
			if (tabela_freq[i] > huffman_maior_freq1->freq) {
				huffman_maior_freq1->codchar = huffman->codchar;
				huffman_maior_freq1->freq = huffman->freq;
			}

#ifdef DEBUG
			printf("enqueue: %c Freq: %d \n ", huffman->codchar, huffman->freq);
#endif // DEBUG

		}

	while (!fila_vazia(fila1) || !fila_vazia(fila2)) {

		huffman_maior_freq2->freq = 0;
		while (!fila_vazia(fila1)) {

			huffman_ret = dequeue(fila1);
			if (huffman_maior_freq1->codchar == huffman_ret->codchar) {
				printf("maior %c -> %d\n", huffman_ret->codchar,
						huffman_ret->freq);
				grafo_adicionar_vertice(grafo, huffman_ret->codchar);
				if (!(fila_tamanho(fila1) == 0) ||!(fila_tamanho(fila2) == 0) ) {
					grafo_adicionar_vertice(grafo, raiz);
					enqueue(raiz, fila3);
					adiciona_adjacentes(grafo,
							procura_vertice(grafo, huffman_ret->codchar), 2,
							raiz, 0);
					raiz++;
				} else
					adiciona_adjacentes(grafo,
							procura_vertice(grafo, huffman_ret->codchar), 2,
							raiz - 1, 0); //ultimo vertice encontrado, liga com raiz anterior

				free(huffman_ret);
			} else {
				if (huffman_ret->freq > huffman_maior_freq2->freq) {
					huffman_maior_freq2->codchar = huffman_ret->codchar;
					huffman_maior_freq2->freq = huffman_ret->freq;

				}

				enqueue(huffman_ret, fila2);
			}
		}

		huffman_maior_freq1->freq = 0;
		while (!fila_vazia(fila2)) {

			huffman_ret = dequeue(fila2);
			if (huffman_maior_freq2->codchar == huffman_ret->codchar) {
				printf("maior %c -> %d\n", huffman_ret->codchar,						huffman_ret->freq);
				grafo_adicionar_vertice(grafo, huffman_ret->codchar);
				if (!(fila_tamanho(fila1) == 0) || !(fila_tamanho(fila2) == 0)) {
					grafo_adicionar_vertice(grafo, raiz);
					adiciona_adjacentes(grafo,
							procura_vertice(grafo, huffman_ret->codchar), 2,
							raiz, 0);
					enqueue(raiz, fila3);
					raiz++;
				} else
					adiciona_adjacentes(grafo,
							procura_vertice(grafo, huffman_ret->codchar), 2,
							raiz - 1, 0); //ultimo vertice encontrado, liga com raiz anterior
				free(huffman_ret);
			} else {
				if (huffman_ret->freq > huffman_maior_freq1->freq) {
					huffman_maior_freq1->codchar = huffman_ret->codchar;
					huffman_maior_freq1->freq = huffman_ret->freq;

				}

				enqueue(huffman_ret, fila1);
			}
		}

	}

	free(huffman_maior_freq1);
	free(huffman_maior_freq2);

	raiz = (int) dequeue(fila3);
	while (!fila_vazia(fila3)) {
		raiz2 = (int) dequeue(fila3);
		printf("raiz %d  raiz2 %d ", raiz, raiz2);
		adiciona_adjacentes(grafo, procura_vertice(grafo, raiz), 2, raiz2, 1);
		raiz = raiz2;
	}

	return (grafo);

}


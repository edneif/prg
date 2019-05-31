/*
 * heap.c
 *
 *  Created on: 21 de mai de 2019
 *      Author: Leonardo Benniz
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "heap.h"


#define FALSO 0
#define VERDADEIRO 1
#define INFINITE INT_MAX
#define DEBUG
#define DEBUG_MAX_HEAPIFY

struct heaps {
	int indice; /* */
	int tamanho;
	int *vertice; /*array de vertices*/
};

heap_t* heap_cria(int id, int tamanho) {
	int i;
	heap_t* heap;

	heap = malloc(sizeof(heap_t));
	if (heap == NULL) {
		perror("heap_new:");
		exit(EXIT_FAILURE);
	}
	heap->vertice = malloc(sizeof(int) * tamanho);
	if (heap->vertice == NULL) {
		perror("novo heap:");
		exit(EXIT_FAILURE);
	}

	heap->indice = id;
	heap->tamanho = tamanho;
	for (i = 0; i < tamanho; i++) {
		heap->vertice[i] = INFINITE;
	}
#ifdef DEBUG
	printf("Heap %d criado\n", id);
#endif // DEBUG_HEAP
	return heap;
}

void heap_from_vetor(heap_t* heap, int* array, int tamanho) {
	int i, pai_ultimo_indice;

	for (i = 0; i < tamanho; i++) {
		heap_set_vertice(heap, i, array[i]);   //copia array para heap
	}

	pai_ultimo_indice = (tamanho-2)/2;
	for (i = pai_ultimo_indice ; i >= 0 ; i--)
		heap_max_heapify(heap, i);


#ifdef DEBUG
	printf("Heap \n");
	for (i = 0; i < tamanho; i++)
		printf(" %d \t", heap->vertice[i]);
#endif // DEBUG_HEAP

}


void heap_set_vertice(heap_t* heap, int vertice, int valor) {
	if (heap == NULL) {
		fprintf(stderr, "heap inválido!");
		exit(EXIT_FAILURE);
	}
	heap->vertice[vertice] = valor;
}



void heap_max_heapify(heap_t* heap, int vertice) {
	if (heap == NULL) {
		fprintf(stderr, "max_heapify: heap inválido!");
		exit(EXIT_FAILURE);
	}
	int left = heap_get_left_child(heap, vertice);
	int right = heap_get_right_child(heap, vertice);
	int bigger;
	int temp;

	if (left < heap->tamanho && heap_get_vertice(heap, left) != INFINITE
			&& heap_get_vertice(heap, left) > heap_get_vertice(heap, vertice))
		bigger = left;
	else
		bigger = vertice;

	if (right < heap->tamanho && heap_get_vertice(heap, left) != INFINITE
			&& heap_get_vertice(heap, right) > heap_get_vertice(heap, bigger))
		bigger = right;


	if (bigger != vertice) {
		temp = heap_get_vertice(heap, vertice);
		heap_set_vertice(heap, vertice, heap_get_vertice(heap, bigger));
		heap_set_vertice(heap, bigger, temp);
		heap_max_heapify(heap, bigger);

	}
}

int heap_get_vertice(heap_t* heap, int vertice) {
	if (heap == NULL || vertice >= heap->tamanho) {
		fprintf(stderr, "heap_get_vertice: heap ou vértice inválido!");
		exit(EXIT_FAILURE);
	}

	return heap->vertice[vertice];
}

int heap_get_left_child(heap_t* heap, int vertice) {
	if (heap == NULL) {   // || vertice >= heap->size)	{
		fprintf(stderr, "heap_get_left_child: heap ou vértice inválido!");
		exit(EXIT_FAILURE);
	}
	return 2 * vertice + 1;
}

int heap_get_right_child(heap_t* heap, int vertice) {
	if (heap == NULL) {   // || vertex >= heap->size)	{
		fprintf(stderr, "heap_get_right_child: heap ou vértice inválido!");
		exit(EXIT_FAILURE);
	}
	return 2 * vertice + 2;
}

/**
 * @brief  Exporta em formato DOT uma árvore.
 * @param  filename: nome do arquivo DOT gerado.
 * @param  arvore: ponteiro válido de uma árvore.
 *
 * @retval Nenhum
 */
void heap_export_dot(const char *filename, heap_t* heap) {
	FILE *file;
	int i;

	if (filename == NULL || heap == NULL) {
#ifdef DEBUG_HEAP
		fprintf(stderr, "exportar_tree_dot: ponteiros invalidos\n");
#endif // DEBUG_HEAP
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "w");
	if (file == NULL) {
#ifdef DEBUG
		perror("exportar_grafp_dot:");
#endif // DEBUG
		exit(EXIT_FAILURE);
	}

	fprintf(file, "graph {\n");

	///Print vertices
	for (i = 0; i < heap->tamanho; i++) {
		if (heap_get_vertice(heap, i) != INFINITE)
			fprintf(file, "%d [label=%d];\n", i, heap_get_vertice(heap, i));

	}
	fprintf(file, "\n");

	///Print arestas
	for (i = 0; i < heap->tamanho; i++) { //TODO: preciso verificar se o filho está dentro do range do meu heap, ou posso só varrer metade do heap?
		if (heap_get_left_child(heap, i)
				< heap->tamanho&& heap_get_vertice(heap, heap_get_left_child(heap, i))!=INFINITE)
			fprintf(file, "%d -- %d;\n", i, heap_get_left_child(heap, i));
		if (heap_get_right_child(heap, i)
				< heap->tamanho&& heap_get_vertice(heap, heap_get_right_child(heap, i))!=INFINITE)
			fprintf(file, "%d -- %d;\n", i, heap_get_right_child(heap, i));
	}
	fprintf(file, "}");
	fclose(file);
}


void libera_heap (heap_t* heap){

	free(heap->vertice);
	free(heap);


}

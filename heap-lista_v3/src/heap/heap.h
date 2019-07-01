/*
 * heap.h
 *
 *  Created on: 21 de mai de 2019
 *      Author: ednei.freiberger
 */

#ifndef HEAP_HEAP_H_
#define HEAP_HEAP_H_

typedef struct heaps heap_t;
typedef struct dados dado_t;


heap_t* heap_cria (int id, int tamanho);

void heap_from_vetor (heap_t* heap, int* array, int tamanho);

void heap_set_vertice (heap_t* heap, int vertice, int valor);

void heap_max_heapify (heap_t* heap, int vertice);

int heap_get_vertice (heap_t* heap, int vertice);

int heap_get_left_child (heap_t* heap, int vertice);

int heap_get_right_child (heap_t* heap, int vertice);

void heap_export_dot (const char *filename, heap_t* heap);

void libera_heap (heap_t* heap);

void heap_sort(heap_t *heap);

void swap (int *x, int *y);

void heap_set_tamanho(heap_t *heap, int tamanho);



#endif /* HEAP_HEAP_H_ */

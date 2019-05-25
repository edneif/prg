/*
 * heap.h
 *
 *  Created on: 21 de mai de 2019
 *      Author: ednei.freiberger
 */

#ifndef HEAP_HEAP_H_
#define HEAP_HEAP_H_

typedef struct heaps heap_t;



typedef struct heaps heap_t;

heap_t* heap_cria (int id, int tamanho);

void heap_from_vetor (heap_t* heap, int* array, int tamanho);

void heap_set_vertice (heap_t* heap, int vertice, int valor);

void heap_max_heapify (heap_t* heap, int vertice);

int heap_get_vertice (heap_t* heap, int vertice);

int heap_get_left_child (heap_t* heap, int vertice);

int heap_get_right_child (heap_t* heap, int vertice);








#endif /* HEAP_HEAP_H_ */

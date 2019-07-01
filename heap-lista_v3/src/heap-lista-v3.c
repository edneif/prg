/*
 ============================================================================
 Name        : arvores-lista-v0.c
 Author      : ednei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 ============================================================================
 Name        : arvores.c
 Author      :
 Version     :
 Copyright   : Renan Augusto Starke, todos os direitos reservados
 Description : arvores com lista encadeadas, Ansi-style
 : estruturas disponiveis:
 : pilha e fila
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#include "heap/heap.h"


#define tamanho_array 10

int main(void) {
	int i;
	int array[tamanho_array];
	heap_t *heap, *heap2;

	clock_t heap_start = 0, heap_end = 0, heap_total = 0;


	//int array[] = {8,8,2,5,9,1,10,30,40,15};
	srand(time(NULL));
	for (i = 0; i < tamanho_array; i++) {
		array[i] = rand() % tamanho_array;
	}

	heap = heap_cria(1, tamanho_array);
	heap2 = heap_cria(2, tamanho_array);

	heap_from_vetor(heap, &array[0], tamanho_array);
	heap_from_vetor(heap2, &array[0], tamanho_array);

	heap_export_dot("heap.dot", heap);



	puts("!!!iniciando Heap_sort!!!\n");
	heap_start = clock();
	heap_sort(heap2);
	heap_end = clock();
	heap_total = heap_end - heap_start;
	printf("\n| Heap Total  | %f",
			(double) heap_total / (CLOCKS_PER_SEC));




	libera_heap(heap);

	printf("\nfim progr v01");

	return EXIT_SUCCESS;


}

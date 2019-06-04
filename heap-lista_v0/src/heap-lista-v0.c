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
	//int array[tamanho_array];
	heap_t * heap;

	int array[] = {8,8,2,5,9,1,0,2,2,7};
	srand(time(NULL));

	for (i = 0; i < tamanho_array; i++) {
		//array[i] = rand() % tamanho_array;
	}

	heap = heap_cria(1, tamanho_array);
	heap_from_vetor(heap, &array[0], tamanho_array);

	heap_export_dot("heap.dot", heap);

	libera_heap(heap);

	printf("\nfim progr v000");

	return EXIT_SUCCESS;


}

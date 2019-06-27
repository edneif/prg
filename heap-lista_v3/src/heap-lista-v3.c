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
#include "tarefa.h"

#define tamanho_array 10

int main(void) {
	int i;
	int array[tamanho_array];
	heap_t *heap;

	int n_tarefas;
	lista_enc_t* lista_tarefas;
	tarefa_t **vetor;

	/* Carrega dados e imprime */
	lista_tarefas = importar_csv_linkedList("dados.csv");
	n_tarefas = obter_tamanho(lista_tarefas);
	imprimir_lista_tarefas(lista_tarefas);

	/* Passa para um vetor e ordena o vetor */
	vetor = lista_para_vetor(lista_tarefas);

	//int array[] = {8,8,2,5,9,1,10,30,40,15};
	srand(time(NULL));
	for (i = 0; i < tamanho_array; i++) {
		array[i] = rand() % tamanho_array;
	}

	heap = heap_cria(1, n_tarefas);

	heap_from_vetor(heap, vetor, n_tarefas);


	//heap_export_dot("heap.dot", heap);

	//heap_sort(heap);

	//libera_heap(heap);

	printf("\nfim progr v03");

	return EXIT_SUCCESS;

}

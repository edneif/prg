/*
 ============================================================================
 Name        : teste3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * main.c
 *
 *  Created on: Jun 14, 2017
 *      Author: Renan Augusto Starke
 */

#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"
#include "tarefa.h"


int main(){

	int n_tarefas;
	lista_enc_t* lista_tarefas;
	tarefa_t **vetor;

	lista_tarefas = importar_csv_linkedList("dados.csv");
	//imprimir_lista_tarefas(lista_tarefas);

    /* Teste aqui suas funções */
    n_tarefas = obter_tamanho(lista_tarefas);
    vetor = lista_para_vetor(lista_tarefas);
    imprimir_vetor(vetor, n_tarefas);

    vetor_para_lista(lista_tarefas, vetor);
    imprimir_lista_tarefas(lista_tarefas);
    // ordenação
    mergesort(vetor, n_tarefas);

    //vetor ordenado
    printf("vetor ordenado\n");
    imprimir_vetor(vetor, n_tarefas);

    vetor_para_lista(lista_tarefas, vetor);

    //lista ordenada
    printf("lista ordenado\n");
    imprimir_lista_tarefas(lista_tarefas);

    /* Dica: use
             - void imprimir_vetor(tarefa_t **vetor, int tam);
             - void imprimir_lista_tarefas(lista_enc_t *lista); */

    //liberando a memória
    libera_lista_tarefas(lista_tarefas);
    libera_tarefas(vetor, n_tarefas);

    printf("fim prog");

	return 0;
}















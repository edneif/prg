/*
 * main.c
 *
 *  Created on: Dec 03, 2018
 *      Author: Renan Augusto Starke
 */

#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"
#include "tarefa.h"
/*
Complexidade do código:
--------------------------------------------------------------------------
Tarefa                          | Complexidade
carregar a imprimir             | O(n), pois o tempo é proporcional ao tamanho do arquivo
Passar para vetor               | O (n)
QuickSort                       | O(n*log(n)), pois o swap pode ser feito em tempo constante (que é o motivo de utilizarmos um vetor ao invés de uma lista encadeada)
Passar para lista e imprimir    | O(n)
Liberação de memória         | O(n), pois o tempo é proporcional ao tamanho alocado
*/
int main(){

	int n_tarefas;
	lista_enc_t* lista_tarefas;
	tarefa_t **vetor;

	/* Carrega dados e imprime */
	lista_tarefas = importar_csv_linkedList("dados.csv");
	n_tarefas = obter_tamanho(lista_tarefas);
	imprimir_lista_tarefas(lista_tarefas);

    /* Passa para um vetor e ordena o vetor */
    vetor = lista_para_vetor (lista_tarefas);
    quick_sort(vetor, 0, n_tarefas-1);
    printf ("\nQuick Sort done \n\n");
    /* Passa para a lista e imprime */
    vetor_para_lista (lista_tarefas, vetor);
    imprimir_lista_tarefas(lista_tarefas);

	/* Liberação de memória */
    libera_lista_tarefas(lista_tarefas);
    libera_vetor (vetor);
	return 0;
	printf("oi");
}

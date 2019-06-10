/*
 ============================================================================
 Name        : prova_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 ============================================================================
 Name        : main.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Instituto Federal de Santa Catarina
 Description : prova grafos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"


int main(void) {

    grafo_t *g;

	/* Cria um grafo com seis v�rtices */
	g = cria_grafo(6);

	/* Cria as arestas */
	cria_adjacencia_nao_dir(g,0,1,7);
	cria_adjacencia_nao_dir(g,0,2,9);
	cria_adjacencia_nao_dir(g,0,5,14);
	cria_adjacencia_nao_dir(g,1,2,10);
	cria_adjacencia_nao_dir(g,1,3,13);
	cria_adjacencia_nao_dir(g,2,3,11);
	cria_adjacencia_nao_dir(g,3,4,6);
	cria_adjacencia_nao_dir(g,5,4,9);
	cria_adjacencia_nao_dir(g,5,2,2);

	/* Chamada de bellman_ford */
	bellman_ford(g,0);

    /* Impress�o do caminho */
	imprimir_caminho(g, 0, 4);

	/* Exporta��o  do grafo */
	exportar_grafo_dot("grafo_dist.dot", g);

	/* Libera��o da mem�ria */
	libera_grafo(g);

	printf("\nfim prog  ");

	return EXIT_SUCCESS;
}

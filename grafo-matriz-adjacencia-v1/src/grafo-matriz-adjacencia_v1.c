/*
 ============================================================================
 Name        : grafo-matriz-adjacencia.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjacencia, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(void) {


	int i,j;
	grafo_t *g;

    /* Cria grafo com 30 vértices */
	g = cria_grafo(30);

	/*    Adicionar arestas    *
	 *------------------------ *
	 *                         *
	 *                         *
	 *                         *
	 *                         *
	 *                         *
	 ***************************/

		cria_adjacencia(g, 1, 2);
		cria_adjacencia(g, 1, 3);
		cria_adjacencia(g, 2, 1);
		cria_adjacencia(g, 2, 3);
		cria_adjacencia(g, 2, 5);
		cria_adjacencia(g, 2, 4);
		cria_adjacencia(g, 4, 2);
		cria_adjacencia(g, 4, 5);
		cria_adjacencia(g, 5, 2);
		cria_adjacencia(g, 5, 3);
		cria_adjacencia(g, 5, 4);
		cria_adjacencia(g, 5, 6);
		cria_adjacencia(g, 6, 5);
		cria_adjacencia(g, 3, 1);
		cria_adjacencia(g, 3, 2);
		cria_adjacencia(g, 3, 5);
		cria_adjacencia(g, 3, 7);
		cria_adjacencia(g, 3, 8);
		cria_adjacencia(g, 7, 8);
		cria_adjacencia(g, 7, 3);
		cria_adjacencia(g, 8, 3);
		cria_adjacencia(g, 8, 7);





	/* Imprime matriz */
	for (i=0; i < 20; i++){
		for (j=0; j < 20; j++)
			printf("[%d] [%d] : %d\n", i,j, adjacente(g,i,j));
	}

	exportar_grafo_dot("grafo.dot", g);

	libera_grafo(g);


	printf("fim prg v1");
	return EXIT_SUCCESS;
}

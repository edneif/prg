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

#include "pilha/pilha.h"
#include "fila/fila.h"
#include "arvore/arvore.h"
#include "heap/heap.h"


int main(void) {

	arvore_t *arvore;
	vertice_t* vertice;

	arvore = cria_arvore(0);


	//Adiciona todos os vertices na arvore
	vertice = arvore_adicionar_vertice_id(arvore, 16);
	arvore_set_raiz(arvore, vertice);
	vertice = arvore_adicionar_vertice_id(arvore, 14);
	vertice = arvore_adicionar_vertice_id(arvore, 10);
	vertice = arvore_adicionar_vertice_id(arvore, 8);
	vertice = arvore_adicionar_vertice_id(arvore, 7);
	vertice = arvore_adicionar_vertice_id(arvore, 2);
	vertice = arvore_adicionar_vertice_id(arvore, 4);
	vertice = arvore_adicionar_vertice_id(arvore, 1);
	vertice = arvore_adicionar_vertice_id(arvore, 9);
	vertice = arvore_adicionar_vertice_id(arvore,3);

	arvore_adiciona_filhos(arvore, arvore_procura_vertice(arvore,16),14,10);
	arvore_adiciona_filhos(arvore, arvore_procura_vertice(arvore,14),8,7);
	arvore_adiciona_filhos(arvore, arvore_procura_vertice(arvore,8),2,4);
	arvore_adiciona_filhos(arvore, arvore_procura_vertice(arvore,7),1, -1);  //sem filho direita
	arvore_adiciona_filhos(arvore, arvore_procura_vertice(arvore,10),9, 3);


	arvore_exportar_grafo_dot("arvore.dot", arvore);

	bfs_pre_ordem_interativo(arvore_procura_vertice(arvore,16));

	bfs_pos_ordem_recusivo(arvore_procura_vertice(arvore,16));

	bfs_ordem_recusivo(arvore_procura_vertice(arvore,16));

    dfs(arvore, arvore_procura_vertice(arvore,16));




	libera_arvore(arvore);


	printf ("fim progr v0");

	return EXIT_SUCCESS;
}

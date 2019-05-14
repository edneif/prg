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





int main(void) {


	arvore_t *arvore;
	arvore_t *arvore_bfs;
	arvore_t *arvore_dfs;


	vertice_t* vertice;
	vertice_t* vertice_inicial;

	int id;

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






	//arvore_bfs = bfs(arvore, vertice_inicial);
	//arvore_dfs = dfs(arvore, vertice_inicial);

	//fflush(stdout);
	arvore_exportar_grafo_dot("arvore.dot", arvore);
//	exportar_arvore_dot("arvore_bfs.dot", arvore_bfs);
//	exportar_arvore_dot("arvore_dfs.dot", arvore_dfs);



	libera_arvore(arvore);
	//libera_arvore(arvore_bfs);
	//libera_arvore(arvore_dfs);


	printf ("fim progr v00");

	return EXIT_SUCCESS;
}

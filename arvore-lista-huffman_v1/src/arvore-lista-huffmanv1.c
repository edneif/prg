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
#include "huffman/huffman.h"

int main(void) {

	arvore_t *arvore;

	arvore = huffman();

	arvore_exportar_grafo_dot("huffman.dot", arvore);

	libera_arvore(arvore);

	printf("fim prog v1 ");

	return EXIT_SUCCESS;

}

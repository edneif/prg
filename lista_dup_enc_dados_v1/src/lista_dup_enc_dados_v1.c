/*
 ============================================================================
 Name        : lista_enc_dados_v0.c
 Author      : ednei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "dados.h"



int main() {


	lista_enc_t *lista;

	lista = ler_arquivo("dados.csv");

	imprimi_dados_lista(lista);

	bubblesort(lista);

	imprimi_dados_lista(lista);

	libera_memoria(lista);

	printf("fim prog v1");

	return 0;

}

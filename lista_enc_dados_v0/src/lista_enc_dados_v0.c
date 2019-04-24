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

/* Demais includes */

int main() {

	/* Variáveis */
	lista_enc_t *minha_lista;

	minha_lista = ler_arquivo("dados.csv");

	imprimi_dados_lista(minha_lista);

	libera_memoria(minha_lista);

	return 0;
}

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

 //   imprimi_dados_lista_cabeca(lista);

    imprimi_dados_lista_cauda(lista);

	libera_memoria(lista);

	printf ("fim prog main");

	return 0;
}

/* Demais includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "fila.h"
#include "lista_enc.h"
#include "no.h"
#include "dados.h"

//#define DEBUG

struct dados {
	int indice;
	char *dado;
	double valor;
};

/* Demais funções */

fila_t* ler_arquivo(char *nome_arquivo) {
	int indice;
	char buffer[64];
	double valor;

	dado_t* dado;
	fila_t* fila;

	FILE* fp = abre_arquivo(nome_arquivo);  //abre arquivo verifica de deu falha

	fseek(fp, 10, SEEK_SET);  			//deixa ponteiro para o primeiro dado

	fila = cria_fila();               //aloca memoria para fila / cria lista

	while ((fscanf(fp, "%d ;  %63[^;] ; %lf ", &indice, buffer, &valor) == 3)) {


		dado = cria_dado_linha(indice, buffer, valor);   // aloca memoria dado enche linha com dados arquivo
#ifdef DEBUG
				printf ("%d %s %lf \n",indice,buffer,valor);
#endif // DEBUG

		//	add_cauda(lista, meu_no); //adiciona um elemeto cauda da lista e faz link no
		enqueue(dado, fila);

	}
	fclose(fp);
	return fila;
}

void imprimi_dados_fila(fila_t *fila) {
	int numero;

	dado_t *dado;

	numero = fila_vazia(fila);

	while (numero) {

		dado = dequeue(fila);

		printf("%d %s %lf \n", dado->indice, dado->dado, dado->valor);
		free(dado->dado);
		free(dado);
		numero = fila_vazia(fila);  //verifica se fila est� vazia.
	}

	printf("fim prog");

}

dado_t* cria_dado_linha(int indice, char *dado, double valor)
{

	dado_t* p = (dado_t*) malloc(sizeof(dado_t));

	if (p == NULL) {

		perror("Memoria insuficiente cria dado !\n");
		exit(1);
	}

	int tamanho = strlen(dado) + 1;
	p->indice = indice;
	p->valor = valor;
	p->dado = malloc(sizeof(char) * tamanho);
	strncpy(p->dado, dado, tamanho);

	return p;
}

FILE* abre_arquivo(char *nome_arquivo)

{

	FILE *fp = fopen(nome_arquivo, "r");

	if (fp == NULL) {
		perror("Erro em abre arquivo: fopen"); /* Imprime erro e aborta */
		exit(EXIT_FAILURE);
	}

	return fp;
}

void libera_memoria(fila_t *p) {

	free_lista(p);
	free(p);

}


fila_t* uniao(fila_t *fila1, fila_t* fila2, fila_t* fila3)

{


     fila3 = cria_fila();

     uni_fila(fila1,fila2,fila3);


   return fila3;

}




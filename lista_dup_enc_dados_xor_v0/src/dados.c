/* Demais includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "lista_enc.h"
#include "no.h"

//#define DEBUG

struct dados {
	int indice;
	char *dado;
	double valor;
};

/* Demais funções */

lista_enc_t* ler_arquivo(char *nome_arquivo) {
	int indice;
	char buffer[64];
	double valor;

	dado_t* dado;
	no_t* meu_no;
	lista_enc_t *lista;

	FILE* fp = abre_arquivo(nome_arquivo);   //abre arquivo
	if (fp == NULL) {
		perror("Erro em dados: fopen"); /* Imprime erro e aborta */
		exit(EXIT_FAILURE);
	}

	fseek(fp, 10, SEEK_SET);  			//deixa ponteiro para o primeiro dado
	lista = criar_lista_enc();  			//aloca memoria para lista

	while ((fscanf(fp, "%d ;  %63[^;] ; %lf ", &indice, buffer, &valor) == 3)) {

		dado = cria_dado();  				//aloca memoria para dado
		meu_no = criar_no(dado); // aloca memoria para no e carrega ender�o de dado

		cria_dado_linha(dado, indice, buffer, valor); //enche linha com dados arquivo
#ifdef DEBUG
				printf ("%p \n ",meu_no);
				printf ("%d %s %lf \n",indice,buffer,valor);
#endif // DEBUG

		add_cauda(lista, meu_no); //adiciona um elemeto cauda da lista e faz link no

	}
	fclose(fp);
	return lista;
}

void imprimi_dados_lista_cabeca(lista_enc_t *lista) {

	dado_t * dado = exc_cabeca(lista);
	free(dado->dado);
	free(dado);
	dado = exc_cauda(lista);
	free(dado->dado);
	free(dado);


	no_t *meu_no = obter_cabeca(lista);
	no_t *meu_no_cauda = obter_cauda(lista);
	no_t *meu_no_anterior, *meu_no_proximo;



	if (meu_no) {
		meu_no_anterior = meu_no;
		imprime_dados_estrutura(obter_dado(meu_no));
		meu_no = obter_proximo(meu_no);
#ifdef DEBUG
		printf ("%p -------- primeiro dado pela cabe�a ------\n",meu_no);
#endif

	}

	while (meu_no != meu_no_cauda && meu_no) {

		imprime_dados_estrutura(obter_dado(meu_no));
		meu_no_proximo = obter_proximo_XOR(meu_no_anterior, meu_no);
		meu_no_anterior = meu_no;
		meu_no = meu_no_proximo;
#ifdef DEBUG
printf ("%p \n",meu_no);
#endif
		if (meu_no == meu_no_cauda)
			imprime_dados_estrutura(obter_dado(meu_no));
	}

}

void imprimi_dados_lista_cauda(lista_enc_t *lista) {

	no_t *meu_no = obter_cauda(lista);
	no_t *meu_no_cabeca = obter_cabeca(lista);
	no_t *meu_no_anterior, *meu_no_proximo;

	if (meu_no)

	{
		meu_no_anterior = meu_no;
		imprime_dados_estrutura(obter_dado(meu_no));
		meu_no = obter_anterior(meu_no);
#ifdef DEBUG
printf ("%p -----  primeiro dado pela cauda ------\n",meu_no);
#endif
	}

	while (meu_no != meu_no_cabeca && meu_no) {

		imprime_dados_estrutura(obter_dado(meu_no));
		meu_no_proximo = obter_anterior_XOR(meu_no_anterior, meu_no);
		meu_no_anterior = meu_no;
		meu_no = meu_no_proximo;
#ifdef DEBUG
printf ("%p \n",meu_no);
#endif
		if (meu_no == meu_no_cabeca)
			imprime_dados_estrutura(obter_dado(meu_no));
	}

}

dado_t* cria_dado(void) {
	dado_t* p = (dado_t*) malloc(sizeof(dado_t));

	if (p == NULL) {

		perror("Memoria insuficiente cria dado !\n");
		exit(1);
	}

	return p;
}

void cria_dado_linha(dado_t *p, int indice, char *dado, double valor) {

	int tamanho = strlen(dado) + 1;
	p->indice = indice;
	p->valor = valor;
	p->dado = malloc(sizeof(char) * tamanho);
	strncpy(p->dado, dado, tamanho);

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

void imprime_dados_estrutura(dado_t *coleta) {

	printf("%d %s %lf \n", coleta->indice, coleta->dado, coleta->valor);

}

void libera_memoria(lista_enc_t *lista) {

	dado_t* dado;
	no_t *meu_no = obter_cauda(lista);
	no_t *meu_no_cabeca = obter_cabeca(lista);
	no_t *meu_no_anterior, *meu_no_proximo;

	if (meu_no)

	{
		meu_no_anterior = meu_no;
		meu_no = obter_anterior(meu_no);
		dado = obter_dado(meu_no_anterior);
		free(dado->dado);
		free(dado);

	}

	while (meu_no != meu_no_cabeca && meu_no) {

		meu_no_proximo = obter_anterior_XOR(meu_no_anterior, meu_no);
		dado = obter_dado(meu_no);
		free(dado->dado);
		free(dado);
		free(meu_no_anterior);
		meu_no_anterior = meu_no;
		meu_no = meu_no_proximo;

		if (meu_no == meu_no_cabeca) {
			dado = obter_dado(meu_no);
			free(dado->dado);
			free(dado);
			free(meu_no);
			free(meu_no_anterior);
		}
	}

	free(lista);

}


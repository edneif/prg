/*
 * seno_timestamp.c
 *
 *  Created on: Apr 10, 2019
 *      Author: xtarke
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Demais includes */

#include "dados.h"
#include "lista_enc.h"

struct dados {
	int i; /*!< Ã�ndice do dado. */
	char *id; /*!< Identificador string do dado. */
	float dado; /*!< Dado numÃ©rico associado ao Ã­ndice e identificador. */
};


//#define DEBUG

lista_enc_t *ler_arquivo(char *nome_do_arquivo) {

	int i;
	char buffer[64], id[64];
	float dado;
	FILE *fp;
	lista_enc_t *lista;

	lista = criar_lista_enc();

	fp = fopen(nome_do_arquivo, "r");

	if (!fp) {
		perror("ler_arquivo");
		exit(-1);
	}

	/* Ignora cabeÃ§lho */
	fgets(buffer, 64, fp);

	while (fgets(buffer, 64, fp) != NULL) {

		/* ToDO: Reportar erros nas linhas caso sscanf falhe */
		sscanf(buffer, "%d;%63[^;];%f", &i, id, &dado);

		dado_t *meu_dado = malloc(sizeof(dado_t));

		if (!meu_dado) {
			perror("ler_arquivo");
			exit(-1);
		}

		/* Cria meu dado */
		meu_dado->i = i;
		meu_dado->id = malloc(strlen(id) + 1);
		strcpy(meu_dado->id, id);
		meu_dado->dado = dado;

		/* Adiciona na lista */
		no_t *meu_no = criar_no(meu_dado);
		add_cauda(lista, meu_no);
	}
	fclose(fp);

	return lista;
}

void imprime_dados_lista(lista_enc_t *lista) {
	no_t *meu_no;

	/* Lista todos os elementos adicionados */
	for (meu_no = obter_cabeca(lista); meu_no != NULL;
			meu_no = obter_proximo(meu_no)) {
		dado_t *meu_dado = obter_dado(meu_no);
		printf("%d %s %f\n", meu_dado->i, meu_dado->id, meu_dado->dado);
	}
}






void libera_memoria_lista(lista_enc_t *lista)
{

	dado_t *dado;
	no_t *no_anterior;
	no_t *meu_no = obter_cabeca(lista);

	while (meu_no) {
		dado = obter_dado(meu_no);
		free(dado->id);
		free(dado);

		no_anterior = meu_no;
		meu_no = obter_proximo(meu_no);
		free(no_anterior);
	}

	free(lista);

}







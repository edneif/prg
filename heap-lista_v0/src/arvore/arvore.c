/*
 * arvore.c
 *
 *  Created on: 13 de mai de 2019
 *      Author: ednei.freiberger
 */

/*
 * arvore.c
 *
 *  Created on: Nov 25, 2016
 *      Author: Renan Augusto Starke
 */


#include <stdio.h>
#include <stdlib.h>

#include "../arvore/vertice.h"
#include "../arvore/arvore.h"
#include "../fila/fila.h"
#include "../pilha/pilha.h"


#define FALSE 0
#define TRUE 1
#define DEBUG

struct arvores {
	int id; /*!< Identifica��o num�rica da �rvore */
	vertice_t *raiz; /*!< Ponteiro para o v�rtice raiz  */
	lista_enc_t *vertices; /*!< Lista encadeada de v�rtices  */
};

/**
 * @brief  Cria uma �rvore. Grau depende do v�rtice.
 * @param	id: identifica��o num�rica da �rvore.
 *
 * @retval arvore_t: ponteiro para uma nova �rvore.
 */
arvore_t *cria_arvore(int id) {
	arvore_t *p = NULL;

	p = (arvore_t*) malloc(sizeof(arvore_t));

	if (p == NULL) {
		perror("cria_grafo:");
		exit(EXIT_FAILURE);
	}

	p->id = id;
	p->vertices = cria_lista_enc();

	return p;
}

/**
 * @brief  Adiciona um v�rtice na �rvore. Essa fun��o cria um novo v�rtice.
 * @param  arvore: ponteiro v�lido de uma �rvore.
 * @param	id: identifica��o num�rica do v�rtice.
 *
 * @retval vertice_t: ponteiro do novo v�rtice criado e adicionado na �rvore.
 */
vertice_t* arvore_adicionar_vertice_id(arvore_t *arvore, int id) {
	vertice_t *vertice;
	no_t *no;

#ifdef DEBUG
	printf("grafo_adicionar_vertice: %d\n", id);
#endif

	if (arvore == NULL) {
		fprintf(stderr, "grafo_adicionar_vertice: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	if (arvore_procura_vertice(arvore, id) != NULL) {
		fprintf(stderr, "grafo_adicionar_vertice: vertice duplicado!\n");
		exit(EXIT_FAILURE);
	}

	vertice = cria_vertice(id);
	no = cria_no(vertice);

	add_cauda(arvore->vertices, no);

	return vertice;
}

/**
 * @brief  Adiciona um v�rtice criado na �rvore. Essa fun��o N�O cria um novo v�rtice.
 * @param  arvore: ponteiro v�lido de uma �rvore.
 * @param	vertice: ponteiro v�lido de um v�rtice.
 *
 * @retval vertice_t: ponteiro do v�rtice adicionado na �rvore.
 */
vertice_t* arvore_adicionar_vertice(arvore_t *arvore, vertice_t *vertice) {
	no_t *no;

#ifdef DEBUG
	printf("grafo_adicionar_vertice: %d\n", vertice_get_id(vertice));
#endif

	if (arvore == NULL) {
		fprintf(stderr, "grafo_adicionar_vertice: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	no = cria_no(vertice);

	add_cauda(arvore->vertices, no);

	return vertice;
}

/**
 * @brief  Procura um v�rtice com identificador espec�fico na �rvore.
 * @param  arvore: ponteiro v�lido de uma �rvore.
 * @param	id: identificador do v�rtice procurado.
 *
 * @retval vertice_t: NULL se v�rtice n�o pertencer a �rvore. Um um ponteiro v�lido caso contr�rio.
 */
vertice_t* arvore_procura_vertice(arvore_t *arvore, int id) {
	no_t *no_lista;
	vertice_t *vertice;
	int meu_id;

	if (arvore == NULL) {
		fprintf(stderr, "procura_vertice: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	if (lista_vazia(arvore->vertices) == TRUE)
		return FALSE;

	no_lista = obter_cabeca(arvore->vertices);

	while (no_lista) {
		//obtem o endereco da lista
		vertice = obter_dado(no_lista);

		//obterm o id do vertice
		meu_id = vertice_get_id(vertice);

		if (meu_id == id) {
			return vertice;
		}

		no_lista = obtem_proximo(no_lista);
	}

	return NULL;
}

/**
 * @brief  Configura os filhos de um v�rtices PERTENCENTES � um �rvore por identificador.
 * @param  arvore: ponteiro v�lido de uma �rvore.
 * @param  vertice: ponteiro de um v�rtice � ser configurado.
 * @param	esq: identificador num�rico do v�rtice � esquerda.
 * @param	dir: identificador num�rico do v�rtice � direita.
 *
 * @retval Nenhum
 */
void arvore_adiciona_filhos(arvore_t * arvore, vertice_t *vertice, int esq,
		int dir) {
	vertice_t *esquerda;
	vertice_t *direita;

	if (arvore == NULL) {
		fprintf(stderr, "arvore_adiciona_filhos: arvore invalida!");
		exit(EXIT_FAILURE);
	}

	if (esq != -1) {
		esquerda = arvore_procura_vertice(arvore, esq);
		vertice_set_pai(esquerda, vertice);
		vertice_set_esq(vertice, esquerda);
	}

	if (dir != -1) {
		direita = arvore_procura_vertice(arvore, dir);
		vertice_set_pai(direita, vertice);
		vertice_set_dir(vertice, direita);
	}
}

/**
 * @brief  Exporta em formato DOT uma �rvore.
 * @param  filename: nome do arquivo DOT gerado.
 * @param  arvore: ponteiro v�lido de uma �rvore.
 *
 * @retval Nenhum
 */
void arvore_exportar_grafo_dot(const char *filename, arvore_t *arvore) {

	vertice_t* no_vert;

	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		exit(1);
	}

	fprintf(fp, "graph G {\n");

	no_vert = arvore->raiz;
	bfs_pre_ordem_recusivo(no_vert, fp);

	fprintf(fp, "\n }\n");
	fclose(fp);

}




void bfs_pre_ordem_interativo(vertice_t* no_vert) {

	pilha_t * pilha;

	pilha = cria_pilha();

	if (!no_vert)
		return;

	push(no_vert, pilha);

	while (!pilha_vazia(pilha)) {
		no_vert = pop(pilha);

		if (vertice_get_dir(no_vert))
			push(vertice_get_dir(no_vert), pilha);

		if (vertice_get_esq(no_vert))
			push(vertice_get_esq(no_vert), pilha);

#ifdef DEBUG
		printf("pre_ordem interativo -> vertice visitado: %d\n",
				vertice_get_id(no_vert));
#endif // DEBUG

	}

	libera_pilha(pilha);
}




void bfs_pre_ordem_recusivo(vertice_t* no_vert, FILE* fp) {

	if (!no_vert)
		return;

	if (vertice_get_esq(no_vert))
		fprintf(fp, "\t%d -- %d [label = %d];\n", vertice_get_id(no_vert),
				vertice_get_id(vertice_get_esq(no_vert)), 1);
	if (vertice_get_dir(no_vert))
		fprintf(fp, "\t%d -- %d [label = %d];\n", vertice_get_id(no_vert),
				vertice_get_id(vertice_get_dir(no_vert)), 1);


#ifdef DEBUG
	printf("bfs_pre_ordem recursico->vertice visitado: %d\n",
			vertice_get_id(no_vert));
#endif // DEBUG

	bfs_pre_ordem_recusivo(vertice_get_esq(no_vert), fp);
	bfs_pre_ordem_recusivo(vertice_get_dir(no_vert), fp);

}



void bfs_pos_ordem_recusivo(vertice_t* no_vert) {

	if (!no_vert)
		return;

	bfs_pos_ordem_recusivo(vertice_get_esq(no_vert));
	bfs_pos_ordem_recusivo(vertice_get_dir(no_vert));

#ifdef DEBUG
	printf("bfs_pos_ordem recursico->vertice visitado: %d\n",
			vertice_get_id(no_vert));
#endif // DEBUG

}


void bfs_ordem_recusivo(vertice_t* no_vert) {

	if (!no_vert)
		return;

	bfs_ordem_recusivo(vertice_get_esq(no_vert));

#ifdef DEBUG
	printf("bfs_ordem recursico->vertice visitado: %d\n",
			vertice_get_id(no_vert));
#endif // DEBUG


	bfs_ordem_recusivo(vertice_get_dir(no_vert));


}








/**
 * @brief  Libera mem�ria din�mica de uma uma �rvore.
 * @param  arvore: ponteiro v�lido de uma �rvore.
 *
 * @retval Nenhum
 */
void libera_arvore(arvore_t* arvore) {

}

/**
 * @brief  Configura a raiz de uma �rvore.
 * @param  arvore: ponteiro v�lido de uma �rvore.
 * @param  vertice: ponteiro v�lido de um v�rtice
 *
 * @retval Nenhum
 */
void arvore_set_raiz(arvore_t *arvore, vertice_t* vertice) {
	if (arvore == NULL) {
		fprintf(stderr, "libera_arvore: arvore invalida\n");
		exit(EXIT_FAILURE);
	}

	arvore->raiz = vertice;

}

/**
 * @brief  Obt�m a raiz de uma �rvore.
 * @param  arvore: ponteiro v�lido de uma �rvore.
 *
 * @retval vertice_t: ponteiro do v�rtice raiz.
 */
vertice_t* arvore_get_raiz(arvore_t *arvore) {
	if (arvore == NULL) {
		fprintf(stderr, "arvore_get_raiz: arvore invalida\n");
		exit(EXIT_FAILURE);
	}

	return arvore->raiz;
}

/**
 * @brief  Obt�m a lista encadeada de v�rtices.
 * @param  arvore: ponteiro v�lido de uma �rvore.
 *
 * @retval lista_enc_t: ponteiro da lista encadeada contendo todos os v�rtices da �rvore.
 */
lista_enc_t *arvore_obter_vertices(arvore_t *arvore) {

	if (arvore == NULL) {
		fprintf(stderr, "arvore_obter_vertices: arvore invalida\n");
		exit(EXIT_FAILURE);
	}

	return arvore->vertices;
}


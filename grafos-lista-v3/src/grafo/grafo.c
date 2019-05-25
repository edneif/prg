/*
 * grafo.c
 *
 *  Created on: 29 de abr de 2019
 *      Author: ednei.freiberger
 */

/*
 * grafo.c
 *
 *  Created on: Jul 5, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <time.h>

#include "grafo.h"
#include "vertice.h"
#include "../lista_enc/lista_enc.h"
#include "../lista_enc/no.h"
#include "../fila/fila.h"
#include "../pilha/pilha.h"

#define FALSE 0
#define TRUE 1

//#define DEBUG

#define INFINITO INT_MAX

struct grafos {
	int id; /*!< Identifica��o num�rica do grafo  */
	lista_enc_t *vertices; /*!< Lista encadeada dos v�rtices: conjunto V  */
};

/**
 * @brief  Busca em largura
 * @param	grafo: ponteiro do grafo que se deseja executar a busca
 * @param  inicial: ponteiro do v�rtice inicial (fonte) da busca
 *
 * @retval Nenhum: V�rtices s�o marcados internamente
 */
void bfs(grafo_t *grafo, vertice_t* vertice_inicial) {

	printf("Iniciando bfs\n");

	fila_t *Q = cria_fila();

	no_t *meu_no_vertice = obter_cabeca(grafo->vertices);

	while (meu_no_vertice) {
		vertice_t *meu_vertice = obter_dado(meu_no_vertice);
		vertice_set_distancia(meu_vertice, INFINITO);
		vertice_set_pai(meu_vertice, NULL);
		meu_no_vertice = obtem_proximo(meu_no_vertice);

	}

	vertice_set_distancia(vertice_inicial, 0);
	enqueue(vertice_inicial, Q);

	while (!fila_vazia(Q)) {

		vertice_t *u = dequeue(Q);

		lista_enc_t *lista_arestas = vertice_get_arestas(u);
		no_t *no_arest = obter_cabeca(lista_arestas);

		while (no_arest) {
			arestas_t *aresta = obter_dado(no_arest);
			vertice_t *v = aresta_get_adjacente(aresta);  //aresta->destino
#ifdef DEBUG
					printf("vetice adjacente %p\t  vertice atual %p\n", v, u);
#endif //DEBUG

			if (vertice_get_distancia(v) == INFINITO) {
				vertice_set_pai(v, u);
				vertice_set_distancia(v, vertice_get_distancia(u) + 1);
				enqueue(v, Q);

				printf("setando %.2d, \t Distancia %.2d \t Pai:%.2d\n",
						vertice_get_id(v), vertice_get_distancia(v),
						vertice_get_id(u));

			}

			no_arest = obtem_proximo(no_arest);
		}

	}

}

/**
 * @brief  Busca em profundidade
 * @param	grafo: ponteiro do grafo que se deseja executar a busca
 * @param  inicial: ponteiro do v�rtice inicial (fonte) da busca
 *
 * @retval Nenhum: V�rtices s�o marcados internamente
 */
void dfs(grafo_t *grafo, vertice_t* vertice_inicial) {

	vertice_t *v;

	printf("Iniciando dfs\n");

	pilha_t *S = cria_pilha();

	no_t *meu_no_vertice = obter_cabeca(grafo->vertices);

	while (meu_no_vertice) {
		vertice_t *meu_vertice = obter_dado(meu_no_vertice);
		vertice_set_visitado(meu_vertice, FALSE);
		meu_no_vertice = obtem_proximo(meu_no_vertice);

	}

	push(vertice_inicial, S);

	while (!pilha_vazia(S)) {

		vertice_t *u = pop(S);

		if (!vertice_get_visitado(u)) {
			vertice_set_visitado(u, TRUE);

			lista_enc_t *lista_arestas = vertice_get_arestas(u);
			no_t *no_arest = obter_cabeca(lista_arestas);

			while (no_arest) {
				arestas_t *aresta = obter_dado(no_arest);
				v =
						aresta_get_adjacente(aresta);  //aresta->destino
#ifdef DEBUG
								printf("vetice adjacente %p\t  vertice atual %p\n", v, u);
#endif //DEBUG
				if (!vertice_get_visitado(v)) {
					push(v, S);
					printf("Vertice pai %.2d, \t  Vertice visitado:%.2d\n",
							vertice_get_id(u), vertice_get_id(v));

				}
				no_arest = obtem_proximo(no_arest);
			}

		}

	}
}
/**
 * @brief  Cria uma novo grafo
 * @param	id: Identifica��o num�rica do grafo
 *
 * @retval grafo_t: ponteiro para um novo grafo
 */
grafo_t *cria_grafo(int id) {
	grafo_t *p = NULL;

	p = (grafo_t*) malloc(sizeof(grafo_t));

	if (p == NULL) {
		perror("cria_grafo:");
		exit(EXIT_FAILURE);
	}

	p->id = id;
	p->vertices = cria_lista_enc();

	return p;
}

/**
 * @brief  Adicionar um v�rtice no grafo (conjunto V)
 * @param	grafo: ponteiro do grafo que se deseja adicionar um v�rtice
 * @param  id: identifica��o da v�rtice
 *
 * @retval vertice_t: ponteiro do v�rtice criado e adicionada no grafo
 */
vertice_t* grafo_adicionar_vertice(grafo_t *grafo, int id) {
	vertice_t *vertice;
	no_t *no;

	if (grafo == NULL) {
		fprintf(stderr, "grafo_adicionar_vertice: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	if (procura_vertice(grafo, id) != NULL) {
		fprintf(stderr, "grafo_adicionar_vertice: vertice duplicado!\n");
		exit(EXIT_FAILURE);
	}

	vertice = cria_vertice(id);
	no = cria_no(vertice);

#ifdef DEBUG
	printf("grafo_adicionar_vertice: %d\t  end:%p\n", id, vertice);
#endif

	add_cauda(grafo->vertices, no);

	return vertice;
}

/**
 * @brief  Procura um v�rtice com id espec�fico no grafo
 * @param	grafo: ponteiro do grafo que se deseja busca o v�rtice
 * @param  id: identifica��o da aresta
 *
 * @retval vertice_t: ponteiro do v�rtice. NULL se n�o encontrado
 */
vertice_t* procura_vertice(grafo_t *grafo, int id) {
	no_t *no_lista;
	vertice_t *vertice;
	int meu_id;

	if (grafo == NULL) {
		fprintf(stderr, "procura_vertice: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	if (lista_vazia(grafo->vertices) == TRUE)
		return FALSE;

	no_lista = obter_cabeca(grafo->vertices);

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
 * @brief  Cria adjac�ncias.
 * @param	grafo: ponteiro do grafo que cont�m o v�rtice (V pertence a G)
 * @param  vertice: v�rtice fonte da(s) adjac�ncias
 * @param  n: n�mero de par�metros ap�s n
 * @param  ...: pares ordenados dos vertices destino e peso da aresta: (id vertice destino, peso aresta)
 *
 * @retval Nenhum
 *
 * Ex: adicionar uma aresta para o vertice 2 e 3 com respectivos pesos 9 e 15
 * adiciona_adjacentes(grafo, vertice, 4(n), 2, 9, 3, 15);
 */

void adiciona_adjacentes(grafo_t *grafo, vertice_t *vertice, int n, ...) {
	va_list argumentos;
	vertice_t *sucessor;
	arestas_t *aresta;

	int id_sucessor;
	int peso;
	int x;

	/* Initializing arguments to store all values after num */
	va_start(argumentos, n);

	for (x = 0; x < n; x = x + 2) {
		id_sucessor = va_arg(argumentos, int);
		peso = va_arg(argumentos, int);

		sucessor = procura_vertice(grafo, id_sucessor);

		if (sucessor == NULL) {
			fprintf(stderr,
					"adiciona_adjacentes: sucessor nao encontrado no grafo\n");
			exit(EXIT_FAILURE);
		}

		aresta = cria_aresta(vertice, sucessor, peso);
		adiciona_aresta(vertice, aresta);

#ifdef DEBUG
		printf("\tvertice: %d\t  end:%p\t ", vertice_get_id(vertice), vertice);
		printf("\tsucessor: %d\t  end:%p\t ", id_sucessor, sucessor);
		printf("\tpeso: %d\t end_aresta: %p \n", peso, aresta);
#endif

	}

	va_end(argumentos);
}

/**
 * @brief  Exporta o grafo em formato dot.
 * @param	filename: nome do arquivo dot gerado
 * @param  grafo: ponteiro do grafo a ser exportado
 *
 * @retval Nenhum
 */
void exportar_grafo_dot(const char *filename, grafo_t *grafo) {
	FILE *file;

	no_t *no_vert;
	no_t *no_arest;
	vertice_t *vertice;
	vertice_t *adjacente;
	arestas_t *aresta;
	arestas_t *contra_aresta;
	lista_enc_t *lista_arestas;

	int peso;

	if (filename == NULL || grafo == NULL) {
		fprintf(stderr, "exportar_grafp_dot: ponteiros invalidos\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "w");

	if (file == NULL) {
		perror("exportar_grafp_dot:");
		exit(EXIT_FAILURE);
	}

	fprintf(file, "graph {\n");

#ifdef DEBUG
	printf("graph {\n");
#endif // DEBUG

//obtem todos os nos da lista
	no_vert = obter_cabeca(grafo->vertices);
	while (no_vert) {
		vertice = obter_dado(no_vert);

		//obtem todos as arestas
		lista_arestas = vertice_get_arestas(vertice);

		no_arest = obter_cabeca(lista_arestas);
		while (no_arest) {
			aresta = obter_dado(no_arest);

			//ignora caso j� exportada
			if (aresta_get_status(aresta) == EXPORTADA) {
				no_arest = obtem_proximo(no_arest);
				continue;
			}

			//marca como exportada esta aresta
			aresta_set_status(aresta, EXPORTADA);
			adjacente = aresta_get_adjacente(aresta);

			//marca contra-aresta tamb�m como exporta no caso de grafo n�o direcionados
			contra_aresta = procurar_adjacente(adjacente, vertice);
			aresta_set_status(contra_aresta, EXPORTADA);

			//obtem peso
			peso = aresta_get_peso(aresta);

			fprintf(file, "\t%d -- %d [label = %d];\n", vertice_get_id(vertice),
					vertice_get_id(adjacente), peso);

#ifdef DEBUG
			printf("\t%d -- %d [label = %d];\n", vertice_get_id(vertice),
					vertice_get_id(adjacente), peso);

#endif // DEBUG

			no_arest = obtem_proximo(no_arest);
		}
		no_vert = obtem_proximo(no_vert);
	}
	fprintf(file, "}\n");
#ifdef DEBUG
	printf("}\n");
#endif // DEBUG

	fclose(file);
}

/**
 * @brief  Libera a mem�ria utilizada pelo grafo
 * @param  grafo: ponteiro do grafo a ser exportado
 *
 * @retval Nenhum
 */
void libera_grafo(grafo_t *grafo) {
	no_t *no_vert;
	no_t *no_arest;
	no_t *no_liberado;
	vertice_t *vertice;
	arestas_t *aresta;
	lista_enc_t *lista_arestas;

	if (grafo == NULL) {
		fprintf(stderr, "libera_grafo: grafo invalido\n");
		exit(EXIT_FAILURE);
	}

//varre todos os vertices
	no_vert = obter_cabeca(grafo->vertices);
	while (no_vert) {
		vertice = obter_dado(no_vert);

		//libera todas as arestas
		lista_arestas = vertice_get_arestas(vertice);
		no_arest = obter_cabeca(lista_arestas);
		while (no_arest) {
			aresta = obter_dado(no_arest);

			//libera aresta
			free(aresta);

			//libera no da lsita
			no_liberado = no_arest;
			no_arest = obtem_proximo(no_arest);
			free(no_liberado);
		}

		//libera lista de arestas e vertice
		free(lista_arestas);
		free(vertice);

		//libera no da lista
		no_liberado = no_vert;
		no_vert = obtem_proximo(no_vert);
		free(no_liberado);
	}

//libera grafo e vertice
	free(grafo->vertices);
	free(grafo);
}

void delay(unsigned int milliseconds) {

	clock_t start = clock();

	while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds)
		;
}


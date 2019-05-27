/*
 * grafo.c
 *
 *  Created on: 4 de mai de 2019
 *      Author: ednei.freiberger
 */

/*
 * grafo.c
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "fila_adj/fila_adj.h"
#include "pilha_adj/pilha_adj.h"

struct vertices {
	int id;         /*!< Identifica��o num�rica do v�rtice  */
	int dist;
	int pai;
	int visitado;
    /* Mais informa��es, se necess�rio */
};

struct arestas {
	int adj;        /*!< Valor booleando. Verdadeiro representa uma adjac�ncia entre dois v�rtices  */

    /* Mais informa��es, se necess�rio */
};

struct grafos{
	int n_vertices;        /*!< N�mero de v�rtices do grafo  */
	vertice_t *vertices;   /*!< Vetor de ponteiros: conjunto V */
	aresta_t **matriz_adj;	/* Matriz de adjac�ncia: conjunto E */
};

/**
  * @brief  Cria uma novo grafo est�tico
  * @param	vertices: quantidade de v�rtices
  *
  * @retval grafo_t: ponteiro para um novo grafo
  */
grafo_t *cria_grafo(int vertices)
{
	int i;
	aresta_t **matriz_adj;
	/* Aloca estrutura do grafo */
    grafo_t *g = malloc(sizeof(grafo_t));

	if (g == NULL){
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	/* Guarda n�mero total de v�rtices */
	g->n_vertices = vertices;
    /* Aloca v�rtices */
	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL){
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	/* Zera vetor de v�rtices */
	memset(g->vertices, 0, vertices * sizeof(vertice_t));

    /* Aloca 1a dimens�o da matriz de adjac�ncia */
	matriz_adj = malloc(vertices * sizeof(aresta_t *));

	if (matriz_adj == NULL){
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	 /* Aloca 2a dimens�o da matriz de adjac�ncia */
	for ( i = 0; i < vertices; i++ )
	{
		matriz_adj[i] = calloc(vertices, sizeof(aresta_t));

		if (matriz_adj[i] == NULL){
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
	}

	g->matriz_adj = matriz_adj;

	return g;
}

/**
  * @brief  Libera a mem�ria utilizada pelo grafo
  * @param	Nenhum
  *
  * @retval Nenhum
  */
void libera_grafo (grafo_t *g){
	int i;

	if (g == NULL){
		perror("libera_grafo");
		exit(EXIT_FAILURE);
	}

	for (i=0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}

/**
  * @brief  Cria adjac�ncia entre v�rtices u e v
  * @param	u: �ndice do v�rtice u
  * @param  v: �ndice do v�rtice v
  *
  * @retval int: verdadeiro se adjac�ncia for criada
  */
int cria_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;

	return TRUE;
}

/**
  * @brief  Remove adjac�ncia entre v�rtices u e v
  * @param	u: �ndice do v�rtice u
  * @param  v: �ndice do v�rtice v
  *
  * @retval int: verdadeiro se adjac�ncia for removida
  */
int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;

	return TRUE;
}

/**
  * @brief  Retorna adjac�ncia entre v�rtices u e v
  * @param	u: �ndice do v�rtice u
  * @param  v: �ndice do v�rtice v
  *
  * @retval int: verdadeiro se u for adjacente a v
  */
int adjacente(grafo_t *g, int u, int v){

	if (u > MAX_VERTICES || v > MAX_VERTICES)
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}


void exportar_grafo_dot(const char *filename, grafo_t *grafo){

    FILE* fp = fopen (filename, "w");
    if (fp == NULL) {
        printf ("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fprintf(fp, "graph G {\n");
    int i, j;
    for (i=0; i < grafo->n_vertices; i++){
        for (j=0; j < grafo->n_vertices && j<=i; j++){
            if (adjacente(grafo,i,j)){
                fprintf(fp, "%d -- %d\n", j, i);
            }
        }
    }
    fprintf(fp, "}");
    fclose (fp);
}



void printNodes (grafo_t* g){
    int i;

    printf("PRINTING NODES\n");
    for (i=0; i < g->n_vertices; i++)
        printf("vertice: % d\tdist: % d\tpai: % d \tvisitado: % d\n", i, g->vertices[i].dist, g->vertices[i].pai, g->vertices[i].visitado);
}


void bfs_buscaLargura (grafo_t* g, int vertice){   //procuras todos vertices ajacentes
    int v, u;
    fila_t* fila = cria_fila(10);

    for (v=0; v < g->n_vertices; v++){
        g->vertices[v].dist = -1;
        g->vertices[v].pai = -1;
        g->vertices[v].id = v;

    }

    g->vertices[vertice].dist = 0;

    enqueue (fila, vertice);

    while (queueSize(fila)!=0){
        u = dequeue(fila);

        for (v=0; v < g->n_vertices; v++){
            if (adjacente(g, v, u) && g->vertices[v].dist==-1){
                g->vertices[v].dist = g->vertices[u].dist + 1;
                g->vertices[v].pai = u;
                printf ("pai: %d \t filho: %d \t dist: %d \n", g->vertices[v].pai,
                		g->vertices[v].id, g->vertices[v].dist);
                enqueue(fila, v);
            }
        }
    }

    libera_fila(fila);
}

void dfs_buscaProfundidade(grafo_t* g, int vertice){
    int v, u;
    pilha_t* stack = cria_pilha(10);

    for (v=0; v < g->n_vertices; v++){
        g->vertices[v].visitado = 0;
        g->vertices[v].id = v;
    }

    push (stack, vertice);

    while (stackSize(stack)!=0){
        u = pop(stack);

        if (g->vertices[u].visitado == 0){
            g->vertices[u].visitado = 1;
            printf("visitado %d\n", g->vertices[u].id);
            for (v=0; v < g->n_vertices; v++){
                if (adjacente(g, v, u)){
                    push (stack, v);
                }
            }
        }
    }

   libera_pilha(stack);
}




/*
 * grafo.h
 *
 *  Created on: 4 de mai de 2019
 *      Author: ednei.freiberger
 */

/*
 * grafo.h
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#define MAX_VERTICES 20
#define TRUE 1
#define FALSE 0

typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo (grafo_t *g);
int cria_adjacencia(grafo_t *g, int u, int v);
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);
void exportar_grafo_dot(const char *filename, grafo_t *grafo);

void printNodes (grafo_t* g);
void bfs_buscaLargura (grafo_t* g, int vertice);
void dfs_buscaProfundidade(grafo_t* g, int vertice);



#endif /* GRAFO_H_ */

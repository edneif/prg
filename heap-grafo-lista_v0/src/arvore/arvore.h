/*
 * arvore.h
 *
 *  Created on: 13 de mai de 2019
 *      Author: ednei.freiberger
 */
/*
 * arvore.h
 *
 *  Created on: Nov 25, 2016
 *      Author: Renan Augusto Starke
 */

#ifndef SRC_ARVORE_ARVORE_H_
#define SRC_ARVORE_ARVORE_H_

#include "vertice.h"

typedef struct arvores arvore_t;

arvore_t* cria_arvore(int id);
vertice_t* arvore_adicionar_vertice_id(arvore_t *arvore, int id);
vertice_t* arvore_adicionar_vertice(arvore_t *arvore, vertice_t *vertice);
vertice_t* procura_vertice(arvore_t *arvore, int id);
vertice_t* arvore_get_raiz (arvore_t *arvore);
lista_enc_t *arvore_obter_vertices (arvore_t *arvore);

void arvore_exportar_grafo_dot(const char *filename, arvore_t *arvore);
void arvore_adiciona_filhos(arvore_t * arvore, vertice_t *vertice, int esq, int dir);
void arvore_set_raiz (arvore_t *arvore, vertice_t* vertice);
void libera_arvore(arvore_t *arvore);

void arvore_pre_ordem_recusivo(vertice_t* no_vert, FILE* fp);

vertice_t* arvore_procura_vertice(arvore_t *arvore, int id);



#endif /* SRC_ARVORE_ARVORE_H_ */

/*
 * tarefa.h
 *
 *  Created on: Jun 14, 2017
 *      Author: xtarke
 */

#ifndef TAREFAS_TAREFA_H_
#define TAREFAS_TAREFA_H_

#include "lista_enc.h"

typedef struct tarefas tarefa_t;

tarefa_t **lista_para_vetor(lista_enc_t *lista);
void vetor_para_lista(lista_enc_t *lista, tarefa_t **vetor);

void mergesort(tarefa_t **vetor, int tam);
void funde (tarefa_t **vetor, int esq, int meio, int dir, tarefa_t **temparray);
void merge_sort_rec (tarefa_t **vetor, int esq, int dir, tarefa_t **temparray);
void imprimir_vetor(tarefa_t **vetor, int tam);
void libera_tarefas(tarefa_t **vetor, int tamanho);
void libera_lista_tarefas(lista_enc_t *lista);
//------------------------------------

lista_enc_t * importar_csv_linkedList(char *nome_arquivo);

int tarefa_obter_id (tarefa_t *tarefa);
int tarefa_obter_C (tarefa_t *tarefa);
int tarefa_obter_T (tarefa_t *tarefa);
float tarefa_obter_U (tarefa_t *tarefa);

void libera_lista_tarefas(lista_enc_t *lista);
void imprimir_lista_tarefas(lista_enc_t *lista);

//------------------------//
tarefa_t * busca_max_U (lista_enc_t *lista);

#endif /* TAREFAS_TAREFA_H_ */

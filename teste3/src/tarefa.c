/*
 * tarefa.c
 *
 *  Created on: Jun 14, 2017
 *      Author: xtarke
 */

#include <stdio.h>
#include <stdlib.h>

#include "tarefa.h"
#include "lista_enc.h"
#include "no.h"

struct tarefas {
	int id;
	int C;
	int T;
	float U;
};

tarefa_t *cria_tarefa(int id, int C, int T);

tarefa_t **lista_para_vetor(lista_enc_t *lista){

    if (lista == NULL)
    {
        fprintf(stderr, "Erro lista para vetor!");
        exit(EXIT_FAILURE);
    }
    tarefa_t **tarefa;
    int tamanho = obter_tamanho(lista);
    tarefa = malloc(tamanho * sizeof(tarefa_t *));
    
    // Faltou verificar o retorno do malloc!
    
    int i = 0;
    no_t *no = obter_cabeca(lista);
    while (no){
       tarefa[i] = obter_dado(no);
       no = obter_proximo(no);
       i++;
    }
    return tarefa;
}

void vetor_para_lista(lista_enc_t *lista, tarefa_t **vetor){
    if (lista == NULL)
    {
        fprintf(stderr, "Erro vetor para lista!");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    no_t *no = obter_cabeca(lista);
    while (no){
        alterar_dados(no, vetor[i]);
        no = obter_proximo(no);
        i++;
    }
}

/* outras funções do merge devem ser implementadas */
void merge_sort_rec (tarefa_t **vetor, int esq, int dir, tarefa_t **temparray){

    int meio;
    if (esq < dir){
        meio = (esq + dir) / 2;

        merge_sort_rec(vetor, esq, meio, temparray);
        merge_sort_rec(vetor, meio + 1, dir, temparray);

        funde(vetor, esq, meio, dir, temparray);
    }
}

void mergesort(tarefa_t **vetor, int tam){
    tarefa_t **temparray;
    temparray = malloc(tam * sizeof(tarefa_t *));
    
    // Faltou verificar o retorno do malloc!
    
    merge_sort_rec(vetor, 0, tam - 1, temparray);

    free (temparray);
}

void funde (tarefa_t **vetor, int esq, int meio, int dir, tarefa_t **temparray){
    int i = esq;
    int j = esq;
    int k = meio + 1;
    while (j <= meio && k <= dir){
        if (tarefa_obter_U(vetor[j])> tarefa_obter_U(vetor[k]))
            temparray[i++] = vetor[j++];
        else
            temparray[i++] = vetor[k++];
    }
    while (j <= meio){
        temparray[i++] = vetor[j++];
    }
    for (i = esq; i < k; i++){
        vetor[i] = temparray[i];
    }
}
//liberação de memória
void libera_tarefas(tarefa_t **vetor, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        free(vetor[i]);
    }
    free(vetor);
}

void libera_lista_tarefas(lista_enc_t *lista){

    if (lista == NULL)
    {
        fprintf(stderr, "Erro desalocando memoria da lista, ponteiro invalido!");
        exit(EXIT_FAILURE);
    }
    no_t *meu_no = obter_cabeca(lista);
    while (meu_no!=NULL)
    {
        no_t *proximo=obter_proximo(meu_no);
        free(meu_no);
        meu_no = proximo;
    }
    free(lista);
}
//------------------------------------------------------------------

lista_enc_t * importar_csv_linkedList(char *nome_arquivo){

	char buffer[32];
	FILE *fp = fopen(nome_arquivo, "r");
	int id, C, T;
	int linha = 2;

	if (!fp){
		perror("importar_csv");
		exit(-1);
	}

	lista_enc_t *lista_tarefas = cria_lista_enc();

	if (!lista_tarefas){
		perror("importar_csv");
		fclose(fp);
		exit(-1);
	}

	/* Ignora linha da cabecalho */
	fgets(buffer, 32, fp);

	while (fgets(buffer, 32, fp) != NULL){

		int ret = sscanf(buffer, "T%d;%d;%d", &id, &C, &T);

		if (ret != 3){
			fprintf(stderr, "Erro lendo %s em linha %d\n", nome_arquivo, linha);
		}

#ifdef DEBUG
		printf("id: %d\n", id);
#endif

		tarefa_t *tarefa = cria_tarefa(id,C,T);
		no_t *no = cria_no(tarefa);

		add_cauda(lista_tarefas, no);
		linha++;
	}

	fclose(fp);

	return lista_tarefas;
}


tarefa_t *cria_tarefa(int id, int C, int T){

	tarefa_t *tarefa = malloc(sizeof(tarefa_t));

	if (!tarefa){
		perror("cria_tarefa");
		exit(-1);
	}

	tarefa->id  = id;
	tarefa->C = C;
	tarefa->T = T;
	tarefa->U = (float)C/T;

	return tarefa;
}

int tarefa_obter_id (tarefa_t *tarefa){
	return tarefa->id;
}

int tarefa_obter_C (tarefa_t *tarefa){
	return tarefa->C;
}

int tarefa_obter_T (tarefa_t *tarefa){
	return tarefa->T;
}

float tarefa_obter_U (tarefa_t *tarefa){
	return tarefa->U;
}

void imprimir_lista_tarefas(lista_enc_t *lista){

	no_t *no;
	puts("----- lista enc -----------");
	printf("[id]\t[C]\t[T]\t[U]\n");

	no= obter_cabeca(lista);
	while (no){

		tarefa_t *tarefa = obter_dado(no);

		printf("%d\t%d\t%d\t%f\n", tarefa_obter_id(tarefa),
				tarefa_obter_C(tarefa), tarefa_obter_T(tarefa),
				tarefa_obter_U(tarefa));


		no = obter_proximo(no);
	}
	puts("-----------------");
}

void imprimir_vetor(tarefa_t **vetor, int tam) {
	int i;

	puts("----- vetor -----------");
	printf("Tarefas no vetor de ponteiros: %d\n[id]\t[C]\t[T]\t[U]\n", tam);
	for (i=0; i < tam; i++)
		printf("%d\t%d\t%d\t%f\n", tarefa_obter_id(vetor[i]),
				tarefa_obter_C(vetor[i]),
				tarefa_obter_T(vetor[i]),
				tarefa_obter_U(vetor[i]));
	puts("----------------");
}

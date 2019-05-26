/*
 * fila_adj.c
 *
 *  Created on: 26 de mai de 2019
 *      Author: ednei_000
 */

#include <stdio.h>
#include <stdlib.h>

#include "fila_adj.h"

struct filas {
    int cabeca;     /*!< Índice do vetor que representa a cabeça da fila. */
    int cauda;      /*!< Índice do vetor que representa a cauda da fila. */
    //int tamanho;    /*!< Tamanho atual da fila. */
    int max;        /*!< Tamanho máximo: utilizado pelo alocador dinâmico. */
    int *dados;     /*!< Vetor alocado dinamicamente que mantém os dados da fila. */
};

/**********************************************************************/
fila_t* cria_fila(int tamanho){
    fila_t *fila = NULL;

    //aloca memória
    fila = (fila_t*)malloc(sizeof(fila_t));

    //variaveis de controle
    fila->cabeca = 0;
    fila->cauda = 0;
    //fila->tamanho = 0;
    fila->max = tamanho;

    fila->dados = (int*) malloc(sizeof(int)*fila->max);

    return fila;
}

/**********************************************************************/
void enqueue(fila_t* fila, int dado){
    if (fila->cauda >= fila->max){
		//TODO: fazer essa concatenação dos dados. Sim, tem que ser feito na mão.
		/*int* data2 = (int*)malloc(sizeof(int)*(fila->cauda - fila->cabeca)*2);
		int newTail = 0;
		while (fila->cabeca != fila->cauda){
			data2[newTail] = fila->dados[fila->cabeca]
		}*/

        fila->max *= 2;
        fila->dados = (int*)realloc(fila->dados, sizeof(int)*fila->max);

        #ifdef DEBUG
        printf("Realocando tamanho dinamico. Tamanho atual: %d\n", fila->max);
        #endif // DEBUG
    }
    fila->dados[fila->cauda] = dado;
    fila->cauda++;
    #ifdef DEBUG
    printf("Dado adicionado\n");
    #endif // DEBUG
}

/**********************************************************************/
int dequeue(fila_t* fila){
    if (fila->cabeca > fila->cauda){
        fprintf(stderr, "Queue corrompida");
        exit(EXIT_FAILURE);
    }
    if (fila->cauda == fila->cabeca){
        #ifdef DEBUG
        printf("Queue empty\n");
        #endif // DEBUG
        return 0;
    }
    return fila->dados[fila->cabeca++];
}

/**********************************************************************/
int queueSize(fila_t* fila){
    return fila->cauda - fila->cabeca;
}

/**********************************************************************/
void libera_fila(fila_t* fila){
    free(fila->dados);
    free(fila);
}

/*
 * pilha_adj.c
 *
 *  Created on: 26 de mai de 2019
 *      Author: ednei_000
 */

#include <stdio.h>
#include <stdlib.h>

#include "pilha_adj.h"

struct pilhas {
    int topo;       /*!< Índice do vetor que representa o topo da fila */
    int max;
    int* data;      /*!< Vetor que manterá os dados. */
    //To that data be abstract, use void**
};



/**********************************************************************/
pilha_t* cria_pilha (int size){
    pilha_t *pilha;

    pilha = (pilha_t*)malloc(sizeof(pilha_t));
    pilha->data = malloc(sizeof(int)*size);

    pilha->topo = 0;
    pilha->max = size;

    #ifdef DEBUG
    printf("Pilha criada, tamanho: %d\n", pilha->max);
    #endif // DEBUG

    return pilha;
}


/**********************************************************************/
void push(pilha_t *pilha, int dado){
    int topo = pilha->topo;

    if (topo == (pilha->max - 1)) {
        pilha->max *= 2;
        pilha->data = realloc(pilha->data, sizeof(int)*pilha->max);
        #ifdef DEBUG
        printf("Dobrando o tamanho dinamico da pilha. Tamanho atual: %d\n", pilha->max);
        #endif // DEBUG
    }
    pilha->data[topo] = dado;
    pilha->topo++;
    #ifdef DEBUG
    printf("Elemento adicionado a pilha. Tamanho atual: %d\n", stackSize(pilha));
    #endif // DEBUG
}

/**********************************************************************/
int pop(pilha_t *pilha){
    int topo = pilha->topo;

    if (topo < 0 || topo > pilha->max){
        fprintf(stderr, "Pilha corrompida!\n");
        exit(EXIT_FAILURE);
    } else if (topo == 0) {
        fprintf(stderr, "pop() em pilha vazia!\n");
        return 0;
    } else if (topo < (pilha->max)/2){
        pilha->max /= 2;
        pilha->data = realloc(pilha->data, sizeof(int)*pilha->max);
        #ifdef DEBUG
        printf("Diminuindo o tamanho dinamico da pilha. Tanho atual: %d\n", pilha->max);
        #endif // DEBUG
    }

    pilha->topo--;
    return pilha->data[topo - 1];
}

/**********************************************************************/
int stackSize (pilha_t* stack){
    return stack->topo;
}





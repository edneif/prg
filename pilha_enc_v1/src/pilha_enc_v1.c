/*
 ============================================================================
 Name        : lita_enc_v0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

#include "lista_enc.h"
#include "no.h"
#include "pilha.h"


int main()
{
    int* x,y,z,h;
    pilha_t *pilha;

    //cria uma pilha
    pilha = cria_pilha();

    x = malloc(sizeof(int));
    *x =5;
    //empilha dados
    push(x,pilha);
    push(10,pilha);
    push(33,pilha);
    push(60,pilha);

    //desempilha
    x = pop(pilha);


    printf("main: pop() ---> %d\n", x);

    x = pop(pilha);
    printf("main: pop() ---> %d\n", x);
    x = pop(pilha);
    printf("main: pop() ---> %d\n", x);

    x = pop(pilha);
    printf("main: pop() ---> %d\n", x);

    //desempilha
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);

    free(pilha);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

//#define DEBUG

struct listas_enc {
    no_t *cabeca;   /*!< Referência da cabeça da lista encadeada: primeiro elemento. */
    no_t *cauda;    /*!< Referência da cauda da lista encadeada: último elemento. */
    int tamanho;    /*!< Tamanho atual da lista. */
};

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (referência) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc (void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}


/**
  * @brief  Obtém a referência do início (cabeça) da lista encadeada.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval no_t *: nó inicial (cabeça) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista){
    return lista->cabeca;
}

/**
  * @brief  Adiciona um nó de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  * @param  elemento: nó que será adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;
        desligar_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cauda da lista com novo elemento
        ligar_nos(lista->cauda, elemento);
        lista->cauda = elemento;
        lista->tamanho++;
   }
}

void imprimi_lista ( lista_enc_t * lista )
{
	no_t *no = NULL ;
	if ( lista == NULL ){
		fprintf (stderr ," imprimi_lista : ponteiros invalidos ");
		exit ( EXIT_FAILURE );
	}
	no = lista -> cabeca ;
	while (no){
		printf (" Dados : %p\n", obter_dado (no));
		no = obter_proximo (no);
	}
}

void imprimi_lista_tras ( lista_enc_t * lista )
{
	no_t *no = NULL ;
	if ( lista == NULL ){
		fprintf (stderr ," imprimi_lista : ponteiros invalidos ");
		exit ( EXIT_FAILURE );
	}
	no = lista -> cauda ;
	while (no){
		printf (" Dados : %p\n", obter_dado (no));
		no = obter_anterior (no);
	}
}




void* exc_cabeca(lista_enc_t *lista)
{

    if (lista->tamanho <= 0)
    {
    	 lista->cabeca = NULL;
    	 lista->cauda = NULL;
    	 lista->tamanho = 0;
    }
    else
    {

    	no_t* cabeca_original = lista->cabeca;
    	lista->cabeca = obter_proximo(lista->cabeca) ;
    	lista->tamanho--;
        desligar_no_anterior(lista->cabeca);
    	void* dado = obter_dado(cabeca_original);
        free(cabeca_original);
        return dado;

    }


    return NULL;

}




void* exc_cauda(lista_enc_t *lista)
{


    if (lista->tamanho <= 0)
    {
    	 lista->cabeca = NULL;
    	 lista->cauda = NULL;
    	 lista->tamanho = 0;
    }
    else
    {
    	no_t* cauda_original = lista->cauda;
    	lista->cauda = obter_anterior(cauda_original) ;
    	lista->tamanho--;
    	desligar_no_proximo(lista->cauda);
    	void* dado = obter_dado(cauda_original);
   	    free(cauda_original);
   	    return dado;

    }


    return NULL;

}




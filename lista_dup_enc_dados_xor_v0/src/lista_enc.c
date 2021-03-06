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
  * @brief  Obtém a referência da cauda da lista encadeada.
  * @param	lista: lista que se deseja .
  *
  * @retval no_t *:endere�o da cuada.
  */
no_t *obter_cauda(lista_enc_t *lista){
        return lista->cauda;


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
   else if (lista->tamanho == 1)
   {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cauda da lista com novo elemento
        ligar_nos_primeiro(lista->cauda, elemento);
        lista->cauda = elemento;
        lista->tamanho++;
   }
   else
   {
           // Remove qualquer ligacao antiga
           desligar_no(elemento);
           // Liga cauda da lista com novo elemento
           ligar_nos(lista->cauda, elemento);
           lista->cauda = elemento;
           lista->tamanho++;
      }

}



/**
  * @brief  Adiciona um nó de lista no incio.
  * @param	lista: lista encadeada que se deseja adicionar.
  * @param  elemento: nó que será adicionado na cabeca.
  *
  * @retval Nenhum
  */
void add_cabeca(lista_enc_t *lista, no_t* elemento)
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
   else if (lista->tamanho ==1 )
   {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cabeca da lista com novo elemento
        ligar_nos_primeiro(lista->cabeca, elemento);
        lista->cabeca = elemento;
        lista->tamanho++;
   }
   else{
	   // Remove qualquer ligacao antiga
	         desligar_no(elemento);
	         // Liga cabeca da lista com novo elemento
	         ligar_nos(lista->cabeca, elemento);
	         lista->cabeca = elemento;
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
    	no_t* proxima_cabeca = obter_proximo(cabeca_original);
    	no_t* proximo_nova_cabeca = obter_proximo_XOR(lista->cabeca,proxima_cabeca) ;
    	lista->cabeca = proxima_cabeca;
    	lista->tamanho--;
        void* dado = obter_dado(cabeca_original);
        free(cabeca_original);
        ligar_nos_primeiro_apos_exclusao(lista->cabeca,proximo_nova_cabeca);
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
    	no_t* cauda_anterior = obter_anterior(cauda_original);
    	no_t* anterior_cauda_nova = obter_anterior_XOR(cauda_original, cauda_anterior) ;
    	lista->cauda = cauda_anterior;
    	lista->tamanho--;
    	void* dado = obter_dado(cauda_original);
   	    free(cauda_original);
   	    ligar_nos_primeiro_apos_exclusao(lista->cauda,anterior_cauda_nova);
   	    return dado;
    }

    return NULL;

}




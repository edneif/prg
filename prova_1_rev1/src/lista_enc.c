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

int  qtd_elementos (lista_enc_t *lista )
{

	return (lista->tamanho);
}



void exc_cabeca(lista_enc_t *lista, no_t *elemento)
{

	elemento = obter_proximo(lista->cabeca) ;
	lista->cabeca = elemento;
    lista->tamanho--;


    if (lista->tamanho <= 0)
    {
    	 lista->cabeca = NULL;
    	 lista->cauda = NULL;
    	 lista->tamanho = 0;
    }


}




void add_cabeca(lista_enc_t *lista, no_t* elemento)
   {
       if (lista == NULL || elemento == NULL){
           fprintf(stderr,"add_cabe�a: ponteiros invalidos");
           exit(EXIT_FAILURE);
       }

      #ifdef DEBUG
      printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
      #endif // DEBUG

      //lista vazia
      if (lista->tamanho == 0)
      {
           #ifdef DEBUG
           printf("add_cabe�a: add primeiro elemento: %p\n", elemento);
           #endif // DEBUG

           lista->cauda = elemento;
           lista->cabeca = elemento;
           lista->tamanho++;

           desligar_no(elemento);
      }
      else {

   	   ligar_nos(elemento, lista->cabeca);  // elemento->proximo = lista->cabeca
   	   lista->cabeca = elemento;
          lista->tamanho++;

      }



   }


lista_enc_t* inverte_lista(lista_enc_t* lista)
{

	no_t* meu_no;
	no_t* end_dado;


	lista_enc_t* lista_inv = criar_lista_enc();

	for (meu_no = obter_cabeca(lista); meu_no != NULL;
			meu_no = obter_proximo(meu_no)) {
		end_dado = obter_dado(meu_no);

		no_t *meu_no_inv = criar_no(end_dado);
		add_cabeca(lista_inv, meu_no_inv);

		//printf("%d %s %f\n", meu_dado->i, meu_dado->id, meu_dado->dado);

#ifdef DEBUG
printf("Adicionando lista_inv %p --- ", meu_no);
#endif // DEBUG

	}

	return lista_inv;

}


void libera_memoria_lista_inv(lista_enc_t *lista_inv)

{

	no_t *no_anterior;
	no_t *meu_no = obter_cabeca(lista_inv);


	while (meu_no) {

		no_anterior = meu_no;
		meu_no = obter_proximo(meu_no);
		free(no_anterior);
	}

	free(lista_inv);


}



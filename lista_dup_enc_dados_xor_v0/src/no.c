#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "no.h"

struct nos{
    void* dados;    /*!< Referência do dado respectiva ao nó da lista encadeada. */
    no_t *nap;  /*!< referencia no anterior e proximo>. */

};


/**
  * @brief  Cria um novo no de lista encadeada.
  * @param	dado: ponteiro generico para qualquer tipo de dado.
  *
  * @retval no_t: ponteiro do tipo no contendo a referencia do dado.
  */
no_t *criar_no(void *dado)
{
    no_t *p = malloc(sizeof(no_t));

    if (p == NULL){
        perror("cria_no:");
        exit(EXIT_FAILURE);
    }

    p->dados = dado;
    p->nap = NULL;

    return p;
}

/**
  * @brief  Faz o encadeamento entre dois nos de encadeados.
  * @param	fonte: ponteiro da fonte entre a ligacao.
  *         destino: ponteiro do destino entre a ligacao.
  *
  * @retval Nenhum.
  */
void ligar_nos_primeiro (no_t *fonte, no_t *destino)
{
    if (fonte == NULL || destino == NULL){
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    fonte->nap = destino ;
    destino->nap = fonte ;
}


void ligar_nos_primeiro_apos_exclusao (no_t *fonte, no_t *destino)
{
    if (fonte == NULL || destino == NULL){
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    fonte->nap = destino ;

}





/**
  * @brief  Faz o encadeamento entre dois nos de encadeados.
  * @param	fonte: ponteiro da fonte entre a ligacao.
  *         destino: ponteiro do destino entre a ligacao.
  *
  * @retval Nenhum.
  */
void ligar_nos (no_t *fonte, no_t *destino)
{
    if (fonte == NULL || destino == NULL){
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    fonte->nap = XOR(fonte->nap,destino) ;
    destino -> nap = fonte;
}


/**
  * @brief  Remove encadeamento um no encadeado.
  * @param	no: no de lista que se deseja remover ligacao.
  *
  * @retval Nenhum.
  */
void desligar_no (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->nap = NULL;
   }


/**
  * @brief  Remove encadeamento um no encadeado.
  * @param	no: no de lista que se deseja remover ligacao.
  *
  * @retval Nenhum.
  */
void desligar_no_proximo (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->nap = NULL;

}


/**
  * @brief  Remove encadeamento um no encadeado.
  * @param	no: no de lista que se deseja remover ligacao.
  *
  * @retval Nenhum.
  */
void desligar_no_anterior (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->nap = NULL;
}



/**
  * @brief  Obtém a referência do dado pertencente ao nó de lista encadeada.
  * @param	no: nó de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo nó encadeado. 
  */
void *obter_dado (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->dados;
}

/**
  * @brief  Obtém a próxima referência encadeada.
  * @param	no: nó de lista que se deseja obter o próximo elemento.
  *
  * @retval no_t *: ponteiro do próximo elemento da lista. NULL se final de lista.
  */
no_t *obter_proximo_XOR (no_t *no_anterior, no_t *no)
{
    if (no == NULL || no_anterior == NULL) {
        fprintf(stderr,"obter_proximo: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return XOR(no_anterior,no->nap);
}




/**
  * @brief  Obtém a referência anterior encadeada.
  * @param	no: nó de lista que se deseja obter o próximo elemento.
  *
  * @retval no_t *: ponteiro elemento anterior da lista. NULL se final de lista.
  */
no_t *obter_anterior_XOR (no_t *no_anterior, no_t *no)
{
    if (no == NULL || no_anterior == NULL) {
        fprintf(stderr,"obter_proximo: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return XOR(no_anterior,no->nap);
}





/**
  * @brief  Obtém a próxima referência encadeada.
  * @param	no: nó de lista que se deseja obter o próximo elemento.
  *
  * @retval no_t *: ponteiro do próximo elemento da lista. NULL se final de lista.
  */
no_t *obter_proximo (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"obter_proximo: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->nap;
}








no_t *obter_anterior (no_t *no)
{
	if (no == NULL) {
	        fprintf(stderr,"obter_anterior: ponteiros invalidos");
	        exit(EXIT_FAILURE);
	    }

	    return  no->nap;
}






no_t *XOR (no_t *anteior, no_t* atual){


	return  ((uintptr_t) (anteior) ^ (uintptr_t) (atual));
}




#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

typedef struct nos no_t;

/**
  * @brief  Cria um novo nó de lista encadeada.
  * @param	dado: ponteiro genérico para qualquer tipo de dado.
  *
  * @retval no_t: ponteiro do tipo nó contendo a referência do dado.
  */
no_t *criar_no(void *dado);


/**
  * @brief  Faz o encadeamento entre dois nós de encadeados.
  * @param	fonte: ponteiro da fonte entre a ligação.
  *         destino: ponteiro do destino entre a ligação.
  *
  * @retval Nenhum.
  */
void ligar_nos_primeiro (no_t *fonte, no_t *destino);


/**
  * @brief  Faz o encadeamento entre dois nós de encadeados.
  * @param	fonte: ponteiro da fonte entre a ligação.
  *         destino: ponteiro do destino entre a ligação.
  *
  * @retval Nenhum.
  */
void ligar_nos (no_t *fonte, no_t *destino);






/**
  * @brief  Remove encadeamento um nó encadeado.
  * @param	no: nó de lista que se deseja remover ligação.
  *
  * @retval Nenhum.
  */
void desligar_no (no_t *no);

/**
  * @brief  Remove encadeamento um nó encadeado.
  * @param	no: nó de lista que se deseja remover ligação.
  *
  * @retval Nenhum.
  */
void desligar_no_anterior (no_t *no);


/**
  * @brief  Remove encadeamento um nó encadeado.
  * @param	no: nó de lista que se deseja remover ligação.
  *
  * @retval Nenhum.
  */
void desligar_no_proximo (no_t *no);










/**
  * @brief  Obtém a referência do dado pertencente ao nó de lista encadeada.
  * @param	no: nó de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo nó encadeado. 
  */
no_t *obter_proximo (no_t *no);




/**
  * @brief  Obtém a referência do dado pertencente ao nó de lista encadeada.
  * @param	no: nó de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo nó encadeado.
  */
no_t *obter_proximo_XOR (no_t *no_anterior, no_t *no);





/**
  * @brief  Obtém a referência do dado pertencente ao nó de lista encadeada.
  * @param	no: nó de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo nó encadeado.
  */
no_t *obter_anterior_XOR (no_t *no_anterior, no_t *no);




/**
  * @brief  Obtém a referência do dado pertencente ao nó de lista encadeada.
  * @param	no: nó de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo nó encadeado.
  */
no_t *obter_anterior (no_t *no);




/**
  * @brief  Obtém a próxima referência encadeada.
  * @param	no: nó de lista que se deseja obter o próximo elemento.
  *
  * @retval no_t *: onteiro do próximo elemento da lista. NULL se final de lista.
  */
void *obter_dado (no_t *no);





/**
  * @brief  xor entre nos
  * @param	no_anterior: n� anterior da lista
  * @parma  no_atual: n� atual
  *
  * @retval no_t *: xor entre no anterior e atual.
  */
no_t *XOR (no_t *anteior, no_t* atual);




void ligar_nos_primeiro_apos_exclusao(no_t *fonte, no_t *destino);


#endif // NO_H_INCLUDED

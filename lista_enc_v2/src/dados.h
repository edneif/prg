/*
 * dado.h
 *
 *  Created on: 20 de mar de 2019
 *      Author: ednei.freiberger
 */

#ifndef DADOS_H_
#define DADOS_H_

typedef struct dados dado_t;

dado_t* cria_dado (void);

void cria_dado_linha (dado_t *p ,int indice, char *dado, double valor, int posicao);

int acessa_dado_indice (dado_t *p, int posicao );

char* acessa_dado_dado (dado_t *p, int posicao);

double acessa_dado_valor (dado_t *p, int posicao);

FILE*  abre_arquivo(char *nome_arquivo);

int conta_linhas_arquivo(FILE *fp);

void carrega_dados_estrutura(FILE *fp, dado_t *coleta, int n_linhas);

void imprime_dados_estrutura(dado_t *coleta, int n_linhas);

void libera_memoria(FILE *fp, dado_t *coleta, int n_linhas);







#endif /* DADOS_H_ */

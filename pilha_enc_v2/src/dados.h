#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

typedef struct dados dado_t;
typedef struct pilhas pilha_t;



pilha_t* ler_arquivo(char *nome_arquivo);

dado_t* cria_dado_linha (int indice, char *dado, double valor);

FILE*  abre_arquivo(char *nome_arquivo);

int conta_linhas_arquivo(FILE *fp);

void libera_memoria(pilha_t *pilha);

void imprimi_dados_pilha(pilha_t *pilha);








#endif // DADOS_H_INCLUDED

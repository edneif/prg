#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

typedef struct dados dado_t;
typedef struct filas fila_t;



fila_t* ler_arquivo(char *nome_arquivo);

dado_t* cria_dado_linha (int indice, char *dado, double valor);

FILE*  abre_arquivo(char *nome_arquivo);

int conta_linhas_arquivo(FILE *fp);

void libera_memoria(fila_t *fila);

void imprimi_dados_fila(fila_t *fila);








#endif // DADOS_H_INCLUDED

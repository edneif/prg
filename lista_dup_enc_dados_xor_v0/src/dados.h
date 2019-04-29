#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

typedef struct dados dado_t;
typedef struct listas_enc lista_enc_t;


lista_enc_t* ler_arquivo(char *nome_arquivo);

dado_t* cria_dado (void);

void cria_dado_linha (dado_t *p ,int indice, char *dado, double valor);

FILE*  abre_arquivo(char *nome_arquivo);

int conta_linhas_arquivo(FILE *fp);

void imprime_dados_estrutura(dado_t *dado);

void libera_memoria(lista_enc_t *lista);

void imprimi_dados_lista_cabeca(lista_enc_t* minha_lista);

void imprimi_dados_lista_cauda(lista_enc_t* minha_lista);








#endif // DADOS_H_INCLUDED

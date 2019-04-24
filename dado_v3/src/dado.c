/*
 ============================================================================
 Name        : dado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 ============================================================================
 Name        : dado.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //srtlen
#include "tratadado.h"



int main()
{
    int n_linha = 0;
    dado_t *coleta1;



    FILE *fp = abre_arquivo("Dados.csv");  //abre aruivo

    n_linha = conta_linhas_arquivo(fp);    //conta numero de linhas

    coleta1 =  cria_dado_array(n_linha);   //aloca espaço para estrutura

    carrega_dados_estrutura(fp, coleta1, n_linha);  //carrega dados estrutura do arquivo

    imprime_dados_estrutura(coleta1, n_linha); //imprie estrutura de dados

    libera_memoria(fp,coleta1,n_linha);  //libera memorias alocadas





return 0;
}

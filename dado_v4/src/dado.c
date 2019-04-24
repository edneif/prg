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
    controle_t *controle;



    controle =  cria_dado_array("dados.csv");   //abre aquirvo e aloca espaço para estrutura

    carrega_dados_estrutura(controle);  //carrega dados estrutura do arquivo

    imprime_dados_estrutura(controle); //imprie estrutura de dados

    libera_memoria(controle);  //libera memorias alocadas



return 0;

}

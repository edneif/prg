/*
 ============================================================================
 Name        : complexto.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main()
{
    //vari�veis
    float x,y,dist;
    ponto *p1, *p2, *p3;

    //cria ponto
    p1 = cria(5.5, 8.9);
    p2 = cria(4.0, 2.1);
    p3 = cria(0,0);

    soma(p3, p1, p2);

    //Acesso direto n�o � permitido
    //x = p->a;

    //c�pia coordenadas de p para x e y
    acessa(p1, &x, &y);
    //mostra
    printf("Criado ponto p1: %f  %f\n",x, y);

    acessa(p3, &x, &y);
     //mostra
    printf("Valores do ponto p3: %f  %f\n",x, y);

    dist = distancia(p1,p2);
    printf("%lf",dist);


    //libera memorua
    libera(p1);
    libera(p2);

    return 0;
}

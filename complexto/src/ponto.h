/*
 * ponto.h
 *
 *  Created on: 12 de mar de 2019
 *      Author: ednei.freiberger
 */

#ifndef PONTO_H
#define PONTO_H

/* TAD: ponto (x,y) */
/* Tipo exportado */
typedef struct pontos ponto;

/* Fun��es exportadas */

/* Fun��o cria
** Aloca e retorna um ponto com coordenadas (x,y)
*/
ponto* cria (float x, float y);

/* Fun��o libera
** Libera a mem�ria de um ponto previamente criado.
*/
void libera (ponto* p);

/* Fun��o acessa
** Devolve os valores das coordenadas de um ponto
*/
void acessa (ponto* p, float* x, float* y);

/* Fun��o atribui
** Atribui novos valores �s coordenadas de um ponto
*/
void atribui (ponto* p, float x, float y);

/* Fun��o soma:
 ** Soma de dois pontos: res = p1 + p2
 */
void soma(ponto *res, ponto *p1, ponto *p2);

/* Fun��o distancia
** Retorna a dist�ncia entre dois pontos
*/
float distancia (ponto* p1, ponto* p2);

#endif // PONTO_H

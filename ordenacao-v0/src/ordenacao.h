/*
 * ordenacao.h
 *
 *  Created on: 31 de mai de 2019
 *      Author: ednei.freiberger
 */

#ifndef ORDENACAO_H_
#define ORDENACAO_H_



void buble_sort (int * array, int tamanho);
void swap (int *x, int *y);

int media_de_tres (int *array, int esq, int dir);
int partition(int *array, int esq, int dir);

void quicksort(int *array, int esq, int dir);

void insertsort(int *array, int tamanho);
void insertbinsort (int* array, int tamanho);


#endif /* ORDENACAO_H_ */

/*
 ============================================================================
 Name        : ordenacao-v0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "ordenacao.h"

#define tamanho_array 10
#define repeticoes 20

int main(void) {

	clock_t buble_start = 0, buble_end = 0, buble_total = 0;
	clock_t quicksort_start = 0, quicksort_end = 0, quicksort_total = 0;
	clock_t insertsort_start = 0, insertsort_end = 0, insertsort_total = 0;
	clock_t insertbinsort_start = 0, insertbinsort_end = 0,
			insertbinsort_total = 0;
	clock_t mergesort_start = 0, mergesort_end = 0, mergesort_total = 0;
	clock_t selectionsort_start = 0, selectionsort_end = 0,
			selectionsort_total = 0;

	int i,j;

	int *array = malloc(sizeof(int) * tamanho_array);
	int *temp_array = malloc(sizeof(int) * tamanho_array);	//usada em merge

	for (j = 1; j <= repeticoes; j++) {

		printf("\n\ninteracao: %d de %d\n",j,repeticoes);
		srand(time(NULL));

		for (i = 0; i < tamanho_array; i++) {
			array[i] = rand() % tamanho_array;
		}
		//puts("!!!iniciando Quicksort!!!\n");
		quicksort_start = clock();
		quicksort(array, 0, tamanho_array - 1); //usar posicao inicial e final vetor
		quicksort_end = clock();
		quicksort_total += quicksort_end - quicksort_start;
		printf("\n| Quicksort T  | %f",
				(double) quicksort_total / (j * CLOCKS_PER_SEC));
		fflush(stdout);

		srand(time(NULL));

		for (i = 0; i < tamanho_array; i++) {
			array[i] = rand() % tamanho_array;
		}
		//puts("!!!iniciando Insertsort!!!\n");
		insertsort_start = clock();
		insertsort(array, tamanho_array);
		insertsort_end = clock();
		insertsort_total += insertsort_end - insertsort_start;
		printf("\n| InsertSort T | %f",
				(double) insertsort_total / (j * CLOCKS_PER_SEC));
		fflush(stdout);

		srand(time(NULL));

		for (i = 0; i < tamanho_array; i++) {
			array[i] = rand() % tamanho_array;
		}
		//puts("!!!iniciando insertbinsort!!!\n");
		insertbinsort_start = clock();
		insertbinsort(array, tamanho_array);
		insertbinsort_end = clock();
		insertbinsort_total += insertbinsort_end - insertbinsort_start;
		printf("\n| Insertbsort T| %f",
				(double) insertbinsort_total / (j * CLOCKS_PER_SEC));
		fflush(stdout);

		srand(time(NULL));

		for (i = 0; i < tamanho_array; i++) {
			array[i] = rand() % tamanho_array;
		}
		//puts("!!!iniciando Bubble!!!\n");
		buble_start = clock();
		buble_sort(array, tamanho_array);
		buble_end = clock();
		buble_total += buble_end - buble_start;
		printf("\n| Buble Total  | %f",
				(double) buble_total / (j * CLOCKS_PER_SEC));

		srand(time(NULL));

		for (i = 0; i < tamanho_array; i++) {
			array[i] = rand() % tamanho_array;
		}
		//puts("!!!iniciando MergeSort!!!\n");
		mergesort_start = clock();
		mergesort(array, 0, tamanho_array - 1, temp_array); //usar posicao inicial e final do vetor
		mergesort_end = clock();
		mergesort_total += mergesort_end - mergesort_start;
		printf("\n| Merger Total  | %f",
				(double) mergesort_total / (j * CLOCKS_PER_SEC));

		srand(time(NULL));

		for (i = 0; i < tamanho_array; i++) {
			array[i] = rand() % tamanho_array;
		}
		//puts("!!!iniciando selectionsort!!!\n");
		selectionsort_start = clock();
		selection_sort(array, tamanho_array);
		selectionsort_end = clock();
		selectionsort_total += selectionsort_end - selectionsort_start;
		printf("\n| Select Total  | %f",
				(double) selectionsort_total / (j * CLOCKS_PER_SEC));

		//int arraym[] = { 9, 8, 7, 3, 5, 4, 3, 2, 1, 10 };
		//selection_sort(arraym, 10);

	}

	puts("\n\n!!fim prog  v13 !!!");
	return EXIT_SUCCESS;
}


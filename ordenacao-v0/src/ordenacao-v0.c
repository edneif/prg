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

#define tamanho_array 100000
#define repeticoes 1

int main(void) {

	clock_t buble_start = 0, buble_end = 0, buble_total = 0;
	clock_t quicksort_start = 0, quicksort_end = 0, quicksort_total = 0;
	clock_t insertsort_start = 0, insertsort_end = 0, insertsort_total = 0;
	clock_t insertbinsort_start = 0, insertbinsort_end = 0,
			insertbinsort_total = 0;

	int i;

	int *array = malloc(sizeof(int) * tamanho_array);


	srand(time(NULL));

	for (i = 0; i < tamanho_array; i++) {
		array[i] = rand() % tamanho_array;
	}
	//puts("!!!iniciando Quicksort!!!\n");
	quicksort_start = clock();
	quicksort(array, 0, tamanho_array - 1);
	quicksort_end = clock();
	quicksort_total = quicksort_end - quicksort_start;
	printf("\n| Quicksort T  | %f",
			(double) quicksort_total / (repeticoes * CLOCKS_PER_SEC));
	fflush(stdout);


	srand(time(NULL));

	for (i = 0; i < tamanho_array; i++) {
		array[i] = rand() % tamanho_array;
	}
	//puts("!!!iniciando Insertsort!!!\n");
	insertsort_start = clock();
	insertsort(array, tamanho_array);
	insertsort_end = clock();
	insertsort_total = insertsort_end - insertsort_start;
	printf("\n| InsertSort T | %f",
			(double) insertsort_total / (repeticoes * CLOCKS_PER_SEC));
	fflush(stdout);


	srand(time(NULL));

	for (i = 0; i < tamanho_array; i++) {
		array[i] = rand() % tamanho_array;
	}
	//puts("!!!iniciando insertbinsort!!!\n");
	insertbinsort_start = clock();
	insertbinsort(array, tamanho_array);
	insertbinsort_end = clock();
	insertbinsort_total = insertbinsort_end - insertbinsort_start;
	printf("\n| Insertbsort T| %f",
			(double) insertbinsort_total / (repeticoes * CLOCKS_PER_SEC));
	fflush(stdout);

	//int array[] = {9,8,7,6,5,4,3,2,1,0};
	srand(time(NULL));

	for (i = 0; i < tamanho_array; i++) {
		array[i] = rand() % tamanho_array;
	}
	//puts("!!!iniciando Bubble!!!\n");
	buble_start = clock();
	buble_sort(array, tamanho_array);
	buble_end = clock();
	buble_total = buble_end - buble_start;
	printf("\n| Buble Total  | %f",
			(double) buble_total / (repeticoes * CLOCKS_PER_SEC));






	puts("\n\n!!fim prog   !!!");
	return EXIT_SUCCESS;
}


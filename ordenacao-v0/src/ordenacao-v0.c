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
#define REPETIONS 1

int main(void) {

	clock_t buble_start=0, buble_end=0, buble_total = 0;

	int i;
	int array[tamanho_array];

	//int array[] = {8,8,2,5,9,1,10,30,40,15};
	srand(time(NULL));

	for (i = 0; i < tamanho_array; i++) {
		array[i] = rand() % tamanho_array;
	}


   puts("!!!iniciando Bubble!!!"); /* prints !!!Hello World!!! */

   buble_start = clock();

   buble_sort(array, tamanho_array);

   buble_end = clock();

   buble_total = buble_end - buble_start;


   printf ("\n| Buble        | %f", (double)buble_total/(REPETIONS*CLOCKS_PER_SEC));


    puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


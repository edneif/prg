/*
 ============================================================================
 Name        : teste-xor.c
 Author      : ednei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	int matriz[5][2];

	matriz[0][0] = 0;
	matriz[1][0] = 1;
	matriz[2][0] = 2;
	matriz[3][0] = 3;
	matriz[4][0] = 4;


	int startTime = clock();

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	fflush(stdout);

	//for(i=0;i<1000000000;i++) ;
	sleep(5);

	int finalTime = clock();

//	int difernça = difftime(finalTime, startTime);

	printf("time %d  %d   ", startTime, finalTime);

	return EXIT_SUCCESS;
}

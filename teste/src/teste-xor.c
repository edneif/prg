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



	int startTime = clock();


	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	fflush(stdout);


	//for(i=0;i<1000000000;i++) ;
	sleep(5);

	int finalTime = clock();


//	int difern�a = difftime(finalTime, startTime);


	printf("time %d  %d   ", startTime, finalTime);





	return EXIT_SUCCESS;
}

/*
 * ordenacao.c
 *
 *  Created on: 31 de mai de 2019
 *      Author: ednei.freiberger
 */


void buble_sort (int * array, int tamanho){
	int i,j;

	for (i=tamanho; i>1 ; i--){
		for ( j=0; j < i - 1; j++){
			if (array[j] > array[j+1])
				swap (&array[j], &array[j+1]);

		}

	}



}


void swap (int *x, int *y){

	*x =  *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;

}



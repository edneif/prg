/*
 * ordenacao.c
 *
 *  Created on: 31 de mai de 2019
 *      Author: ednei.freiberger
 */

void buble_sort(int * array, int tamanho) {
	int i, j;

	for (i = tamanho; i > 1; i--) {
		for (j = 0; j < i - 1; j++) {
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);

		}

	}

}

void swap(int *x, int *y) {

	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;

}

/* algoritmo utilizado quicksort*/
int media_de_tres(int *array, int esq, int dir) {
	int med;

	med = (esq + dir) / 2;

	if (array[dir] < array[esq])
		swap(&dir, &esq);
	if (array[med] < array[esq])
		swap(&med, &esq);
	if (array[dir] < array[med])
		swap(&dir, &med);

	return med;
}

/* algoritmo utilizado quicksort*/
int partition(int *array, int esq, int dir) {
	int med, pivot, i, j;

	med = media_de_tres(array, esq, dir);
	pivot = array[med];
	i = esq - 1;
	j = dir + 1;

	for (;;) {
		do {

			i++;

		} while (array[i] < pivot);

		do {

			j--;

		} while (array[j] > pivot);

		if (i >= j)
			return j;

		swap(&array[i], &array[j]);

	}

	return j;

}

void quicksort(int *array, int esq, int dir) {
	int p;

	if (esq < dir) {
		p = partition(array, esq, dir);
		quicksort(array, esq, p);
		quicksort(array, p + 1, dir);
	}
}

void insertsort(int *array, int tamanho) {
	int i, j;
	for (i = 1; i < tamanho; i++) {
		for (j = i; j > 0 && array[j - 1] > array[j]; j--) {
			swap(&array[j], &array[j - 1]);

		}

	}

}

void insertbinsort(int* array, int tamanho) {
	int i, j, tmp, meio, esq, dir;
	for (i = 1; i < tamanho; i++) {
		tmp = array[i];
		esq = 0;
		dir = i;
		while (esq < dir) {
			meio = (esq + dir) / 2;
			if (tmp >= array[meio])
				esq = meio + 1;
			else
				dir = meio;

		}
		for (j = i; j > esq; j--)
			swap(&array[j - 1], &array[j]);

	}

}

//use mergesort
void funde(int *array, int esq, int meio, int dir, int *temp_array) {

	int i = esq;
	int j = esq;
	int k = meio+1;

	while (j <= meio && k <= dir) {

		if (array[j] < array[k])
			temp_array[i++] = array[j++];
		else
			temp_array[i++] = array[k++];

	}
		while (j <= meio) {
			temp_array[i++] = array[j++];
		}
		for (i = esq; i < k; i++) {
			array[i] = temp_array[i];
		}


}

void mergesort(int *array, int esq, int dir, int *temp_array) {

	if (esq < dir) {

		int meio = (esq + dir) / 2;

		mergesort(array, esq, meio, temp_array);
		mergesort(array, meio + 1, dir, temp_array);

		funde(array, esq, meio, dir, temp_array);

	}

}



void selection_sort (int *array, int tamanho){
	int i,j;
	for ( i = tamanho; i > 1 ; i--){
	int max = 0;
	for (j = 1 ; j < i ; j++)            //procura maximo do array
		if (array[j] > array[max])
			max = j;

	if (i-1 != max)                        //necessario troca feito por xor
	   swap (&array[i-1], &array[max]);   //troca posicoes do vetor
	}


}




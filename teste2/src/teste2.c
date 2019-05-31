/*
 ============================================================================
 Name        : teste2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int mdc(int a, int b){


	if (b==0)
		return (a);
	else
	    return mdc (b, a%b);



}


int q_perfeito(int n){
	int temp;

	if (n==0)
		return n;

	else{
       temp = q_perfeito(n-1);
		return temp + 2*n -1;


	}

}


int main(void) {

	int i= 3;
	int res;

	res = q_perfeito(i);

    printf("%d", res);

	return EXIT_SUCCESS;
}



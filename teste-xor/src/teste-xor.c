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

int main(void) {

	int a,b,c,r,rant,rpro;

	a= 0x100;  //nap = 542
	b= 0x542;  //nap = 600 axc
	c= 0x700;  //nap = 224 bxd
	d =0x766;  //nap = 700


	r = a ^ b;

   rant = r ^ a;



 printf ( "   %x\n   %x\n = %x\n   %x\n", a,b,r,rant);

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

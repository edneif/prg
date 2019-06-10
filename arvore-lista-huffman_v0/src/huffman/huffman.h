/*
 * huffman.h
 *
 *  Created on: 5 de jun de 2019
 *      Author: ednei.freiberger
 */

#ifndef HUFFMAN_H_
#define HUFFMAN_H_


typedef struct huffmans huffman_t;


arvore_t* huffman(void);
huffman_t* retorna_fila_menor(fila_t *fila1);
void cod_huffman(vertice_t* no_vert, vertice_t *raiz, char codchar,
		char* codificacao);


#endif /* HUFFMAN_H_ */

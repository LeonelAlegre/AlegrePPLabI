/*
 * Bicicleta.h
 *
 *  Created on: 13 may. 2020
 *      Author: Leonel
 */

#ifndef BICICLETA_H_
#define BICICLETA_H_

typedef struct
{
	int id;
	char nombreColor[20];
	int isEmpty;
}Colores;

int col_getEmptyIndex(Colores* array,int limite);
int col_altaArray(Colores* array,int limite, int indice, int* id);
int col_imprimir(Colores* pElemento);
int col_buscarId(Colores* array, int limite, int valorBuscado);
int col_modificarArray(Colores* array,int limite, int indice);
int col_buscarId(Colores* array, int limite, int valorBuscado);
int col_bajaArray(Colores* array,int limite, int indice);


#endif /* BICICLETA_H_ */

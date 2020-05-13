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
	char descripcion[20];
	int isEmpty;
}Tipos;

int tip_getEmptyIndex(Tipos* array,int limite);
int tip_altaArray(Tipos* array,int limite, int indice, int* id);
int tip_imprimir(Tipos* pElemento);
int tip_buscarId(Tipos* array, int limite, int valorBuscado);
int tip_modificarArray(Tipos* array,int limite, int indice);
int tip_buscarId(Tipos* array, int limite, int valorBuscado);
int tip_bajaArray(Tipos* array,int limite, int indice);


#endif /* BICICLETA_H_ */

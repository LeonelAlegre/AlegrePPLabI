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
	int idBicicleta;
	int idServicio;
	char fecha[25];
	int isEmpty;
}Servicios;

int ser_getEmptyIndex(Servicios* array,int limite);
int ser_altaArray(Servicios* array,int limite, int indice, int* id);
int ser_imprimir(Servicios* pElemento);
int ser_buscarId(Servicios* array, int limite, int valorBuscado);
int ser_modificarArray(Servicios* array,int limite, int indice);
int ser_buscarId(Servicios* array, int limite, int valorBuscado);
int ser_bajaArray(Servicios* array,int limite, int indice);


#endif /* BICICLETA_H_ */

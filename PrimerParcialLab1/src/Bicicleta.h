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
	char marca[20];
	int idTipo; //validar
	int idColor; //validar
	float rodado;
	int isEmpty;
}Bicicleta;

int bic_getEmptyIndex(Bicicleta* array,int limite);
int bic_altaArray(Bicicleta* array,int limite, int indice, int* id);
int bic_imprimir(Bicicleta* pElemento);
int bic_buscarId(Bicicleta* array, int limite, int valorBuscado);
int bic_modificarArray(Bicicleta* array,int limite, int indice);
int bic_buscarId(Bicicleta* array, int limite, int valorBuscado);
int bic_bajaArray(Bicicleta* array,int limite, int indice);


#endif /* BICICLETA_H_ */

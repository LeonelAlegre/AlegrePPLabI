#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Colores.h"
#include "utn.h"

/**
 * \brief Buscar primer posicion vacia
 * \param array Array a analizar
 * \param limite Limite del array
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int col_getEmptyIndex(Colores* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Da de alta un tipo en una posicion del array
 * \param array Array ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int col_altaArray(Colores* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Colores buffer;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(buffer.nombreColor,sizeof(buffer.nombreColor),"\nMarca: \n","\nERROR\n",2) == 0)
		{
			respuesta = 0;
			buffer.id = *id;
			buffer.isEmpty = 0;
			array[indice] = buffer;
			(*id)++;
		}
	}
	return respuesta;
}
/**
 * \brief Imprime los datos de una bicileta
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int col_imprimir(Colores* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s",pElemento->id,pElemento->nombreColor);
	}
	return retorno;
}
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Puntero a analizar
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int col_buscarId(Colores* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Actualiza los datos de la entidad en una posicion del array
 * \param array Array a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int col_modificarArray(Colores* array,int limite, int indice)
{
	int respuesta = -1;
	Colores buffer;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(buffer.nombreColor,sizeof(buffer.nombreColor),"\nNombre Color: \n","\nERROR\n",2) == 0)
		{
			respuesta = 0;
			buffer.id = array[indice].id;
			buffer.isEmpty = 0;
			array[indice] = buffer;
		}
	}
	return respuesta;
}
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Array a ser analizado
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int col_buscarId(Colores* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Actualiza una posicion del array
 * \param array Array a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int col_bajaArray(Colores* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}

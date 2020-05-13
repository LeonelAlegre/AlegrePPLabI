#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicios.h"
#include "utn.h"

/**
 * \brief Buscar primer posicion vacia
 * \param array Array a analizar
 * \param limite Limite del array
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int ser_getEmptyIndex(Servicios* array,int limite)
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
int ser_altaArray(Servicios* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Servicios buffer;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(buffer.descripcion,sizeof(buffer.descripcion),"\nDescripcion: \n","\nERROR\n",2) == 0 &&
				utn_getNumeroFlotante(&buffer.precio,"\nPrecio?\n","\nERROR\n",0,10000,2) == 0)
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
int ser_imprimir(Servicios* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %.2f",pElemento->id,pElemento->descripcion, pElemento->precio);
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
int ser_buscarId(Servicios* array, int limite, int valorBuscado)
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
int ser_modificarArray(Servicios* array,int limite, int indice)
{
	int respuesta = -1;
	Servicios buffer;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(buffer.descripcion,sizeof(buffer.descripcion),"\nDescripcion: \n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&buffer.precio,"\nPrecio?\n","\nERROR\n",0,10000,2) == 0 )
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
int ser_buscarId(Servicios* array, int limite, int valorBuscado)
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
int ser_bajaArray(Servicios* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bicicleta.h"
#include "utn.h"

static const char RODADO_TIPOS[4][4]={20,26,27.5,29};

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int bic_getEmptyIndex(Bicicleta* array,int limite)
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
 * \brief Da de alta una bici en una posicion del array
 * \param array Array de bici a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int bic_altaArray(Bicicleta* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Bicicleta bufferBici;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferBici.marca,sizeof(bufferBici.marca),"\nMarca: \n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferBici.rodado,"Ingrese tipo de rodado [0:20 1:26 2:27.5 3:29]: ","\nERROR\n",20,29,2) == 0)
		{
			respuesta = 0;
			bufferBici.id = *id;
			bufferBici.isEmpty = 0;
			array[indice] = bufferBici;
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
int bic_imprimir(Bicicleta* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %.2f ",pElemento->id,pElemento->marca,RODADO_TIPOS[pElemento->rodado]);
	}
	return retorno;
}
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int bic_buscarId(Bicicleta* array, int limite, int valorBuscado)
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
 * \brief Actualiza los datos de una bicicleta en una posicion del array
 * \param array Array de bicicleta a ser actualizado
 * \param limite Limite del array de bicicleta
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int bic_modificarArray(Bicicleta* array,int limite, int indice)
{
	int respuesta = -1;
	Bicicleta bufferBici;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferBici.marca,sizeof(bufferBici.marca),"\nMarca: \n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferBici.rodado,"Ingrese tipo de rodado [0:20 1:26 2:27.5 3:29]: ","\nERROR\n",20,29,2) == 0)
		{
			respuesta = 0;
			bufferBici.id = array[indice].id;
			bufferBici.isEmpty = 0;
			array[indice] = bufferBici;
		}
	}
	return respuesta;
}
/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Array de bicicleta
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int bic_buscarId(Bicicleta* array, int limite, int valorBuscado)
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
 * \param array Array de bicicleta a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int bic_bajaArray(Bicicleta* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}

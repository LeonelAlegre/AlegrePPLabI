/*
 ============================================================================
 Name        : PrimerParcialLab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bicicleta.h"
#include "Colores.h"
//#include "Fecha.h"
#include "Servicios.h"
#include "Tipos.h"
#include "Trabajo.h"
#include "utn.h"

#define CANT_BICI 30
#define MARCA 20
#define COLOR 20

int main(void) {

	Bicicleta aBicicleta[CANT_BICI];
	int opcion;
	int auxiliarIndice;
	int auxiliarId;
	int idBicicleta = 0;

	Tipos aTipos[MARCA];

	Colores aColor[COLOR];

	do
		{
			if(!utn_getNumero(	&opcion,
								"\n\n1.ALTA BICICLETA"
								"\n2.Modificar BICICLETA"
								"\n3.BAJAR BICICLETA"
								"\n4.LISTAR BICICLETAS"
								"\n5.LISTAR TIPOS"
								"\n6.LISTAR COLORES"
								"\n7.LISTAR SERVICIOS"
								"\n8.ALTA TRABAJO"
								"\n9.LISTAR TRABAJO"
								"\n10.Informar",

								"\nError opcion invalida",1,11,2) )
			{
				switch(opcion)
				{
				case 1:
					auxiliarIndice = bic_getEmptyIndex(aBicicleta,CANT_BICI);
					if(auxiliarIndice >= 0)
					{
						if(bic_altaArray(aBicicleta,CANT_BICI,auxiliarIndice,&idBicicleta) == 0)
						{
							printf("\nCarga realizada con exito\n");
						}
					}
					else
					{
						printf("\nNO HAY MAS LUGAR");
					}
					break;
				case 2:
					bic_imprimirArray(aBicicleta,CANT_BICI);
					if(utn_getNumero(&auxiliarId,"\nIndique el ID del Panatalla a modificar","\nID invalido",0,idBicicleta,0) == 0)
					{
						auxiliarIndice = bic_buscarId(aBicicleta,CANT_BICI,auxiliarId);
						if(	auxiliarIndice >= 0 &&
								bic_modificarArray(aBicicleta,CANT_BICI,auxiliarIndice) == 0)
						{
							printf("\nModificacion realizada con exito\n");
						}
					}
					break;

				case 3:
					bic_imprimirArray(aBicicleta,CANT_BICI);
					if(utn_getNumero(&auxiliarId,"\nIndique el ID de la bicileta a eliminar","\nID invalido",0,idBicicleta,0)==0)
					{
						auxiliarIndice = bic_buscarId(aBicicleta,CANT_BICI,auxiliarId);
						if(	auxiliarIndice >= 0 &&
								bic_bajaArray(aBicicleta,CANT_BICI,auxiliarIndice)== 0)
						{
							printf("\nBaja realizada con exito\n");
						}
					}
					break;
				case 4:
					bic_imprimirArray(aBicicleta,CANT_BICI);
					break;

				case 5:
					tip_imprimirArray(aTipos,MARCA);
					break;
				case 6:
					col_imprimirArray(aColor,COLOR);
					break;
				case 7:
					ser_imprimirArray(aColor,COLOR);
					break;
				case 8:
					auxiliarIndice = bic_getEmptyIndex(aBicicleta,CANT_BICI);
					if(auxiliarIndice >= 0)
					{
						if(bic_altaArray(aBicicleta,CANT_BICI,auxiliarIndice,&idBicicleta) == 0)
						{
							printf("\nCarga realizada con exito\n");
						}
					}
					else
					{
						printf("\nNO HAY MAS LUGAR");
					}
					break;
				case 9:
					break;
				case 10:
					break;
				default:
					printf("Opcion incorrecta");
					break;


				}
			}
		}while(opcion != 10);
	return EXIT_SUCCESS;
}

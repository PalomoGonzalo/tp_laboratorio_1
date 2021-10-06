/*
 * ArrayEmployees.c
 *
 *  Created on: 5 oct. 2021
 *      Author: mati_
 */
#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "funciones.h"
int initEmployees(Employee* list, int len)
{
	int retorno=-1;
	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty=LIBRE;
			retorno=0;
		}

	}
	return retorno;
}

int dameUnIdNuevo(void)
{
	static int contador=0;
	contador++;
	return contador;
}

int employe_buscarLibre(Employee list[],int len)
{
	int i;
	int indice=-1;
	if(list!=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==LIBRE)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}

int addEmployee(Employee list[],int len)
{
	int retorno=-1;
	int indice;
	if(list!=NULL && len>0)
	{
		indice=employe_buscarLibre(list, len);
		if(indice>0)
		{
			list[indice].id=dameUnIdNuevo();
			getString("ingrese el nombre del empleado \n", list[indice].name);
			getString("Ingrese el apellido del empleado \n", list[indice].lastName);
			utn_getFloat(&list[indice].salary, "Ingrese su salario", "error ingrese solo numeros\n", 1, 999999, 6);
			utn_getInt(&list[indice].sector, "Ingrese:\n1-admistracion\n2-Programacion", "Error ingrese numeros validos\n", 1, 2, 4);
			list[indice].isEmpty=OCUPADO;
			retorno=0;

		}


	}
	return retorno;

}

int findEmployeeById(Employee* list, int len,int id)
{
	int retorno=-1;

	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCUPADO&&list[i].id==id)
			{
				retorno=id;
				break;
			}
		}
	}
	return retorno;
}
void mostrarStruct(Employee mostrar [],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(mostrar[i].isEmpty==OCUPADO)
        {
            printf("Id:%d NOMBRE: %s PRECIO: %f DIRECCION: %s \n",mostrar[i].id,mostrar[i].name,mostrar[i].price,mostrar[i].addres);

        }
    }

}

int modificarEmployee (Employee* list,int len)
{
	int retorno=-1;
	int indice;
	if (len!=0&&list!=NULL)
	{
		utn_getInt(&indice, "ingrese el id a modificar \n", "error ingrese un numero\n", 1, len, 5);
		indice=findEmployeeById(list, len, indice);
		if(indice!=-1)
		{



		}



	}



}

int disp_menuModificar(Employee list[],int len,int indice)
{
	int retorno=-1;
	int opcion;
	char auxNombre[20];
	char auxApellido[20];
	int auxSector;
	float auxSalary;
	//int continuar;

	utn_getInt(&opcion, " Que desea modificar? \n 1-NOMBRE\n 2-APELLIDO\n 3-SALARIO\n 4-SECTOR \n 5-SALIR \n", "error ingrese un numero valid\n", 1, len, 5);

	switch(opcion)
	{
	case 1:
		getString("ingrese el nuevo nombre", auxNombre);
		strncpy(list[indice].name,auxNombre,sizeof(list->name));
		break;
	case 2:
		getString("ingrese la nueva direccion", auxApellido);
		strncpy(list[indice].lastName,auxApellido,sizeof(list->lastName));
		break;
	case 3:
		utn_getFloat(&auxSalary, "ingrese nuevo precio", "error ingrese numero validos", 1, 9999, 3);
		list[indice].salary=auxSalary;
		break;
	case 4:
		utn_getInt(&auxSector, "Ingrese:\n1-admistracion\n2-Programacion", "Error ingrese numeros validos\n", 1, 2, 4);
		list[indice].sector=auxSector;
		break;
	case 5:
		printf("saliendo del menu \n");
		break;
	default:
		printf("no es un numero valido \n");
		break;
	}


return retorno;
}





























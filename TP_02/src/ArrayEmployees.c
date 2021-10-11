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
	if(list!=NULL&& len>0)
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
	if(list!=NULL&& len>0)
	{
		indice=employe_buscarLibre(list, len);
		if(indice>=0)
		{
			list[indice].id=dameUnIdNuevo();
			getString("ingrese el nombre del empleado \n", list[indice].name);
			getString("Ingrese el apellido del empleado \n", list[indice].lastName);
			utn_getFloat(&list[indice].salary, "Ingrese su salario\n", "error ingrese solo numeros\n", 1, 999999, 6);
			utn_getInt(&list[indice].sector, "Ingrese:\n1-admistracion\n2-Programacion\n", "Error ingrese numeros validos\n", 1, 2, 4);
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
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
char reemplazarTipo(int tipo,char *retorno,int len)
{
	char aux[20];

	switch(tipo)
	{
	case 1:
		strncpy(aux,"administracion",sizeof(aux));
		break;
	case 2:
		strncpy(aux,"programacion",sizeof(aux));
		break;

	}
	strncpy(retorno,aux,len);
	return *retorno;

}
void mostrarUno(Employee mostrar[],int i)
{
	char auxTipo[14];
	reemplazarTipo(mostrar[i].sector,auxTipo,sizeof(auxTipo));
    printf("Id:%d NOMBRE: %s APELLIDO: %s SALARIO: %0.2f TIPO: %s  \n",mostrar[i].id,mostrar[i].name,mostrar[i].lastName,mostrar[i].salary,auxTipo);

}
void mostrarStruct(Employee mostrar [],int len)
{
    int i;
    char auxTipo[20];
    for(i=0; i<len; i++)
    {

        if(mostrar[i].isEmpty==OCUPADO)
        {
        	reemplazarTipo(mostrar[i].sector,auxTipo,sizeof(auxTipo));
            printf("Id:%d NOMBRE: %s APELLIDO: %s SALARIO: %f TIPO: %s  \n",mostrar[i].id,mostrar[i].name,mostrar[i].lastName,mostrar[i].salary,auxTipo);

        }
    }

}

int modificarEmployee (Employee* list,int len)
{
	int retorno=-1;
	int indice;
	int idAux;
	if (len!=0&&list!=NULL)
	{
		printEmployees(list, len);
		utn_getInt(&idAux, "ingrese el id a modificar \n", "error ingrese un numero\n", 1, len, 5);
		indice=findEmployeeById(list, len, idAux);
		if(indice!=-1)
		{

			disp_menuModificar(list, len, indice);
			retorno=1;

		}
		else
		{

			printf("no se encontro el id\n");
		}


	}

	return retorno;
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

int removeEmployee(Employee* list, int len)
{
	int retorno=-1;
	int idAux;
	int indice;
	if (len>0&&list!=NULL)
	{
		printEmployees(list, len);
		utn_getInt(&idAux, "ingrese el id a modificar \n", "error ingrese un numero\n", 1, len, 5);
		indice=findEmployeeById(list, len, idAux);
		if(indice!=-1)
		{
			struct_bajaMenu(list, len, indice);
			retorno=0;
		}
		else
		{
			printf("el id no existe\n");
		}



	}
	return retorno;

}
int struct_bajaMenu(Employee list[],int len,int indice)
{
	int auxBaja;
	int retorno;

	if (len!=0&&list!=NULL)
	{
		mostrarUno(list, indice);
		utn_getInt(&auxBaja, "Aprete 1 para dar de baja 2 para cancelar", "error ingrese un numero valido", 1, 2, 3);

		if (auxBaja==1)
		{
			printf("se dio de baja\n");
			list[indice].isEmpty=2;
			retorno=1;
		 }
		 else
		 {
			 printf("no se dio de baja\n");
			 retorno=0;
		 }

	}
	return retorno;
}
void transefrirDatos(Employee listado  [],Employee auxiliarListado  [],int len)
{
    int i;

    for(i=0;i<len;i++)
    {
       // if(listado[i].isEmpty==OCUPADO)
        {
            listado[i].isEmpty=auxiliarListado[i].isEmpty;
            listado[i].id=auxiliarListado[i].id;
            listado[i].salary=auxiliarListado[i].salary;
            listado[i].sector=auxiliarListado[i].sector;
            strcpy(listado[i].name,auxiliarListado[i].name);
            strcpy(listado[i].lastName,auxiliarListado[i].lastName);
        }
    }
}


int ordenarArraySegunCriterio(Employee list [], int len, int orden)
{
	Employee Aux;

	int contador = 0;
	char auxTipo[15];
	char auxTipoDos[15];
	switch (orden)
	{
	case 1:

		for (int i = 0; i < len - 1; i++)
		{
			if (list[i].isEmpty == OCUPADO)
			{
				if (strcmp(list[i].lastName, list[i + 1].lastName) > 0)
				{
					Aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = Aux;
					reemplazarTipo(list[i].sector, auxTipo, len);
					reemplazarTipo(list[i + 1].sector, auxTipoDos, len);
					if (strcmp(auxTipo, auxTipoDos) == 0)
					{
						Aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = Aux;
					}
				}
			}
		}
		break;

	case 2:

		for (int i = 0; i < len - 1; i++)
		{
			if (list[i].isEmpty == OCUPADO)
			{
				if (strcmp(list[i].lastName, list[i + 1].lastName) < 0)
				{

					Aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = Aux;
					reemplazarTipo(list[i].sector, auxTipo, len);
					reemplazarTipo(list[i + 1].sector, auxTipoDos, len);
					if (strcmp(auxTipo, auxTipoDos) == 0)
					{
						Aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = Aux;
					}
				}
			}
		}
		break;
	}

	printEmployees(list, len);
	//imprimirIntArray(arrayParaOrdenar, len);
	return contador;

}

int printEmployees(Employee* list, int len)
{
	int retorno=-1;
    int i;
    char auxTipo[20];
    printf("\nId: NOMBRE:  APELLIDO:  SALARIO:  TIPO:  ");
    for(i=0; i<len; i++)
    {

        if(list[i].isEmpty==OCUPADO)
        {
        	reemplazarTipo(list[i].sector,auxTipo,sizeof(auxTipo));
            printf("\n%d\t%s\t%s\t  %0.2f\t %s  \t",list[i].id,list[i].name,list[i].lastName,list[i].salary,auxTipo);

        }
    }
    retorno=0;
    return retorno;

}

float informarSalarios(Employee* list,int len,float * promedio)
{

	float acumulador=0;
	int contador=0;
	if (len!=0&&list!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if (list[i].isEmpty==OCUPADO)

			{
				acumulador=acumulador+list[i].salary;
				contador++;
			}
		}
		*promedio=acumulador/contador;
	}
	return acumulador;
}

int empleadosQueSuperanElPromedio(Employee* list,int len)
{
	float promedio;
	int contador=0;

	informarSalarios(list, len,&promedio);
	if (len!=0&&list!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if (list[i].isEmpty==OCUPADO)
			{
				if(list[i].salary>promedio)
				{
					contador++;
				}
			}
		}
	}

	return contador;

}
void mostrarStructQueSuperaPromedio(Employee mostrar [],int len)
{
    int i;
    char auxTipo[20];
    float promedio;
    float acumulador=0;
    acumulador=informarSalarios(mostrar, len,&promedio);
    int PromedioQueSuperan=0;
    PromedioQueSuperan=empleadosQueSuperanElPromedio(mostrar, len);

    printf("TOTAL DE LOS SALARIOS %f, PROMEDIO DE LOS SALARIOS %f \n",acumulador,promedio);
    printf("CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO %d\n",PromedioQueSuperan);

   printf("ESTOS EMPLEADOS SUPERAN EL PROMEDIO \n");

    for(i=0; i<len; i++)
    {

        if(mostrar[i].isEmpty==OCUPADO)
        {
        	if(mostrar[i].salary>promedio)
        	{
        		reemplazarTipo(mostrar[i].sector,auxTipo,sizeof(auxTipo));
        		printf("Id:%d NOMBRE: %s APELLIDO: %s SALARIO: %f TIPO: %s  \n",mostrar[i].id,mostrar[i].name,mostrar[i].lastName,mostrar[i].salary,auxTipo);
        	}

        }
    }

}


















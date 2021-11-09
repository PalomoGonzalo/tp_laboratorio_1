#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "funciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
//
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;

	FILE* pFile=fopen(path,"r");

	if(pFile!=NULL)
	{
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			parser_EmployeeFromText(pFile, pArrayListEmployee);
			retorno=1;
			printf("\nSe cargo con exito la lista\n");
		}
		else
			printf("no se puedo cargar la lista\n");
	}

	fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;

	FILE * pFile=fopen(path,"rb");

	if(pFile!=NULL)
	{
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			retorno=1;
			printf("se cargo con exito la lista\n");
		}
		else
			printf("no se puedo cargar la lista \n");
	}
	fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int auxId;
	char idChar[32];
	char sueldo[32];
	char horasTrabajadas[32];
	char nombre[32];

	auxId=controller_nextId(pArrayListEmployee);
	sprintf(idChar,"%d",auxId);

	if(pArrayListEmployee!=NULL)
	{
		getString("ingrese su nombre\n", nombre);
		getIntString("ingrese su sueldo \n", sueldo);
		getIntString("ingrese su horas trabajadas", horasTrabajadas);

		ll_add(pArrayListEmployee,employee_newParametros(idChar, nombre, horasTrabajadas, sueldo));

	}





    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* pEmploye=NULL;
	int id;
	int existeId;
	int indiceId;

	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		utn_getInt(&id, "\ningrese el id que desea modificar\n", "Error reingrese un numero valido \n", 1, 111111, 3);
		existeId=employee_findById(pArrayListEmployee, id, &indiceId);
		if(existeId==1)
		{
			printf("\neste es el empleado que va a modificar\n");
			controller_ListOneEmployee(pArrayListEmployee, indiceId);
			controller_menuEditEmployee(pEmploye, pArrayListEmployee, indiceId);
			printf("\nse modifico correctamente\n");
		}
		else
		{

			printf("no existe el id \n");
		}



	}

    return retorno;
}

int controller_menuEditEmployee(Employee* pEmploye,LinkedList* pArrayListEmployee,int indiceId)
{
	int opcion;
	char auxNombre[32];
	int auxHoras;
	int sueldoAux;
	printf("\nQue desea modificar\n");
	puts("\n1- NOMBRE\n2- Horas Trabajadas\n3- Sueldo\n4- Salir\n ");
	utn_getInt(&opcion, "\ningrese una opcion\n", "error reingrese numeros validos \n", 1, 4, 4);
	pEmploye=ll_get(pArrayListEmployee, indiceId);
	switch(opcion)
	{
	case 1:
		getString("ingrese el nuevo nombre\n", auxNombre);
		employee_setNombre(pEmploye, auxNombre);
		break;
	case 2:
		utn_getInt(&auxHoras, "ingrese las nuevas horas trabajadas\n", "Error ingrese un numero valido", 1, 999, 4);
		employee_setHorasTrabajadas(pEmploye, auxHoras);
		break;
	case 3:
		utn_getInt(&sueldoAux, "ingrese su nuevo sueldo\n", "Error ingrese un numero valido", 1, 9999999, 4);
		employee_setSueldo(pEmploye, sueldoAux);
		break;
	case 4:
		break;

	}
	ll_set(pArrayListEmployee, indiceId, pEmploye);


	return 1;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee * pEaux;
	int id;
	char nombre[32];
	int sueldo;
	int horasTrabajads;

	printf("id:\tnombre:\t      sueldo:\t horas trabajadas:\t");
   for(int i=0; i<ll_len(pArrayListEmployee); i++)
	{
		pEaux = ll_get(pArrayListEmployee,i);
		employee_getNombre(pEaux, nombre);
		employee_getId(pEaux, &id);
		employee_getSueldo(pEaux, &sueldo);
		employee_getHorasTrabajadas(pEaux, &horasTrabajads);
		printf("\n%d\t%8s\t%6d\t%10d\t",id,nombre,sueldo,horasTrabajads);
	}

   return 1;
}
int controller_ListOneEmployee(LinkedList* pArrayListEmployee,int indice)
{
	Employee * pEaux;
	int id;
	char nombre[32];
	int sueldo;
	int horasTrabajads;

	printf("id:\tnombre:\t      sueldo:\t horas trabajadas:\t");


		pEaux = ll_get(pArrayListEmployee,indice);
		employee_getNombre(pEaux, nombre);
		employee_getId(pEaux, &id);
		employee_getSueldo(pEaux, &sueldo);
		employee_getHorasTrabajadas(pEaux, &horasTrabajads);
		printf("\n%d\t%8s\t%6d\t%10d\t",id,nombre,sueldo,horasTrabajads);


   return 1;
}
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile = NULL;
    Employee * pEmployee = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {

            for(int i =0 ; i<ll_len(pArrayListEmployee) ; i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                fwrite(pEmployee, sizeof(Employee), 1, pFile);

            }

            printf("Guardado con exito\n");
            retorno = 0;
        }
    }
    fclose(pFile);
    return retorno;
}

int controller_nextId(LinkedList* pArrayListEmployee)
{
	int idRetorno;
	int i;
	if(pArrayListEmployee!=NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{

		}
	}
	idRetorno=i+1;
	return idRetorno;

}
int employee_findById(LinkedList* pArrayListEmployee,int id, int* indiceDeId)
{
	int retorno=-1;
	Employee *pEmployee;
	int idAux;

	if(pArrayListEmployee!=NULL&&indiceDeId!=NULL)
	{
		for(int i=0;i<ll_len(pArrayListEmployee);i++)
		{
			pEmployee=ll_get(pArrayListEmployee, i);
			if(pEmployee!=NULL)
			{
				employee_getId(pEmployee, &idAux);
				if(idAux==id)
				{
					*indiceDeId=i;
					retorno=1;
					break;
				}
			}
		}
	}
	return retorno;
}






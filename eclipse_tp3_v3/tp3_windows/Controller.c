#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;

	FILE* pFile=fopen(path,"r");

	if(pFile!=NULL)
	{
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			if(parser_EmployeeFromText(pFile, pArrayListEmployee))
			{
				retorno=1;
				printf("\nSe cargo con exito la lista\n");

			}
			else
				printf("no se puedo cargar la lista\n");

		}

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

	FILE * pFile=fopen(path,"r");

	if(pFile!=NULL)
	{
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			if(parser_EmployeeFromBinary(pFile, pArrayListEmployee))
			{
				retorno=1;
				printf("se cargo con exito la lista\n");

			}
			else
				printf("no se puedo cargar la lista \n");

		}
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
                if(pEmployee != NULL)
                    fwrite(pEmployee, sizeof(Employee), 1, pFile);
            }
            fclose(pFile);
            printf("Guardado con exito\n");
            retorno = 0;
        }
    }
    return retorno;
}









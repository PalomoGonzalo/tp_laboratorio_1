#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int retorno=-1;
	Employee* pEaux;
	char id[256];
	char nombre[256];
	char horas[256];
	char sueldo[256];

	if(pFile!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo); // salteo la 1era
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo)==4)
			{

				pEaux = employee_newParametros(id,nombre,horas,sueldo);
				if(pEaux!=NULL)
				{
					retorno=1;
					ll_add(pArrayListEmployee,pEaux);
					employee_dameIdNuevo();
				}
			}
			else
			{
				employee_delete(pEaux);
				break;
			}

		}while( feof(pFile)==0 );
	}
return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;

    Employee* pEaux;

    if(pFile!=NULL)
    {
        do
        {
        	pEaux = employee_new();
            if(fread(pEaux,sizeof(Employee),1,pFile)==1)
            {
                ll_add(pArrayListEmployee,pEaux);
                retorno=1;
            }
            else
            {
                employee_delete(pEaux);
                break;
            }
        }while( feof(pFile)==0 );
    }
    return retorno;
}

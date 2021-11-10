#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "LinkedList.h"

#define NOMBRE_LEN 32
Employee* employee_new()
{
	Employee* pEmployee= malloc(sizeof(Employee));
	return pEmployee;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char *sueldo,LinkedList* pArrayListEmployee,int * flag)
{
	Employee* auxEmployee;
	auxEmployee=employee_new();
	*flag=1;
	int idAux;


	if(auxEmployee!=NULL && idStr!=NULL && nombreStr !=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL )
	{
		idAux=controller_nextId(pArrayListEmployee);
		sprintf(idStr,"%d",idAux);
		if(employee_setIdTxt(auxEmployee, idStr)!=1)
		{
			*flag=0;
		}
		if(employee_setNombre(auxEmployee, nombreStr)!=1)
		{
			*flag=0;
		}
		if(employee_setHorasTrabajadasTxt(	auxEmployee,horasTrabajadasStr)!=1)
		{
			*flag=0;
		}
		if(employee_setSueldoTxt(auxEmployee, sueldo)!=1)
		{
			*flag=0;
		}



	}

	return auxEmployee;


}

void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);

	}

}

int employee_setId(Employee* this,int id)
{
	 int retorno =-1;
	 if(this!=NULL && id>=0)
	 {
		 retorno=1;
		 this->id=id;
	 }

	 return retorno;

}

int employee_getId(Employee* this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		retorno=1;
		*id=this->id;
	}

	return retorno;

}




int employee_setIdTxt(Employee* this, char* idTxt)
{
    int retorno = -1;
    if(this != NULL && idTxt!=NULL)
        if(esNumerico(idTxt))
        {
        	retorno=1;
           this->id=atoi(idTxt);
        }
    return retorno;
}

int employee_getIdTxt(Employee* this, char *idTxt)
{
	int retorno=-1;
	if(this!=NULL && idTxt!=NULL)
	{
		retorno=1;
		sprintf(idTxt,"%d",this->id);

	}

	return retorno;

}



int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		if(validar_palabra(nombre))
		{
			retorno=1;
			strncpy(this->nombre,nombre,NOMBRE_LEN);

		}

	}

	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		retorno=1;
		strncpy(nombre,this->nombre,NOMBRE_LEN);


	}
	return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;

	if(this!=NULL && horasTrabajadas>0)
	{
		retorno=1;
		this->horasTrabajadas=horasTrabajadas;

	}

	return retorno;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;

	if(this!=NULL&& horasTrabajadas!=NULL)
	{
		retorno=1;
		*horasTrabajadas=this->horasTrabajadas;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;

	if(this!=NULL && sueldo>0)
	{

		retorno=1;
		this->sueldo=sueldo;

	}
	return retorno;

}


int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno =-1;

	if(this!=NULL && sueldo!=NULL)
	{
		retorno=1;
		*sueldo=this->sueldo;

	}
	return retorno;

}



int employee_dameIdNuevo(void)
{
	static int contador=0;
	contador++;
	return contador;

}


int employee_setSueldoTxt(Employee* this, char* idTxt)
{
    int retorno = -1;
    if(this != NULL && idTxt!=NULL)
        if(esNumerico(idTxt))
        {
        	retorno=1;
           this->sueldo=atoi(idTxt);
        }
    return retorno;
}


int employee_setHorasTrabajadasTxt(Employee* this, char* idTxt)
{
    int retorno = -1;
    if(this != NULL && idTxt!=NULL)
        if(esNumerico(idTxt))
        {
        	retorno=1;
           this->horasTrabajadas=atoi(idTxt);
        }
    return retorno;
}



int controller_nextId(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int idAux;
    int idMax=0;
    Employee *pEmployee;
    if(pArrayListEmployee != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            if(i == 0)
            {
                employee_getId(pEmployee, &idMax);
            }
            else
            {
                employee_getId(pEmployee, &idAux);
                if(idAux > idMax)
                {
                    idMax = idAux;
                }
            }
        }
        retorno = idMax+1;
    }
    return retorno;

}

int employee_ordenarPorNombre(void* employeeA, void* employeeB)
{
    int retorno = 0;
    Employee* empA=(Employee*) employeeA;
    Employee* empB=(Employee*) employeeB;
    if(employeeA !=NULL && employeeB !=NULL)
    {
        retorno = stricmp(empB->nombre, empA->nombre);
    }
    return retorno;
}





















































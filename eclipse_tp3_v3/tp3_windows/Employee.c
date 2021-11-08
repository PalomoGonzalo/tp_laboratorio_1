#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define NOMBRE_LEN 32
Employee* employee_new()
{
	Employee* pEmployee= malloc(sizeof(Employee));
	return pEmployee;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char *sueldo)
{
	Employee* auxEmployee;
	auxEmployee=employee_new();

	if(auxEmployee!=NULL && idStr!=NULL && nombreStr !=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL )
	{
		employee_setIdTxt(auxEmployee, idStr);
		employee_setNombre(auxEmployee, nombreStr);
		employee_setHorasTrabajadas(auxEmployee, atoi(horasTrabajadasStr));
		employee_setSueldo(auxEmployee, atoi(sueldo));
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
		if(esSoloLetras(nombre))
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































































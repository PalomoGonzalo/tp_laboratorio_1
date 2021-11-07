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

	if(auxEmployee!=NULL)
	{
		auxEmployee->horasTrabajadas=atoi(horasTrabajadasStr);
		auxEmployee->id=atoi(idStr);
		strncpy(auxEmployee->nombre,nombreStr,sizeof(auxEmployee->nombre));

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

int employee_getIdTxt(Employee* this, char idTxt)
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



	}


}

























































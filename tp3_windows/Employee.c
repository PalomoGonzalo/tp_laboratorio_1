#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void employee_delete()
{



}

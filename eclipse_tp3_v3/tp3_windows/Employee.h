#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char *sueldo,LinkedList* pArrayListEmployee);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setIdTxt(Employee* this, char* idTxt);
int employee_getIdTxt(Employee* this, char* idTxt);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_dameIdNuevo(void);
int employee_setHorasTrabajadasTxt(Employee* this, char* idTxt);
int employee_setSueldoTxt(Employee* this, char* idTxt);
int controller_nextId(LinkedList* pArrayListEmployee);
int employee_ordenarPorNombre(void* employeeA, void* employeeB);
#endif // employee_H_INCLUDED

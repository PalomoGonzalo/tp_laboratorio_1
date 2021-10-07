/*
 * ArrayEmployees.h
 *
 *  Created on: 5 oct. 2021
 *      Author: mati_
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define OCUPADO 0
#define LIBRE 1
#include "funciones.h"
struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);
int dameUnIdNuevo(void);
int addEmployee(Employee list[],int len);
int employe_buscarLibre(Employee list[],int len);
int disp_menuModificar(Employee list[],int len,int indice);
int findEmployeeById(Employee* list, int len,int id);
void mostrarStruct(Employee mostrar [],int len);
char reemplazarTipo(int tipo,char *retorno);


#endif /* ARRAYEMPLOYEES_H_ */

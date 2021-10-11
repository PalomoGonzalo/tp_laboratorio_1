/*
 ============================================================================
 Name        : TP_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayEmployees.h"
#define LEN_EMPLOYEES 100

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	char seguir='s';
	int retornoAdd=-1;



	Employee listaEmployee[LEN_EMPLOYEES];
	Employee auxOrdenar[LEN_EMPLOYEES];

	initEmployees(listaEmployee, LEN_EMPLOYEES);

	do{
		utn_getInt(&opcion, "\n 1-Dar de Alta\n 2-Modificar\n 3-Dar de baja\n 4-ordenar\n 5-Mostrar de forma encolumnada\n 6-Informar\n 7-Salir\n", "error ingrese numeros validos", 1, 7, 4);
		switch(opcion)
		{
		case 1:
			retornoAdd=addEmployee(listaEmployee, LEN_EMPLOYEES);
			printEmployees(listaEmployee, LEN_EMPLOYEES);
			break;
		case 2:
			if(retornoAdd==0)
				modificarEmployee(listaEmployee, LEN_EMPLOYEES);
			else
				printf("no hay datos cargados \n");
			break;
		case 3:
			if(retornoAdd==0)
				removeEmployee(listaEmployee, LEN_EMPLOYEES);
			else
				printf("no hay datos cargados \n");
			break;
		case 4:
			if(retornoAdd==0)
			{
				transefrirDatos(auxOrdenar, listaEmployee, LEN_EMPLOYEES);
				ordenarArraySegunCriterio(auxOrdenar,LEN_EMPLOYEES,2);
			}
			else
				printf("no hay datos cargados \n");
			break;
		case 5:
			if(retornoAdd==0)
				printEmployees(listaEmployee, LEN_EMPLOYEES);
			else
				printf("no hay datos cargados \n");
			break;
		case 6:
				mostrarStructQueSuperaPromedio(listaEmployee, LEN_EMPLOYEES);
			break;
		case 7:
			seguir='n';
		}
	}while(seguir=='s');



	return EXIT_SUCCESS;
}

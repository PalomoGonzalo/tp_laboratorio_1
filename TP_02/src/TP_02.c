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

	do{
		utn_getInt(&opcion, " 1-Dar de Alta\n 2-Modificar\n 3-Dar de baja\n 4-Salir\n", "error ingrese numeros validos", 1, 4, 4);
		switch(opcion)
		{
		case 1:
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			seguir='n';
			break;
		}
	}while(seguir=='s');



	return EXIT_SUCCESS;
}

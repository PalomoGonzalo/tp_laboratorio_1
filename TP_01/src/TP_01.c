/*
 ============================================================================
 Name        : TP_01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {

	setbuf(stdout, NULL);
	float numeroUno=0;
	float numeroDos=0;
	char seguir = 's';
	int opcion = 0;
	int aux;
	int flagNumUno;
	int flagNumDos;
	int auxDatos;
	float resultadoDivision;
	while (seguir=='s')
	{
		auxDatos=verificarDatos(flagNumUno, flagNumDos);
		printf("1- Ingresar 1er operando (A=x)\n");
		printf("2- Ingresar 2do operando (B=y)\n");
		printf("3- Calcular la suma (A+B)\n");
		printf("4- Calcular la resta (A-B)\n");
		printf("5- Calcular la division (A/B)\n");
		printf("6- Calcular la multiplicacion (A*B)\n");
		printf("7- Calcular el factorial (A!)\n");
		printf("8- Calcular todas las operacione\n");
		printf("9- Salir\n");
		scanf("%d",&opcion);

		switch (opcion)
		{
			case 1:
				flagNumUno=pedirNumeros(&numeroUno, "ingrese el primer operando\n");
				break;
			case 2:
				flagNumDos=pedirNumeros(&numeroDos,"ingrese el segundo operando\n");
				break;

			case 3:

				if(auxDatos==1)
				{
					sumarNumeros(numeroUno,numeroDos);
				}
				else
				{
					mensajeErrorDatos(auxDatos);
				}

				break;

			case 4:

				if(auxDatos==1)
				{
					restarNumeros(numeroUno,numeroDos);
				}
				else
				{
					mensajeErrorDatos(auxDatos);
				}
				break;

			case 5:

				if(auxDatos==1)
				{
					aux=dividirNumeros(numeroUno, numeroDos, &resultadoDivision);
					mensajeDivison(aux,resultadoDivision,numeroUno,numeroDos);
				}
				else
				{
					mensajeErrorDatos(auxDatos);
				}
				break;

			case 6:

				if(auxDatos==1)
				{
					multiplicarNumeros(numeroUno, numeroDos);
				}
				else
				{
					mensajeErrorDatos(auxDatos);
				}
				break;

			case 7:

				if(auxDatos==1)
				{
					factorialNumeros(numeroUno);
					factorialNumeros(numeroDos);
				}
				else
				{
					mensajeErrorDatos(auxDatos);
				}

				break;

			case 8:

				if(auxDatos==1)
				{
					sumarNumeros(numeroUno,numeroDos);
					restarNumeros(numeroUno,numeroDos);
					aux=dividirNumeros(numeroUno, numeroDos, &resultadoDivision);
					mensajeDivison(aux,resultadoDivision,numeroUno,numeroDos);
					multiplicarNumeros(numeroUno, numeroDos);
					factorialNumeros(numeroUno);
					factorialNumeros(numeroDos);
				}
				else
				{
					mensajeErrorDatos(auxDatos);
				}
				break;
			case 9:
				seguir='n';
				break;
		}
	}

	return EXIT_SUCCESS;
}

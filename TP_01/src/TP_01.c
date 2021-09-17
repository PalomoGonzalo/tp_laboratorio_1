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
	float suma;
	float resta;
	float multiplicar;
	int factorialUno;
	int factorialDos;
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
		printf("3- Calcular todas las operaciones\n");
		printf("4- Informar todos los resultados\n");
		printf("5- Salir\n");
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
									suma=sumarNumeros(numeroUno,numeroDos);
									resta=restarNumeros(numeroUno,numeroDos);
									aux=dividirNumeros(numeroUno, numeroDos, &resultadoDivision);
									multiplicar=multiplicarNumeros(numeroUno, numeroDos);
									factorialUno=factorialNumeros(numeroUno);
									factorialDos=factorialNumeros(numeroDos);
								}
								else
								{
									mensajeErrorDatos(auxDatos);
								}

				break;
			case 4:

				mostrarTodosLosResultados(numeroUno,numeroDos,suma,resta,resultadoDivision,aux, multiplicar, factorialUno, factorialDos);
				break;
		}
	}

	return EXIT_SUCCESS;
}

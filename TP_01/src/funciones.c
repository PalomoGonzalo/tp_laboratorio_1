/*
 * funciones.c
 *
 *  Created on: 14 sept. 2021
 *      Author: mati_
 */
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int pedirNumeros(float* numeros,char* mensaje)
{
	int flag=1;
	printf(mensaje);
	fflush(stdin);
	scanf("%f",numeros);
	return flag;
}
int verificarDatos(int flagUno, int flagDos)
{
	int retorno=0;
	if(flagUno!=1&&flagDos!=1)
	{
		retorno=0;
	}
	if(flagUno==1&&flagDos!=1)
	{
		retorno=-1;
	}
	 if(flagUno!=1&&flagDos==1)
	{
		retorno=-2;
	}
	if(flagUno==1&&flagDos==1)
	{
		retorno=1;
	}
	return retorno;
}
void mensajeErrorDatos(int retorno)
{
	if(retorno==0)
	{
		printf("no hay datos para los operandos\n\n");
	}
	if(retorno==-1)
	{
		printf("no hay dato para el segundo operando\n\n");
	}
	if(retorno==-2)
	{
		printf("no hay dato para el primer operando\n\n");
	}


}
void sumarNumeros(float a,float b)
{
	float resultado;
	resultado=a+b;
	printf("la suma de %0.2f+%0.2f es = %0.2f \n",a,b,resultado);

}
float restarNumeros(float a,float b)
{
	float resultado;
	resultado=a-b;
	printf("la resta de %0.2f-%0.2f es = %0.2f \n",a,b,resultado);
	return resultado;
}
int dividirNumeros (float a,float b,float* resultado)
{
	int retorno;

	if(b!=0)
	{
		*resultado=a /b;

	}
	else
	{
		retorno=1;
	}
	return retorno;

}
void mensajeDivison(int retorno,float resultado,float a,float b)
{
	if(retorno==1)
	{
		printf("no se puede divivir por cero\n");
	}
	else
	{
		printf("la division de %0.2f/%0.2f es = %0.2f \n",a,b,resultado);
	}

}

float multiplicarNumeros(float a,float b)
{
	float resultado;
	resultado=a*b;
	printf("la multiplicacion de %0.2f*%0.2f es = %0.2f \n",a,b,resultado);
	return resultado;
}
int factorialNumeros(int numero)
{
	int factorial = 1;
	while (numero < 0)
	{
		printf("no se puede sacar factor numero negativo, reingrese el numero\n");
		scanf("%d", &numero);
	}

	for (int i = 1; i <= numero; i++)
	{
		factorial *= i;
	}

	printf("el factorial de %d es = %d\n",numero,factorial);
	return factorial;

}


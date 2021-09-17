/*
 * funciones.h
 *
 *  Created on: 14 sept. 2021
 *      Author: mati_
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
int pedirNumeros(float* numeros,char* mensaje);
float sumarNumeros(float a,float b);
float restarNumeros(float a,float b);
float dividirNumeros (float a,float b,float* resultado);
void mensajeDivison(int retorno,float resultado,float a,float b);
float multiplicarNumeros(float a,float b);
float factorialNumeros(float numero);
int verificarDatos(int flagUno, int flagDos);
void mensajeErrorDatos(int retorno);
void mensajeFactorialNumero(float numero,int resultado);
void mostrarTodosLosResultados(float a,float b,float suma, float resta, float division,int retornoDivision, float multiplicacion,float factorialUno, float factorialDos);



#endif /* FUNCIONES_H_ */

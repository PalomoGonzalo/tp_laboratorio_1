/*
 * funciones.h
 *
 *  Created on: 14 sept. 2021
 *      Author: mati_
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
int pedirNumeros(float* numeros,char* mensaje);
void sumarNumeros(float a,float b);
float restarNumeros(float a,float b);
int dividirNumeros (float a,float b,float* resultado);
void mensajeDivison(int retorno,float resultado,float a,float b);
float multiplicarNumeros(float a,float b);
int factorialNumeros(int numero);
int verificarDatos(int flagUno, int flagDos);
void mensajeErrorDatos(int retorno);


#endif /* FUNCIONES_H_ */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int banderaLoad=0;


    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
       printf(" \nMenu:\n");
         printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
         printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
         printf("3. Alta de empleado\n");
         printf ("4. Modificar datos de empleado\n");
         printf("5. Baja de empleado\n");
         printf("6. Listar empleados\n");
         printf("7. Ordenar empleados\n");
         printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
         printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
         printf("10. Salir");
    	utn_getInt(&option, "\ningrese una opcion \n", "error reingre \n", 1, 11, 3);
        switch(option)
        {
            case 1:
            	if(banderaLoad==0)
            	{
            		controller_loadFromText("data.csv",listaEmpleados);
            		banderaLoad=1;
            	}
            	else
            		printf("ya hay datos cargados\n");
                break;
            case 2:
            	if(banderaLoad==0)
            	{
            		controller_loadFromBinary("binario.bin", listaEmpleados);
            		banderaLoad=1;
            	}
            	else
            		printf("ya hay datos cargados\n");

            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	if(ll_isEmpty(listaEmpleados)==0)
            		controller_editEmployee(listaEmpleados);
            	else
            		printf("error cargue algo en la lista\n");
            	break;
            case 5:
            	if(ll_isEmpty(listaEmpleados)==0)
            		controller_removeEmployee(listaEmpleados);
            	else
            		printf("error cargue algo a la lista \n");
            	break;
            case 6:
            	if(ll_isEmpty(listaEmpleados)==0)
            	{
            	 controller_ListEmployee(listaEmpleados);
            	}
            	else
            		printf("no hay existe datos para listar \n");
            	break;
            case 7:
            	if(ll_isEmpty(listaEmpleados)==0)
            	{
            	 controller_sortEmployee(listaEmpleados);
            	 controller_ListEmployee(listaEmpleados);
            	}
            	else
            		printf("no hay existe datos para ordenar \n");
            	break;
            case 8:
            	if(ll_isEmpty(listaEmpleados)==0)
            		controller_saveAsText("data.csv", listaEmpleados);
            	else
            		printf("no hay existe datos guardar \n");
            	break;

            case 9:
            	if(ll_isEmpty(listaEmpleados)==0)
            		controller_saveAsBinary("binario.bin", listaEmpleados);
            	else
            		printf("no hay existe datos guardar \n");
            	break;
            case 10:
            	ll_deleteLinkedList(listaEmpleados);
            	option=10;
            	break;

        }
    }while(option != 10);
    return 0;
}


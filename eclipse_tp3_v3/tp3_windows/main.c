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

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
       printf(" Menu:");
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
    	utn_getInt(&option, "ingrese una opcion \n", "error reingre \n", 1, 8, 3);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	controller_loadFromBinary("binario.bin", listaEmpleados);
            	break;
            case 3:
            	controller_ListEmployee(listaEmpleados);

            	break;
            case 6:
            	controller_saveAsBinary("binario.bin", listaEmpleados);
            	break;
        }
    }while(option != 10);
    return 0;
}


#include "Employee.h"
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_nextId(LinkedList* pArrayListEmployee);
int employee_findById(LinkedList* pArrayListEmployee,int id, int* indiceDeId);
int controller_menuEditEmployee(Employee* pEmploye,LinkedList* pArrayListEmployee,int indiceId);
int controller_ListOneEmployee(LinkedList* pArrayListEmployee,int indice);

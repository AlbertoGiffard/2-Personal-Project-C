#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
struct
{
 int id;
 int isEmpty;
 int sector;
 char lastName[51];
 char name[51];
 float salary;
}typedef Employee;

/**
* Esta funcion será el menu principal que se mostrara para la resolucion del usuario
*/
int mainMenu();
/**
* inicia el atributo isEmpty en 1 indicando que ese espacio esta vacio
*/
int initEmployees(Employee[], int);
/**
* Aca pide los datos del empleado al elegir la opcion de darse de Altas
*/
Employee addEmployee(int);
/**
* verifica que hay espacio disponible en la nomina
*/
int thereIsSpace(Employee[], int);
/**
* Recorre el array de empleados
*/
int arrayOfEmployees(Employee[], int, int);
/**
* busca dentro del array el empleado a modificar por id
*/
int modifyEmployee(Employee[], int, int);
/**
* el nombre y apellido me lo coloca con las primeras letras en mayuscula
*/
int firstLetterUp(char[], int);
/**
* busca dentro del array el empleado a eliminar por id
*/
int removeEmployee(Employee[], int, int);
/**
* verifica que no haya ningun empleado en la nomina
*/
int fileEmpty(Employee[], int);
/**
* recorre el array y me devuelve el indice del vector
*/
int findEmployeeById(Employee[], int, int);
/**
* Ordena el array de empleados por apellido y sector de manera ascendente o descendente
*/
int sortEmployees(Employee[], int);
/**
* Imprime el array de empleados de forma encolumnada
*/
int printEmployees(Employee[], int, float, float, int);
/**
* para determinar total y promedio
*/
float totalSalary(Employee[], int);
float avgSalary(Employee[], int);
/**
* para determinar que este sobre el promedio
*/
int aboveAvg(Employee[], int, float);


#endif // ARRAYEMPLOYEES_H_INCLUDED

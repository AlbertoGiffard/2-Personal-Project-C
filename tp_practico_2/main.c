/******************************************************************************

Alberto Giffard

bajo ninguna circunstancia superara los 1000 empleados.

menu de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
(por parametro ID)
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
(por parametro ID)
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
(por parametro ID)
4. INFORMAR:
    a. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
    b. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

( no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.)

                                ///////// Biblioteca ///////////
ArrayEmployees.h y ArrayEmployees.c
struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;
1. Primera Funcion
    int initEmployees(Employee, int);
    Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
    (isEmpty) en TRUE(1) en todas las posiciones del array.
    int initEmployees(Employee list, int count)
    {
        return 0;
    }
2. Segunda Funcion
    int addEmployee(Employee, int, int, char[],char[],float,int);
    Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
    posición libre.
    int addEmployee(Employee list, int len, int id, char name[],charlastName[],float salary,int sector)
    {
     \brief add in a existing list of employees the values received as parameters
     * in the first empty position
     * \param list employee*
     * \param len int
     * \param id int
     * \param name[] char
     * \param lastName[] char
     * \param salary float
     * \param sector int
     * \return int Return (-1) if Error [Invalid length or NULL pointer or without
    free space] - (0) if Ok
    *
        // el isEmpty pasa a ser -1
        return -1;
    }
3. Tercera Funcion
    int findEmployeeById(Employee, int,int);
    Busca un empleado recibiendo como parámetro de búsqueda su Id.
    \brief find an Employee by Id en returns the index position in array.
     *
     * \param list Employee*
     * \param len int
     * \param id int
     * \return Return employee index position or (-1) if [Invalid length or NULL
    pointer received or employee not found]
    *

    int findEmployeeById(Employee list, int count,int id)
    {
    return NULL
    }
4. Cuarta Función
    int removeEmployee(Employee, int, int);
    Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
    \brief Remove a Employee by Id (put isEmpty Flag in 1)
     *
     * \param list Employee*
     * \param len int
     * \param id int
     * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
    find a employee] - (0) if Ok
    *
    int removeEmployee(Employee* list, int count, int id)
    {
        return -1;
    }
5. Quinta Función
    int sortEmployees(Employee, int, int);
    Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
    \brief Sort the elements in the array of employees, the argument order
    indicate UP or DOWN order
    *
    * \param list Employee*
    * \param len int
    * \param order int [1] indicate UP - [0] indicate DOWN
    * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
    *
    int sortEmployees(Employee list, int count, int order)
    {
        return 0;
    }

6. Sexta Función
    int printEmployees(Employee, int);
    Imprime el array de empleados de forma encolumnada.
    \brief print the content of employees array
     *
     * \param list Employee*
     * \param length int
     * \return int
     *
    int printEmployees(Employee* list, int length)
    {
    return 0;
    }
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#define PAYROLL 1000


int main()
{
    setlocale(LC_ALL, "");

    int option;
    int idToChange;
    int id;
    int empty;
    int add;
    int space;
    Employee listOfEmployee[PAYROLL];

    id = 1;
    initEmployees(listOfEmployee, PAYROLL);
    do
    {
        option = mainMenu();
        while (!(option > 0 && option < 6))
        {
            printf("\t\t    -\n");
            printf("\t%s\n","Ingrese una opción válida");
            printf("\t\t    -\n");
            option = mainMenu();
        }
        switch (option)
        {
            case 1:
                space = thereIsSpace(listOfEmployee, PAYROLL);
                if (space == 1)
                {
                    add = arrayOfEmployees(listOfEmployee, PAYROLL, id);
                    if (add == 0)
                    {
                        id++;
                    }
                }
                else
                {
                    printf("\t\t\t    -\n");
                    printf("\tNo queda más espacio para cargar empleados\n");
                    printf("\t\t\t    -\n");
                }
                break;

            case 2:
                empty = fileEmpty(listOfEmployee, PAYROLL);
                if (empty == PAYROLL)
                {
                    printf("\t\t\t    -\n");
                    printf("Debe ingresar al menos un empleado para poder modificar\n");
                    printf("\t\t\t    -\n");
                }
                else
                {
                    printf("Indique el ID del empleado que quiere modificar: ");
                    scanf("%d", &idToChange);
                    modifyEmployee(listOfEmployee, PAYROLL, idToChange);
                }
                break;
            case 3:
                empty = fileEmpty(listOfEmployee, PAYROLL);
                if (empty == PAYROLL)
                {
                    printf("\t\t\t    -\n");
                    printf("Debe ingresar al menos un empleado para poder eliminar\n");
                    printf("\t\t\t    -\n");
                }
                else
                {
                    printf("Indique el ID del empleado que quiere eliminar: ");
                    scanf("%d", &idToChange);
                    removeEmployee(listOfEmployee, PAYROLL, idToChange);
                }
                break;
            case 4:
                empty = fileEmpty(listOfEmployee, PAYROLL);
                if (empty == PAYROLL)
                {
                    printf("\t\t\t    -\n");
                    printf("Debe ingresar al menos un empleado para poder ordenarlo\n");
                    printf("\t\t\t    -\n");
                }
                else
                {
                    sortEmployees(listOfEmployee, PAYROLL);
                }
                break;
            case 5:
                printf("Saliendo del Sistema...\n");
                break;
        }
    } while (option != 5);

    return 0;
}

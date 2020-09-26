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
#define JUNIOR 2

struct
{
 int id;
 int isEmpty;
 int sector;
 char aboveAvg;
 char lastName[51];
 char name[51];
 float salary;
}typedef Employee;

//Esta funcion será el menu principal que se mostrara para la resolucion del usuario
int mainMenu();
//inicia el atributo isEmpty en 1 indicando que ese espacio esta vacio
int initEmployees(Employee[], int);
//Aca pide los datos del empleado al elegir la opcion de darse de Altas
Employee addEmployee(int);
//verifica que hay espacio disponible en la nomina
int thereIsSpace(Employee[], int);
//Recorre el array de empleados
int arrayOfEmployees(Employee[], int, int);
//busca dentro del array el empleado a modificar por id
int modifyEmployee(Employee[], int, int);
//el nombre y apellido me lo coloca con las primeras letras en mayuscula
int firstLetterUp(char[], int);
//busca dentro del array el empleado a eliminar por id
int removeEmployee(Employee[], int, int);
//verifica que no haya ningun empleado en la nomina
int fileEmpty(Employee[], int);
// recorre el array y me devuelve el indice del vector
int findEmployeeById(Employee[], int, int);
//Ordena el array de empleados por apellido y sector de manera ascendente o descendente
int sortEmployees(Employee[], int);
//Imprime el array de empleados de forma encolumnada
int printEmployees(Employee[], int, float, float);
//para determinar total y promedio
float totalSalary(Employee[], int);
float avgSalary(Employee[], int);
// para determinar que este sobre el promedio
int aboveAvg(Employee[], int);

int main()
{
    setlocale(LC_ALL, "");

    int option;
    int idToChange;
    int id;
    int empty;
    int add;
    int space;
    Employee listOfEmployee[JUNIOR];

    id = 1;
    initEmployees(listOfEmployee, JUNIOR);
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
                space = thereIsSpace(listOfEmployee, JUNIOR);
                if (space == 1)
                {
                    add = arrayOfEmployees(listOfEmployee, JUNIOR, id);
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
                empty = fileEmpty(listOfEmployee, JUNIOR);
                if (empty == JUNIOR)
                {
                    printf("\t\t\t    -\n");
                    printf("Debe ingresar al menos un empleado para poder modificar\n");
                    printf("\t\t\t    -\n");
                }
                else
                {
                    printf("Indique el ID del empleado que quiere modificar: ");
                    scanf("%d", &idToChange);
                    modifyEmployee(listOfEmployee, JUNIOR, idToChange);
                }
                break;
            case 3:
                empty = fileEmpty(listOfEmployee, JUNIOR);
                if (empty == JUNIOR)
                {
                    printf("\t\t\t    -\n");
                    printf("Debe ingresar al menos un empleado para poder eliminar\n");
                    printf("\t\t\t    -\n");
                }
                else
                {
                    printf("Indique el ID del empleado que quiere eliminar: ");
                    scanf("%d", &idToChange);
                    removeEmployee(listOfEmployee, JUNIOR, idToChange);
                }
                break;
            case 4:
                empty = fileEmpty(listOfEmployee, JUNIOR);
                if (empty == JUNIOR)
                {
                    printf("\t\t\t    -\n");
                    printf("Debe ingresar al menos un empleado para poder ordenarlo\n");
                    printf("\t\t\t    -\n");
                }
                else
                {
                    sortEmployees(listOfEmployee, JUNIOR);
                }
                break;
            case 5:
                printf("Saliendo del Sistema...\n");
                break;
        }
    } while (option != 5);

    return 0;
}
//Esta funcion será el menu principal que se mostrara para la resolucion del usuario
int mainMenu()
{
    int option;

    printf("-----------------------------------------\n");
    printf("|           Nómina de Empleados         |\n");
    printf("-----------------------------------------\n");
    printf("1. Altas\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informar\n");
    printf("5. Salir\n");
    printf("Elija una opción: ");
    scanf("%d", &option);

    return option;
}

int initEmployees(Employee list[], int count)
{
    int i;

    for (i = 0; i  < count; i++)
    {
        list[i].isEmpty = 1;
        list[i].aboveAvg = ' ';
    }

    return 0;
}
//SI toda la nomina esta vacia entonces no me permitira modificar, eliminar u organizar
int fileEmpty(Employee list[], int count)
{
    int i;
    int countOfSpace;

    countOfSpace = 0;

    for (i = 0; i < count; i++)
    {
        if (list[i].isEmpty == 1)
        {
            countOfSpace++;
        }
    }

    return countOfSpace;
}
//verifica que haya espacio dentro del array
int thereIsSpace(Employee findSpace[], int count)
{
    int i;
    int space;

    space = 0;
    for (i = 0; i < count; i++)
    {
        if (findSpace[i].isEmpty == 1)
        {
            space = 1;
            break;
        }
    }
    return space;
}
int firstLetterUp(char data[], int length)
{
    int i;

    for(i = 0;i < length; i++)
    {
        data[i] = tolower(data[i]);
    }
    for(i = 0;i < length;i++)
    {
        if(i == 0)
        {
            data[i] = toupper(data[i]);
        }

        if(data[i] == ' ')
        {
            data[i + 1] = toupper(data[i + 1]);
        }

    }
    return 0;
}
Employee addEmployee(int id)
{
    Employee newEmployee;

    printf("Ingrese el nombre del empleado: ");
    fflush(stdin);
    gets(newEmployee.name);
    firstLetterUp(newEmployee.name, 51);
    printf("Ingrese el apellido del empleado: ");
    fflush(stdin);
    gets(newEmployee.lastName);
    firstLetterUp(newEmployee.lastName, 51);
    printf("Ingrese el número del sector donde trabaja este empleado: ");
    scanf("%d", &newEmployee.sector);
    while (newEmployee.sector < 0)
    {
        printf("Error, reingrese el número válido del sector donde trabaja este empleado: ");
        scanf("%d", &newEmployee.sector);
    }
    printf("Ingrese el salario del empleado, separando los decimales por coma(,): ");
    scanf("%f", &newEmployee.salary);
    while (newEmployee.salary < 0)
    {
        printf("Error, reingrese un salario válido para el empleado: ");
        scanf("%f", &newEmployee.salary);
    }
    newEmployee.isEmpty = 0;

    newEmployee.id = id;

    return newEmployee;
}
int arrayOfEmployees(Employee array[], int count, int id)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (array[i].isEmpty == 1)
        {
            array[i] = addEmployee(id);
            printf("\t\t\t   -\n");
            printf("\tCargado el nuevo empleado con éxito\n");
            printf("\t\t\t   -\n");
            break;
        }
    }

    return 0;
}
int modifyEmployee(Employee list[], int count, int id)
{
    int i;
    int newSector;
    int newSalary;
    int option;
    char toModify;
    char newLastName[30];
    char newName[20];

    toModify = 'n';

    i = findEmployeeById(list, count, id);
    if(i != -1)
    {

        printf("-------------------------------\n");
        printf("|      Datos del empleado     |\n");
        printf("-------------------------------\n");
        printf("ID: %d\n", list[i].id);
        printf("Nombre y apellido del empleado: %s %s\n", list[i].name, list[i].lastName);
        printf("Sector al que pertenece: %d\n", list[i].sector);
        printf("Salario: %.2f\n", list[i].salary);
        toModify = 's';
    }

    //si no encuentra ningun empleado
    if (toModify == 'n')
    {
        printf("-------------------------------\n");
        printf("|           Resultado         |\n");
        printf("-------------------------------\n");
        printf("No se ha encontrado ningún empleado con ese ID\n");
    }
    else
    {
        do
        {
            printf("-------------------------------\n");
            printf("|  Modificación de empleado   |\n");
            printf("-------------------------------\n");
            printf("1. Modificar nombre\n");
            printf("2. Modificar apellido\n");
            printf("3. Modificar sector de trabajo\n");
            printf("4. Modificar salario\n");
            printf("5. Regresar\n");
            printf("Ingrese su opción: ");
            scanf("%d", &option);
            switch (option)
            {
                case 1:
                    printf("Ingrese el nuevo nombre: ");
                    fflush(stdin);
                    gets(newName);
                    strcpy(list[i].name,newName);
                    firstLetterUp(list[i].name, 51);
                    printf("-------------------------------\n");
                    printf("|           Resultado         |\n");
                    printf("-------------------------------\n");
                    printf("Nombre modificado con éxito\n");
                    break;
                case 2:
                    printf("Ingrese el nuevo apellido: ");
                    fflush(stdin);
                    gets(newLastName);
                    strcpy(list[i].lastName,newLastName);
                    firstLetterUp(list[i].lastName, 51);
                    printf("-------------------------------\n");
                    printf("|           Resultado         |\n");
                    printf("-------------------------------\n");
                    printf("Apellido modificado con éxito\n");
                    break;
                case 3:
                    printf("Ingrese el nuevo sector del empleado: ");
                    scanf("%d", &newSector);
                    list[i].sector = newSector;
                    printf("-------------------------------\n");
                    printf("|           Resultado         |\n");
                    printf("-------------------------------\n");
                    printf("Sector modificado con éxito\n");
                    break;
                case 4:
                    printf("Ingrese el nuevo salario: ");
                    scanf("%d", &newSalary);
                    list[i].salary = newSalary;
                    printf("-------------------------------\n");
                    printf("|           Resultado         |\n");
                    printf("-------------------------------\n");
                    printf("Salario modificado con éxito\n");
                    break;
            }
        } while (option != 5);
    }

    return 0;
}
int removeEmployee(Employee list[], int count, int id)
{
    int i;
    char option;
    char someEmployee;

    someEmployee = 'n';


    for (i = 0; i < count; i++)
    {
        if(list[i].id == id && list[i].isEmpty != 1)
        {
            printf("-------------------------------\n");
            printf("|      Datos del empleado     |\n");
            printf("-------------------------------\n");
            printf("ID: %d\n", list[i].id);
            printf("Nombre y apellido del empleado: %s %s\n", list[i].name, list[i].lastName);
            printf("Sector al que pertenece: %d\n", list[i].sector);
            printf("Salario: %.2f\n", list[i].salary);
            someEmployee = 's';
            break;
        }
    }

    //si no encuentra ningun empleado
    if (someEmployee == 'n')
    {
        printf("No se ha encontrado ningún empleado con ese número de ID\n");
    }
    else
    {
        //confirmacion de querer eliminar al empleado
        printf("-------------------------------\n");
        printf("|   Eliminación de empleado   |\n");
        printf("-------------------------------\n");
        printf("¿Seguro de querer borrar los datos de este empleado, luego no podrá recuperarlo?\n");
        printf("Ingrese 'S' para si o 'N' para no: ");
        fflush(stdin);
        scanf("%c", &option);
        option = tolower(option);
        while (!(option == 's' || option == 'n'))
        {
            printf("Respuesta inválida, ingrese 'S' para si o 'N' para no: ");
            fflush(stdin);
            scanf("%c", &option);
            option = tolower(option);
        }
        //resolucion de eliminacion
        if (option == 's')
        {
            list[i].isEmpty = 1;
            printf("-------------------------------\n");
            printf("|           Resultado         |\n");
            printf("-------------------------------\n");
            printf("Empleado eliminado con éxito\n");
        }
    }
    return 0;
}

int findEmployeeById(Employee list[], int count, int id)
{
    int i;
    int vector;

    vector = -1;

    for (i = 0; i < count; i++)
    {
        if (list[i].id == id && list[i].isEmpty != 1)
        {
            vector  = i;
            break;
        }

    }
    return vector;
}

int sortEmployees(Employee list[], int count)
{
    int i;
    int j;
    int sumSalary;
    int sumAvgSalary;
    int option;
    Employee firstObject[count];

    printf("1. Ordenar por Apellido\n");
    printf("2. Ordenar por Sector\n");
    printf("3. Regresar\n");
    printf("Ingrese su opción: ");
    scanf("%d", &option);
    switch (option)
    {
        case 1:
                printf("1. De forma ascendente\n");
                printf("2. De forma descendente\n");
                printf("3. Regresar\n");
                printf("Ingrese su opción: ");
                scanf("%d", &option);
                switch (option)
                {
                    case 1:
                        //ordenar por apellido ascendente
                        for (i = 0; i < count; i++)
                        {
                            for (j = i + 1; j < count; j++)
                            {
                                if (strcmp(list[i].lastName, list[j].lastName) > 0)
                                {
                                    firstObject[i] = list[i];
                                    list[i] = list[j];
                                    list[j] = firstObject[i];
                                }
                            }
                        }
                        printf("-------------------------------\n");
                        printf("|           Resultado         |\n");
                        printf("-------------------------------\n");
                        printf("Ordenado con éxito\n");
                        break;
                    case 2:
                        //ordenar por apellido descendente
                        for (i = 0; i < count; i++)
                        {
                            for (j = i + 1; j < count; j++)
                            {
                                if (strcmp(list[i].lastName, list[j].lastName) < 0)
                                {
                                    firstObject[i] = list[i];
                                    list[i] = list[j];
                                    list[j] = firstObject[i];
                                }
                            }
                        }
                        printf("-------------------------------\n");
                        printf("|           Resultado         |\n");
                        printf("-------------------------------\n");
                        printf("Ordenado con éxito\n");
                        break;
                    default:
                        break;
                }
        break;
        case 2:
                printf("1. De menor a mayor\n");
                printf("2. De mayor a menor\n");
                printf("3. Regresar\n");
                printf("Ingrese su opción: ");
                scanf("%d", &option);
                switch (option)
                {
                    case 1:
                        //ordenar por sector ascendente
                        for (i = 0; i < count; i++)
                        {
                            for (j = i + 1; j < count; j++)
                            {
                                if (list[i].sector <= list[j].sector)
                                {
                                    firstObject[i] = list[i];
                                    list[i] = list[j];
                                    list[j] = firstObject[i];
                                }
                            }
                        }
                        printf("-------------------------------\n");
                        printf("|           Resultado         |\n");
                        printf("-------------------------------\n");
                        printf("Ordenado con éxito\n");
                        break;
                    case 2:
                        //ordenar por sector descendente
                        for (i = 0; i < count; i++)
                        {
                            for (j = i + 1; j > count; j++)
                            {
                                if (list[i].sector <= list[j].sector)
                                {
                                    firstObject[i] = list[i];
                                    list[i] = list[j];
                                    list[j] = firstObject[i];
                                }
                            }
                        }
                        printf("-------------------------------\n");
                        printf("|           Resultado         |\n");
                        printf("-------------------------------\n");
                        printf("Ordenado con éxito\n");
                        break;
                    default:
                        break;
                }
        break;
        default:
            break;
    }
    sumSalary = totalSalary(list, count);
    sumAvgSalary = avgSalary(list, count);
    aboveAvg(list, count);
    printEmployees(list, count, sumSalary, sumAvgSalary);
    return 0;
}
float totalSalary(Employee list[], int count)
{
    int i;
    float total;

    total = 0;

    for (i = 0; i < count; i++)
    {
        if (list[i].isEmpty != 1)
        {
            total += list[i].salary;
        }

    }
    return total;
}
float avgSalary(Employee list[], int count)
{
    int i;
    float total;

    total = 0;

    for (i = 0; i < count; i++)
    {
        if (list[i].isEmpty != 1)
        {
            total += list[i].salary;
        }

    }
    total = total / i;
    return total;
}
int aboveAvg(Employee list[], int count)
{
    int i;
    int avg;

    avg = avgSalary(list, count);

    for (i = 0; i < count; i++)
    {
        if (list[i].salary >= avg)
        {
            list[i].aboveAvg = 'X';
        }
    }
    return 0;
}
int printEmployees(Employee list[], int count, float totalSalary, float avgSalary)
{
    int i;
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("| ID | Nombre y Apellido | Sector |   Salario   | Promedio del Salario | Total de Salarios | Sobre el Promedio  |\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < count; i++)
    {
        if (list[i].isEmpty != 1)
        {
    printf("| %d    \t%s %s\t\t%d\t%.2f\t%.2f\t%.2f\t%c\t|\n", list[i].id, list[i].name, list[i].lastName, list[i].sector, list[i].salary, avgSalary, totalSalary, list[i].aboveAvg);
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

//Esta funcion ser� el menu principal que se mostrara para la resolucion del usuario
int mainMenu()
{
    int option;

    printf("-----------------------------------------\n");
    printf("|           N�mina de Empleados         |\n");
    printf("-----------------------------------------\n");
    printf("1. Altas\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informar\n");
    printf("5. Salir\n");
    printf("Elija una opci�n: ");
    scanf("%d", &option);

    return option;
}

int initEmployees(Employee list[], int count)
{
    int i;

    for (i = 0; i  < count; i++)
    {
        list[i].isEmpty = 1;
        list[i].aboveAvg = '.';
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
    printf("Ingrese el n�mero del sector donde trabaja este empleado: ");
    scanf("%d", &newEmployee.sector);
    while (newEmployee.sector < 0)
    {
        printf("Error, reingrese el n�mero v�lido del sector donde trabaja este empleado: ");
        scanf("%d", &newEmployee.sector);
    }
    printf("Ingrese el salario del empleado, separando los decimales por coma(,): ");
    scanf("%f", &newEmployee.salary);
    while (newEmployee.salary < 0)
    {
        printf("Error, reingrese un salario v�lido para el empleado: ");
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
            printf("\tCargado el nuevo empleado con �xito\n");
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
        printf("No se ha encontrado ning�n empleado con ese ID\n");
    }
    else
    {
        do
        {
            printf("-------------------------------\n");
            printf("|  Modificaci�n de empleado   |\n");
            printf("-------------------------------\n");
            printf("1. Modificar nombre\n");
            printf("2. Modificar apellido\n");
            printf("3. Modificar sector de trabajo\n");
            printf("4. Modificar salario\n");
            printf("5. Regresar\n");
            printf("Ingrese su opci�n: ");
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
                    printf("Nombre modificado con �xito\n");
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
                    printf("Apellido modificado con �xito\n");
                    break;
                case 3:
                    printf("Ingrese el nuevo sector del empleado: ");
                    scanf("%d", &newSector);
                    list[i].sector = newSector;
                    printf("-------------------------------\n");
                    printf("|           Resultado         |\n");
                    printf("-------------------------------\n");
                    printf("Sector modificado con �xito\n");
                    break;
                case 4:
                    printf("Ingrese el nuevo salario: ");
                    scanf("%d", &newSalary);
                    list[i].salary = newSalary;
                    printf("-------------------------------\n");
                    printf("|           Resultado         |\n");
                    printf("-------------------------------\n");
                    printf("Salario modificado con �xito\n");
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
            someEmployee = 's';
    }

    //si no encuentra ningun empleado
    if (someEmployee == 'n')
    {
        printf("-------------------------------\n");
        printf("|           Resultado         |\n");
        printf("-------------------------------\n");
        printf("No se ha encontrado ning�n empleado con ese n�mero de ID\n");
    }
    else
    {
        //confirmacion de querer eliminar al empleado
        printf("-------------------------------\n");
        printf("|   Eliminaci�n de empleado   |\n");
        printf("-------------------------------\n");
        printf("�Seguro de querer borrar los datos de este empleado, luego no podr� recuperarlo?\n");
        printf("Ingrese 'S' para si o 'N' para no: ");
        fflush(stdin);
        scanf("%c", &option);
        option = tolower(option);
        while (!(option == 's' || option == 'n'))
        {
            printf("Respuesta inv�lida, ingrese 'S' para si o 'N' para no: ");
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
            printf("Empleado eliminado con �xito\n");
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
    printf("Ingrese su opci�n: ");
    scanf("%d", &option);
    switch (option)
    {
        case 1:
                printf("1. De forma ascendente\n");
                printf("2. De forma descendente\n");
                printf("3. Regresar\n");
                printf("Ingrese su opci�n: ");
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
                        printf("Ordenado con �xito\n");
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
                        printf("Ordenado con �xito\n");
                        break;
                    default:
                        break;
                }
        break;
        case 2:
                printf("1. De menor a mayor\n");
                printf("2. De mayor a menor\n");
                printf("3. Regresar\n");
                printf("Ingrese su opci�n: ");
                scanf("%d", &option);
                switch (option)
                {
                    case 1:
                        //ordenar por sector ascendente
                        for (i = 0; i < count; i++)
                        {
                            for (j = i + 1; j < count; j++)
                            {
                                if (list[i].sector >= list[j].sector)
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
                        printf("Ordenado con �xito\n");
                        break;
                    case 2:
                        //ordenar por sector descendente
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
                        printf("Ordenado con �xito\n");
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
        else
        {
            list[i].aboveAvg = '.';
        }
    }
    return 0;
}
int printEmployees(Employee list[], int count, float totalSalary, float avgSalary)
{
    int i;
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("| ID |  Nombre y Apellido  | Sector |   Salario   | Sobre el Promedio  | Promedio del Salario | Total de Salarios |\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < count; i++)
    {
        if (list[i].isEmpty != 1 && i == 0)
        {
            printf("| %d \t%s %1s %7d \t%.2f %12c \t\t%15.2f %21.2f     |\n", list[i].id, list[i].name, list[i].lastName, list[i].sector, list[i].salary, list[i].aboveAvg, avgSalary, totalSalary);
        }
        else if(list[i].isEmpty != 1)
        {
            printf("| %d \t%s %1s %8d \t%.2f %12c          |\n", list[i].id, list[i].name, list[i].lastName, list[i].sector, list[i].salary, list[i].aboveAvg);
        }
    }

    return 0;
}

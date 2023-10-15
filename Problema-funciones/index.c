//Presentado por: Juan David García Arce

#include <stdio.h>
//Para strings
#include <string.h>
//Para time
#include <time.h>

//funcion para imprimir el menu
void imprimirMenu() {
    printf("1. Agregar empleado\n");
    printf("2. Eliminar empleado\n");
    printf("3. Buscar empleado\n");
    printf("4. Listar empleados\n");
    printf("5. Ajustar salario base de un puesto\n");
    printf("6. Definir fecha actual\n");
    printf("7. Salir\n");
    printf("Ingrese una opcion: ");
}

//funcion para agregar un empleado
void agregarEmpleado(char empleados[100][20]) {
    //Se pide el nombre del empleado
    char nombre[20];
    printf("Ingrese el nombre del empleado: ");
    scanf("%s", nombre);

    //Se busca un espacio vacio
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(empleados[i], "") == 0) {
            strcpy(empleados[i], nombre);
            break;
        }
    }
}

//funcion para eliminar un empleado
void eliminarEmpleado(char empleados[100][20]) {
    //Se pide el nombre del empleado
    char nombre[20];
    printf("Ingrese el nombre del empleado: ");
    scanf("%s", nombre);

    //Se busca el empleado
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(empleados[i], nombre) == 0) {
            strcpy(empleados[i], "");
            break;
        }
    }
}

//funcion para buscar un empleado
void buscarEmpleado(char empleados[100][20]) {
    //Se pide el nombre del empleado
    char nombre[20];
    printf("Ingrese el nombre del empleado: ");
    scanf("%s", nombre);

    //Se busca el empleado
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(empleados[i], nombre) == 0) {
            printf("El empleado %s se encuentra en la posicion %d\n", nombre, i);
            break;
        }
    }
}

//El programa, antes de iniciar debe preguntar al usuario por la fecha actual (el formato debe ser consistente e indicado), para luego utilizar este valor para calcular el aumento del salario del resto de empleados, más de 1 año, 2%, más de 5 años 5% y más de 10 años, 10%.
//funciòn para ajustar el salario base de un puesto dado su nombre y tiempo
void ajustarSalario(char empleados[100][20]) {
    //Se pide el nombre del empleado
    char nombre[20];
    printf("Ingrese el nombre del empleado: ");
    scanf("%s", nombre);

    //Se busca el empleado
    int i, existe = 0;
    for (i = 0; i < 100; i++) {
        if (strcmp(empleados[i], nombre) == 0) {
            existe = 1;
            break;
        }
    }

    if (existe == 1) {
        //Se pide el tiempo
        int tiempo;
        printf("Ingrese el tiempo en años: ");
        scanf("%d", &tiempo);

        //Se calcula el aumento
        float aumento = 0;
        if (tiempo > 10) {
            aumento = 0.1;
        } else if (tiempo > 5) {
            aumento = 0.05;
        } else if (tiempo > 1) {
            aumento = 0.02;
        }

        //Se imprime el aumento
        printf("El aumento es de %.2f\n", aumento);
    } else {
        printf("El empleado %s no existe\n", nombre);
    }

}


int main() {

    //Se define un vector con 10 empleados
    char empleados[100][20] = {"Juan", "Pedro", "Luis", "Maria", "Ana", "Jose", "Carlos", "Andres", "Sofia", "Camila"};


    //Se imprime el menu

    int opcion = 0;

    do {
        imprimirMenu();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Agregar empleado\n");
                agregarEmpleado(empleados);

                break;
            case 2:
                printf("Eliminar empleado\n");
                eliminarEmpleado(empleados);

                break;
            case 3:
                printf("Buscar empleado\n");
                buscarEmpleado(empleados);
                break;
            case 4:
                printf("Listar empleados\n");
                int i;

                //Se imprime la lista de empleados con nùmeraciòn en el orden que se imprime
                int j = 0;
                for (i = 0; i < 100; i++) {
                    if (strcmp(empleados[i], "") != 0) {
                        j++;
                        printf("%d. %s\n", j, empleados[i]);
                    }
                }
                break;
            case 5:
                printf("Ajustar salario base de un puesto\n");
                ajustarSalario(empleados);

                break;
            case 6:
                printf("Definir fecha actual\n");
                //Muestra la fecha actual
                printf("La fecha actual es: %s\n", __DATE__);
                break;
            case 7:
                printf("Salir\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    } while (opcion != 7);


    return 0;
}
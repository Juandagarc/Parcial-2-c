//Presentado por: Juan David García Arce

#include <stdio.h>
//Se definen colores
#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

int main () {

    //Se crea una matriz de 6x7 con 1, 2, 3...
    char matriz[6][7];
    int i, j;
    int ganador = 0;

    //Se llena de espacios
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 7; j++) {
            matriz[i][j] = ' ';
        }
    }

    int turno = 1;

    do {
    //Se imprime la matriz
    printf("\t\t1\t\t2\t\t3\t\t4\t\t5\t\t6\t\t7\n");
    printf("\n\t┌───────────────┬───────────────┬───────────────┬───────────────┬───────────────┬───────────────┬───────────────┐\n");
    for (i = 0; i < 6; i++) {
        printf("%d", i+1);
        for (j = 0; j < 7; j++) {
            if (matriz[i][j] == 'X') {
                printf("\t│\t%s%c%s ", RED, matriz[i][j], RESET);
            } else if (matriz[i][j] == 'O') {
                printf("\t│\t%s%c%s ", YELLOW, matriz[i][j], RESET);
            } else {
                printf("\t│\t%c ", matriz[i][j]);
            }
        }
        printf("\t│\n\t├───────────────┼───────────────┼───────────────┼───────────────┼───────────────┼───────────────┼───────────────┤\n");
    }
    printf("\t▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n");
    if (turno == 1) {
        printf("Turno del jugador 1\n");
        turno = 2;
    } else {
        printf("Turno del jugador 2\n");
        turno = 1;
    }
    printf("Ingrese la columna donde quiere poner la ficha: ");
    scanf("%d", &j);
    j--;
    for (i = 5; i >= 0; i--) {
        if (matriz[i][j] == ' ') {
            if (turno == 1) {
                matriz[i][j] = 'X';
            } else {
                matriz[i][j] = 'O';
            }
            break;
        }
    }
    //Se verifica si hay un ganador
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 7; j++) {
            if (matriz[i][j] != ' ') {
                //Se verifica si hay un ganador horizontal
                if (j < 4) {
                    if (matriz[i][j] == matriz[i][j+1] && matriz[i][j] == matriz[i][j+2] && matriz[i][j] == matriz[i][j+3]) {
                        ganador = 1;
                    }
                }
                //Se verifica si hay un ganador vertical
                if (i < 3) {
                    if (matriz[i][j] == matriz[i+1][j] && matriz[i][j] == matriz[i+2][j] && matriz[i][j] == matriz[i+3][j]) {
                        ganador = 1;
                    }
                }
                //Se verifica si hay un ganador diagonal
                if (i < 3 && j < 4) {
                    if (matriz[i][j] == matriz[i+1][j+1] && matriz[i][j] == matriz[i+2][j+2] && matriz[i][j] == matriz[i+3][j+3]) {
                        ganador = 1;
                    }
                }
                if (i < 3 && j > 2) {
                    if (matriz[i][j] == matriz[i+1][j-1] && matriz[i][j] == matriz[i+2][j-2] && matriz[i][j] == matriz[i+3][j-3]) {
                        ganador = 1;
                    }
                }
            }
        }
    }
    //Se piden los datos
    } while (ganador == 0);

    //Se imprime la matriz
    printf("\t\t1\t\t2\t\t3\t\t4\t\t5\t\t6\t\t7\n");
    printf("\n\t┌───────────────┬───────────────┬───────────────┬───────────────┬───────────────┬───────────────┬───────────────┐\n");
    for (i = 0; i < 6; i++) {
        printf("%d", i+1);
        for (j = 0; j < 7; j++) {
            if (matriz[i][j] == 'X') {
                printf("\t│\t%s%c%s ", RED, matriz[i][j], RESET);
            } else if (matriz[i][j] == 'O') {
                printf("\t│\t%s%c%s ", YELLOW, matriz[i][j], RESET);
            } else {
                printf("\t│\t%c ", matriz[i][j]);
            }
        }
        printf("\t│\n\t├───────────────┼───────────────┼───────────────┼───────────────┼───────────────┼───────────────┼───────────────┤\n");
    }
    printf("\t▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n");
    if (turno == 1) {
        printf("Ganó el jugador 2\n");
    } else {
        printf("Ganó el jugador 1\n");
    }

    return 0;
}
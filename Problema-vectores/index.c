//Presentado por Juan David García Arce

#include <stdio.h>
//para random
#include <stdlib.h>
#include <time.h>
//Se definen colores
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */


//Juego blackjack
int main () {

    srand(time(NULL));
    int i, j;
    int a = 0, b = 0, c = 0, d = 0;
    //Se definen las cartas
    int cartasC[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int cartasD[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int cartasT[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int cartasP[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

    //Se revuelve el mazo

    //Para C
    for (i = 0; i < 13; i++) {
        int temp = cartasC[i];
        int randomIndex = rand() % 13;
        cartasC[i] = cartasC[randomIndex];
        cartasC[randomIndex] = temp;
    }

    //Para D
    for (i = 0; i < 13; i++) {
        int temp = cartasD[i];
        int randomIndex = rand() % 13;
        cartasD[i] = cartasD[randomIndex];
        cartasD[randomIndex] = temp;
    }

    //Para T
    for (i = 0; i < 13; i++) {
        int temp = cartasT[i];
        int randomIndex = rand() % 13;
        cartasT[i] = cartasT[randomIndex];
        cartasT[randomIndex] = temp;
    }

    //Para P
    for (i = 0; i < 13; i++) {
        int temp = cartasP[i];
        int randomIndex = rand() % 13;
        cartasP[i] = cartasP[randomIndex];
        cartasP[randomIndex] = temp;
    }

    //Se define el inventario del jugador
    int inventario[13] = {0};
    char inventarioConPalos[13] = {'\0'};
    //Se define el inventario de la maquina 1:
    int inventarioM1[13] = {0};
    char inventarioM1ConPalos[13] = {'\0'};
    //Se define el inventario de la maquina 2:
    int inventarioM2[13] = {0};
    char inventarioM2ConPalos[13] = {'\0'};

    //El jugador (usuario) y las dos máquinas (jugadores automáticos) deben recibir dos cartas cada uno al inicio del juego.
    //Se reparten las cartas
        //Se definen las primeras dos cartas para el jugador
        i = 0;
        for (j = 0; j <= 2; j++)
        {
            int palo = rand() % 4 + 1;
            //Se define la carta
            switch (palo)
            {
                case 1:
                    inventario[i] = cartasC[a];
                    inventarioConPalos[i] = 'C';
                    a++;
                    break;
                case 2:
                    inventario[i] = cartasD[b];
                    inventarioConPalos[i] = 'D';
                    b++;
                    break;
                case 3:
                    inventario[i] = cartasT[c];
                    inventarioConPalos[i] = 'T';
                    c++;
                    break;
                case 4:
                    inventario[i] = cartasP[d];
                    inventarioConPalos[i] = 'P';
                    d++;
                    break;
            }
            j++;
            i++;
        }

        //Se definen las primeras dos cartas para la máquina 1
        i = 0;
        for (j = 0; j <= 2; j++)
        {
            int palo = rand() % 4 + 1;
            //Se define la carta
            switch (palo)
            {
                case 1:
                    inventarioM1[i] = cartasC[a];
                    inventarioM1ConPalos[i] = 'C';
                    a++;
                    break;
                case 2:
                    inventarioM1[i] = cartasD[b];
                    inventarioM1ConPalos[i] = 'D';
                    b++;
                    break;
                case 3:
                    inventarioM1[i] = cartasT[c];
                    inventarioM1ConPalos[i] = 'T';
                    c++;
                    break;
                case 4:
                    inventarioM1[i] = cartasP[d];
                    inventarioM1ConPalos[i] = 'P';
                    d++;
                    break;
            }
            j++;
            i++;
        }

        //Se definen las primeras dos cartas para la máquina 2
        i = 0;
        for (j = 0; j <= 2; j++)
        {
            int palo = rand() % 4 +1;
            //Se define la carta
            switch (palo)
            {
                case 1:
                    inventarioM2[i] = cartasC[a];
                    inventarioM2ConPalos[i] = 'C';
                    a++;
                    break;
                case 2:
                    inventarioM2[i] = cartasD[b];
                    inventarioM2ConPalos[i] = 'D';
                    b++;
                    break;
                case 3:
                    inventarioM2[i] = cartasT[c];
                    inventarioM2ConPalos[i] = 'T';
                    c++;
                    break;
                case 4:
                    inventarioM2[i] = cartasP[d];
                    inventarioM2ConPalos[i] = 'P';
                    d++;
                    break;
            }
            j++;
            i++;
        }

    //Se imprimen las cartas del jugador
    printf(RED"Cartas jugador: \n"RESET);
    for (i = 0; i < 13; i++) {
        //Se muestran hasta que se encuentre un 0
        if (inventario[i] != 0)
        {
            printf(RED"%d%c\t"RESET, inventario[i], inventarioConPalos[i]);
        }
    }
    //Muestra el puntaje
    printf(RED"\nPuntaje: %d\n"RESET, inventario[0] + inventario[1]);

    printf("\n");
    //Se muestran las de la maquina
    printf(GREEN"Cartas maquina 1: \n"RESET);
    for (i = 0; i < 13; i++) {
        //Se muestran hasta que se encuentre un 0
        if (inventarioM1[i] != 0)
        {
            printf(GREEN"%d%c\t"RESET, inventarioM1[i], inventarioM1ConPalos[i]);
        }
    }
    //Se muestra el puntaje
    printf(GREEN"\nPuntaje: %d\n"RESET, inventarioM1[0] + inventarioM1[1]);
    printf("\n");

    //Se muestran las de la maquina
    printf(YELLOW"Cartas maquina 2: \n"RESET);
    for (i = 0; i < 13; i++) {
        //Se muestran hasta que se encuentre un 0
        if (inventarioM2[i] != 0)
        {
            printf(YELLOW"%d%c\t"RESET, inventarioM2[i], inventarioM2ConPalos[i]);
        }
    }
    //Se muestra el puntaje
    printf(YELLOW"\nPuntaje: %d\n"RESET, inventarioM2[0] + inventarioM2[1]);
    printf("\n");

    int puntajeJugador = inventario[0] + inventario[1];
    int puntajeM1 = inventarioM1[0] + inventarioM1[1];
    int puntajeM2 = inventarioM2[0] + inventarioM2[1];

    //Se hace un ciclo en donde se le pregunta al usuario si desea otra carta, el vetor se empieza a llenar con ciclos desde la posición 2
    //Si el jugador decide no pedir más cartas, se pasa a la máquina 1 la cual tomara la desicion aleatoriamente, si la máquina 1 decide no pedir más cartas, se pasa a la máquina 2 la cual tomara la desicion aleatoriamente
    
    //Se define la variable que indica si el jugador desea otra carta
    int otraCarta = 1;

    //Se define la variable que indica si la máquina 1 desea otra carta
    int otraCartaM1 = 1;

    //Se define la variable que indica si la máquina 2 desea otra carta
    int otraCartaM2 = 1;

    int i1 = 2, i2 = 2, i3 = 2;


    while(puntajeJugador <= 21){
            
            //Se le pregunta al jugador si desea otra carta
            printf("Desea otra carta? (1 = si, 0 = no): ");
            scanf("%d", &otraCarta);
    
            //Si el jugador desea otra carta
            if (otraCarta == 1)
            {
                //Se define la carta
                int palo = rand() % 4 + 1;
                //Se define la carta
                switch (palo)
                {
                    case 1:
                        inventario[i1] = cartasC[a];
                        inventarioConPalos[i1] = 'C';
                        a++;
                        break;
                    case 2:
                        inventario[i1] = cartasD[b];
                        inventarioConPalos[i1] = 'D';
                        b++;
                        break;
                    case 3:
                        inventario[i1] = cartasT[c];
                        inventarioConPalos[i1] = 'T';
                        c++;
                        break;
                    case 4:
                        inventario[i1] = cartasP[d];
                        inventarioConPalos[i1] = 'P';
                        d++;
                        break;
                }
                i1++;
                //Se muestra la carta
                printf(RED"Cartas jugador: \n"RESET);
                for (i = 0; i < 13; i++) {
                    //Se muestran hasta que se encuentre un 0
                    if (inventario[i] != 0)
                    {
                        printf(RED"%d%c\t"RESET, inventario[i], inventarioConPalos[i]);
                    }
                }
                //Muestra el puntantaje sumando todo el vector
                puntajeJugador = 0;
                for (i = 0; i < 13; i++) {
                    puntajeJugador += inventario[i];
                }
                printf(RED"\nPuntaje: %d\n"RESET, puntajeJugador);
                printf("\n");
            }
            else
            {
                break;
            }

            //Se le pregunta a la máquina 1 si desea otra carta
            otraCartaM1 = rand() % 2;
            //Si la máquina 1 desea otra carta
            if (otraCartaM1 == 1)
            {
                //Se define la carta
                int palo = rand() % 4 + 1;
                //Se define la carta
                switch (palo)
                {
                    case 1:
                        inventarioM1[i2] = cartasC[a];
                        inventarioM1ConPalos[i2] = 'C';
                        a++;
                        break;
                    case 2:
                        inventarioM1[i2] = cartasD[b];
                        inventarioM1ConPalos[i2] = 'D';
                        b++;
                        break;
                    case 3:
                        inventarioM1[i2] = cartasT[c];
                        inventarioM1ConPalos[i2] = 'T';
                        c++;
                        break;
                    case 4:
                        inventarioM1[i2] = cartasP[d];
                        inventarioM1ConPalos[i2] = 'P';
                        d++;
                        break;
                }
                i2++;
                //Se muestra la carta
                printf(GREEN"Cartas maquina 1: \n"RESET);
                for (i = 0; i < 13; i++) {
                    //Se muestran hasta que se encuentre un 0
                    if (inventarioM1[i] != 0)
                    {
                        printf(GREEN"%d%c\t"RESET, inventarioM1[i], inventarioM1ConPalos[i]);
                    }
                }
                //Muestra el puntantaje sumando todo el vector
                puntajeM1 = 0;
                for (i = 0; i < 13; i++) {
                    puntajeM1 += inventarioM1[i];
                }
                printf(GREEN"\nPuntaje: %d\n"RESET, puntajeM1);

                //Se le pregunta a la máquina 2 si desea otra carta
                otraCartaM2 = rand() % 2;
                //Si la máquina 2 desea otra carta
                if (otraCartaM2 == 1)
                {
                    //Se define la carta
                    int palo = rand() % 4 + 1;
                    //Se define la carta
                    switch (palo)
                    {
                        case 1:
                            inventarioM2[i3] = cartasC[a];
                            inventarioM2ConPalos[i3] = 'C';
                            a++;
                            break;
                        case 2:
                            inventarioM2[i3] = cartasD[b];
                            inventarioM2ConPalos[i3] = 'D';
                            b++;
                            break;
                        case 3:
                            inventarioM2[i3] = cartasT[c];
                            inventarioM2ConPalos[i3] = 'T';
                            c++;
                            break;
                        case 4:
                            inventarioM2[i3] = cartasP[d];
                            inventarioM2ConPalos[i3] = 'P';
                            d++;
                            break;
                    }
                    i3++;
                    //Se muestra la carta
                    printf(YELLOW"Cartas maquina 2: \n"RESET);
                    for (i = 0; i < 13; i++) {
                        //Se muestran hasta que se encuentre un 0
                        if (inventarioM2[i] != 0)
                        {
                            printf(YELLOW"%d%c\t"RESET, inventarioM2[i], inventarioM2ConPalos[i]);
                        }
                    }
                    printf("\n");
                    //Muestra el puntantaje sumando todo el vector
                    puntajeM2 = 0;
                    for (i = 0; i < 13; i++) {
                        puntajeM2 += inventarioM2[i];
                    }
                    printf(YELLOW"\nPuntaje: %d\n"RESET, puntajeM2);
                }
                else
                {
                    break;
                }
    }
    }
    //Se establece el ganador buscando el mayor
    int ganador = 0;

    if ( puntajeJugador <= 21 )
    {
        ganador = 1;
    }
    else if ( puntajeM1 <= 21 )
    {
        ganador = 2;
    }
    else if ( puntajeM2 <= 21 )
    {
        ganador = 3;
    }

    //Para el jugador
    if (puntajeJugador > puntajeM1 && puntajeJugador > puntajeM2 && puntajeJugador <= 21)
    {
        ganador = 1;
    }
    //Para la máquina 1
    else if (puntajeM1 > puntajeJugador && puntajeM1 > puntajeM2 && puntajeM1 <= 21)
    {
        ganador = 2;
    }
    //Para la máquina 2
    else if (puntajeM2 > puntajeJugador && puntajeM2 > puntajeM1 && puntajeM2 <= 21)
    {
        ganador = 3;
    }



    //Se muestra el ganador
    switch (ganador)
    {
        case 1:
            printf("El ganador es el jugador\n");
            break;
        case 2:
            printf("El ganador es la maquina 1\n");
            break;
        case 3:
            printf("El ganador es la maquina 2\n");
            break;
        default:
            printf("No hay ganador\n");
            break;
    }


    return 0;
}
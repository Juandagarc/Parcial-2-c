//Presentado por: Juan David García Arce

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Este programa recibe un texto y busca cuantas veces esta ubna palabra en el texto
    char texto[10000];
    char palabra[100];
    int i = 0, j = 0, k = 0, contador = 0;
    printf("Ingrese el texto: ");
    gets(texto);
    printf("Ingrese la palabra a buscar: ");
    gets(palabra);
    while (texto[i] != '\0')
    {
        if (texto[i] == palabra[j])
        {
            j++;
            if (palabra[j] == '\0')
            {
                contador++;
                j = 0;
            }
        }
        else
        {
            j = 0;
        }
        i++;
    }
    printf("La palabra %s se repite %d veces", palabra, contador);

    return 0;
}
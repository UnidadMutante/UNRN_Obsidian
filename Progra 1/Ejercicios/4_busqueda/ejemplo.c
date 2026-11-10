#include <stdio.h>
#include <string.h>

int main(void)
{
    char oracion[] =
        "la programacion en lenguaje c permite resolver problemas de forma eficiente";
    char palabraBuscada[50];
    printf("Ingrese una palabra para buscar: ");
    scanf("%49s", palabraBuscada);

  // strtok() Divide la oración en palabras usando el espacio " " como separador.
    
    char copia[200];
    strcpy(copia, oracion);

    char *palabra = strtok(copia, " ");

    int posicion = 1;
    int encontrada = 0;

    while (palabra != NULL)
    {
// strcmp()  Compara dos cadenas. Devuelve 0 si son iguales.
        if (strcmp(palabra, palabraBuscada) == 0)
        {
            encontrada = 1;

            printf(
                "La palabra \"%s\" fue encontrada en la posicion %d de la oracion.\n",
                palabraBuscada,
                posicion
            );

            break;
        }

        posicion++;

        palabra = strtok(NULL, " ");
    }

    if (!encontrada)
    {
        printf(
            "La palabra \"%s\" no se encuentra en la oracion secreta.\n",
            palabraBuscada
        );
    }

    return 0;
}
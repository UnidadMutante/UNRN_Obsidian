 #include <stdio.h>
#include <stddef.h>

size_t contar_caracter(const char cadena[], char caracter_buscado);

int main(void)
{
    char palabra[100];
    char caracter_buscado;

    printf("Ingrese una palabra: ");

    /*
        %99s evita escribir más de 99 caracteres.
        No usamos & porque palabra ya representa la dirección
        del primer elemento del arreglo.
    */
    scanf("%99s", palabra);

    printf("Ingrese el carácter que quiere contar: ");

    /*
        El espacio antes de %c descarta el Enter anterior.
        Usamos & porque scanf necesita la dirección de la variable.
    */
    scanf(" %c", &caracter_buscado);

    size_t ocurrencias =
        contar_caracter(palabra, caracter_buscado);

    printf(
        "En la palabra \"%s\", el carácter '%c' aparece %zu veces.\n",
        palabra,
        caracter_buscado,
        ocurrencias
    );

    return 0;
}

size_t contar_caracter(
    const char cadena[],
    char caracter_buscado
)
{
    size_t contador = 0;

    for (size_t i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == caracter_buscado) {
            contador++;
        }
    }

    return contador;
}
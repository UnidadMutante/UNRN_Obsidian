#include <stdio.h>
#include <string.h>

int main(void)
{
    char oracion[100];
    char palabra[30];
    printf("Ingrese una oracion: ");

    //fgets(destino, cantidad_maxima, origen);
    fgets(oracion, sizeof(oracion), stdin);

    printf("Ingrese la palabra a buscar: ");

    /*
     * scanf Lee una palabra hasta encontrar:
     * - un espacio
     * - un Enter
     * - un tab
     */
    scanf("%s", palabra);

    /*
     * strstr(texto, subtexto)
     * 1) texto
     *    Cadena donde se realizará la búsqueda.
     *    En este caso: oracion

     * 2) subtexto
     *    Cadena que se quiere encontrar.
     *    En este caso: palabra
     *
     * Devuelve:
     * - Un puntero a la primera aparición encontrada.
     * - NULL si no la encuentra.
     */
    if (strstr(oracion, palabra) != NULL)
    {
        printf("La palabra \"%s\" fue encontrada.\n", palabra);
    }
    else
    {
        printf("La palabra \"%s\" NO fue encontrada.\n", palabra);
    }

    return 0;
}
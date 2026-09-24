#include <stdio.h>

//Implementar un menú de Opciones con switch-case. 
//Definir la lista de opciones que quieran.

int main (void) {

    int opcion;

    printf("Elegi una opcion:\n* 1 -> Vender tu casa\n* 2 -> Vender tu auto\n* 3 -> Vender un riñón\n* 4 -> Todas las anteriores\n");

    scanf(" %d", &opcion);

    switch (opcion) {
        case 1:
        printf("elegiste la opcion %d. Excelente idea. Suerte con tu inquilino.\n", opcion);
        break;

        case 2: 
        printf("Elegiste la opcion %d. Que conservador, pagas tus deudas y que mas?\n", opcion);
        break;

        case 3:
        printf("Elegiste la opcion %d. Jugado, pero valiente.\n", opcion);
        break;

        case 4:
        printf("Elegiste la opcion %d. No esperaba menos, todo sea por la familia.\n");
        break;

        default:
        printf("No elegiste ninguna opcion válida. No seas salame.\n");
        break;
    }


    return 0;
}
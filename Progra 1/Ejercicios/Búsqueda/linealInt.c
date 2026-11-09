#include <stdio.h>
#include <stdbool.h>

int buscarLineal(int vec[], int tam, int buscado);

int main(void) {

    int vec[] = {12, 8, 45, 23, 56, 7, 34};
    int tam = sizeof(vec) / sizeof(vec[0]);

    int buscado;

    printf("Ingrese el numero a buscar: ");
    scanf("%d", &buscado);

    int posicion = buscarLineal(vec, tam, buscado);

    if (posicion != -1) {
        printf("Encontrado en la posicion %d\n", posicion);
    } else {
        printf("No encontrado\n");
    }

    return 0;
}

int buscarLineal(int vec[], int tam, int buscado) {

    for (int i = 0; i < tam; i++) {

        if (vec[i] == buscado) {
            return i;
        }
    }

    return -1;
}
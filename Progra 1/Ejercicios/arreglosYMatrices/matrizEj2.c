#include <stdio.h>
#define COLUMNA 3
#define FILA 3

int main (void) {

int matriz [3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int matriz2 [3][3];
int entero;
//int multiplicacion;

printf("ay dios mio");
scanf("%d", &entero);

for (int i = 0; i < COLUMNA; i++) {
    for (int j = 0; j < FILA; j++) {
        matriz2[i][j] = matriz[i][j] * entero;
        printf("%4d, ", matriz2[i][j]);
    }
    printf("\n");
}
    return 0;
}
#include <stdio.h>
#define COLUMNA 2
#define FILA 2

int main (void) {

int matriz1[2][2] = {
    {1, 2},
    {3, 4}
};
int matriz2[2][2] = {
    {5, 6},
    {7, 8}
};
int matriz3[2][2];


int suma = 0;

for (int i = 0; i < COLUMNA; i++) {
    for (int j = 0; j < FILA; j++)
    {
        matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
        suma = suma +1;
        printf("%4d, ", matriz3[i][j]);
    }
    printf("\n");
}
return 0;
}
#include <stdio.h>
#define COLUMNA 2
#define FILA 2

/*
En C[00] = A00x B00 + A01 X B10  | En C[01] = A00x B01 + A01 X B11 
En C[10] = A10x B00 + A11 X B10  | En C[11] = A10x B01 + A11 X B11 
*/

int main (void) {

    int matriz1[FILA][COLUMNA] = {{1, 2},{3, 4}};
    int matriz2[FILA][COLUMNA] = {{5, 6},{7, 8}};
    int matriz3[FILA][COLUMNA];

for (int i = 0; i < FILA; i++) {
    for (int j = 0; j < COLUMNA; j++) {
        matriz3[i][j] = matriz1[i][j] * matriz2[i][j];
        printf("%4d, \n", matriz1[i][j]);
        printf("*\n");
        printf("%4d, \n", matriz2[i][j]);
        printf("-----------------------\n");
        printf("%4d, \n", matriz3[i][j]);        
    }
    printf("\n");
}
    return 0;


}
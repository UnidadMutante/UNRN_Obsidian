#include <stdio.h>

int main () {

int numeros[3][3];

int suma = 0;

for (int i = 0; i < 3; i++) {
    for (int j = 0; j <3; j++)
    {
        numeros[i][j] = suma; 
        suma = suma +1;
        printf("%d ", numeros[i][j]);
    }
    printf("\n");
}

}
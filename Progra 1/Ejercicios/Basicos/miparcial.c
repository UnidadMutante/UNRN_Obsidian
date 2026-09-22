#include <stdio.h>

int validador_fibonacci(int f) {
    int f1 = 0;
    int f2 = 1; 
    int f3 = 2; 
    int pertenece = -1; 
    int found = 0;

    while (found == 0) {
        if (f <= f2) {
            found = 1; 
            if (f == f2) {
                pertenece = 1;
            }
            else if (f == f1) {
                pertenece = 1;
            }
         else {
            pertenece = 0;
            }
        } else {
            f1 = f2 + f3;
            f2 = f1 + f3; 
            f3 = f2 + f1;
        }
    }
    return pertenece;
} 

int main(void) {

int prueba = -1;
int prueba2 = -1;

prueba2 = validador_fibonacci(13);
prueba = validador_fibonacci(8);


printf("%d\n", prueba);
printf("%d\n", prueba2);
}
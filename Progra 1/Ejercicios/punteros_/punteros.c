#include <stdio.h>

/*
pre: a y b son enteros cualesquiera a=a0 y b=b0
postcondicion: a y b tal que a=b0 y b= a0
*/

void intercambio(char *a, char *b);

int main(void)
{
char a = 'x';
char b = 'y';

printf("a: %c\n", a);
printf("b: %c\n", b);

intercambio(&a, &b);

return 0;
}

void intercambio(char *a, char *b) {
    char temp;

    printf("pa: %p\n", a);
    printf("pb: %p\n", b);

    temp = *a; 
    *a = *b;
    *b = temp;

    printf("a: %c\n", *a);
    printf("b: %c\n", *b);

}

// void test(int a, int b){
//     if (a == 'x' || b == 'y') {
//     printf("fallo el swap");
// } else if (a == 'y' || b == 'x') {
//     printf("OK");
// }


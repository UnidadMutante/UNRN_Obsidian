#include <stdio.h>

char a = 'x';
char b = 'y';
char c;
/*
pre: a y b son enteros cualesquiera a=a0 y b=b0
postcondicion: a y b tal que a=b0 y b= a0
*/
void intercambio(void);
void test(void);

int main(void)
{

// char *pa;
// char *pb;
// pa = &b;
// pb = &a;

printf("a: %c\n", a);
printf("b: %c\n", b);

intercambio();

printf("a: %c\n", a);
printf("b: %c\n", b);
//printf("intercambio: %d\n", aa);

test();

return 0;
}

void intercambio() {
c = a; 
a = b;
b = c;
}

void test(void){
    if (a == 'x' || b == 'y') {
    printf("fallo el swap");
} else if (a == 'y' || b == 'x') {
    printf("OK");
}

}
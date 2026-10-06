#include <stdio.h>

void swap(char *a, char *b);

int main (void) {

    char a = 'x';
    char b = 'y'; 

    printf("a: %c\n",a); 
    printf("b: %c\n",b); 

    printf("intercambio:\n",a); 
    swap(&a, &b);
    
    printf("a: %c\n",a); 
    printf("b: %c\n",b);

    return 0;
}
void swap(char *a, char *b) {
    char temp; 
    temp=*a; 
    *a=*b; 
    *b=temp;
}
#include <stdio.h>

int incremento(int valor)
{
    valor = valor + 1;
    return valor;
}

int main(void)
{
    int variable = 10;
    variable = incremento(variable);
    printf("variable: %d\n", variable);
    return 0;
}

#include <stdio.h>

float saldo = 0;

void print_menu(void) {
    printf("SELECCIONE UNA OPCION:\n");
    printf("c -> para consultar. \n");
    printf("d -> para depositar. \n");
    printf("r -> para retirar. \n");
    printf("s -> para salir. \n");
}

void consultar_saldo();
void depositar_dinero();
void retirar_dinero();


int main(void) {
    char opcion;

    do {
    print_menu();
    scanf(" %c" , &opcion);
    printf("Se ingreso la opción: %c\n" ,opcion);

    switch (opcion)
    {
    case 'c':
    case 'C':
        consultar_saldo();
        break;
    
    case 'd':
    case 'D':
        depositar_dinero();
        break;

    case 'r':
    case 'R':
        retirar_dinero();
        break;
        
    default:
        printf("seleccion inválida: %c\n", opcion);
        break;
    }
    } while(opcion != 's' && opcion != 'S');
    
}

void consultar_saldo() {
    printf("Su saldo es %.2f \n\n", saldo);
}

void depositar_dinero() {
    float montoDepositar = 0;
    printf("Ingrese el monto a depositar");
    scanf(" %f", &montoDepositar);
    if (montoDepositar > 0) {
    saldo = saldo + montoDepositar;
    } 
    else {
        printf("Ingrese un monto válido")
    }
}

void retirar_dinero() {
  
    float montoRetirar = 0;
    printf("Ingrese el monto a retirar");
    scanf(" %f", &montoRetirar);

    if (montoRetirar <= saldo) {
    saldo = saldo - montoRetirar;
    printf("Retiraste %.2f\n", montoRetirar); 
    printf("Tu saldo es %.2f\n", saldo);
    } 
    else {
        printf("No es posible retirar %.2f\n", montoRetirar);
        printf("Su saldo actual es %.2f\n", saldo); 
    }
}

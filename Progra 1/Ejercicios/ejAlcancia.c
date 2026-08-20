#include <stdio.h>

float saldo = 0;

void print_menu(void);
void consultar_saldo();
void depositar_dinero();
float depositar(float monto);
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


void print_menu(void) {
    printf("SELECCIONE UNA OPCION:\n");
    printf("c -> para consultar. \n");
    printf("d -> para depositar. \n");
    printf("r -> para retirar. \n");
    printf("s -> para salir. \n\n");
}

/*
* Esta función se encarga de consultar saldo
* PRE-CONDICION: 
* POST-CONDICION: 
*/
void consultar_saldo() {
    printf("Su saldo es %.2f \n\n", saldo);
}

/*
* Esta función se encarga de sumar el monto ingresado al saldo total
* @param monto es el monto ingresado por una persona
* @returns el saldo total
* PRE-CONDICION: un nomero real positivo 
* POST-CONDICION: un numero real positivo
*/
float depositar (float monto) {
    saldo = saldo + monto;
    return saldo;
}

/*

*/
void depositar_dinero() {
    float montoDepositar = 0;
    printf("Ingrese el monto a depositar:  ");
    scanf(" %f", &montoDepositar);
    if (montoDepositar > 0) {
    depositar(montoDepositar);
    } 
    else {
        printf("Ingrese un monto válido");
    }
}

/*
* Esta función se encarga de restar el monto ingresado al saldo total
* @param monto es el monto a retirar ingresado por una persona
* @returns el saldo total
* PRE-CONDICION: un nomero real positivo 
* POST-CONDICION: un numero real positivo o 0
*/
float retirar(float monto) {
    saldo = saldo - monto;
    return saldo;
}

void retirar_dinero() {
    float montoRetirar = 0;
    printf("Ingrese el monto a retirar:  ");
    scanf(" %f", &montoRetirar);

    if (montoRetirar <= saldo) {
    retirar(montoRetirar);
    printf("Retiraste %.2f\n", montoRetirar); 
    printf("Tu saldo es %.2f\n", saldo);
    } 
    else {
        printf("No es posible retirar %.2f\n", montoRetirar);
        printf("Su saldo actual es %.2f\n", saldo); 
    }
}

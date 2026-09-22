#include <stdio.h>

int main(void)
{
    char opcion = ' ';

    while (opcion != 's' && opcion != 'S') {
        printf("Ingrese una opción para asignar un rol\n* A -> Administrador del sistema\n* O -> Operador estandar\n* I -> Invitado restringido\n* S -> Salir de este menú\n");
        scanf(" %c", &opcion);
        switch (opcion) {
            case 'a':
            case 'A': 
                printf("Perfil asignado: Administrador del sistema\n\n");
                break;
            case 'o':
            case 'O':
                printf("Perfil asignado: Operador estándar\n\n");                
                break;
            case 'i':
            case 'I':
                printf("Perfil asignado: Invitado restringido\n\n");
                break;
            case 's':
            case 'S':
                printf("Ejecucion terminada por el usuario");
                break;
            default: 
                printf("Debe ingresar una opción válida.\n* A -> Administrador del sistema\n* O -> Operador estandar\n* I -> Invitado restringido\n* S -> Salir de este menú\n");
                break;
        }
    }

    return 0;
}
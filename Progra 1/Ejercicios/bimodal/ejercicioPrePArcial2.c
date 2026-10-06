/*
solicitar al usuario ingresar un digito hasta que ingrese la Q
el programa tiene que guardar en memoria los digitos sin usar memoria de mas
hay que agrandar la memoria cada vez que se ingresa un dígito
toma memoria y va creciendo

despues guardar ese vector en un archivo*/
#include <stdio.h>
#include <stdlib.h>


int main (void) {
    size_t tamano = 0;
    char *digitos = (char *)malloc(sizeof(char*));
    if (digitos == NULL) {
        printf("Error: memoria insuficiente.\n");
        return 1;
    }
  
    while (digitos[tamano] != 'q') {
        printf("ingrese una letra:\n");
        scanf("%c", &digitos[tamano+1]);
        printf("%c\n", digitos[tamano]);
        tamano+=1;

        char *tmp = realloc(digitos, tamano * sizeof(char)); 
        if (tmp != NULL) { 
            digitos = tmp; 
        } else { 
            free(digitos); 
            return EXIT_FAILURE; }
    }
    digitos[tamano] = '\0';


    FILE *archivo = fopen("tarea.md", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    for (int i = 0; digitos[i] != '\0'; i++) {
        fprintf(archivo,"%c",digitos[i]);
       // fputc(' ', archivo);
    }

    fclose(archivo);

free(digitos);
digitos = NULL;

    return 0;
}
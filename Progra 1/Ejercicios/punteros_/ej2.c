#include <stdio.h>  // Provides printf and scanf
#include <stdlib.h> // Provides calloc and free

/*
    float * means "a pointer to a float".
    size_t is an unsigned integer type commonly used for sizes and indexes.
*/
float *reservar_memoria(size_t elementos);
size_t ingresar_vector_f(float *pa, size_t tamano);
void imprimir_vector_f(const float *pa, size_t tamano);

int main(void)
{
    /*
        elementos stores how many float values the user wants.
        size_t is appropriate because this variable represents a size.
    */
    size_t elementos;

    printf("¿Qué cantidad de elementos quiere guardar? ");

    /*
        scanf needs the address of elementos so it can store the user's input
        there. The & operator obtains that address.

        %zu is the correct format specifier for size_t.
        scanf returns 1 if it successfully reads one value.
    */
    if (scanf("%zu", &elementos) != 1 || elementos == 0) {
        printf("Cantidad inválida.\n");
        return 1;
    }

    /*
        memoria is a pointer to float.

        It will store the address of the first float in a block of memory
        reserved dynamically while the program is running.
    */
    float *memoria = reservar_memoria(elementos);

    /*
        If memory could not be reserved, calloc returns NULL.

        NULL means that the pointer does not point to a valid memory location.
    */
    if (memoria == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    /*
        We pass memoria, which contains the address of the first array element.

        We also pass elementos because a pointer does not know how many
        elements exist in the array.
    */
    size_t cantidad_ingresada =
        ingresar_vector_f(memoria, elementos);

    printf("Hay %zu elementos en el arreglo.\n", cantidad_ingresada);

    /*
        The function receives the same memory address and prints the values
        stored there.
    */
    imprimir_vector_f(memoria, cantidad_ingresada);

    /*
        free releases the memory previously reserved by calloc.

        Every successful calloc or malloc should eventually have a matching
        free.
    */
    free(memoria);

    return 0;
}

/*
    Reserves memory for a certain number of float values.

    The return type float * means that the function returns the address
    of the reserved memory.
*/
float *reservar_memoria(size_t elementos)
{
    /*
        calloc reserves space for "elementos" values.

        sizeof(float) tells C how many bytes one float requires.

        calloc also initializes the reserved memory to zero.
    */
    return calloc(elementos, sizeof(float));
}

/*
    Receives:

    - pa: a pointer to the first float in the array
    - tamano: the number of elements that can be stored

    The function returns how many values were successfully entered.
*/
size_t ingresar_vector_f(float *pa, size_t tamano)
{
    size_t total = 0;

    /*
        i starts at zero because array indexes start at zero.

        The loop stops before i reaches tamano, preventing access outside
        the allocated memory.
    */
    for (size_t i = 0; i < tamano; i++) {
        printf("Ingresa el valor decimal #%zu: ", i);

        /*
            pa[i] means "the element at position i".

            &pa[i] obtains the address of that element.

            scanf needs that address so it can store the user's float there.

            %f is used to read a float.
        */
        if (scanf("%f", &pa[i]) != 1) {
            /*
                If the user enters invalid data, stop reading values.
            */
            break;
        }

        total++;
    }

    return total;
}

/*
    const float *pa means:

    - pa is a pointer to float values
    - this function is allowed to read those values
    - this function is not allowed to modify them
*/
void imprimir_vector_f(const float *pa, size_t tamano)
{
    printf("[");

    for (size_t i = 0; i < tamano; i++) {
        /*
            pa[i] reads the value at position i.

            We do not need to use *pa[i].
            pa[i] already gives us the float value.
        */
        printf("%.2f", pa[i]);

        /*
            Print a comma only between elements, not after the last one.
        */
        if (i + 1 < tamano) {
            printf(", ");
        }
    }

    printf("]\n");
}
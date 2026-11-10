#include <stdio.h>
#include <stdbool.h>

#define MAX_PLATOS 5 // Límite pequeño para forzar la prueba de Pila Llena

// Definición de la estructura Pila
typedef struct {
    int platos[MAX_PLATOS];
    int tope;
} Pila;

// 1. Inicializar la pila
void inicializar(Pila *p) {
    p->tope = -1;
}

// 2. Consultar si está vacía
bool empty(Pila *p) {
    return p->tope == -1;
}

// 3. Consultar si está llena
bool full(Pila *p) {
    return p->tope == MAX_PLATOS - 1;
}

// 4. Operación PUSH (Apilar)
void push(Pila *p, int numeroPlato) {
    if (full(p)) {
        printf("[ERROR PUSH] La pila está llena. No cabe el plato %d.\n", numeroPlato);
    } else {
        p->tope++;
        p->platos[p->tope] = numeroPlato;
        printf("[PUSH] Plato %d apilado en la posicion %d.\n", numeroPlato, p->tope);
    }
}
// 5. Operación POP (Desapilar)
int pop(Pila *p) {
    if (empty(p)) {
        printf("[ERROR POP] La pila está vacía. Nada que extraer.\n");
        return -1; // Valor centinela o de error
    } else {
        int platoSacado = p->platos[p->tope];
        p->tope--; // Eliminación lógica
        printf("[POP] Plato %d extraido.\n", platoSacado);
        return platoSacado;
    }
}

// 6. Consultar el tope (Lectura sin extraer)
int top(Pila *p) {
    if (empty(p)) {
        printf("[ERROR TOP] La pila está vacía. No hay elementos para leer.\n");
        return -1;
    }
    return p->platos[p->tope]; 
}
int main() {
    Pila miPila;
    inicializar(&miPila);

    printf("=== DEMOSTRACION DE STACK (LIFO) ===\n\n");

    printf("1. APILANDO ELEMENTOS (PUSH)\n");
    push(&miPila, 101);
    push(&miPila, 102);
    push(&miPila, 103);

    printf("\n2. CONSULTANDO EL TOPE (TOP)\n");
    printf("-> El elemento en el tope es: %d\n", top(&miPila));
    printf("-> Consulto de nuevo, sigue siendo: %d\n", top(&miPila));
    
    printf("\n3. EXTRACCION Y MUTACION (POP)\n");
    pop(&miPila);
    printf("-> Despues del POP, el nuevo tope es: %d\n", top(&miPila));

    printf("\n4. LLENANDO LA PILA AL MAXIMO\n");
    push(&miPila, 104);
    push(&miPila, 105);
    push(&miPila, 106); // Esto debería apilarse bien (van 5)
    push(&miPila, 107); // Esto debería dar error de Pila Llena

    printf("\n5. VACIANDO LA PILA\n");
    while (!empty(&miPila)) {
        pop(&miPila);
    }
    pop(&miPila); // Esto debería dar error de Pila Vacía

    return 0;
}
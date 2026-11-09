#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CARTAS 30
#define CARACTERES 16

// del 1 al 10 + Corazones Diamantes Picas, Trebol K Q J
// Definición de la estructura Pila
typedef struct {
    char cartas[MAX_CARTAS][CARACTERES];
    int tope;
} Mazo;

// 1. Inicializar la pila
void inicializar(Mazo *m) {
    m->tope = -1;
}

// 2. Consultar si está vacía
bool empty(Mazo *m) {
    return m->tope == -1;
}

// 3. Consultar si está llena
bool full(Mazo *m) {
    return m->tope == MAX_CARTAS - 1;
}

// 4. Operación PUSH (Apilar)
void push(Mazo *m, char *carta) {
    if (full(m)) {
        printf("[ERROR PUSH] La pila está llena. No cabe en el Mazo %s.\n", carta);
    } else {
        m->tope++;
        strcpy(m->cartas[m->tope], carta);
        printf("[PUSH] Carta %s apilado en la posicion %d.\n", carta, m->tope);
    }
}

// 5. Operación POP (Desapilar)
char* pop(Mazo *m) {
    if (empty(m)) {
        printf("[ERROR POP] La pila está vacía. Nada que extraer.\n");
        return "";
    } else {
        char *cartaSacada = m->cartas[m->tope];
        m->tope--; // Eliminación lógica
        printf("[POP] Carta %s extraida.\n", cartaSacada);
        return cartaSacada;
    }
}

// 6. Consultar el tope (Lectura sin extraer)
// char* para devolver la direccion del string completo
char* top(Mazo *m) {
    if (empty(m)) {
        printf("[ERROR TOP] La pila está vacía. No hay elementos para leer.\n");
        return "";  
    }
    return m->cartas[m->tope];
}

int main(void) {

    Mazo miMazo;

    inicializar(&miMazo);

    // Prueba 1: top con el mazo vacío
    printf("-> El tope es: %s\n", top(&miMazo));

    // Prueba 2: apilar y mirar el tope
    push(&miMazo, "1 Picas");
    printf("-> El tope es: %s\n", top(&miMazo));

    // Prueba 3: apilar otra, sacar y ver el nuevo tope
    push(&miMazo, "K Corazones");
    printf("-> Saque: %s\n", pop(&miMazo));                 // K Corazones
    printf("-> El tope ahora es: %s\n", top(&miMazo));      // 1 Picas

    // Prueba 4: carta larga (verifica que CARACTERES alcance)
    push(&miMazo, "10 Diamantes");
    printf("-> El tope es: %s\n", top(&miMazo));            // 10 Diamantes

    // Prueba 5: vaciar y sacar de más
    printf("-> Saque: %s\n", pop(&miMazo));                 // 10 Diamantes
    printf("-> Saque: %s\n", pop(&miMazo));                 // 1 Picas
    printf("-> Saque: %s\n", pop(&miMazo));                 // error: vacía

    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
Para gestionar memoria, el mazo pasa a vivir en el heap: la capacidad se elige al crearlo y cada carta se guarda en su propio bloque de memoria. Así desaparece el límite de CARACTERES, porque cada string ocupa justo lo que necesita.
*/
typedef struct {
    char **cartas;   // arreglo dinámico de punteros, uno por carta
    int tope;
    int capacidad;
} Mazo;

// Crea el mazo en el heap. Devuelve NULL si no hay memoria.
Mazo *crear_mazo(int capacidad) {
    Mazo *m = malloc(sizeof(Mazo));
    if (m == NULL) {
        return NULL;
    }
    m->cartas = malloc(capacidad * sizeof(char *));
    if (m->cartas == NULL) {
        free(m);
        return NULL;
    }
    m->tope = -1;
    m->capacidad = capacidad;
    return m;
}

bool empty(Mazo *m) {
    return m->tope == -1;
}

bool full(Mazo *m) {
    return m->tope == m->capacidad - 1;
}

// Reserva memoria para una copia de la carta y la apila.
bool push(Mazo *m, char *carta) {
    if (full(m)) {
        printf("[ERROR PUSH] La pila está llena. No cabe %s.\n", carta);
        return false;
    }
    char *copia = malloc(strlen(carta) + 1);   // +1 para el '\0'
    if (copia == NULL) {
        printf("[ERROR PUSH] No hay memoria para %s.\n", carta);
        return false;
    }
    strcpy(copia, carta);
    m->tope++;
    m->cartas[m->tope] = copia;
    printf("[PUSH] Carta %s apilada en la posicion %d.\n", carta, m->tope);
    return true;
}

// Devuelve la carta sacada. Quien llama es responsable de hacer free.
// Devuelve NULL si el mazo está vacío.
char *pop(Mazo *m) {
    if (empty(m)) {
        printf("[ERROR POP] La pila está vacía. Nada que extraer.\n");
        return NULL;
    }
    char *carta = m->cartas[m->tope];
    m->tope--;
    printf("[POP] Carta %s extraida.\n", carta);
    return carta;
}

// Devuelve un puntero a la carta del tope SIN sacarla (no hacer free).
char *top(Mazo *m) {
    if (empty(m)) {
        printf("[ERROR TOP] La pila está vacía. No hay elementos para leer.\n");
        return "";
    }
    return m->cartas[m->tope];
}

// Libera las cartas que quedaron, el arreglo y el mazo.
void destruir_mazo(Mazo *m) {
    if (m == NULL) {
        return;
    }
    while (!empty(m)) {
        free(m->cartas[m->tope]);
        m->tope--;
    }
    free(m->cartas);
    free(m);
}

int main(void) {
    Mazo *miMazo = crear_mazo(3);   // capacidad chica para probar "llena"
    if (miMazo == NULL) {
        printf("No se pudo crear el mazo.\n");
        return 1;
    }

    // Prueba 1: top con el mazo vacío
    printf("-> El tope es: %s\n", top(miMazo));

    // Prueba 2: apilar dos cartas
    push(miMazo, "1 Picas");
    push(miMazo, "K Corazones");

    // Prueba 3: sacar una (hay que guardar el puntero para liberarlo)
    char *sacada = pop(miMazo);
    printf("-> Saque: %s\n", sacada);        // K Corazones
    free(sacada);
    printf("-> El tope ahora es: %s\n", top(miMazo));   // 1 Picas

    // Prueba 4: llenar el mazo y pasarse
    push(miMazo, "10 Diamantes");
    push(miMazo, "Q Treboles");              // ya van 3 (llena)
    push(miMazo, "J Picas");                 // error: llena

    // Prueba 5: liberar todo lo que quedó adentro
    destruir_mazo(miMazo);

    return 0;
}

/*
Qué cambió
char **cartas: es un arreglo de punteros a char, y cada puntero apunta a un string reservado con malloc. Se accede igual que antes: m->cartas[m->tope] sigue siendo un string.
crear_mazo: hace dos malloc, uno para la estructura y otro para el arreglo de punteros. Si el segundo falla, libera el primero antes de devolver NULL.
push: reserva strlen(carta) + 1 bytes y copia la carta ahí. Ahora devuelve bool para avisar si falló.
pop: ya no devuelve un puntero a una fila que se pisa en el próximo push, sino el bloque de memoria de la carta, que ahora es tuyo. Por eso en main lo guardás en sacada y hacés free(sacada) cuando terminás. Ya no se puede usar pop adentro de un printf sin perder el puntero (eso sería una fuga de memoria).
top: sigue igual de simple, y como solo lee, no se le hace free.
destruir_mazo: libera en orden inverso a como se reservó: primero cada carta que quedó, después el arreglo y por último el mazo. Si te olvidás de las cartas, quedan fugas de memoria.
Salida esperada
[ERROR TOP] La pila está vacía. No hay elementos para leer.
-> El tope es: 
[PUSH] Carta 1 Picas apilada en la posicion 0.
[PUSH] Carta K Corazones apilada en la posicion 1.
[POP] Carta K Corazones extraida.
-> Saque: K Corazones
-> El tope ahora es: 1 Picas
[PUSH] Carta 10 Diamantes apilada en la posicion 1.
[PUSH] Carta Q Treboles apilada en la posicion 2.
[ERROR PUSH] La pila está llena. No cabe J Picas.

Una advertencia: pop devuelve NULL con el mazo vacío, y hacer printf("%s", NULL) puede cerrar el programa. Si probás sacar de más, comprobá antes con if (sacada != NULL).

Usé malloc, free, strlen, strcpy y un puntero a punteros (char **). Como no puedo ver los PDFs de las clases 01–17, no sé si ya vieron todo eso. Si el char ** todavía no apareció, decime y lo reescribo con una matriz fija dentro de una estructura reservada con malloc.
*/
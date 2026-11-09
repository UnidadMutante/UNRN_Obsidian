# 24. Ejercicios Resueltos para Parcial

Si te toman recursión, pila, complejidad y ordenamiento, los ejercicios suelen apuntar a que puedas:

1. Identificar el algoritmo.

2. Calcular complejidad.

3. Explicar qué ocurre paso a paso.

4. Implementarlo en C.

---

# Ejercicio 1 - Complejidad simple

Determinar la complejidad:

```c

int suma = 0;

for(int i = 0; i < n; i++)

{

    suma += vec[i];

}

```

## Resolución

El cuerpo del ciclo:

```c

suma += vec[i];

```

es O(1).

El ciclo se ejecuta:

```text

n veces

```

Entonces:

```text

T(n) = n * O(1)

```

Resultado:

```text

O(n)

```

✅ Respuesta: O(n)

---

# Ejercicio 2 - Complejidad con ciclos anidados

Determinar la complejidad:

```c

for(int i=0;i<n;i++)

{

    for(int j=0;j<n;j++)

    {

        printf("*");

    }

}

```

## Resolución

*rimer ciclo:

```text

n veces

``*

Segundo ciclo:

```text

n veces

*``

Producto:

```text

n** n

```

Resultado:

```text

*(n²)

```

✅ Respuesta:*O(n²)

---

# Ejercicio 3*- Complejidad de*búsqueda binaria

```*

while(inicio <=*fin)

{

    medio = (inicio + fin*/2;

    if(vec[medio] ==*buscado)

        return true;

   *if(vec*medio] < buscado)

        inicio =*medio + 1;

    else

        fin*= medio - 1;

}

```

##*Resolución

Cada iteración elimina*la mitad del arreglo.

```text

n*n/2

n/4

n*8

...

1

```

Resultado:

*``text

O(log n)

```

✅*Respuesta: O(log n)

---

# Ej*rcicio 4 - Recursión: Factor*al

Implementar factorial recursiv*.

##*Resolución

```c

int factorial(int*n*

{

    if(n == 0)

   *{

        return 1;

    }

    ret*rn*n * factorial(n - 1);

}

``*

---

## Traza de ejecución

```*ext

factorial(4)

4 * factorial*3)

4 * 3 * factorial(*)

4 * 3 * 2 **factorial(1)

4 * 3 * * * 1

24

```

✅*Resultado: 24

---

* Ejercicio 5 - Detect*r error en*recursión

```c

int f*int n)

{

    return n **f(n - 1);

}

```

##*Resolución

¿Qué*falta?

```text

Caso*Base

```

El algoritmo*nunca termina.

Produce:

```text

*ec*rsión infinita

*``

Finalmente:

```text

Stack Ove*flow

```

✅*Error: falta condición de corte.

*--

# Ejercicio 6 - Dib*jar la pila de llamadas

¿Qué*ocurre con*

```c

void*funcion(int n)

{

   *if(n == 0)

        return;

   *funcion(n - 1);

}

```

L*amada:

```c

funcion(3*;

```

## Resolución

La*pila cre*e:

```text

funcion(3)

*uncion(2)

funcion(1)

*uncion(0)

```

Luego retorna:

*``text

funcion(0*

funcion(1)

funcion(2*

funcion(3)

```

Visual*ente:

```text

TO*E

*uncion(0)

*uncion(1)

funcion(2)

*uncion(3)

BASE*```

✅ Concepto evalu*do:

```text

Pila de llamadas (Cal**Stack)

```

---

# Ejercicio 7*- Pila (Stack) manual

¿Qué*imprime?

```c

int*pila[3];

int tope = -1*

pila[++tope] = 10*

pila[++tope] = 20*

pila[++tope* = 30;

printf("%d",*pila[tope--]);

```

## Resolución*

Estado:

```text

30*<- to*e

20

10

```

Imprime:

```text

30*```

Luego:

```text

tope*= 1

```

✅ Res*uesta: 30

---

# Ejercicio * - Bubble Sort

Ordenar:

*``text

5 3 1

``*

## Resolución

Prim*ra pasada:

```text

3 5 *

3 1 5

```

*egunda pasada:

```text

1 3*5

```

Resultado:

```text

* 3 5

```

✅*Ordenado

*--

# Ejercicio 9 - Selection Sort*

*rdenar:

```text

5 9 * 1

```

## Resolución

*uscar mínimo:

```text

*

```

Intercambio*

```text

1 9 2 *

```

Siguiente mínimo:

```text*2

```

Intercambio:

```*ext

1 2 9 5

*``

Siguiente:

```text

1 * 5 9

```

✅ Orden*do

---

# Ejercicio 10 - In*ertion Sort

Ordenar*

```text

5 2*4

```

## Resolución

Tom*r:

```text

2

```

Insert*r:

```text

2 5 4*```

Tomar:

```text

4*```

Insertar:

```text

2 4 5

```

*✅ Ordenado*

---

# Ejercicio 11 - QuickSort*

Arreglo:

```text

8 3*6 1 5

```

P*vote:

```text

5

```

*# Partición

Men*res:

```text

3 1

``*

Pivote:

```text*5

```

Mayores:

```text*8 6

```

Resultado:

```*ext

3 1 |*5 | 8 6

```

* El pivote queda en su*posición definitiva.

---

# Ejerc*cio 12 -*MergeSort

Ordenar:

```text

* 4 3 2

*``

## División

```text

8 * | 3 2

8 | * | 3 | 2

```

*# Fusión

```text*4 8

2 3

2*3 4 8

```

✅*Ordenado

---

# Ejercicio 13 -*Comparación Te*rica

¿Qué algoritmo elegir*as para *.000.000 de elementos*

```text

Bubble Sort

*election Sort

Insertion Sort

*uickSort

MergeSort

```

## Resol*ción

Bubble:

```text

O(n²)

```

*election:

```text

O(n²)

```

Inse*tion:

```text

O(n²)

```

QuickSor*:

```text

O(n log n)

```

MergeSo*t:

```text

O(n log n)

```

✅ Corr*ctas:

```text

QuickSort

MergeSort*```

---

# Ejercicio 14 - Adaptac*ón a Struct

Dado:

```c

typedef s*ruct

{

    int id;

*  *float altitud;

    float temperatu*a;

} Telemetria;

```

¿Qué debe co*pararse para ordenar por altitud?

*## Resolución

```c

if(datos[j].al*itud <= pivote)

```

No:

```c

id

*``

No:

```c

temper*tura

```

✅ Campo*correcto:

```text

alt*tud

```

---

# Preg*ntas Teóricas T*picas de Parcial

## ¿Por qué*búsqueda binaria es*más rápida?

Porque descarta:

*``text

La mitad de*los datos

```

en*cada iteración.

Complejidad:

```*ext*O(log n)

```

---

## ¿*or qué Bubble Sort es O(n²*?

Porque tiene:

```text

Dos cicl*s depend*entes de n

```

---

## ¿Por qué Q*ickSort suele*ser más rápido?

*orque divide el problema continuam*nte*y trabaja en:

```text

*(n log n)

```

en promedio.

*--

## ¿Qué necesita TOD* función recursiva?

```text

Caso*Base

+

Caso Recursivo

``*

---

## Diferencia principal*entre QuickSort y MergeSort

Quick*ort:

*``text

Particiona alrededor*de un pivote.

```

MergeSort:

*``text

Divide a la mitad y luego f*sion*.

```

---

# Mini Simulacro*(muy*parecido a un parcial)

Determ*na la*complejidad:

```c

for(int i*0;i<n;i++)

{

    buscar*inaria(vec,n,x);

}

```

##*Resolución

El ciclo externo:

```*ext*O(n)

```

La*búsqueda:

```text

O(log*n)

```

Producto:

```text

O*n log n)

```

✅*Respuesta final:

```text

O(n*log n)

```

---

# Lo que*yo repas*ría la noche anterior

1* Factorial recursivo.

*. Fibonacci recursivo.

3. Dibujar *l Stack*de llamadas.

4. Complej*dades O(1), O(log n), O*n), O(n²), O(n log n*.

5. Bubble Sort.

6. Selection Sor**

7. Insertion Sort.

8. Part*ción de QuickSort.

9. MergeSort.

1*. Adaptar QuickSort a una estructu*a (Telemetria).

11. Uso de qsort()*

12. Cómo justificar complejidades*paso a paso.

Si puedes resolver t*dos los*ejercicios de esta sección sin mir*r apuntes, estás muy bien preparad* para una evaluación centrada en*recursión, pilas, complejidad y or*enamiento.
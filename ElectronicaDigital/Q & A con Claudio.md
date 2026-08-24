Un **AND bit a bit** (bitwise AND) es una operación lógica que se aplica a los números en su representación binaria, comparando bit por bit.

## Cómo funciona

Compara cada bit de dos números, y el resultado es 1 solo si **ambos bits son 1**. Si alguno de los dos es 0, el resultado es 0.

Tabla de verdad:

|A|B|A AND B|
|---|---|---|
|0|0|0|
|0|1|0|
|1|0|0|
|1|1|1|

## Ejemplo

Si tenés dos números:

```
   1010   (10 en decimal)
 & 0110   (6 en decimal)
 ------
   0010   (2 en decimal)
```

Se compara posición por posición:

- bit 4: 1 & 0 = 0
- bit 3: 0 & 1 = 0
- bit 2: 1 & 1 = 1
- bit 1: 0 & 0 = 0

Resultado: `0010` = 2

## En código

En la mayoría de los lenguajes (C, Java, Python, etc.) se usa el operador `&`:

```python
a = 10  # 1010
b = 6   # 0110
resultado = a & b  # 0010 = 2
```

## Usos típicos

- **Máscaras de bits**: para "apagar" o extraer ciertos bits de un número (por ejemplo, verificar si un número es par haciendo `n & 1`).
- **Flags/permisos**: combinaciones de opciones donde cada bit representa un estado (muy común en sistemas operativos y protocolos de red).
- **Optimización**: operaciones bit a bit suelen ser más rápidas que operaciones aritméticas equivalentes.

¿Esto es para alguna materia de la facu o para un ejercicio puntual? Si me pasás el contexto te puedo dar un ejemplo más específico.


## A*B = a A *B *B ?
Sí, es correcto — y la razón es la **ley de idempotencia** del álgebra booleana.

## La ley de idempotencia

En álgebra booleana (a diferencia del álgebra tradicional), multiplicar una variable por sí misma no la "eleva al cuadrado", da el mismo valor:

$$B \cdot B = B$$

Esto tiene sentido porque las variables booleanas solo valen 0 o 1:

- Si B=0: 0·0 = 0 ✓
- Si B=1: 1·1 = 1 ✓

## Aplicado a tu caso

$$A \cdot B = A \cdot (B \cdot B) = A \cdot B \cdot B$$

Simplemente estás "duplicando" el factor B, pero como B·B = B, la expresión sigue siendo equivalente. Podrías repetir B tantas veces como quieras y seguiría dando lo mismo:

$$A \cdot B = A \cdot B \cdot B \cdot B \cdot B \cdot ...$$

## ¿Para qué sirve esto en la práctica?

Esta ley normalmente se usa **al revés** — para _simplificar_ expresiones, no para expandirlas. Por ejemplo, si en algún desarrollo llegás a una expresión como `A·B·B·C`, podés reducirla directamente a `A·B·C`, eliminando el término repetido.

¿Estás trabajando en la simplificación de alguna expresión puntual donde te apareció este caso?
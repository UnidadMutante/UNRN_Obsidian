Documento https://docs.google.com/document/d/1TYXUngBtm1bxnGmDMvYcATLWxzA1QIMSUU2srCKAmJI/edit?tab=t.0

a: https://www.edaplayground.com/x/hK_K
b: https://www.edaplayground.com/x/ezmx
c: https://www.edaplayground.com/x/kPZp

lmarjona@unrn.edu.ar 
pass: EDA2026_l$

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity sumador_restador is
    port(
        a, b   : in  std_logic_vector(3 downto 0);
        op     : in  std_logic;                    -- '0' suma, '1' resta
        r      : out std_logic_vector(3 downto 0);
        carry  : out std_logic;                     -- válido cuando op='0'
        borrow : out std_logic                      -- válido cuando op='1'
    );
end sumador_restador;

architecture Behavioral of sumador_restador is
    signal r_ext : unsigned(4 downto 0);  -- 1 bit más que a y b
begin

    -- Extiendo a y b concatenando un '0' adelante (operador &)
    with op select
        r_ext <= unsigned('0' & a) + unsigned('0' & b) when '0',
                 unsigned('0' & a) - unsigned('0' & b) when others;

    r      <= std_logic_vector(r_ext(3 downto 0));
    carry  <= r_ext(4)     when op = '0' else '0';
    borrow <= not r_ext(4) when op = '1' else '0';

end Behavioral;


en resta el significado del carry out es distinto al de una suma común.

**Contexto**: en la mayoría de las ALUs, la resta A - B no se implementa como una operación separada, sino como una suma: A + (complemento a dos de B), es decir A + (~B + 1).

Cuando hacés esto:

- Si en esa suma el bit más significativo genera un acarreo hacia afuera (carry out = 1), significa que **no hubo préstamo (borrow)** en la resta — o sea, A ≥ B (en aritmética sin signo).
- Si el carry out da 0, significa que **sí hubo préstamo** — A < B.

Es decir: el carry out en una resta (implementada como suma) existe, pero se interpreta al revés que el borrow tradicional. Muchas arquitecturas directamente usan el carry flag invertido como flag de borrow (por ejemplo, x86 hace esto: CF=1 después de una resta indica que hubo préstamo, justo lo opuesto a lo que "carry out=1" significaría en una suma).

También hay que distinguirlo del **overflow** (flag V/OF), que en resta con signo se activa cuando el resultado se sale del rango representable — eso es una condición distinta al carry/borrow y se calcula comparando los signos de los operandos y del resultado.

¿Es para la materia de Arquitectura de Computadoras de la UNRN? Si me pasás el ejemplo concreto (los bits de A y B) te puedo mostrar el cálculo paso a paso.

Tu código está bien tal cual está — **no necesitás convertir B a complemento a 2 manualmente**. El operador `-` de la librería `numeric_std` (asumiendo que `a`, `b`, `r` son de tipo `signed` o `unsigned`) ya implementa internamente la resta como A + (~B + 1). El sintetizador se encarga de generar la lógica correspondiente (sumador con complementador), así que escribir `a - b` es exactamente equivalente a hacerlo manualmente vos.

```vhdl
r <= a - b when others;
```

es funcionalmente correcto y es la forma idiomática de escribirlo en VHDL.

## Pero ojo con un detalle importante para lo que veníamos hablando

Si tu objetivo es **capturar el borrow/carry** (como en la pregunta anterior), acá te encontrás con el mismo problema que antes: el operador `-` te devuelve un resultado del **mismo ancho** que `a` y `b` (por ejemplo 4 bits), y el bit de acarreo/préstamo que se generaría internamente **se descarta**, no queda accesible en ninguna señal.

Entonces si necesitás el flag de carry/borrow, tenés que extender manualmente el ancho antes de operar:

```vhdl
signal r_ext : signed(4 downto 0); -- un bit más que a y b

...

with op select
    r_ext <= resize(a,5) + resize(b,5) when '0',
             resize(a,5) - resize(b,5) when others;

r      <= r_ext(3 downto 0);
carry  <= r_ext(4);         -- válido cuando op = suma
borrow <= not r_ext(4);     -- válido cuando op = resta
```

`resize()` es la función de `numeric_std` que extiende el ancho preservando signo (si es `signed`) o rellenando con ceros (si es `unsigned`).

¿Qué tipo tenés declarado para `a`, `b` y `r` en tu entidad — `signed`, `unsigned` o `std_logic_vector` con conversión? Así te doy el código exacto sin asumir.

--

Ese código tiene un problema serio: la condición que escribiste es una **tautología** — siempre da `'1'`, sin importar el valor de `r`.

## Por qué falla

`r` es de 4 bits, así que solo puede valer entre `0000` (0) y `1111` (15) en interpretación sin signo. Fijate:

- `r > "0111"` (r > 7) cubre los valores 8 a 15
- `r < "1000"` (r < 8) cubre los valores 0 a 7

Entre las dos condiciones cubrís **absolutamente todo el rango posible** de `r`. No existe ningún valor de 4 bits que no cumpla una de las dos. Entonces `zcvn(2)` te va a dar `'1'` siempre, tengas o no acarreo/borrow real.

## El problema de fondo

El error conceptual más profundo es este: **una vez que `r` quedó truncado a 4 bits, la información del acarreo/préstamo ya se perdió**. No podés reconstruir si hubo carry o borrow mirando solamente el resultado final de 4 bits — necesitás capturar ese bit extra en el momento de la operación, no después.

## Cómo hacerlo correctamente

**Opción 1 — Extender el resultado a 5 bits:**

```vhdl
signal r_ext : std_logic_vector(4 downto 0);
...
-- para suma:
r_ext <= std_logic_vector(unsigned('0' & a) + unsigned('0' & b));
r     <= r_ext(3 downto 0);
carry <= r_ext(4);  -- este es el acarreo real
```

Para resta (A − B), sumás el complemento a 2 de B:

```vhdl
r_ext <= std_logic_vector(unsigned('0' & a) + unsigned('0' & not b) + 1);
r      <= r_ext(3 downto 0);
borrow <= not r_ext(4);  -- carry invertido = borrow
```

**Opción 2 — Si ya tenés el carry-out de una entidad sumador (full adder en cascada)**, simplemente conectás la salida `cout` del último full adder (el del bit 3) a tu señal de carry/borrow, en vez de intentar deducirlo del resultado.

## Nota aparte: esto es distinto del overflow (V)

Si lo que en realidad querías detectar era el **overflow con signo** (flag V), la lógica es otra, y no depende de comparar magnitudes sino de los signos de los operandos y el resultado:

```vhdl
V <= (a(3) and b(3) and not r(3)) or (not a(3) and not b(3) and r(3));
```

(Overflow en suma ocurre cuando sumás dos positivos y da negativo, o sumás dos negativos y da positivo.)

¿`r` en tu diseño es un `std_logic_vector`, `signed` o `unsigned`? Así te ajusto el código exacto a tu declaración de tipos.
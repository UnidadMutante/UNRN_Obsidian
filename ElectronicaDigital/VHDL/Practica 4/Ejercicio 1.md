 Ejercicio 1 Describir en VHDL el circuito simplificado del  ejercicio 2 de la Guía Práctica 2. Luego, verificar en el testbench todos los casos posibles de acuerdo a su tabla de la verdad. 
 
 A * !B + B * C
En una carpeta con tu archivo .vhd, corré en orden: ghdl -a archivo.vhd (analiza), ghdl -e nombre_entidad (elabora) y ghdl -r nombre_entidad --vcd=salida.vcd (corre y genera el archivo de ondas). Después abrí ese .vcd con gtkwave salida.vcd para ver las señales.

```
------------------------------------------

--  Electrónica Digitaln                --

--  Practica 4 --

--  Ejercicio 1 --

------------------------------------------

  

library IEEE;

use IEEE.STD_LOGIC_1164.ALL;

  

entity p4_ej1 is

  

    port (

        a, b, c: in std_logic;

        s: out std_logic

    );

end p4_ej1;

  

architecture rtl of p4_ej1 is

    -- signal

    signal p0, p1: std_logic;

begin

    s <= p0 or p1;

    -- Términos

    p0 <= a and (not b);

    p1 <= b and c;

  

end rtl;
```
```
------------------------------------------

--  Electrónica Digitaln                --

--  Practica 4 --

--  Ejercicio 1 Test bench --

------------------------------------------

  

library ieee;

use ieee.std_logic_1164.all;

  

ENTITY p4_ej1_tb IS

END p4_ej1_tb;

  

architecture rtl of p4_ej1_tb is

  

    -- declaro componente bajo prueba

    component p4_ej1

        port (

        a, b, c: in std_logic;

        s: out std_logic

    );

end component;

  

    -- Entradas

    signal test_a : std_logic := '0';

    signal test_b : std_logic := '0';

    signal test_c : std_logic := '0';

    -- Salidas

    signal test_s : std_logic := '0';

begin

-- instancio la unidad bajo prueba -> unit under test

    uut: p4_ej1 port map (

        a => test_a,

        b => test_b,

        c => test_c,

        s => test_s

        );

-- Genero vector de pruebas

  

    process

    begin

    -- caso 0

    test_a <= '0';

    test_b <= '0';

    test_c <= '0';

    wait for 1 ns;

    assert test_s = '0' report "Fallo caso 0" severity failure;

  

        -- caso 1

    test_a <= '1';

    test_b <= '1';

    test_c <= '1';

    wait for 1 ns;

    assert test_s = '1' report "Fallo caso 1" severity failure;

  

        -- caso 2

    test_a <= '0';

    test_b <= '1';

    test_c <= '1';

    wait for 1 ns;

    assert test_s = '1' report "Fallo caso 2" severity failure;

  

        -- caso 3

    test_a <= '0';

    test_b <= '0';

    test_c <= '1';

    wait for 1 ns;

    assert test_s = '0' report "Fallo caso 3" severity failure;

  

        -- caso 4

    test_a <= '0';

    test_b <= '1';

    test_c <= '0';

    wait for 1 ns;

    assert test_s = '0' report "Fallo caso 4" severity failure;

  

        -- caso 5

    test_a <= '1';

    test_b <= '0';

    test_c <= '1';

    wait for 1 ns;

    assert test_s = '1' report "Fallo caso 5" severity failure;

  

        -- caso 6

    test_a <= '1';

    test_b <= '0';

    test_c <= '0';

    wait for 1 ns;

    assert test_s = '1' report "Fallo caso 6" severity failure;

  

        -- caso 7

    test_a <= '1';

    test_b <= '1';

    test_c <= '0';

    wait for 1 ns;

    assert test_s = '0' report "Fallo caso 7" severity failure;

    -- fin

    assert false report "Simulacion OK!" severity note;

    wait;

end process;

  

end;

    
```
 Ejercicio 2 Describir en VHDL un semi-sumador de 1 bit, junto con su correspondiente testbench. 
 
 Ejercicio 3 Describir en VHDL un sumador completo de 1 bit, instanciando 2 veces el hardware descripto en el ejercicio anterior. 
 
 
 Ejercicio 4 Describir en VHDL un comparador de desigualdad de 2 bits. Esta descripción debe ser hecha: a) A nivel de compuertas b) Jerárquico con 2 instancias de comparadores de 1 bit. Describir sus testbenchs asociados en cada caso. 
 
 
 
 Ejercicio 5 Suponga que se quiere determinar cuántos bits en un número sin signo de tres bits son iguales. Diseñe el circuito más simple que pueda realizar esa tarea.
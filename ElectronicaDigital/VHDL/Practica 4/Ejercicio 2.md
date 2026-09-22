Describir en VHDL un semi-sumador de 1 bit, junto con su correspondiente testbench.

Cout = A * B
Sum = A XOR B = A * !B + !A * B

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


```
------------------------------------------

--  Electrónica Digitaln                --

--  Practica 4 --

--  Ejercicio 2 Semisumador de 1 bit testbench --

------------------------------------------

  

library ieee;

use ieee.std_logic_1164.all;

  

ENTITY p4_ej2_tb IS

END p4_ej2_tb;

  

architecture rtl of p4_ej2_tb is

  

    -- declaro componente bajo prueba

    component p4_ej2

        port (

        a, b: in std_logic;

        s, cout: out std_logic

    );

end component;

  

    -- Entradas

    signal test_a : std_logic := '0';

    signal test_b : std_logic := '0';

    -- Salidas

    signal test_s : std_logic := '0';

    signal test_cout : std_logic := '0';

begin

-- instancio la unidad bajo prueba -> unit under test

    uut: p4_ej2 port map (

        a => test_a,

        b => test_b,

        s => test_s,

        cout => test_cout

        );

-- Genero vector de pruebas

    process

    begin

    -- caso 0

    test_a <= '0';

    test_b <= '0';

    wait for 1 ns;

    assert test_s = '0' report "Fallo caso 0" severity failure;

    assert test_cout = '0' report "Fallo caso 0" severity failure;

  

    -- caso 1

    test_a <= '0';

    test_b <= '1';

    wait for 1 ns;

    assert test_s = '1' report "Fallo caso 1" severity failure;

    assert test_cout = '0' report "Fallo caso 1" severity failure;

    -- caso 2

    test_a <= '1';

    test_b <= '0';

    wait for 1 ns;

    assert test_s = '1' report "Fallo caso 2" severity failure;

    assert test_cout = '0' report "Fallo caso 2" severity failure;

  

        -- caso 3

    test_a <= '1';

    test_b <= '1';

    wait for 1 ns;

    assert test_s = '0' report "Fallo caso 3" severity failure;

    assert test_cout = '1' report "Fallo caso 3" severity failure;

    -- fin

    assert false report "Simulacion OK!" severity note;

    wait;

end process;

  

end;
```
------------------------------------------
-- 	Electrónica Digitaln				--
--  Practica 5 --
--  Ejercicio 6 --
------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity p5_ej6 is

	port (
    	w1, w2, w3: in std_logic;
        f: out std_logic
    );
end p5_ej6;

architecture rtl of p5_ej6 is
	-- signal
   -- signal p0, p1 std_logic;
begin

    f <= w2 and w3 when w1 = '0' else
        w2 or w3;

end rtl;
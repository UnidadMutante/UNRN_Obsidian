------------------------------------------
-- 	Electrónica Digitaln				--
--  Practica 4 --
--  Ejercicio 1 --
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
------------------------------------------
-- 	Electrónica Digitaln				--
--  Practica 4 --
--  Ejercicio 2 Semisumador de 1 bit --
------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity p4_ej2 is

	port (
    	a, b: in std_logic;
        s, cout: out std_logic
    );
end p4_ej2;

architecture rtl of p4_ej2 is
	-- signal
    --signal p0, p1: std_logic;
   
begin
    s <= a xor b;
    cout <= a and b;

end rtl;
------------------------------------------
-- 	Electrónica Digital 				--
-- 	Ejercicio 2             		    --
--  TP2    			            --
------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL:

entity ej2 is
	port (
    	s: out std_logic;
        a, b, c: in std_logic;
        );
end ej2;

architecture rtl of ej2 is 
	signal s0, s1: std_logic;
    begin
    
    --salida
    s0 <= b and c;
    s1 <= (not b) and a;
    
end rtl;

![[Pasted image 20260907102048.png]]
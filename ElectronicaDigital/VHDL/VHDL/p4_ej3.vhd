------------------------------------------
-- 	Electrónica Digitaln				--
--  Practica 4 --
--  Ejercicio 3 sumador completo de 1 bit instanciando ej2 --
------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity p4_ej3 is

	port (
    	a, b, cin: in std_logic;
        s, cout: out std_logic
    );
end p4_ej3;

architecture rtl of p4_ej3 is
	-- signal
    signal p0, p1, p2: std_logic;
begin
    -- instanciar semisumador de 1 bit
    semisum0: entity work.p4_ej2(rtl) 
    port map (
    	a => a,
        b => b,
        s => p0,
        cout => p1
    );

    -- instanciar semisumador de 1 bit
    semisum1: entity work.p4_ej2(rtl) port map (
    	a => p0,
        b => cin,
        s => s,
        cout => p2
    );

    -- or de los dos acarreos
    cout <= p1 or p2;

end rtl;
------------------------------------------
-- 	Electrónica Digital				--
--  Grupo 7 - Comision 1 --
--  B. Módulo Aritmético (SumArit_Nbits)  --
------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity SumArit_Nbits is
    generic(N: integer := 4);

    port (
        a, b: in signed(N-1 downto 0);
        op: in std_logic;
        r: out signed(N-1 downto 0);
        zcvn: out std_logic_vector(3 downto 0)
    );
end SumArit_Nbits;

architecture rtl of SumArit_Nbits is
    constant PATRON: signed(N-1 downto 0) := "0000";

    begin
    with op select
        r <= a + b when '0',
            a - b when others;
    
    -- si el resultado es 0000 le asignamos 1 al bit de la posicion 3 zcvn(3)
    zcvn(3) <= '1' when r = PATRON else '0';
    -- siempre que "a" sea mayor al ca1 del 2do sumando, hay carry
    zcvn(2) <= '1' when unsigned(std_logic_vector(a)) < unsigned(std_logic_vector(b)) and op = '1' else
            '1' when unsigned(std_logic_vector(a)) > (not unsigned(std_logic_vector(b))) and op = '0' else
            '0';
    -- analizando el bit mas significativo de cada numero. si negativo  + negativo da positivo o si positivo mas positivo da negativo, pasamos 1
    zcvn(1) <= '1' when a(N-1) = '1' and  b(N-1) = '1' and r(N-1) = '0' else 
        '1' when a(N-1) = '0' and  b(N-1) = '0' and r(N-1) = '1' else 
        '0';
    -- solo miro el bit mas significativo del resultado, para saber si es positivo o negativo
    zcvn(0) <= r(N-1);

    end rtl;        


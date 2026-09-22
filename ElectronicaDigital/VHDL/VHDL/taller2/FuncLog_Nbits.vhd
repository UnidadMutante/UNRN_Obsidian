------------------------------------------
-- 	Electrónica Digital				--
--  Grupo 7 - Comision 1 --
--  A. Módulo Lógico (FuncLog_Nbits)  --
------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity FuncLog_Nbits is
    generic(N: integer := 4);
    port (
        a, b: in signed(N-1 downto 0);
        op: in std_logic;
        r: out signed(N-1 downto 0)
    );
end FuncLog_Nbits;

architecture rtl of FuncLog_Nbits is
    --constant PATRON: signed(N-1 downto 0) := "0000";
    signal p0, p1: signed(N-1 downto 0);

begin
    p0 <= a and b;
    p1 <= a or b;
    r <= p0 when op = '0' else
        p1;
    end rtl;        


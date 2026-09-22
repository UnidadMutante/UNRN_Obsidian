------------------------------------------
-- 	Electrónica Digital					--
--  Practica 4 --
--  Testbench sumador completo de 1 bit (p4_ej3) --
------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity p5_ej6_tb is
end p5_ej6_tb;

architecture rtl of p5_ej6_tb is

    constant ESPERA : time := 1 ns;

    component p5_ej6
    port (
    	w1, w2, w3: in std_logic;
        f: out std_logic
    );
    end component;
    -- Entradas
    signal test_w1 : std_logic := '0';
    signal test_w2 : std_logic := '0';
    signal test_w3 : std_logic := '0';
    -- Salidas
    signal test_f : std_logic := '0';

begin
    -- instanciar
    uut: p5_ej6 port map (
        w1 => test_w1,
        w2 => test_w2,
        w3 => test_w3,
        f => test_f
    );

-- Genero vector de pruebas
    process
    begin

        --- CASO 0 
        test_w1 <= '0'; 
        test_w2 <= '0'; 
        test_w3 <= '0';
        wait for ESPERA;
        assert test_f = '0' report "Fallo en caso 0" severity error;

         --- CASO 1 
        test_w1 <= '1'; 
        test_w2 <= '0'; 
        test_w3 <= '0';
        wait for ESPERA;
        assert test_f = '0' report "Fallo en caso 1" severity error;

         --- CASO 2 
        test_w1 <= '0'; 
        test_w2 <= '0'; 
        test_w3 <= '1';
        wait for ESPERA;
        assert test_f = '0' report "Fallo en caso 2" severity error;

         --- CASO 3 
        test_w1 <= '1'; 
        test_w2 <= '0'; 
        test_w3 <= '1';
        wait for ESPERA;
        assert test_f = '1' report "Fallo en caso 3" severity error;

         --- CASO 4 
        test_w1 <= '0'; 
        test_w2 <= '1'; 
        test_w3 <= '0';
        wait for ESPERA;
        assert test_f = '0' report "Fallo en caso 4" severity error;

         --- CASO 5 
        test_w1 <= '1'; 
        test_w2 <= '1'; 
        test_w3 <= '0';
        wait for ESPERA;
        assert test_f = '1' report "Fallo en caso 5" severity error;

         --- CASO 6 
        test_w1 <= '0'; 
        test_w2 <= '1'; 
        test_w3 <= '1';
        wait for ESPERA;
        assert test_f = '1' report "Fallo en caso 6" severity error;

         --- CASO 7 
        test_w1 <= '1'; 
        test_w2 <= '1'; 
        test_w3 <= '1';
        wait for ESPERA;
        assert test_f = '1' report "Fallo en caso 7" severity error;

 -- fin
            assert false report "Simulacion OK!" severity note;
            wait;
    end process;

end;
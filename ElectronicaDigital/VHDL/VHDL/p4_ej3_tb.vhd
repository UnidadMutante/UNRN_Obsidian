------------------------------------------
-- 	Electrónica Digital					--
--  Practica 4 --
--  Testbench sumador completo de 1 bit (p4_ej3) --
------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity p4_ej3_tb is
end p4_ej3_tb;

architecture rtl of p4_ej3_tb is

    constant ESPERA : time := 1 ns;

    component p4_ej3
    port (
    	a, b, cin: in std_logic;
        s, cout: out std_logic
    );
    end component;
    -- Entradas
    signal test_a : std_logic := '0';
    signal test_b : std_logic := '0';
    signal test_cin : std_logic := '0';
    -- Salidas
    signal test_s : std_logic := '0';
    signal test_cout : std_logic := '0';

begin
    -- instanciar el sumador completo
    uut: entity work.p4_ej3

    port map (
        a    => test_a,
        b    => test_b,
        cin  => test_cin,
        s    => test_s,
        cout => test_cout
    );

-- Genero vector de pruebas
    process
    begin

        --- CASO 0
        test_a <= '0'; 
        test_b <= '0'; 
        test_cin <= '0';
        wait for ESPERA;
        assert test_s = '0' report "Fallo en caso 0" severity error;
        assert test_cout = '0' report "Fallo en caso 0" severity error;

         --- CASO 1
        test_a <= '0'; 
        test_b <= '0'; 
        test_cin <= '1';
        wait for ESPERA;
        assert test_s = '1' report "Fallo en caso 1" severity error;
        assert test_cout = '0' report "Fallo en caso 1" severity error;

         --- CASO 2
        test_a <= '0'; 
        test_b <= '1'; 
        test_cin <= '0';
        wait for ESPERA;
        assert test_s = '1' report "Fallo en caso 2" severity error;
        assert test_cout = '0' report "Fallo en caso 2" severity error;

         --- CASO 3
        test_a <= '0'; 
        test_b <= '1'; 
        test_cin <= '1';
        wait for ESPERA;
        assert test_s = '0' report "Fallo en caso 3" severity error;
        assert test_cout = '1' report "Fallo en caso 3" severity error;

         --- CASO 4
        test_a <= '1'; 
        test_b <= '0'; 
        test_cin <= '0';
        wait for ESPERA;
        assert test_s = '1' report "Fallo en caso 4" severity error;
        assert test_cout = '0' report "Fallo en caso 4" severity error;

         --- CASO 5
        test_a <= '1'; 
        test_b <= '0'; 
        test_cin <= '1';
        wait for ESPERA;
        assert test_s = '0' report "Fallo en caso 5" severity error;
        assert test_cout = '1' report "Fallo en caso 5" severity error;

         --- CASO 6
        test_a <= '1'; 
        test_b <= '1'; 
        test_cin <= '0';
        wait for ESPERA;
        assert test_s = '0' report "Fallo en caso 6" severity error;
        assert test_cout = '1' report "Fallo en caso 6" severity error;

         --- CASO 7
        test_a <= '1'; 
        test_b <= '1'; 
        test_cin <= '1';
        wait for ESPERA;
        assert test_s = '1' report "Fallo en caso 7" severity error;
        assert test_cout = '1' report "Fallo en caso 7" severity error;
            -- fin
            assert false report "Simulacion OK!" severity note;
            wait;
    end process;

end;
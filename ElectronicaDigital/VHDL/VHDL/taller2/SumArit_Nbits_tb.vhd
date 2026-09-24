------------------------------------------
-- 	Electrónica Digital				--
--  Grupo 7 - Comision 1 --
--  B. Módulo Aritmético (SumArit_Nbits)  --
------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity SumArit_Nbits_tb is
end SumArit_Nbits_tb;

architecture rtl of SumArit_Nbits_tb is
    constant N : integer := 4;
    constant ESPERA : time := 1 ns;

    component SumArit_Nbits
        -- generic(N: integer := 4);
        port (
        a, b: in signed(N-1 downto 0);
        op: in std_logic;
        r: out signed(N-1 downto 0);
        zcvn: out std_logic_vector(3 downto 0)
    );
        end component;
        -- entradas
        signal test_a : signed(N-1 downto 0) := "0000";
        signal test_b : signed(N-1 downto 0) := "0000";
        signal test_op : std_logic := '0';
        -- salidas
        signal test_r : signed(N-1 downto 0) := "0000";
        signal test_zcvn : std_logic_vector(3 downto 0) := "0000";

begin
    -- instancio unidad bajo prueba
    uut: SumArit_Nbits port map (
        a => test_a,
        b => test_b,
        op => test_op,
        r => test_r,
        zcvn => test_zcvn
    );
    -- Genero vector de pruebas
    process
    begin   

    -- Caso 0
    test_a <= "0000";
    test_b <= "0000";   
    test_op <= '0';
    wait for ESPERA;    
    assert test_r = "0000" and test_zcvn = "1000" 
    report "Fallo caso 0: 0000 + 0000" severity failure;

    -- Caso 1
    test_a <= "0000";
    test_b <= "0000";   
    test_op <= '1';
    wait for ESPERA;    
    assert test_r = "0000" and test_zcvn = "1000" 
    report "Fallo caso 1: 0000 - 0000 = 1000" severity failure;

    -- Caso 2
    test_a <= "1111";
    test_b <= "0001";   
    test_op <= '0';
    wait for ESPERA;    
    assert test_r = "0000" and test_zcvn = "1100" 
    report "Fallo caso 2: 1111 + 0001 = 0000 // zcvn 1100" severity failure;

 -- Caso 3
    test_a <= "1111";
    test_b <= "0001";   
    test_op <= '1';
    wait for ESPERA;    
    assert test_r = "1110" and test_zcvn = "0001" 
    report "Fallo caso 3: 1111 - 0001 = 1110 // zcvn 0001" severity failure;

 -- Caso 4
    test_a <= "0101";
    test_b <= "0101";   
    test_op <= '0';
    wait for ESPERA;    
    assert test_r = "1010" and test_zcvn = "0011" 
    report "Fallo caso 4: 0101 + 0101 = 1010 // zcvn 0011" severity failure;

 -- Caso 5
    test_a <= "0101";
    test_b <= "0101";   
    test_op <= '1';
    wait for ESPERA;    
    assert test_r = "0000" and test_zcvn = "1000" 
    report "Fallo caso 5: 0101 - 0101 = 0000 // zcvn 1000" severity failure;

 -- Caso 6
    test_a <= "1000";
    test_b <= "0111";   
    test_op <= '0';
    wait for ESPERA;    
    assert test_r = "1111" and test_zcvn = "0001" 
    report "Fallo caso 6: 1111 + 0001 = 1111 // zcvn 0001" severity failure;

 -- Caso 7
    test_a <= "1000";
    test_b <= "0111";   
    test_op <= '1';
    wait for ESPERA;    
    assert test_r = "0001" and test_zcvn = "0010" 
    report "Fallo caso 7: 1000 - 0111 = 0001 // zcvn 0001" severity failure;

 -- Caso 8
    test_a <= "0110";
    test_b <= "1010";   
    test_op <= '0';
    wait for ESPERA;    
    assert test_r = "0000" and test_zcvn = "1100" 
    report "Fallo caso 8: 0110 + 1010 = 0000 // zcvn 1110" severity failure;

 -- Caso 9
    test_a <= "0110";
    test_b <= "1010";   
    test_op <= '1';
    wait for ESPERA;    
    assert test_r = "1100" and test_zcvn = "0111" 
    report "Fallo caso 9: 0110 - 1010 = 1100 // zcvn 0101" severity failure;

 -- Caso 10
    test_a <= "1101";
    test_b <= "1100";   
    test_op <= '0';
    wait for ESPERA;    
    assert test_r = "1001" and test_zcvn = "0101" 
    report "Fallo caso 10: 1101 + 1100 = 1001 // zcvn 1010" severity failure;

 -- Caso 11
    test_a <= "1101";
    test_b <= "1100";   
    test_op <= '1';
    wait for ESPERA;    
    assert test_r = "0001" and test_zcvn = "0000" 
    report "Fallo caso 11: 1101 - 1100 = 0001 // zcvn 0000" severity failure;

 -- Caso 12
    test_a <= "1101";
    test_b <= "1101";   
    test_op <= '0';
    wait for ESPERA;    
    assert test_r = "1010" and test_zcvn = "0101" 
    report "Fallo caso 12: 1101 + 1101 = 1010 // zcvn 0101" severity failure;

 -- Caso 13
    test_a <= "1101";
    test_b <= "1101";   
    test_op <= '1';
    wait for ESPERA;    
    assert test_r = "0000" and test_zcvn = "1000" 
    report "Fallo caso 13: 1101 - 1101 = 0000 // zcvn 1000" severity failure;

     -- fin
            assert false report "Simulacion OK!" severity note;
            wait;
    end process;

end;
------------------------------------------
-- 	Electrónica Digitaln				--
--  Grupo 7  --
--  A. Módulo Lógico (FuncLog_Nbits) TestBench --
------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

ENTITY FuncLog_Nbits_tb IS
END FuncLog_Nbits_tb;

architecture rtl of FuncLog_Nbits_tb is
    constant N : integer := 4;
    constant ESPERA : time := 1 ns;

	-- declaro componente bajo prueba
    component FuncLog_Nbits
    	generic (N: integer := 4);
    	port (
        a, b: in signed(N-1 downto 0);
        op: in std_logic;
        r: out signed(N-1 downto 0)
    );
end component;

	-- Entradas
    signal test_a : signed(N-1 downto 0) := "0000";
    signal test_b : signed(N-1 downto 0) := "0000";
    signal test_op : std_logic := '0';
    
    -- Salida
    signal test_r : signed(N-1 downto 0) := "0000";
    
begin
-- instancio la unidad bajo prueba -> unit under test
	uut: FuncLog_Nbits port map (
    	a => test_a,
        b => test_b, 
        op => test_op,
        r => test_r
        );
    
-- Genero vector de pruebas

	process
    begin
    
    -- caso 1
    test_a <= "0000";
    test_b <= "0000";
    test_op <= '0';
    wait for ESPERA;
    assert test_r = "0000" report "Fallo caso 01: 0000 AND 0000 = 0000" severity failure;

    -- caso 2
    test_a <= "0000";
    test_b <= "0000";
    test_op <= '1';
    wait for ESPERA;
    assert test_r = "0000" report "Fallo caso 2: 00000 OR 0000 = 0000" severity failure;

    -- caso 3
    test_a <= "0000";
    test_b <= "0001";
    test_op <= '0';
    wait for ESPERA;
    assert test_r = "0000" report "Fallo caso 3: 0000 AND 0001 = 0000" severity failure;

    -- caso 4
    test_a <= "0000";
    test_b <= "0001";
    test_op <= '1';
    wait for ESPERA;
    assert test_r = "0001" report "Fallo caso 4: 00000 OR 0001 = 0001" severity failure;

    -- caso 5
    test_a <= "0001";
    test_b <= "0001";
    test_op <= '0';
    wait for ESPERA;
    assert test_r = "0001" report "Fallo caso 5: 0001 AND 0001 = 0001" severity failure;

    -- caso 6
    test_a <= "0001";
    test_b <= "0001";
    test_op <= '1';
    wait for ESPERA;
    assert test_r = "0001" report "Fallo caso 6: 0001 OR 0001 = 0001" severity failure;

    -- caso 7
    test_a <= "1000";
    test_b <= "0000";
    test_op <= '0';
    wait for ESPERA;
    assert test_r = "0000" report "Fallo caso 7: 1000 AND 0000 = 0000" severity failure;

    -- caso 8
    test_a <= "1000";
    test_b <= "0000";
    test_op <= '1';
    wait for ESPERA;
    assert test_r = "1000" report "Fallo caso 8: 1000 OR 0000 = 1000" severity failure;

    -- fin
    assert false report "Simulacion OK!" severity note;
    wait;
end process;

end;

    
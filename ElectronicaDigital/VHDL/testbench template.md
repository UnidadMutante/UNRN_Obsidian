```
------------------------------------------
-- 	Electrónica Digital 				--
-- 	Ejercicio 2             		    --
--  Demux 1:4    			            --
------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

ENTITY test_Demux14 IS
END test_Demux14;
	
architecture Behavioral of test_Demux14 is 

	-- Declaro componente bajo prueba
    component Demux14
    port (
		Y : in std_logic;
        S : in std_logic_vector (1 downto 0);
		D:  out std_logic_vector (3 downto 0)
        );
        
    end component;
    
   -- Entradas
   signal test_Y : std_logic := '0';
   signal test_S : std_logic_vector(1 downto 0) := "00";

   -- Salidas
   signal test_D : std_logic_vector(3 downto 0) := "0000";

begin

   -- Instancio unidad bajo prueba (uut)
   uut: Demux14 port map (
          Y => test_Y,
          S => test_S,
          D => test_D
          );

  --Genero vector de pruebas
   process
   begin		

   	-- Caso 0
    test_Y  <= '0';
	test_S <= "--";
	wait for 1 ns;
	assert test_D = "0000" report "Fallo caso 0" severity
      failure;
	
    -- Caso 1
    test_Y  <= '1';
	test_S <= "00";
	wait for 1 ns;
	assert test_D = "0001" report "Fallo caso 1" severity
      failure;
      
	-- Caso 2
    test_Y  <= '1';
	test_S <= "01";
	wait for 1 ns;
	assert test_D = "0010" report "Fallo caso 2" severity
      failure;
      
	-- Caso 3
    test_Y <= '1';
	test_S <= "10";
	wait for 1 ns;
	assert test_D = "0100" report "Fallo caso 3" severity
      failure;
        
	-- Caso 4
    test_Y <= '1';
	test_S <= "11";
	wait for 1 ns;
	assert test_D = "1000" report "Fallo caso 4" severity
      failure;
     
	-- Fin de simulación
    assert false report "Simulacion termino OK" severity note;
	wait;
  end process;
end;

```
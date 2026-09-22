
```
------------------------------------------
-- 	Electrónica Digital 				--
-- 	Ejercicio 2             		    --
--  Demux 1:2    			            --
------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Demux12 is
	
	port (
		Y,S0: in std_logic;
		D0,D1:  out std_logic);
end Demux12;

architecture Behavioral of Demux12 is
begin

  D0 <= Y and (not S0);
  D1 <= Y and S0;

end Behavioral;
```


```
------------------------------------------
-- 	Electrónica Digital 				--
-- 	Ejercicio 2             		    --
--  Demux 1:4    			            --
------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Demux14 is
	port (
		Y: in std_logic;
        S: in std_logic_vector (1 downto 0);
		D: out std_logic_vector (3 downto 0)
        );
end Demux14;

architecture Behavioral of Demux14 is
signal signalY1, signalY2: std_logic; 
begin

-- instanciamos tres Demux 1:2
	demux12_0: entity  work.Demux12(Behavioral)
    port map ( Y =>Y, S0 => S(1),
    		   D0=> signalY1, D1=> signalY2);

	demux12_1: entity  work.Demux12(Behavioral)
    port map ( Y =>signalY1 ,S0 =>S(0),
    		   D0=> D(0), D1=> D(1));
               	
    demux12_2: entity  work.Demux12(Behavioral)
    port map ( Y =>signalY2 ,S0 => S(0),
    		   D0=> D(2), D1=> D(3));
               
end Behavioral;
```



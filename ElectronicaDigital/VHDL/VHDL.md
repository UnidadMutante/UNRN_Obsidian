![[Pasted image 20260907082749.png|328]]

![[Pasted image 20260907083003.png|647]]

### Demultiplexor en VHDL

![[Pasted image 20260907083032.png]]

![[Pasted image 20260907083237.png]]

![[Pasted image 20260907083304.png]]

demux de 4 bits

![[Pasted image 20260907083737.png]]

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

eL TEST bench es una entidad sin puertos
![[Pasted image 20260907084801.png]]

![[Pasted image 20260907085908.png]]

![[Pasted image 20260907085925.png]]


https://www.edaplayground.com/x/NzRH

A * !B + B* C

![[Pasted image 20260907093938.png]]


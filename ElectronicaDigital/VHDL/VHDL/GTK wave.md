```
ghdl -a --std=08 p5_ej6.vhd p5_ej6_tb.vhd
ghdl -e --std=08 p5_ej6_tb
ghdl -r --std=08 p5_ej6_tb --vcd=onda.vcd
gtkwave onda.vcd
```

videos de soporte
https://www.youtube.com/watch?v=H2GyAIYwZbw
https://www.youtube.com/watch?v=0JJku1vTu78

```
GHDL + GTKwave: commandos para simular mayor tiempo

ghdl -a --std=08 sumN.vhd  
ghdl -a --std=08 sumadorN2_tb.vhd  
ghdl -e --std=08 sumadorN2_tb  
ghdl -r --std=08 sumadorN2_tb --vcd=sumadorN.vcd
```
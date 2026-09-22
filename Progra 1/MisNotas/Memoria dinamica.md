![[Pasted image 20260915155703.png]]
# malloc

cuando escribiendo mi programa no se que tamaño va a tener mi dato
como se el tamaño que va a tener y necesito asignar dinamicamente
puedo escribir mi programa sin reservar memoria 
y puedo reciencuando se que tamaño tiene lo que necesito pido un vector de n bytes usando malloc

El tamaño que recibe malloc es en bytes
parametro size especifica la cantidad total de bytes a reservar

![[Pasted image 20260908163342.png]]

## calloc
le pide al sistema operativo memoria, lo recorre y le pone 0 en todos lados

![[Pasted image 20260908164328.png]]

## realloc

redimensiona el bloque de memoria
tengo que pasarle cual es el puntero que tengo que redimensionar
y le tengo que pedir el nuevo tamaño
![[Pasted image 20260908164643.png]]

### cálculo del tamaño del bloque
![[Pasted image 20260908165811.png]]

### Liberar la memoria

Es responsabilidad del programador liberar la memoria

![[Pasted image 20260908170138.png]]

![[Pasted image 20260908170336.png]]

dangling pointer -> el punter queda aputando a una direccion que ya no le corresponde. 
y si despues escribo en ese lugar de memoria, podria estaa sobre escribiendo algo que ya cprrespondia a otra cosa

![[Pasted image 20260908175121.png]]
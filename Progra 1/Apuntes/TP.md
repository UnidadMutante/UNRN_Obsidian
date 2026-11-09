# Posibles preguntas de defensa

Prepárate para responder:

### ¿Por qué `Contacto **contactos`?

Respuesta:

> Porque quiero modificar el puntero original que está en `main` después de hacer `malloc/realloc`.

---

### ¿Por qué usar memoria dinámica?

Respuesta:

> Porque no conocemos cuántos contactos tendrá la agenda. La memoria se reserva en tiempo de ejecución.

---

### ¿Por qué usaste archivo binario?

Respuesta:

> Porque permite guardar la estructura completa con `fwrite()` y recuperarla con `fread()` sin tener que parsear texto.

---

### ¿Por qué existe `tmp` antes de reasignar?

Respuesta:

> Para no perder el puntero original si `realloc()` falla.

---

### ¿Qué pasa cuando eliminás un contacto?

Respuesta:

> Se desplazan los elementos posteriores una posición hacia atrás y después se reescribe completamente el archivo.

### ¿Por qué usar memoria dinámica?

> Porque no conocemos la cantidad de contactos que tendrá la agenda al momento de compilar.

### ¿Por qué usar un archivo binario?

> Permite guardar estructuras completas utilizando `fwrite()` y recuperarlas con `fread()`.

### ¿Por qué usar `Contacto **contactos` en agregarContacto?

> Porque necesitamos modificar el puntero original después de realizar un `realloc()`.

### ¿Por qué existe el campo id?

> Facilita identificar y eliminar contactos de forma única.

### ¿Qué ocurre al eliminar?

> Se desplazan los elementos del arreglo y luego se reescribe completamente el archivo.
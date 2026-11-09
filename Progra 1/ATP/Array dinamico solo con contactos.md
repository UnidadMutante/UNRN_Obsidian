agenda.h

```
#ifndef AGENDA_H

#define AGENDA_H

#include <stddef.h>

#define MAX_CHARS 30

#define PHONE_LENGTH 17

typedef struct {

    int id;

    char nombre[MAX_CHARS];

    char telefono_main[PHONE_LENGTH];

    char telefono_alt[PHONE_LENGTH];

    char direccion[MAX_CHARS];

    char email[MAX_CHARS];

} Contacto;

void mostrarInstrucciones(void);

int cargarContactos(

    const char *nombreArchivo,

    Contacto **contactos,

    size_t *cantidad

);

int guardarContactos(

    const char *nombreArchivo,

    Contacto *contactos,

    size_t cantidad

);

int agregarContacto(

    Contacto **contactos,

    size_t *cantidad

);

void mostrarContactos(

    Contacto *contactos,

    size_t cantidad

);

void buscarContacto(

    Contacto *contactos,

    size_t cantidad,

    const char *nombre

);

int eliminarContacto(

    Contacto **contactos,

    size_t *cantidad,

    int id

);

#endif
```

agenda.c
```
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "agenda.h"

void mostrarInstrucciones(void)

{

    printf("Uso:\n");

    printf("./agenda datos.txt mostrar\n");

    printf("./agenda datos.txt agregar\n");

    printf("./agenda datos.txt buscar nombre\n");

    printf("./agenda datos.txt eliminar id\n");

}

int agregarContacto(

    Contacto **contactos,

    size_t *cantidad)

{

    Contacto nuevo;

    nuevo.id = (int)(*cantidad + 1);

    printf("Nombre: ");

    scanf("%29s", nuevo.nombre);

    printf("Telefono principal: ");

    scanf("%16s", nuevo.telefono_main);

    printf("Telefono alternativo: ");

    scanf("%16s", nuevo.telefono_alt);

    printf("Direccion: ");

    scanf("%29s", nuevo.direccion);

    printf("Email: ");

    scanf("%29s", nuevo.email);

    Contacto *tmp =

        realloc(

            *contactos,

            (*cantidad + 1) * sizeof(Contacto)

        );

    if (tmp == NULL)

        return 1;

    *contactos = tmp;

    (*contactos)[*cantidad] = nuevo;

    (*cantidad)++;

    return 0;

}

void mostrarContactos(

    Contacto *contactos,

    size_t cantidad)

{

    size_t i;

    for (i = 0; i < cantidad; i++)

    {

        printf("\n");

        printf("ID: %d\n", contactos[i].id);

        printf("Nombre: %s\n", contactos[i].nombre);

        printf("Telefono Principal: %s\n",

               contactos[i].telefono_main);

        printf("Telefono Alternativo: %s\n",

               contactos[i].telefono_alt);

        printf("Direccion: %s\n",

               contactos[i].direccion);

        printf("Email: %s\n",

               contactos[i].email);

    }

}

void buscarContacto(

    Contacto *contactos,

    size_t cantidad,

    const char *nombre)

{

    size_t i;

    int encontrado = 0;

    for (i = 0; i < cantidad; i++)

    {

        if (strcmp(contactos[i].nombre, nombre) == 0)

        {

            printf("ID: %d\n",

                   contactos[i].id);

            printf("Telefono: %s\n",

                   contactos[i].telefono_main);

            encontrado = 1;

        }

    }

    if (!encontrado)

    {

        printf("Contacto no encontrado.\n");

    }

}

int eliminarContacto(

    Contacto **contactos,

    size_t *cantidad,

    int id)

{

    size_t i;

    int encontrado = 0;

    for (i = 0; i < *cantidad; i++)

    {

        if ((*contactos)[i].id == id)

        {

            encontrado = 1;

            break;

        }

    }

    if (!encontrado)

        return 1;

    for (; i < *cantidad - 1; i++)

    {

        (*contactos)[i] =

            (*contactos)[i + 1];

    }

    (*cantidad)--;

    if (*cantidad == 0)

    {

        free(*contactos);

        *contactos = NULL;

        return 0;

    }

    Contacto *tmp =

        realloc(

            *contactos,

            (*cantidad) * sizeof(Contacto)

        );

    if (tmp != NULL)

        *contactos = tmp;

    return 0;

}

int guardarContactos(

    const char *nombreArchivo,

    Contacto *contactos,

    size_t cantidad)

{

    FILE *archivo =

        fopen(nombreArchivo, "w");

    if (archivo == NULL)

        return 1;

    size_t i;

    for (i = 0; i < cantidad; i++)

    {

        fprintf(

            archivo,

            "%d;%s;%s;%s;%s;%s\n",

            contactos[i].id,

            contactos[i].nombre,

            contactos[i].telefono_main,

            contactos[i].telefono_alt,

            contactos[i].direccion,

            contactos[i].email

        );

    }

    fclose(archivo);

    return 0;

}

int cargarContactos(

    const char *nombreArchivo,

    Contacto **contactos,

    size_t *cantidad)

{

    FILE *archivo =

        fopen(nombreArchivo, "r");

    if (archivo == NULL)

        return 0;

    Contacto aux;

    while (

        fscanf(

            archivo,

            "%d;%29[^;];%16[^;];%16[^;];%29[^;];%29[^\n]\n",

            &aux.id,

            aux.nombre,

            aux.telefono_main,

            aux.telefono_alt,

            aux.direccion,

            aux.email

        ) == 6

    )

    {

        Contacto *tmp =

            realloc(

                *contactos,

                (*cantidad + 1)

                * sizeof(Contacto)

            );

        if (tmp == NULL)

        {

            fclose(archivo);

            return 1;

        }

        *contactos = tmp;

        (*contactos)[*cantidad] = aux;

        (*cantidad)++;

    }

    fclose(archivo);

    return 0;

}
```

main.c
```
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "agenda.h"

int main(int argc, char *argv[])

{

    Contacto *contactos = NULL;

    size_t cantidad = 0;

    if (argc < 3)

    {

        mostrarInstrucciones();

        return 1;

    }

    cargarContactos(

        argv[1],

        &contactos,

        &cantidad

    );

    if (strcmp(argv[2], "mostrar") == 0)

    {

        mostrarContactos(

            contactos,

            cantidad

        );

    }

    else if (strcmp(argv[2], "agregar") == 0)

    {

        agregarContacto(

            &contactos,

            &cantidad

        );

        guardarContactos(

            argv[1],

            contactos,

            cantidad

        );

    }

    else if (

        strcmp(argv[2], "buscar") == 0

        && argc == 4)

    {

        buscarContacto(

            contactos,

            cantidad,

            argv[3]

        );

    }

    else if (

        strcmp(argv[2], "eliminar") == 0

        && argc == 4)

    {

        eliminarContacto(

            &contactos,

            &cantidad,

            atoi(argv[3])

        );

        guardarContactos(

            argv[1],

            contactos,

            cantidad

        );

    }

    else

    {

        mostrarInstrucciones();

    }

    free(contactos);

    return 0;

}
```
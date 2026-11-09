agenda.h

```
#ifndef AGENDA_H

#define AGENDA_H

#include <stddef.h>

#define MAX_CHARS 50

#define PHONE_LENGTH 20

typedef struct {

    int id;

    char nombre[MAX_CHARS];

    char telefono[PHONE_LENGTH];

    char direccion[MAX_CHARS];

    char email[MAX_CHARS];

} Contacto;

typedef struct {

    Contacto *contactos;

    size_t cantidad;

} Agenda;

void inicializarAgenda(Agenda *agenda);

void liberarAgenda(Agenda *agenda);

int cargarAgenda(Agenda *agenda, const char *archivo);

int guardarAgenda(const Agenda *agenda, const char *archivo);

void agregarContacto(Agenda *agenda);

void mostrarContactos(const Agenda *agenda);

void buscarContacto(const Agenda *agenda, const char *nombre);

void eliminarContacto(Agenda *agenda, int id);

void mostrarInstrucciones(void);

#endif
```

agenda.c

```
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "agenda.h"

void inicializarAgenda(Agenda *agenda)

{

    agenda->contactos = NULL;

    agenda->cantidad = 0;

}

void liberarAgenda(Agenda *agenda)

{

    free(agenda->contactos);

    agenda->contactos = NULL;

    agenda->cantidad = 0;

}

int cargarAgenda(Agenda *agenda, const char *archivoNombre)

{

    FILE *archivo = fopen(archivoNombre, "r");

    if (archivo == NULL)

        return 0;

    Contacto contacto;

    while (fscanf(

               archivo,

               "%d;%49[^;];%19[^;];%49[^;];%49[^\n]\n",

               &contacto.id,

               contacto.nombre,

               contacto.telefono,

               contacto.direccion,

               contacto.email) == 5)

    {

        Contacto *tmp =

            realloc(

                agenda->contactos,

                (agenda->cantidad + 1) * sizeof(Contacto));

        if (tmp == NULL)

        {

            fclose(archivo);

            return 1;

        }

        agenda->contactos = tmp;

        agenda->contactos[agenda->cantidad] = contacto;

        agenda->cantidad++;

    }

    fclose(archivo);

    return 0;

}

int guardarAgenda(const Agenda *agenda, const char *archivoNombre)

{

    FILE *archivo = fopen(archivoNombre, "w");

    if (archivo == NULL)

        return 1;

    for (size_t i = 0; i < agenda->cantidad; i++)

    {

        Contacto c = agenda->contactos[i];

        fprintf(

            archivo,

            "%d;%s;%s;%s;%s\n",

            c.id,

            c.nombre,

            c.telefono,

            c.direccion,

            c.email);

    }

    fclose(archivo);

    return 0;

}

void agregarContacto(Agenda *agenda)

{

    Contacto nuevo;

    printf("ID: ");

    scanf("%d", &nuevo.id);

    printf("Nombre: ");

    scanf("%49s", nuevo.nombre);

    printf("Telefono: ");

    scanf("%19s", nuevo.telefono);

    printf("Direccion: ");

    scanf("%49s", nuevo.direccion);

    printf("Email: ");

    scanf("%49s", nuevo.email);

    Contacto *tmp =

        realloc(

            agenda->contactos,

            (agenda->cantidad + 1) * sizeof(Contacto));

    if (tmp == NULL)

    {

        printf("Error reservando memoria.\n");

        return;

    }

    agenda->contactos = tmp;

    agenda->contactos[agenda->cantidad] = nuevo;

    agenda->cantidad++;

    printf("Contacto agregado.\n");

}

void mostrarContactos(const Agenda *agenda)

{

    if (agenda->cantidad == 0)

    {

        printf("No hay contactos.\n");

        return;

    }

    for (size_t i = 0; i < agenda->cantidad; i++)

    {

        Contacto c = agenda->contactos[i];

        printf("\n");

        printf("ID: %d\n", c.id);

        printf("Nombre: %s\n", c.nombre);

        printf("Telefono: %s\n", c.telefono);

        printf("Direccion: %s\n", c.direccion);

        printf("Email: %s\n", c.email);

    }

}

void buscarContacto(const Agenda *agenda, const char *nombre)

{

    int encontrado = 0;

    for (size_t i = 0; i < agenda->cantidad; i++)

    {

        if (strcmp(agenda->contactos[i].nombre, nombre) == 0)

        {

            Contacto c = agenda->contactos[i];

            printf("ID: %d\n", c.id);

            printf("Nombre: %s\n", c.nombre);

            printf("Telefono: %s\n", c.telefono);

            printf("Direccion: %s\n", c.direccion);

            printf("Email: %s\n", c.email);

            encontrado = 1;

        }

    }

    if (!encontrado)

        printf("Contacto no encontrado.\n");

}

void eliminarContacto(Agenda *agenda, int id)

{

    size_t indice = agenda->cantidad;

    for (size_t i = 0; i < agenda->cantidad; i++)

    {

        if (agenda->contactos[i].id == id)

        {

            indice = i;

            break;

        }

    }

    if (indice == agenda->cantidad)

    {

        printf("ID no encontrado.\n");

        return;

    }

    for (size_t i = indice; i < agenda->cantidad - 1; i++)

    {

        agenda->contactos[i] =

            agenda->contactos[i + 1];

    }

    agenda->cantidad--;

    if (agenda->cantidad == 0)

    {

        free(agenda->contactos);

        agenda->contactos = NULL;

    }

    else

    {

        agenda->contactos =

            realloc(

                agenda->contactos,

                agenda->cantidad * sizeof(Contacto));

    }

    printf("Contacto eliminado.\n");

}

void mostrarInstrucciones(void)

{

    printf("Uso:\n");

    printf("./agenda archivo.txt mostrar\n");

    printf("./agenda archivo.txt agregar\n");

    printf("./agenda archivo.txt buscar nombre\n");

    printf("./agenda archivo.txt eliminar id\n");

}
```

```
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "agenda.h"

int main(int argc, char *argv[])

{

    if (argc < 3)

    {

        mostrarInstrucciones();

        return 1;

    }

    Agenda agenda;

    inicializarAgenda(&agenda);

    cargarAgenda(&agenda, argv[1]);

    if (strcmp(argv[2], "mostrar") == 0)

    {

        mostrarContactos(&agenda);

    }

    else if (strcmp(argv[2], "agregar") == 0)

    {

        agregarContacto(&agenda);

        guardarAgenda(&agenda, argv[1]);

    }

    else if (strcmp(argv[2], "buscar") == 0)

    {

        if (argc != 4)

        {

            printf("Debe indicar un nombre.\n");

        }

        else

        {

            buscarContacto(&agenda, argv[3]);

        }

    }

    else if (strcmp(argv[2], "eliminar") == 0)

    {

        if (argc != 4)

        {

            printf("Debe indicar un ID.\n");

        }

        else

        {

            eliminarContacto(

                &agenda,

                atoi(argv[3]));

            guardarAgenda(

                &agenda,

                argv[1]);

        }

    }

    else

    {

        mostrarInstrucciones();

    }

    liberarAgenda(&agenda);

    return 0;

}
```
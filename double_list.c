#include <stdio.h>
#include <stdlib.h>
#include "double_list.h" //Este es el archivo que incluye las funciones con las funcionalidades del codigo

DoubleList* crear_lista() {
    // Asignar memoria para DoubleList
    DoubleList* lista = (DoubleList*)malloc(sizeof(DoubleList));
    if (!lista) {
        // Verificar si fallo la asignación de memoria
        fprintf(stderr, "Error: No se pudo asignar memoria para la lista.\n");
        exit(EXIT_FAILURE);
    }

    // Inicializar los punteros head y tail como NULL para que la lista este vacia
    lista->head = NULL;
    lista->tail = NULL;

    // Retornar el puntero a la lista creada
    return lista;
}
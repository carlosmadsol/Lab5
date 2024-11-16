#include <stdio.h>
#include <stdlib.h>
#include "double_list.h" // Incluir el encabezado con las definiciones

int main() {
    // Crear una nueva lista
    DoubleList* mi_lista = crear_lista();

    // Verificar si la lista se creó correctamente
    if (mi_lista != NULL && mi_lista->head == NULL && mi_lista->tail == NULL) {
        printf("¡La lista se creo correctamente y está vacia!\n");
    } else {
        printf("Error al crear la lista.\n");
    }

    // Liberar memoria asignada para la lista (aunque esta vacia)
    free(mi_lista);

    return 0;
}

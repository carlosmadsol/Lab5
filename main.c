#include <stdio.h>
#include "double_list.h"

int main() {
    // Crear una nueva lista
    DoubleList* miLista = crear_lista();

    // Insertar nodos al inicio
    pasar_al_inicio(miLista, 10);
    pasar_al_inicio(miLista, 20);
    pasar_al_inicio(miLista, 30);

    // Insertar nodos al final
    pasar_al_final(miLista, 40);
    pasar_al_final(miLista, 50);

    // Verificar la lista recorriéndola hacia adelante
    moverse_adelante(miLista);

    // Liberar la lista
    liberar_memoria(miLista);

    return 0;
}


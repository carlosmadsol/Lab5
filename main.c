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

    // Insertar nodos en un lugar especifico
    insertar_en_index(miLista, 2, 60);
    insertar_en_index(miLista, 4, 70);

    // Ver la lista recorriendola hacia adelante
    moverse_adelante(miLista);

    // Ver la lista recorriendola hacia atras
    moverse_atras(miLista);

    // Buscamos un nodo por su valor
    buscar_valor(miLista, 60);
    buscar_valor(miLista, 40);

    //Eliminamos un nodo
    borrar_valor(miLista, 50);

    // Liberar la lista
    liberar_memoria(miLista);

    return 0;
}


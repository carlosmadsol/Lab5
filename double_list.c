#include <stdio.h>
#include <stdlib.h>
#include "double_list.h" //Este es el archivo que incluye las funciones con las funcionalidades del codigo

DoubleList* crear_lista() {
    // Asignar memoria dinamica para DoubleList
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
void pasar_al_inicio(DoubleList* lista, int data) {
    // Verificar que la lista no sea NULL
    if (!lista) { //!list es el equivalente a list == NULL
        fprintf(stderr, "Error: La lista no está inicializada.\n");
        return;
    }

    // Crear un nuevo nodo y asignar a memoria dinamica
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo)); 
    if (!nuevo_nodo) { // Nos aseguramos que nuevo_nodo no sea NULL (o sea que no haya espacio en memoria)
        fprintf(stderr, "Error: No se pudo asignar memoria para el nodo.\n");
        return;
    }

    // Asignar datos al nuevo nodo
    nuevo_nodo->data = data;
    nuevo_nodo->prev = NULL; // Prev le asignamos NULL ya que este sera el primer nodo de la lista
    nuevo_nodo->next = lista->head; // Apuntamos a lista->head ya que este comando significa el primer nodo de la lista y queremos ir delante de el

    // Si la lista no estaba vacia, ajustamos el prev del nodo que estaba de primero para que apunte al nuevo nodo
    if (lista->head) {
        lista->head->prev = nuevo_nodo;
    }

    // Cambiamos el head de la lista para que apunte al nuevo nodo
    lista->head = nuevo_nodo;

    // Si la lista estaba vacia, apuntamos tail hacia el nuevo nodo ya que al estar vacia el nuevo nodo es el ultimo tambien
    if (!lista->tail) {
        lista->tail = nuevo_nodo;
    }

    printf("Nodo con valor %d puesto al inicio de la lista.\n", data);
}

/**
 * Recorre la lista desde el inicio hasta el final e imprime sus elementos.
 * @param list La lista doblemente enlazada.
 */
void moverse_adelante(DoubleList* lista) {
    // Verificar que la lista no sea NULL
    if (!lista) {
        fprintf(stderr, "Error: La lista no está inicializada.\n");
        return;
    }

    Nodo* current = lista->head; // Empezar en el head
    printf("Lista (hacia adelante): ");

    while (current) {
        printf("%d ", current->data); // Imprimir el dato del nodo actual
        current = current->next;     // Moverse al siguiente nodo
    }

    printf("\n");
}
void liberar_memoria(DoubleList* lista) {
    if (!lista) return;

    Nodo* current = lista->head;
    while (current) {
        Nodo* siguiente = current->next;
        free(current);
        current = siguiente;
    }

    free(lista);
    printf("Memoria liberada correctamente.\n");
}


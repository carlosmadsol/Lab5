#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

/**
 * Crea una nueva lista doblemente enlazada.
 * @return Puntero a la lista creada.
 */
DoubleList* crear_lista() {
    // Asignar memoria dinámica para DoubleList
    DoubleList* lista = (DoubleList*)malloc(sizeof(DoubleList));
    if (!lista) {
        fprintf(stderr, "Error: No se pudo asignar memoria para la lista.\n");
        exit(EXIT_FAILURE);
    }

    // Inicializar los punteros head y tail como NULL
    lista->head = NULL;
    lista->tail = NULL;

    return lista;
}

/**
 * Valida si una lista está inicializada.
 * @param lista Puntero a la lista a validar.
 * @return 1 si la lista está inicializada, 0 de lo contrario.
 */
int validar_lista(const DoubleList* lista) {
    if (!lista) {
        fprintf(stderr, "Error: La lista no está inicializada.\n");
        return 0;
    }
    return 1;
}

/**
 * Inserta un nodo con el valor dado al inicio de la lista.
 * @param lista La lista doblemente enlazada.
 * @param data El valor del nodo a insertar.
 */
void pasar_al_inicio(DoubleList* lista, int data) {
    if (!validar_lista(lista)) return;

    // Crear un nuevo nodo y asignar memoria
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo_nodo) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nodo.\n");
        return;
    }

    // Inicializar el nodo
    nuevo_nodo->data = data;
    nuevo_nodo->prev = NULL;
    nuevo_nodo->next = lista->head;

    // Ajustar punteros si la lista no está vacía
    if (lista->head) {
        lista->head->prev = nuevo_nodo;
    }

    lista->head = nuevo_nodo;

    // Si la lista estaba vacía, el nuevo nodo también es el último
    if (!lista->tail) {
        lista->tail = nuevo_nodo;
    }

    printf("Nodo con valor %d puesto al inicio de la lista.\n", data);
}

/**
 * Inserta un nodo con el valor dado al final de la lista.
 * @param lista La lista doblemente enlazada.
 * @param data El valor del nodo a insertar.
 */
void pasar_al_final(DoubleList* lista, int data) {
    if (!validar_lista(lista)) return;

    // Crear un nuevo nodo y asignar memoria
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo_nodo) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nodo.\n");
        return;
    }

    // Inicializar el nodo
    nuevo_nodo->data = data;
    nuevo_nodo->next = NULL;
    nuevo_nodo->prev = lista->tail;

    // Ajustar punteros si la lista no está vacía
    if (lista->tail) {
        lista->tail->next = nuevo_nodo;
    }

    lista->tail = nuevo_nodo;

    // Si la lista estaba vacía, el nuevo nodo también es el primero
    if (!lista->head) {
        lista->head = nuevo_nodo;
    }

    printf("Nodo con valor %d insertado al final de la lista.\n", data);
}

/**
 * Recorre la lista desde el inicio hasta el final e imprime sus elementos.
 * @param lista La lista doblemente enlazada.
 */
void moverse_adelante(DoubleList* lista) {
    if (!validar_lista(lista)) return;

    Nodo* current = lista->head;
    printf("Lista (hacia adelante): ");

    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

/**
 * Libera la memoria de todos los nodos de la lista y de la lista misma.
 * @param lista La lista doblemente enlazada.
 */
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

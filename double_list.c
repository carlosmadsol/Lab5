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

    // Asignamos tanto el head como el tail de la lista en NULL
    lista->head = NULL;
    lista->tail = NULL;

    return lista;
}

/**
 * Funciona si una lista está inicializada.
 * @param lista Puntero a la lista a validar.
 * @return 1 si la lista está inicializada, 0 de lo contrario.
 */
int validar_lista(const DoubleList* lista) {
    if (!lista) {
        fprintf(stderr, "Error: La lista no está inicializada.\n");
        return 0;
    }
    return 1;
} // Creamos esta funcion ya que es un codigo que vamos a repetir varias veces durante el laboratorio

Nodo* crear_nodo(int data) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo_nodo) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nodo.\n");
        return NULL;
    }

    // Inicializar valores del nodo
    nuevo_nodo->data = data;
    nuevo_nodo->prev = NULL;
    nuevo_nodo->next = NULL;

    return nuevo_nodo;
} // Lo creamos por que es un codigo que vamos a repetir varias veces

/**
 * Inserta un nodo con el valor dado al inicio de la lista.
 * @param lista La lista doblemente enlazada.
 * @param data El valor del nodo a insertar.
 */
void pasar_al_inicio(DoubleList* lista, int data) {
    if (!validar_lista(lista)) return;

    Nodo* nuevo_nodo = crear_nodo(data);
    if (!nuevo_nodo) return;

    nuevo_nodo->next = lista->head; // Apuntamos next a nuestro anterior nodo que estaba de primero

    // Si la lista no esta vacia asignamos el nuevo nodo como el prev del nodo que estaba primero
    if (lista->head) {
        lista->head->prev = nuevo_nodo;
    }

    lista->head = nuevo_nodo;

    // Si la lista esta vacia, el nuevo nodo es el último
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

    Nodo* nuevo_nodo = crear_nodo(data);
    if (!nuevo_nodo) return;

    nuevo_nodo->prev = lista->tail; // Apuntamos prev a nuestro anterior ultimo nodo

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

    while (current) { // Hacemos el bucle para el while y para movernos por la lista
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

/**
 * Recorre la lista desde el final hasta el inicio e imprime sus elementos.
 * @param lista La lista doblemente enlazada.
 */
void moverse_atras(DoubleList* lista) {
    if (!validar_lista(lista)) return;

    Nodo* current = lista->tail; // Empezar en el tail
    printf("Lista (hacia atrás): ");

    while (current) {
        printf("%d ", current->data); 
        current = current->prev;     
    } // La funcion funciona igual que la de moverse_adelante solo que usamos tail en lugar de head

    printf("\n");
}

/**
 * Inserta un nodo con el valor dado en una posición específica de la lista.
 * @param lista La lista doblemente enlazada donde se insertará el nodo.
 * @param index La posición donde se insertará el nodo (0 basado).
 * @param data El valor del nodo a insertar.
 */
void insertar_en_index(DoubleList* lista, int index, int data) {
    if (!validar_lista(lista)) return;

    // Si el índice es 0, insertar al inicio
    if (index == 0) {
        pasar_al_inicio(lista, data);
        return;
    }

    Nodo* nuevo_nodo = crear_nodo(data); // Usamos la función crear_nodo
    if (!nuevo_nodo) return;

    // Encontrar la posición en la lista
    Nodo* current = lista->head;
    int current_index = 0;

    while (current && current_index < index - 1) {
        current = current->next;
        current_index++;
    }

    // Verificar si el índice es válido
    if (!current) {
        fprintf(stderr, "Error: El índice %d está fuera de rango.\n", index);
        free(nuevo_nodo);
        return;
    }

    // Insertar el nodo en la posición encontrada
    nuevo_nodo->next = current->next;
    nuevo_nodo->prev = current;

    if (current->next) {
        current->next->prev = nuevo_nodo;
    }

    current->next = nuevo_nodo;

    // Si se insertó al final, actualizar tail
    if (nuevo_nodo->next == NULL) {
        lista->tail = nuevo_nodo;
    }

    printf("Nodo con valor %d insertado en la posición %d.\n", data, index);
}

/**
 * Libera la memoria de todos los nodos de la lista y de la lista misma.
 * @param lista La lista doblemente enlazada.
 */
void liberar_memoria(DoubleList* lista) {
    if (!lista) return;

    Nodo* current = lista->head; // Asignamos current como el primer nodo de la lista
    while (current) { // Empezamos el bucle, mientras current no sea NULL el while se seguira corriendo
        Nodo* siguiente = current->next; // Guardamos en un puntero el nodo al que le sigue current y lo llamamos siguiente
        free(current);
        current = siguiente; // Asignamos current como siguiente para asi en bucle ir eliminando uno por uno los nodos
    }

    free(lista);
    printf("Memoria liberada correctamente.\n");
}

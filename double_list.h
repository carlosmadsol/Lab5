#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct Nodo {
    int data;
    struct Nodo* prev;
    struct Nodo* next;
} Nodo; 

typedef struct DoubleList {
    Nodo* head;
    Nodo* tail; 
} DoubleList;

DoubleList* crear_lista();
void pasar_al_inicio(DoubleList* lista, int data);
void pasar_al_final(DoubleList* lista, int data);
void insertar_en_index(DoubleList* lista, int index, int data);
void borrar_valor(DoubleList* lista, int data);
Nodo* buscar_valor(DoubleList* lista, int data);
void moverse_adelante(DoubleList* lista);
void moverse_atras(DoubleList* lista);
void liberar_memoria(DoubleList* lista);

#endif 
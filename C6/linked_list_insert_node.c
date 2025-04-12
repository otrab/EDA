#include <stdlib.h>
#include <stdio.h>

// Este programa crea una lista enlazada con varios nodos, 
// inserta un nuevo nodo en una posición específica basada en una condición 
// y luego imprime los valores de los nodos.

// Definición de una estructura para un nodo de lista enlazada
struct node {
    int value;           // Campo de datos
    struct node *next;   // Puntero al siguiente nodo
};

int main(int argc, char* argv[]) {
    // Crear el primer nodo
    struct node *list = (struct node *)malloc(sizeof(struct node));
    list->value = 5;        // Asignar valor al primer nodo
    list->next = NULL;      // Terminar la lista enlazada

    // Crear el segundo nodo
    struct node *second = (struct node *)malloc(sizeof(struct node));
    second->value = 15;     // Asignar valor al segundo nodo
    list->next = second;
    second->next = NULL;

    // Crear el tercer nodo
    struct node *third = (struct node *)malloc(sizeof(struct node));
    third->value = 25;      // Asignar valor al tercer nodo
    second->next = third;
    third->next = NULL;

    // Crear un nuevo nodo e insertar en una posición específica
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = 40; // Asignar valor al nuevo nodo

    struct node *iterator = list;
    while (iterator->next != NULL && iterator->value < 20) {
        iterator = iterator->next;
    }
    struct node *tmp = iterator->next;
    iterator->next = new_node;
    new_node->next = tmp;

    // Imprimir los valores de los nodos
    struct node *temp = list;
    while (temp != NULL) {
        printf("%i\n", temp->value);
        temp = temp->next;
    }

    // Liberar la memoria asignada para evitar fugas de memoria
    free(new_node);
    free(third);
    free(second);
    free(list);

    return 0; // Indicar la terminación exitosa del programa
}
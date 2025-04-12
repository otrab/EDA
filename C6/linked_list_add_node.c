#include <stdlib.h>
#include <stdio.h>

// Este programa crea una lista enlazada con un nodo inicial, 
// agrega un nuevo nodo al final y luego imprime los valores de los nodos.

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

    // Crear un nuevo nodo y asignar valores
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = 100;  // Asignar valor al nuevo nodo

    // Recorrer la lista hasta el último nodo
    struct node *iterator = list;
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    // Agregar el nuevo nodo al final
    iterator->next = new_node;
    new_node->next = NULL;

    // Imprimir los valores de los nodos
    struct node *temp = list;
    while (temp != NULL) {
        printf("%i\n", temp->value);
        temp = temp->next;
    }

    // Liberar la memoria asignada para evitar fugas de memoria
    free(new_node);
    free(list);

    return 0; // Indicar la terminación exitosa del programa
}
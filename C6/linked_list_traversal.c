#include <stdlib.h> // Para malloc y NULL
#include <stdio.h>  // Para printf

// Este programa crea una lista enlazada con cuatro nodos, asigna valores a cada nodo, 
// imprime sus valores y libera la memoria asignada dinámicamente para evitar fugas.

// Definición de una estructura para un nodo de lista enlazada
struct node {
    int value;           // Campo de datos
    struct node *next;   // Puntero al siguiente nodo
};

int main(int argc, char* argv[]) {
    // Crear el primer nodo
    struct node *list = (struct node *)malloc(sizeof(struct node));
    list->value = 5; // Asignar valor al primer nodo

    // Crear el segundo nodo
    list->next = (struct node *)malloc(sizeof(struct node));
    list->next->value = 10; // Asignar valor al segundo nodo

    // Crear el tercer nodo
    list->next->next = (struct node *)malloc(sizeof(struct node));
    list->next->next->value = 15; // Asignar valor al tercer nodo

    // Crear el cuarto nodo
    list->next->next->next = (struct node *)malloc(sizeof(struct node));
    list->next->next->next->value = 20; // Asignar valor al cuarto nodo

    // Terminar la lista enlazada
    list->next->next->next->next = NULL;

    // Imprimir los valores de los nodos
    printf("%i\n", list->value);
    printf("%i\n", list->next->value);
    printf("%i\n", list->next->next->value);
    printf("%i\n", list->next->next->next->value);

    // Liberar la memoria asignada para evitar fugas de memoria
    free(list->next->next->next);
    free(list->next->next);
    free(list->next);
    free(list);

    return 0; // Indicar la terminación exitosa del programa
}
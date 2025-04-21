#include <stdlib.h>
#include <stdio.h>

// Definición de un nodo de lista enlazada
struct node {
    int value;          // Valor del nodo
    struct node *next;  // Puntero al siguiente nodo
};

// Función para insertar un nodo en la pila (push)
void push(struct node **stack, int value) {
    // Crear un nuevo nodo
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    // Asignar el valor al nuevo nodo
    new_node->value = value;

    // Insertar el nuevo nodo al inicio de la pila
    struct node *tmp = *stack;   // Guardar el nodo actual
    *stack = new_node;           // Actualizar el puntero de la pila al nuevo nodo
    new_node->next = tmp;        // Enlazar el nuevo nodo con el resto de la pila
}

int main() {
    struct node *stack = NULL; // Inicializar la pila vacía

    // Insertar elementos en la pila
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Imprimir y liberar los nodos de la pila
    while (stack != NULL) {
        printf("Cima de la pila: %d\n", stack->value);
        struct node *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}
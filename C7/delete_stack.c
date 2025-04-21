#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct node {
    int data;           // Dato almacenado en el nodo
    struct node *next;  // Puntero al siguiente nodo
};

// Función para eliminar el nodo superior de la pila (pop)
void pop(struct node **stack) {
    if (*stack == NULL) { // Si la pila está vacía
        printf("La pila está vacía.\n");
        return;
    }
    struct node *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

int main() {
    struct node *stack = NULL; // Inicializar la pila vacía

    // Crear manualmente algunos nodos para la pila
    struct node *node1 = malloc(sizeof(struct node));
    struct node *node2 = malloc(sizeof(struct node));
    struct node *node3 = malloc(sizeof(struct node));

    if (!node1 || !node2 || !node3) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    // Inicializar los nodos
    node1->data = 10; node1->next = node2;
    node2->data = 20; node2->next = node3;
    node3->data = 30; node3->next = NULL;

    // Configurar la pila
    stack = node1;

    // Imprimir estado inicial de la pila
    printf("Estado inicial de la pila:\n");
    struct node *current = stack;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Eliminar nodos de la pila
    printf("Eliminando nodos de la pila...\n");
    while (stack != NULL) {
        pop(&stack);
    }

    printf("Pila vacía.\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct node {
    int data; // Dato almacenado en el nodo
    struct node *next; // Puntero al siguiente nodo
};

// Función para verificar si la pila está vacía
int isEmpty(struct node *stack) {
    return stack == NULL;
}

// Función para insertar un nuevo elemento en la pila
void push(struct node **stack, int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = *stack;
    *stack = new_node;
}

// Función para eliminar el elemento superior de la pila
int pop(struct node **stack) {
    if (isEmpty(*stack)) {
        printf("Pila vacía. No se puede hacer pop.\n");
        return -1;
    }
    struct node *temp = *stack;
    int popped_value = temp->data;
    *stack = (*stack)->next;
    free(temp);
    return popped_value;
}

// Función para obtener el elemento superior de la pila sin eliminarlo
int peek(struct node *stack) {
    if (isEmpty(stack)) {
        printf("Pila vacía. No hay elementos para mostrar.\n");
        return -1;
    }
    return stack->data;
}

// Función para imprimir la pila
void print_stack(struct node *stack) {
    struct node *current = stack;
    printf("Pila: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *stack = NULL; // Inicializar la pila como vacía

    // Insertar elementos en la pila
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Estado de la pila después de las inserciones:\n");
    print_stack(stack);

    // Obtener el elemento superior
    printf("Elemento en la cima de la pila: %d\n", peek(stack));

    // Eliminar un elemento de la pila
    printf("Eliminando el elemento superior: %d\n", pop(&stack));
    printf("Estado de la pila después de hacer pop:\n");
    print_stack(stack);

    // Insertar un nuevo elemento en la pila
    printf("Insertando un nuevo elemento (40) en la pila...\n");
    push(&stack, 40);

    printf("Estado de la pila después de insertar 40:\n");
    print_stack(stack);

    // Liberar la memoria de los nodos
    while (!isEmpty(stack)) {
        pop(&stack);
    }

    printf("Pila vacía.\n");
    return 0;
}
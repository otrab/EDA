#include <stdlib.h>
#include <stdio.h>

// Definición de un nodo de lista enlazada
struct node {
    int value;          // Valor del nodo
    struct node *next;  // Puntero al siguiente nodo
};

// Función para insertar un nodo al final de la cola
void enqueue(struct node **front, struct node **rear, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node) {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        return;
    }
    new_node->value = value;
    new_node->next = NULL;

    if (*rear == NULL) { // Si la cola está vacía
        *front = *rear = new_node;
    } else {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

// Función para imprimir los valores de la cola
void print_queue(struct node *front) {
    while (front != NULL) {
        printf("Frente de la cola: %d\n", front->value);
        front = front->next;
    }
}

// Función para liberar la memoria de la cola
void free_queue(struct node *front) {
    while (front != NULL) {
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}

int main() {
    struct node *front = NULL, *rear = NULL; // Inicializar la cola vacía

    enqueue(&front, &rear, 100);
    enqueue(&front, &rear, 200);
    enqueue(&front, &rear, 300);

    print_queue(front); // Imprimir los valores de la cola
    free_queue(front);  // Liberar la memoria de la cola

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct node {
    int data;           // Dato almacenado en el nodo
    struct node *next;  // Puntero al siguiente nodo
};

// Función para verificar si la cola está vacía
int isEmpty(struct node *front) {
    return front == NULL;
}

// Función para insertar un nuevo elemento al final de la cola (enqueue)
void enqueue(struct node **front, struct node **rear, int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;

    if (*rear == NULL) { // Si la cola está vacía
        *front = *rear = new_node;
    } else {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

// Función para eliminar el elemento del frente de la cola (dequeue)
int dequeue(struct node **front, struct node **rear) {
    if (isEmpty(*front)) {
        printf("Cola vacía. No se puede hacer dequeue.\n");
        return -1;
    }
    struct node *temp = *front;
    int dequeued_value = temp->data;
    *front = (*front)->next;

    if (*front == NULL) { // Si la cola queda vacía
        *rear = NULL;
    }
    free(temp);
    return dequeued_value;
}

// Función para obtener el elemento del frente de la cola sin eliminarlo
int peek(struct node *front) {
    if (isEmpty(front)) {
        printf("Cola vacía. No hay elementos para mostrar.\n");
        return -1;
    }
    return front->data;
}

// Función para imprimir la cola
void print_queue(struct node *front) {
    struct node *current = front;
    printf("Cola: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *front = NULL, *rear = NULL; // Inicializar la cola como vacía

    // Insertar elementos en la cola
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    printf("Estado de la cola después de las inserciones:\n");
    print_queue(front);

    // Obtener el elemento del frente
    printf("Elemento en el frente de la cola: %d\n", peek(front));

    // Eliminar un elemento de la cola
    printf("Eliminando el elemento del frente: %d\n", dequeue(&front, &rear));
    printf("Estado de la cola después de hacer dequeue:\n");
    print_queue(front);

    // Insertar un nuevo elemento en la cola
    printf("Insertando un nuevo elemento (40) en la cola...\n");
    enqueue(&front, &rear, 40);

    printf("Estado de la cola después de insertar 40:\n");
    print_queue(front);

    // Liberar la memoria de los nodos
    while (!isEmpty(front)) {
        dequeue(&front, &rear);
    }

    printf("Cola vacía.\n");
    return 0;
}
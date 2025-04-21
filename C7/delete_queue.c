#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct node {
    int data;           // Dato almacenado en el nodo
    struct node *next;  // Puntero al siguiente nodo
};

// Función para eliminar el nodo del frente de la cola (dequeue)
void dequeue(struct node **front, struct node **rear) {
    if (*front == NULL) { // Si la cola está vacía
        printf("La cola está vacía.\n");
        return;
    }
    struct node *temp = *front;
    *front = (*front)->next;

    if (*front == NULL) { // Si la cola queda vacía
        *rear = NULL;
    }
    free(temp);
}

int main() {
    struct node *front = NULL, *rear = NULL; // Inicializar la cola vacía

    // Crear manualmente algunos nodos para la cola
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

    // Configurar el frente y el final de la cola
    front = node1;
    rear = node3;

    // Imprimir estado inicial de la cola
    printf("Estado inicial de la cola:\n");
    struct node *current = front;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Eliminar nodos de la cola
    printf("Eliminando nodos de la cola...\n");
    while (front != NULL) {
        dequeue(&front, &rear);
    }

    printf("Cola vacía.\n");
    return 0;
}
#include <stdlib.h>
#include <stdio.h>

// Definición de un nodo de lista enlazada
struct node {
    int value;          // Valor del nodo
    struct node *next;  // Puntero al siguiente nodo
};

int main() {
    struct node *front = malloc(sizeof(struct node)); // Crear nodo inicial (frente de la cola)
    if (!front) { // Verificar asignación de memoria
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        return 1;
    }

    front->value = 5;    // Asignar valor
    front->next = NULL;  // No hay siguiente nodo

    struct node *rear = front; // Inicialmente, frente y final apuntan al mismo nodo

    printf("Frente de la cola: %i\n", front->value); // Imprimir valor del frente

    free(front); // Liberar memoria
    return 0;
}
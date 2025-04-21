#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct node {
    int value;          // Valor del nodo
    struct node *next;  // Puntero al siguiente nodo
};

// Función para recorrer e imprimir los valores de una estructura (pila o cola)
void traverse(struct node *start) {
    printf("Elementos:\n");
    while (start != NULL) {
        printf("%d\n", start->value);
        start = start->next;
    }
}

int main() {
    // Crear manualmente algunos nodos
    struct node *start = malloc(sizeof(struct node)); // Puede ser la cima de la pila o el frente de la cola
    struct node *node2 = malloc(sizeof(struct node));
    struct node *node3 = malloc(sizeof(struct node));

    if (!start || !node2 || !node3) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    // Inicializar los nodos
    start->value = 10; start->next = node2;
    node2->value = 20; node2->next = node3;
    node3->value = 30; node3->next = NULL;

    // Recorrer e imprimir los valores
    traverse(start);

    // Liberar memoria
    free(start);
    free(node2);
    free(node3);

    return 0;
}
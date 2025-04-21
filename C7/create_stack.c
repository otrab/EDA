#include <stdlib.h>
#include <stdio.h>

// Definición de un nodo de lista enlazada
struct node {
    int value;          // Valor del nodo
    struct node *next;  // Puntero al siguiente nodo
};

int main() {
    struct node *top = malloc(sizeof(struct node)); // Crear nodo inicial (cima de la pila)
    if (!top) { // Verificar asignación de memoria
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        return 1;
    }

    top->value = 5;    // Asignar valor
    top->next = NULL;  // No hay siguiente nodo

    printf("Cima de la pila: %i\n", top->value); // Imprimir valor de la cima

    free(top); // Liberar memoria
    return 0;
}
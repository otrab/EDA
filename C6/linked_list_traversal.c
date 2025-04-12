#include <stdlib.h> // Para malloc y NULL
#include <stdio.h>  // Para printf

// Este programa crea una lista enlazada con cuatro nodos, asigna valores a cada nodo, 
// imprime sus valores y libera la memoria asignada dinámicamente para evitar fugas.

// Definición de una estructura para un nodo de lista enlazada
struct n {
    int x;           // Campo de datos
    struct n *next;  // Puntero al siguiente nodo
};

int main(int argc, char* argv[]) {
    // Crear el primer nodo
    struct n *lista = (struct n *)malloc(sizeof(struct n));
    lista->x = 5; // Asignar valor al primer nodo

    // Crear el segundo nodo
    lista->next = (struct n *)malloc(sizeof(struct n));
    lista->next->x = 10; // Asignar valor al segundo nodo

    // Crear el tercer nodo
    lista->next->next = (struct n *)malloc(sizeof(struct n));
    lista->next->next->x = 15; // Asignar valor al tercer nodo

    // Crear el cuarto nodo
    lista->next->next->next = (struct n *)malloc(sizeof(struct n));
    lista->next->next->next->x = 20; // Asignar valor al cuarto nodo

    // Terminar la lista enlazada
    lista->next->next->next->next = NULL;

    // Imprimir los valores de los nodos
    printf("%i\n", lista->x);
    printf("%i\n", lista->next->x);
    printf("%i\n", lista->next->next->x);
    printf("%i\n", lista->next->next->next->x);

    // Liberar la memoria asignada para evitar fugas de memoria
    free(lista->next->next->next);
    free(lista->next->next);
    free(lista->next);
    free(lista);

    return 0; // Indicar la terminación exitosa del programa
}
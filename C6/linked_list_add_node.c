#include <stdlib.h>
#include <stdio.h>

// Este programa crea una lista enlazada con un nodo inicial, 
// agrega un nuevo nodo al final y luego imprime los valores de los nodos.

// Definición de una estructura para un nodo de lista enlazada
struct n {
    int x;           // Campo de datos
    struct n *next;  // Puntero al siguiente nodo
};

int main(int argc, char* argv[]) {
    // Crear el primer nodo
    struct n *lista = (struct n *)malloc(sizeof(struct n));
    lista->x = 5;        // Asignar valor al primer nodo
    lista->next = NULL;  // Terminar la lista enlazada

    // Crear un nuevo nodo y asignar valores
    struct n *nuevo_elemento = (struct n *)malloc(sizeof(struct n));
    nuevo_elemento->x = 100; // Asignar valor al nuevo nodo

    // Recorrer la lista hasta el último nodo
    struct n *it2 = lista;
    while (it2->next != NULL) {
        it2 = it2->next;
    }
    // Agregar el nuevo nodo al final
    it2->next = nuevo_elemento;
    nuevo_elemento->next = NULL;

    // Imprimir los valores de los nodos
    struct n *temp = lista;
    while (temp != NULL) {
        printf("%i\n", temp->x);
        temp = temp->next;
    }

    // Liberar la memoria asignada para evitar fugas de memoria
    free(nuevo_elemento);
    free(lista);

    return 0; // Indicar la terminación exitosa del programa
}
#include <stdlib.h>
#include <stdio.h>

// Este programa crea una lista enlazada con varios nodos, 
// inserta un nuevo nodo en una posición específica basada en una condición 
// y luego imprime los valores de los nodos.

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

    // Crear el segundo nodo
    struct n *segundo = (struct n *)malloc(sizeof(struct n));
    segundo->x = 15;     // Asignar valor al segundo nodo
    lista->next = segundo;
    segundo->next = NULL;

    // Crear el tercer nodo
    struct n *tercero = (struct n *)malloc(sizeof(struct n));
    tercero->x = 25;     // Asignar valor al tercer nodo
    segundo->next = tercero;
    tercero->next = NULL;

    // Crear un nuevo nodo e insertar en una posición específica
    struct n *nuevo_elemento3 = (struct n *)malloc(sizeof(struct n));
    nuevo_elemento3->x = 40; // Asignar valor al nuevo nodo

    struct n *it3 = lista;
    while (it3->next != NULL && it3->x < 20) {
        it3 = it3->next;
    }
    struct n *tmp = it3->next;
    it3->next = nuevo_elemento3;
    nuevo_elemento3->next = tmp;

    // Imprimir los valores de los nodos
    struct n *temp = lista;
    while (temp != NULL) {
        printf("%i\n", temp->x);
        temp = temp->next;
    }

    // Liberar la memoria asignada para evitar fugas de memoria
    free(nuevo_elemento3);
    free(tercero);
    free(segundo);
    free(lista);

    return 0; // Indicar la terminación exitosa del programa
}
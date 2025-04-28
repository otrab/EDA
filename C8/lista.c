/*
Pseudocódigo:

1. Crear un nuevo nodo con el valor proporcionado.
2. Si la lista está vacía:
   - Asignar el nuevo nodo como el primer nodo.
   - Establecer los punteros `next` y `prev` del nuevo nodo a NULL.
3. Si el valor del nuevo nodo es menor o igual al valor del primer nodo:
   - Insertar el nuevo nodo al principio.
   - Actualizar el puntero `prev` del nodo que era el primero.
4. Si no:
   - Recorrer la lista hasta encontrar la posición correcta (donde el valor del siguiente nodo sea mayor o igual al valor del nuevo nodo).
   - Insertar el nuevo nodo en esa posición:
       - Actualizar los punteros `next` y `prev` del nuevo nodo.
       - Actualizar los punteros `next` y `prev` de los nodos adyacentes.
*/

#include <stdio.h>
#include <stdlib.h>

// Definición de un nodo para una lista doblemente enlazada
typedef struct Nodo {
    int valor;           // Valor del nodo
    struct Nodo* siguiente; // Puntero al siguiente nodo
    struct Nodo* anterior;  // Puntero al nodo anterior
} Nodo;

// Función para insertar un nodo en orden ascendente
void insertarEnOrden(Nodo** lista, int valor) {
    // Crear un nuevo nodo
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;

    // Caso 1: La lista está vacía
    if (*lista == NULL) {
        *lista = nuevoNodo;
        return;
    }

    // Caso 2: El nuevo nodo debe ir al principio
    if ((*lista)->valor >= valor) {
        nuevoNodo->siguiente = *lista;
        (*lista)->anterior = nuevoNodo;
        *lista = nuevoNodo;
        return;
    }

    // Caso 3: Buscar la posición correcta para insertar el nuevo nodo
    Nodo* actual = *lista;
    while (actual->siguiente != NULL && actual->siguiente->valor < valor) {
        actual = actual->siguiente;
    }

    // Insertar el nuevo nodo en la posición encontrada
    nuevoNodo->siguiente = actual->siguiente;
    nuevoNodo->anterior = actual;
    if (actual->siguiente != NULL) {
        actual->siguiente->anterior = nuevoNodo;
    }
    actual->siguiente = nuevoNodo;
}

// Función para imprimir los valores de la lista
void imprimirLista(Nodo* lista) {
    printf("Lista: ");
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->siguiente;
    }
    printf("\n");
}

// Función para liberar la memoria de la lista
void liberarLista(Nodo* lista) {
    while (lista != NULL) {
        Nodo* temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
}

int main() {
    Nodo* lista = NULL; // Inicializar la lista como vacía

    // Insertar valores en la lista
    insertarEnOrden(&lista, 30);
    insertarEnOrden(&lista, 20);
    insertarEnOrden(&lista, 10);
    insertarEnOrden(&lista, 25);
    insertarEnOrden(&lista, 5);

    // Imprimir la lista
    imprimirLista(lista);

    // Liberar la memoria de la lista
    liberarLista(lista);

    return 0;
}

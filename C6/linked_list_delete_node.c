#include <stdlib.h>
#include <stdio.h>

// Este programa crea una lista enlazada con varios nodos, 
// imprime la lista antes y después de eliminar el nodo con el valor 22.

// Definición de una estructura para un nodo de lista enlazada
struct n {
    int x;           // Campo de datos
    struct n *next;  // Puntero al siguiente nodo
};

// Función para imprimir los valores de la lista enlazada
void imprimir_lista(struct n *lista) {
    struct n *temp = lista;
    while (temp != NULL) {
        printf("%i -> ", temp->x);
        temp = temp->next;
    }
    printf("NULL\n");
}

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
    tercero->x = 22;     // Asignar valor al tercer nodo
    segundo->next = tercero;
    tercero->next = NULL;

    // Crear el cuarto nodo
    struct n *cuarto = (struct n *)malloc(sizeof(struct n));
    cuarto->x = 30;      // Asignar valor al cuarto nodo
    tercero->next = cuarto;
    cuarto->next = NULL;

    // Imprimir la lista antes de eliminar el nodo
    printf("Lista antes de eliminar el nodo con valor 22:\n");
    imprimir_lista(lista);

    // Eliminar el nodo con valor 22
    struct n *it4 = lista;
    while (it4->next != NULL && it4->next->x != 22) {
        it4 = it4->next;
    }
    if (it4->next != NULL) { // Verificar si el nodo con valor 22 fue encontrado
        struct n *tmp = it4->next->next; // Guardar el puntero al nodo siguiente al nodo que será eliminado
        free(it4->next); // Liberar la memoria del nodo eliminado
        it4->next = tmp; // Ajustar el puntero del nodo anterior
    }

    // Imprimir la lista después de eliminar el nodo
    printf("Lista después de eliminar el nodo con valor 22:\n");
    imprimir_lista(lista);

    // Liberar la memoria asignada para evitar fugas de memoria
    free(cuarto);
    free(segundo);
    free(lista);

    return 0; // Indicar la terminación exitosa del programa
}
#include <stdlib.h> // Para malloc y NULL
#include <stdio.h>  // Para printf

// Definición de una estructura para un nodo de lista enlazada
struct n {
    int x;           // Campo de datos
    struct n *next;  // Puntero al siguiente nodo
};

int main(int argc, char* argv[]) {
    // Asignar memoria dinámicamente para un único nodo
    struct n *lista = (struct n *)malloc(sizeof(struct n));
    
    // Asignar valores al nodo
    lista->x = 5;        // Establecer el campo de datos en 5
    lista->next = NULL;  // Establecer el puntero al siguiente nodo como NULL (fin de la lista)
    
    // Imprimir el valor del campo de datos
    printf("%i\n", lista->x);
    
    // Liberar la memoria asignada para evitar fugas de memoria
    free(lista);

    return 0; // Indicar la terminación exitosa del programa
}
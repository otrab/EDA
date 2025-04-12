#include <stdlib.h> // Para malloc y NULL
#include <stdio.h>  // Para printf

// Definición de una estructura para un nodo de lista enlazada
struct node {
    int value;           // Campo de datos
    struct node *next;   // Puntero al siguiente nodo
};

int main(int argc, char* argv[]) {
    // Asignar memoria dinámicamente para un único nodo
    struct node *list = (struct node *)malloc(sizeof(struct node));
    
    // Asignar valores al nodo
    list->value = 5;        // Establecer el campo de datos en 5
    list->next = NULL;      // Establecer el puntero al siguiente nodo como NULL (fin de la lista)
    
    // Imprimir el valor del campo de datos
    printf("%i\n", list->value);
    
    // Liberar la memoria asignada para evitar fugas de memoria
    free(list);

    return 0; // Indicar la terminación exitosa del programa
}
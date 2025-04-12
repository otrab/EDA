#include <stdlib.h>
#include <stdio.h>

// Este programa crea una lista enlazada con varios nodos, 
// imprime la lista antes y después de eliminar el nodo con el valor 22.

// Definición de una estructura para un nodo de lista enlazada
struct node {
    int value;           // Campo de datos
    struct node *next;   // Puntero al siguiente nodo
};

// Función para imprimir los valores de la lista enlazada
void print_list(struct node *list) {
    struct node *temp = list;
    while (temp != NULL) {
        printf("%i -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char* argv[]) {
    // Crear el primer nodo
    struct node *list = (struct node *)malloc(sizeof(struct node));
    list->value = 5;        // Asignar valor al primer nodo
    list->next = NULL;      // Terminar la lista enlazada

    // Crear el segundo nodo
    struct node *second = (struct node *)malloc(sizeof(struct node));
    second->value = 15;     // Asignar valor al segundo nodo
    list->next = second;
    second->next = NULL;

    // Crear el tercer nodo
    struct node *third = (struct node *)malloc(sizeof(struct node));
    third->value = 22;      // Asignar valor al tercer nodo
    second->next = third;
    third->next = NULL;

    // Crear el cuarto nodo
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    fourth->value = 30;     // Asignar valor al cuarto nodo
    third->next = fourth;
    fourth->next = NULL;

    // Imprimir la lista antes de eliminar el nodo
    printf("Lista antes de eliminar el nodo con valor 22:\n");
    print_list(list);

    // Eliminar el nodo con valor 22
    struct node *current = list;
    while (current->next != NULL && current->next->value != 22) {
        current = current->next;
    }
    if (current->next != NULL) { // Verificar si el nodo con valor 22 fue encontrado
        struct node *tmp = current->next->next; // Guardar el puntero al nodo siguiente al nodo que será eliminado
        free(current->next); // Liberar la memoria del nodo eliminado
        current->next = tmp; // Ajustar el puntero del nodo anterior
    }

    // Imprimir la lista después de eliminar el nodo
    printf("Lista después de eliminar el nodo con valor 22:\n");
    print_list(list);

    // Liberar la memoria asignada para evitar fugas de memoria
    free(fourth);
    free(second);
    free(list);

    return 0; // Indicar la terminación exitosa del programa
}
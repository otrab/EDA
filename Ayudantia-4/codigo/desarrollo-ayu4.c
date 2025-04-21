#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int x; // valor del nodo.
    struct n *next; // puntero que apunta al siguiente nodo.
} nodo;

void insertar_elemento(nodo **ref_lista, int valor) {
    // Caso en que la lista esté vacía.
    if (*ref_lista == NULL) {
        nodo *nuevo_nodo = (nodo *)malloc(sizeof(nodo));
        nuevo_nodo->x = valor;
        nuevo_nodo->next = NULL;
        *ref_lista = nuevo_nodo;
    } else {
        nodo *it = *ref_lista;
        while (it->next != NULL) {
            it = it->next;
        }
        nodo *nuevo_nodo = (nodo *)malloc(sizeof(nodo));
        nuevo_nodo->x = valor;
        nuevo_nodo->next = NULL;
        it->next = nuevo_nodo;
    }
}

void imprimir_lista(nodo *lista) {
    nodo *it = lista;
    while(it != NULL) {
        printf("%d ", it->x);
        it = it->next;
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    nodo *lista = NULL;
    int elementos[12] = {3,78,4,8,2,98,55,32,67,12,11,20};
    int largo = 12;

    for (int i = 0; i < largo; i++) {
        insertar_elemento(&lista, elementos[i]);
    }

    imprimir_lista(lista);

    insertar_elemento(&lista, 15);

    imprimir_lista(lista);
}
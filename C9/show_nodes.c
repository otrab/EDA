#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Función para mostrar los nodos del árbol en orden
void show_nodes(struct node *root) {
    if (root->left != NULL) {
        show_nodes(root->left); // Recorrer el subárbol izquierdo
    }
    printf("%i ", root->data); // Imprimir el valor del nodo actual
    if (root->right != NULL) {
        show_nodes(root->right); // Recorrer el subárbol derecho
    }
}

int main() {
    // Crear el nodo raíz
    struct node *tmp = malloc(sizeof(struct node));
    tmp->data = 0; // Asignar valor al nodo raíz
    tmp->left = NULL;
    tmp->right = NULL;

    struct node *root = tmp; // Asignar el nodo raíz

    // Crear el hijo izquierdo
    tmp = malloc(sizeof(struct node));
    tmp->data = 2; // Asignar valor al hijo izquierdo
    tmp->left = NULL;
    tmp->right = NULL;
    root->left = tmp; // Conectar el hijo izquierdo al nodo raíz

    // Crear el hijo derecho
    tmp = malloc(sizeof(struct node));
    tmp->data = 7; // Asignar valor al hijo derecho
    tmp->left = NULL;
    tmp->right = NULL;
    root->right = tmp; // Conectar el hijo derecho al nodo raíz

    // Mostrar los valores del árbol
    printf("Nodos del árbol en orden: ");
    show_nodes(root);
    printf("\n");

    // Liberar la memoria
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
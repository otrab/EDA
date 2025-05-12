#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Función para crear un nuevo nodo
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Función para insertar un nodo en el árbol binario de búsqueda
struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data); // Crear un nuevo nodo si el árbol está vacío
    if (data < node->data)
        node->left = insert(node->left, data); // Insertar en el subárbol izquierdo
    else if (data > node->data)
        node->right = insert(node->right, data); // Insertar en el subárbol derecho
    return node;
}

// Función para mostrar los nodos del árbol en orden (in-order traversal)
void show_nodes(struct node *root) {
    if (root != NULL) {
        show_nodes(root->left); // Recorrer el subárbol izquierdo
        printf("%d ", root->data); // Imprimir el valor del nodo actual
        show_nodes(root->right); // Recorrer el subárbol derecho
    }
}

int main() {
    struct node *root = NULL; // Inicializar el árbol como vacío

    // Insertar valores en el árbol
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);

    // Mostrar los valores del árbol en orden
    printf("Nodos del árbol en orden: ");
    show_nodes(root);
    printf("\n");

    // Liberar la memoria (opcional, no implementado aquí para simplicidad)

    return 0;
}
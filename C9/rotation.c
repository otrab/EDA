#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};

// Función para crear un nuevo nodo
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1; // Altura inicial del nodo
    return temp;
}

// Función para obtener el máximo entre dos números
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función para calcular la altura de un nodo
int height(struct node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

// Función para realizar una rotación a la derecha
struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *z = x->right;

    // Realizar la rotación
    x->right = y;
    y->left = z;

    // Actualizar las alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Devolver la nueva raíz
    return x;
}

// Función para imprimir el árbol en in-order
void inOrder(struct node *root) {
    if (root != NULL) {
        inOrder(root->left);       // Recorrer el subárbol izquierdo
        printf("%d ", root->data); // Imprimir el valor del nodo actual
        inOrder(root->right);      // Recorrer el subárbol derecho
    }
}

// Función para imprimir el árbol en pre-order
void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data); // Imprimir el valor del nodo actual
        preOrder(root->left);      // Recorrer el subárbol izquierdo
        preOrder(root->right);     // Recorrer el subárbol derecho
    }
}

int main() {
    // Crear un árbol desbalanceado hacia la izquierda
    struct node *root = newNode(30);
    root->left = newNode(20);
    root->left->left = newNode(10);

    printf("Árbol antes de la rotación a la derecha (pre-order):\n");
    preOrder(root);
    printf("\n");

    // Realizar una rotación a la derecha
    root = rightRotate(root);

    printf("Árbol después de la rotación a la derecha (pre-order):\n");
    preOrder(root);
    printf("\n");

    return 0;
}

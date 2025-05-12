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

// Función para realizar una rotación a la derecha
struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(y->left ? y->left->height : 0, y->right ? y->right->height : 0) + 1;
    x->height = max(x->left ? x->left->height : 0, x->right ? x->right->height : 0) + 1;

    return x;
}

// Función para realizar una rotación a la izquierda
struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *z = y->left;

    y->left = x;
    x->right = z;

    y->height = max(y->left ? y->left->height : 0, y->right ? y->right->height : 0) + 1;
    x->height = max(x->left ? x->left->height : 0, x->right ? x->right->height : 0) + 1;

    return y;
}

// Función para imprimir el árbol en in-order
void inOrder(struct node *root) {
    if (root != NULL) {
        inOrder(root->left);       // Recorrer el subárbol izquierdo
        printf("%d ", root->data); // Imprimir el valor del nodo actual
        inOrder(root->right);      // Recorrer el subárbol derecho
    }
}

int main() {
    // Crear un árbol desbalanceado hacia la izquierda para demostrar la rotación a la derecha
    struct node *root = newNode(50);
    root->left = newNode(30);
    root->left->left = newNode(10);
    root->left->right = newNode(40);

    printf("Árbol antes de la rotación a la derecha (in-order):\n");
    inOrder(root);
    printf("\n");

    // Realizar una rotación a la derecha
    root = rightRotate(root);

    printf("Árbol después de la rotación a la derecha (in-order):\n");
    inOrder(root);
    printf("\n");

    // Crear un árbol desbalanceado hacia la derecha para demostrar la rotación a la izquierda
    root = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(20);
    root->right->right = newNode(40);

    printf("Árbol antes de la rotación a la izquierda (in-order):\n");
    inOrder(root);
    printf("\n");

    // Realizar una rotación a la izquierda
    root = leftRotate(root);

    printf("Árbol después de la rotación a la izquierda (in-order):\n");
    inOrder(root);
    printf("\n");

    return 0;
}

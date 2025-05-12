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

// Función para realizar una rotación a la izquierda
struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *z = y->left;

    // Realizar la rotación
    y->left = x;
    x->right = z;

    // Actualizar las alturas
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Devolver la nueva raíz
    return y;
}

// Función para insertar un nodo en el árbol AVL
struct node* insert(struct node* node, int data) {
    // Paso 1: Realizar la inserción normal en un árbol binario de búsqueda
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // No se permiten duplicados

    // Paso 2: Actualizar la altura del nodo actual
    node->height = 1 + max(height(node->left), height(node->right));

    // Paso 3: Calcular el factor de balance
    int balance = height(node->left) - height(node->right);

    // Paso 4: Balancear el árbol si está desbalanceado

    // Caso 1: Rotación a la derecha (Left-Left)
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Caso 2: Rotación a la izquierda (Right-Right)
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Caso 3: Rotación izquierda-derecha (Left-Right)
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso 4: Rotación derecha-izquierda (Right-Left)
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Función para imprimir el árbol en pre-order
void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct node *root = NULL;

    // Insertar nodos en el árbol AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Imprimir el árbol en pre-order
    printf("Árbol AVL en pre-order después de las inserciones:\n");
    preOrder(root);
    printf("\n");

    return 0;
}
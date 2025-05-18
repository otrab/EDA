#include <stdio.h>
#include <stdlib.h>

// Estructura para árboles binarios
typedef struct n {
    int data;
    struct n *left;
    struct n *right;
} nodo;

// Inserta del dato 'data' al árbol binario de búsqueda
// retorna la nueva raíz del árbol
nodo* insert(nodo* node, int data) {
    // Caso árbol vacío
    if (node == NULL) {
        nodo *tmp = (nodo *)malloc(sizeof(nodo));
        tmp->data = data;
        tmp->left = NULL;
        tmp->right = NULL;

        return tmp;
    }

    // Caso en que el árbol no es vacío. En este caso la raíz es la misma,
    // por eso hacemos 'return node;' al final.
    // Llamamos recursivamente al método insert, ya sea al lado izquierdo o derecho.
    // Actualizamos el hijo correspondiente con la nueva raíz obtenida
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }

    return node;
}

// Orden inorder (I, R, D)
void inorder(nodo *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Orden preorder (R, I, D)
void preorder(nodo *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Orden postorder (I, D, R)
void postorder(nodo *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Función para obtener el valor mínimo. Se asume que el árbol no es vacío
int minValueNode(nodo *node) {
    nodo *it = node;
    while (it->left != NULL) {
        it = it->left;
    }

    return it->data;
}

// Función para buscar un valor 'data' en el árbol
// Se retorna la primera ocurrencia de 'data', o
// si el 'data' no está en el árbol se retorna NULL.
nodo *search(nodo *root, int data) {
    // Caso base: Ya sea root es NULL, es decir, el dato no está, o
    // el dato está en root. En cualquier caso, retornamos root.
    if (root == NULL || root->data == data) {
        return root;
    }

    // Hacemos la búsqueda hacia la derecha o izquierda y retornamos lo obtenido.
    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}



int main(int argc, char* argv[]) {
    /* Ejercicio 2 */
    printf("Ejercicio 2.\n");
    nodo *root = NULL;

    // Insertamos valores en el árbol.
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 13);
    printf("En el siguiente ejercicio podremos 'ver' nuestro árbol.");
    printf("\n");
    printf("\n");

    /* Ejercicio 3 */
    printf("Ejercicio 3.\n");
    // Funciones para mostrar los nodos del árbol.
    // Mostramos los nodos del árbol en inorder.
    printf("Distintas maneras de mostrar los nodos del árbol.\n");
    printf("Inorder   : ");
    inorder(root);
    // Mostramos los nodos del árbol en preorder.
    printf("\nPreorder  : ");
    preorder(root);
    // Mostramos los nodos del árbol en postorder.
    printf("\nPostorder : ");
    postorder(root);
    printf("\n");
    printf("\n");
    
    /* Ejercicio 5 */
    printf("Ejercicio 5.\n");
    printf("El valor mínimo del árbol es %d.\n", minValueNode(root));
    printf("\n");
    printf("Insertemos el valor 1 al árbol y veamos como se comporta la función.\n");
    root = insert(root, 1);
    printf("El valor mínimo del árbol es %d.\n", minValueNode(root));
}
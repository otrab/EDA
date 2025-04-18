#include <stdio.h>

#define SIZE 9

int hash(int n) {
    return (2 * n + 3) % SIZE;
}

int main() {
    int arreglo[SIZE];
    int numeros[] = {13, 5, 28, 9, 43, 39, 23, 27, 17};
    int i;

    // Inicializar arreglo con -1
    for (i = 0; i < SIZE; i++) {
        arreglo[i] = -1;
    }

    // Insertar números usando la función hash
    for (i = 0; i < sizeof(numeros) / sizeof(numeros[0]); i++) {
        int n = numeros[i];
        int pos = hash(n);

        if (arreglo[pos] == -1) {
            arreglo[pos] = n;
        } else {
            printf("Colisión al insertar %d en la posición %d\n", n, pos);
        }
    }

    // Mostrar resultado
    printf("Contenido del arreglo:\n");
    for (i = 0; i < SIZE; i++) {
        printf("Posición %d: %d\n", i, arreglo[i]);
    }

    return 0;
}
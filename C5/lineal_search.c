#include <stdio.h>

/*
 * Algoritmo de búsqueda lineal:
 * Busca un elemento en un arreglo recorriéndolo desde el principio hasta el final.
 * Es simple pero no muy eficiente para arreglos grandes.
 */

// Función para realizar la búsqueda lineal
int linearSearch(int arr[], int size, int key) {
    // Recorremos el arreglo elemento por elemento
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) { // Si encontramos el elemento
            return i;        // Devolvemos el índice donde se encuentra
        }
    }
    return -1; // Si no encontramos el elemento, devolvemos -1
}

int main() {
    // Declaramos un arreglo
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 90, 100, 120};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculamos el tamaño del arreglo
    int key = 35; // Elemento que queremos buscar

    // Llamamos a la función de búsqueda lineal
    int index = linearSearch(arr, size, key);

    // Mostramos el resultado al usuario
    if (index != -1) {
        printf("Elemento encontrado en el índice %d\n", index);
    } else {
        printf("Elemento no encontrado\n");
    }

    return 0;
}
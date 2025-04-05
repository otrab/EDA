#include <stdio.h>

/*
 * Este programa implementa el algoritmo de búsqueda de Fibonacci.
 * La idea es dividir el rango de búsqueda en segmentos basados en los números de Fibonacci.
 * Es útil para buscar elementos en arreglos ordenados.
 */

// Algoritmo de búsqueda de Fibonacci
int fibonacciSearch(int arr[], int size, int key) {
    // Inicializamos los tres números de Fibonacci necesarios
    int fibM2 = 0;       // F(k-2): Dos pasos atrás en la secuencia de Fibonacci
    int fibM1 = 1;       // F(k-1): Un paso atrás en la secuencia de Fibonacci
    int fibM = fibM2 + fibM1; // F(k): Número de Fibonacci actual

    // Generamos el menor número de Fibonacci mayor o igual al tamaño del arreglo
    while (fibM < size) {
        fibM2 = fibM1;       // Actualiza F(k-2) a F(k-1)
        fibM1 = fibM;        // Actualiza F(k-1) a F(k)
        fibM = fibM2 + fibM1; // Calcula el siguiente número de Fibonacci F(k)
    }

    // Inicializamos el desplazamiento para controlar el rango de búsqueda
    int offset = -1; // Empieza fuera del arreglo

    /*
     * Mientras haya elementos para comparar, seguimos ajustando el rango de búsqueda.
     * Cada vez reducimos el rango usando los números de Fibonacci.
     */
    while (fibM > 1) {
        // Calculamos el índice a comparar
        int i = (offset + fibM2 < size - 1) ? offset + fibM2 : size - 1;

        // Si el valor en el índice 'i' es menor que la clave buscada
        if (arr[i] < key) {
            fibM = fibM1;          // Reducimos el rango a la derecha (usamos F(k-1))
            fibM1 = fibM2;         // Actualizamos F(k-1) a F(k-2)
            fibM2 = fibM - fibM1;  // Calculamos el nuevo F(k-2)
            offset = i;            // Movemos el inicio del rango al índice actual
        }
        // Si el valor en el índice 'i' es mayor que la clave buscada
        else if (arr[i] > key) {
            fibM = fibM2;          // Reducimos el rango a la izquierda (usamos F(k-2))
            fibM1 = fibM1 - fibM2; // Actualizamos F(k-1) a F(k-1) - F(k-2)
            fibM2 = fibM - fibM1;  // Calculamos el nuevo F(k-2)
        }
        // Si el valor es igual a la clave buscada
        else {
            return i;              // Devolvemos el índice donde se encontró el elemento
        }
    }

    // Verificamos el último elemento del rango
    if (fibM1 && arr[offset + 1] == key) {
        return offset + 1;         // Si coincide, devolvemos el índice
    }

    // Si no se encuentra el elemento, devolvemos -1
    return -1;
}

int main() {
    // Declaramos un arreglo ordenado
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 90, 100, 120};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculamos el tamaño del arreglo
    int key = 35; // Elemento que queremos buscar en el arreglo

    // Llamamos a la función de búsqueda de Fibonacci
    int index = fibonacciSearch(arr, size, key);

    // Mostramos el resultado al usuario
    if (index != -1) {
        printf("Elemento encontrado en el índice %d\n", index);
    } else {
        printf("Elemento no encontrado\n");
    }

    return 0;
}
#include <stdio.h>

/*
 * La secuencia de Fibonacci es una serie de números donde cada número es la suma de los dos anteriores:
 * F(0) = 0, F(1) = 1, F(2) = F(0) + F(1) = 1, F(3) = F(1) + F(2) = 2, y así sucesivamente.
 * En este algoritmo, usamos los números de Fibonacci para dividir el rango de búsqueda en segmentos cada vez más pequeños,
 * aprovechando sus propiedades matemáticas para optimizar la búsqueda en arreglos ordenados.
 */

// Función para encontrar el menor número de Fibonacci mayor o igual a 'n'
int getFibonacciNumber(int n) {
    int fibM2 = 0;   // F(0): Primer número de la secuencia de Fibonacci
    int fibM1 = 1;   // F(1): Segundo número de la secuencia de Fibonacci
    int fibM = fibM2 + fibM1; // F(2): Suma de los dos anteriores (0 + 1 = 1)

    // Genera números de Fibonacci hasta que el número sea mayor o igual a 'n'
    while (fibM < n) {
        fibM2 = fibM1;           // Actualiza F(k-2) a F(k-1)
        fibM1 = fibM;            // Actualiza F(k-1) a F(k)
        fibM = fibM2 + fibM1;    // Calcula el siguiente número de Fibonacci F(k)
    }
    return fibM; // Devuelve el menor número de Fibonacci mayor o igual a 'n'
}

// Algoritmo de búsqueda de Fibonacci
int fibonacciSearch(int arr[], int size, int key) {
    int fibM2 = 0;                  // F(k-2): Número de Fibonacci dos pasos atrás
    int fibM1 = 1;                  // F(k-1): Número de Fibonacci un paso atrás
    int fibM = fibM2 + fibM1;       // F(k): Número de Fibonacci actual

    // Encuentra el menor número de Fibonacci mayor o igual al tamaño del arreglo
    while (fibM < size) {
        fibM2 = fibM1;             // Actualiza F(k-2) a F(k-1)
        fibM1 = fibM;              // Actualiza F(k-1) a F(k)
        fibM = fibM2 + fibM1;      // Calcula el siguiente número de Fibonacci F(k)
    }

    int offset = -1; // Inicializa el desplazamiento para controlar el rango de búsqueda

    /*
     * Mientras haya elementos para comparar, sigue ajustando el rango de búsqueda.
     * La búsqueda se realiza dividiendo el rango en segmentos usando los números de Fibonacci.
     */
    while (fibM > 1) {
        // Calcula el índice a comparar usando el número de Fibonacci
        int i = (offset + fibM2 < size - 1) ? offset + fibM2 : size - 1;

        // Si el valor en el índice 'i' es menor que la clave buscada
        if (arr[i] < key) {
            fibM = fibM1;          // Reduce el rango de búsqueda usando F(k-1)
            fibM1 = fibM2;         // Actualiza F(k-1) a F(k-2)
            fibM2 = fibM - fibM1;  // Calcula el nuevo F(k-2)
            offset = i;            // Ajusta el desplazamiento al índice actual
        }
        // Si el valor en el índice 'i' es mayor que la clave buscada
        else if (arr[i] > key) {
            fibM = fibM2;          // Reduce el rango de búsqueda usando F(k-2)
            fibM1 = fibM1 - fibM2; // Actualiza F(k-1) a F(k-1) - F(k-2)
            fibM2 = fibM - fibM1;  // Calcula el nuevo F(k-2)
        }
        // Si el valor es igual a la clave buscada
        else {
            return i;              // Devuelve el índice donde se encontró el elemento
        }
    }

    // Verifica el último elemento del rango de búsqueda
    if (fibM1 && arr[offset + 1] == key) {
        return offset + 1;         // Si coincide, devuelve el índice
    }

    // Si el elemento no se encuentra, devuelve -1
    return -1;
}

int main() {
    // Declaración del arreglo ordenado
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 90, 100, 120};
    int size = sizeof(arr) / sizeof(arr[0]); // Calcula el tamaño del arreglo
    int key = 35; // Elemento a buscar en el arreglo

    // Llamada a la función de búsqueda de Fibonacci
    int index = fibonacciSearch(arr, size, key);

    // Imprime el resultado de la búsqueda
    if (index != -1) {
        printf("Elemento encontrado en el índice %d\n", index);
    } else {
        printf("Elemento no encontrado\n");
    }

    return 0;
}
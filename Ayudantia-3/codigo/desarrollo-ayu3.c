#include <stdio.h>

int busqueda_lineal(int array[], int largo, int n) {
    for (int i = 0; i < largo; i++) {
        if (array[i] == n) {
            return i;
        }
    }

    return -1;
}

int busqueda_binaria(int array[], int largo, int n) {
    int min = 0;
    int max = largo - 1;
    
    while (min <= max) {
        int mid = ((max + min) / 2);

        if (array[mid] == n) {
            return mid;
        }

        if (array[mid] > n) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }

    return -1;
}

int busqueda_binaria_recursiva(int array[], int low, int high, int n) {
    if (high >= low) {
        int mid = (low + high) / 2;

        if (n == array[mid]) return mid;
        
        if (n > array[mid]) return busqueda_binaria_recursiva(array, mid + 1, high, n);

        return busqueda_binaria_recursiva(array, low, mid - 1, n);
    }

    return -1;
}

void bubble_sort(int array[], int largo) {
    int aux;
    for (int i = 0; i < largo; i++) {
        for (int j = 0; j < largo - 1; j++) {
            if (array[j] > array[j + 1]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}


void bubble_sort_optimizado(int array[], int largo) {
    int aux;
    for (int i = 0; i < largo; i++) {
        for (int j = 0; j < largo - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}

int main(int argc, char **argv) {
    /* Ejercicio 3 */
    printf("Ejercicio 3.\n");
    int array[10] = {5, 6, 7, 8, 4, 1, 3, 2, 10, 9};
    int largo = 10;
    int n = 12;
    printf("El valor de n: %i está en la posición %i del arreglo.\n", n, busqueda_lineal(array, largo, n));
    printf("\n");

    /* Ejercicio 4 */
    printf("Ejercicio 4.\n");
    int array_ordenado[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int largo_ordenado = 10;
    int n_ordenado = 5;
    printf("Busqueda binaria iterativa:\n");
    printf("El valor de n: %i está en la posición %i del arreglo.\n", n_ordenado, busqueda_binaria(array_ordenado, largo_ordenado, n_ordenado));
    printf("Busqueda binaria recursiva:\n");
    printf("El valor de n: %i está en la posición %i del arreglo.\n", n_ordenado, busqueda_binaria_recursiva(array_ordenado, 0, largo_ordenado - 1, n_ordenado));
    printf("\n");

    /* Ejercicio 6 */
    printf("Ejercicio 6.\n");
    int array_desordenado[10] = {1, 5, 6, 2, 4, 3, 7, 10, 9, 8};
    int largo_desordenado = 10;
    printf("Bubble sort.\n");
    printf("El arreglo era {");
	for(int i = 0; i < largo_desordenado; i++) {
        if (i < largo_desordenado - 1) {
            printf("%i ", array_desordenado[i]);
        } else {
            printf("%i", array_desordenado[i]);
        }
    }
    printf("} y ahora es {");
    bubble_sort(array_desordenado, largo_desordenado);
	for(int i = 0; i < largo_desordenado; i++) {
        if (i < largo_desordenado - 1) printf("%i ", array_desordenado[i]);
        else printf("%i", array_desordenado[i]);
    }
    printf("}.\n");
    printf("\n");
    printf("Bubble sort Optimizado.\n");
    int array_desordenado_o[10] = {1, 5, 6, 2, 4, 3, 7, 10, 9, 8};
    printf("El arreglo era {");
	for(int i = 0; i < largo_desordenado; i++) {
        if (i < largo_desordenado - 1) {
            printf("%i ", array_desordenado_o[i]);
        } else {
            printf("%i", array_desordenado_o[i]);
        }
    }
    printf("} y ahora es {");
    bubble_sort_optimizado(array_desordenado_o, largo_desordenado);
	for(int i = 0; i < largo_desordenado; i++) {
        if (i < largo_desordenado - 1) printf("%i ", array_desordenado_o[i]);
        else printf("%i", array_desordenado_o[i]);
    }
    printf("}.\n");
}
#include <stdio.h>

/* Para poder ver los prints completos en una misma ventana pueden
ocupar alt + z, y la longitud del texto debería ajustarse al
tamaño de su ventana (conocido como text wrappping). */
int ejercicio1(int n) {
    int *p = &n;
    
    printf("Valor del input: %d.\n", n);
    printf("Dirección de memora del input: %p.\n", p);
}

int swap_v(int x, int y) {
    int aux = x;
    x = y;
    y = aux;
    
    return printf("(Swap) Valor de x: %i y su dirección de memoria es: %p\n(Swap) Valor de y: %i y su dirección de memoria es: %p.\n", x, &x, y, &y);
}

int ejercicio2(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int ejercicio3(int array[], int largo) {
    int *p = array;
    int suma = 0;
    
    for (int i = 0; i < largo; i++) {
        suma = suma + *(p + i);
    }
    
    return suma;
}

int main() {
    printf("Ejercicio 1.\n");
    int n = 10;
    ejercicio1(n);
    printf("\n");
    
    printf("Ejercicio 2.\n");
    int x = 5, y = 7;
    printf("Paso por valor.\n");
    printf("Valor de x: %i y su dirección de memoria es: %p\nValor de y: %i y su dirección de memoria es: %p.\n", x, &x, y, &y);
    swap_v(x, y);
    printf("Valor de x: %i y su dirección de memoria es: %p\nValor de y: %i y su dirección de memoria es: %p.\n", x, &x, y, &y);
    printf("\n");
    /* Revisen si cambian o se mantienen
    las direcciones de memoria de x e y, 
    antes, durante y luego del swap */
    printf("Paso por referencia.\n");
    printf("Valor de x: %i y valor de y: %i.\n", x, y);
    ejercicio2(&x, &y);
    printf("Valor de x: %i y valor de y: %i.\n", x, y);
    printf("\n");

    printf("Ejericio 3.\n");
    int arreglo[] = {1, 2, 3, 4, 5};
    int largo = 5;
    int suma = ejercicio3(arreglo, largo);
    printf("La suma de los elementos del array es: %i.\n", suma);
}
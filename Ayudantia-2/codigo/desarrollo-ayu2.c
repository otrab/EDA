#include <stdio.h>

void invertir(int A[], int n) {
    int B[n];
    int count = 0; // Contador para las iteraciones
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
        count++;
    }
    printf("Iteraciones del primer for loop: %d\n", count);

    count = 0;
    for (int i = 0; i < n; i++) {
        A[i] = B[n-1-i];
        count++;
    }
    printf("Iteraciones del segundo for loop: %d\n", count);
}

// Usando el mismo método que para el ejercicio 3.3, calcule la complejidad temporal
// con el fin de entender por qué da 45 y no 100.
int sumPairs(int A[], int n) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {           // Bucle exterior: i de 0 a n-1
        for (int j = i + 1; j < n; j++) {   // Bucle interior: j de i+1 a n-1
            sum += A[i] + A[j];             // Operación de suma, O(1)
            count++;
        }
    }
    printf("Iteraciones de los ciclos anidados: %d\n", count);

    return sum;
}

int fibonacci0(int n) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    
    return (fibonacci0(n - 1) + fibonacci0(n - 2));
}

int fibonacci1(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return (fibonacci1(n - 1) + fibonacci1(n - 2));
}

int main() {
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    for (int i = 0; i < n; i++) {
        printf("%i ", A[i]);
    }
    printf("\n");
    invertir(A, n);
    for (int i = 0; i < n; i++) {
        printf("%i ", A[i]);
    }
    printf("\n");
    printf("\n");

    int sum = sumPairs(A, n);

    printf("Sum of pairs: %d\n", sum);
    printf("\n");
    printf("Considerando al 0 como el primer término.\n");
    printf("El valor del término %i de la secuencia de fibonacci es: %i.\n", n, fibonacci0(n));
    printf("Y la secuencia es:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", fibonacci0(i));
    }
    printf("\n");
    printf("\n");
    printf("Considerando al 1 como el primer término.\n");
    printf("El valor del término %i de la secuencia de fibonacci es: %i.\n", n, fibonacci1(n));
    for (int i = 1; i <= n; i++) {
        printf("%d ", fibonacci1(i));
    }
    printf("\n");
}
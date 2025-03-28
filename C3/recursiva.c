#include <stdio.h>

void hola();  // Declaración de función

int main() {
    hola();    // Llamada inicial
    return 0;
}

void hola() {
    static int contador = 1;  // Variable estática (persiste entre llamadas)
    printf("%d: Hola\n", contador++);  // Imprime y aumenta el contador
    hola();     // Llamada recursiva sin condición base
}

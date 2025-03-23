#include <stdio.h>

void hola();  // Declaración de función

int main() {
    hola();    // Llamada inicial
    return 0;
}

void hola() {
    printf("Hola\n");
    hola();     // Llamada recursiva sin condición base
}

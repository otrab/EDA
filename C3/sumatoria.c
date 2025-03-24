#include <stdio.h>

int main() {
    int n;
    int a = 0;
    int i = 1;

    printf("Ingresa un valor para n: ");
    scanf("%d", &n);

    while (i <= n) {
        a = a + i;
        i = i + 1;
    }

    printf("El resultado es: %d\n", a); 

    return 0;
}

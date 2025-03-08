#include <stdio.h>

#define MAX_LEN 100
#define MAX_PERSONAS 10

typedef struct {
    char nombre[MAX_LEN];
    char rut[MAX_LEN];
} Persona;

int main() {
    Persona personas[MAX_PERSONAS];

    for (int i = 0; i < MAX_PERSONAS; i++) {
        printf("Ingrese el nombre de la persona %d: ", i + 1);
        fgets(personas[i].nombre, MAX_LEN, stdin);
        
        printf("Ingrese el RUT de la persona %d: ", i + 1);
        fgets(personas[i].rut, MAX_LEN, stdin);
    }

    printf("\nFichas ingresadas:\n");
    for (int i = 0; i < MAX_PERSONAS; i++) {
        printf("Persona %d\n", i + 1);
        printf("Nombre: %s", personas[i].nombre);
        printf("RUT: %s", personas[i].rut);
    }

    return 0;
}

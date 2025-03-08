#include <stdio.h>

#define MAX_LEN 100

int main() {
    char nombre[MAX_LEN];
    char apellido[MAX_LEN];
    char rut[MAX_LEN];
    char telefono[MAX_LEN];
    int edad;

    printf("Ingrese su nombre: ");
    fgets(nombre, MAX_LEN, stdin);
    
    printf("Ingrese su apellido: ");
    fgets(apellido, MAX_LEN, stdin);
    
    printf("Ingrese su RUT: ");
    fgets(rut, MAX_LEN, stdin);
    
    printf("Ingrese su teléfono: ");
    fgets(telefono, MAX_LEN, stdin);
    
    printf("Ingrese su edad: ");
    scanf("%d", &edad);
    getchar(); // Limpiar el buffer de entrada

    printf("\nDatos ingresados:\n");
    printf("Nombre: %s", nombre);
    printf("Apellido: %s", apellido);
    printf("RUT: %s", rut);
    printf("Teléfono: %s", telefono);
    printf("Edad: %d\n", edad);
    
    return 0;
}

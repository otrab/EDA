#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_RECORDS 1000
#define MAX_CITY_NAME 50
#define MAX_CITIES 100

void load_cities(const char *filename, char cities[][MAX_CITY_NAME], int *num_cities) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el archivo de ciudades");
        exit(EXIT_FAILURE);
    }

    *num_cities = 0;
    while (fgets(cities[*num_cities], MAX_CITY_NAME, file)) {
        // Eliminar el salto de línea al final de cada ciudad
        cities[*num_cities][strcspn(cities[*num_cities], "\n")] = '\0';
        (*num_cities)++;
        if (*num_cities >= MAX_CITIES) {
            fprintf(stderr, "Se alcanzó el número máximo de ciudades permitidas (%d).\n", MAX_CITIES);
            break;
        }
    }

    fclose(file);
}

void generate_random_csv(const char *filename, char cities[][MAX_CITY_NAME], int num_cities) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error al abrir el archivo para escritura");
        exit(EXIT_FAILURE);
    }

    // Escribir encabezado
    fprintf(file, "city_name,seismic_level,risk_percent\n");

    srand(time(NULL)); // Inicializar la semilla para números aleatorios

    for (int i = 0; i < NUM_RECORDS; i++) {
        const char *city = cities[rand() % num_cities];
        int seismic_level = rand() % 5 + 1; // Nivel sísmico entre 1 y 5
        float risk_percent = (rand() % 10 < 9) ? ((float)rand() / RAND_MAX * 90.0 + 10.0) : -1.0; // 10% de valores faltantes

        if (risk_percent < 0) {
            fprintf(file, "%s,%d,\n", city, seismic_level); // Valor faltante
        } else {
            fprintf(file, "%s,%d,%.2f\n", city, seismic_level, risk_percent); // Formato con 2 decimales
        }
    }

    fclose(file);
    printf("Archivo '%s' generado con %d registros.\n", filename, NUM_RECORDS);
}

int main() {
    const char *cities_file = "cities.txt";
    const char *output_file = "input.csv";

    char cities[MAX_CITIES][MAX_CITY_NAME];
    int num_cities;

    // Cargar las ciudades desde el archivo
    load_cities(cities_file, cities, &num_cities);

    // Generar el archivo CSV
    generate_random_csv(output_file, cities, num_cities);

    return 0;
}
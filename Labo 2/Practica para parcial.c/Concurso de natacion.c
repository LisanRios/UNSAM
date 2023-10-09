#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FIL 4
#define COL 6
#define T 30

// Competidores
struct Competidor {
    int Id;
    char nombre[30];
    char provincia[30];
    float tiempo[T];
    float prommes;
    float maxprom;
};

// Instructores
struct Instructor {
    int Id;
    char nombre[30];
    char instructor[30];
};

// Lista de nombres
char provincias[FIL][30] = {"Bs As", "Tierra del Fuego", "Santa Fe", "La Pampa"};
char instructoresNombres[FIL][30] = {"Coscu", "Oso Polar", "Messi", "Un gaucho"};
char competidoresNombres[FIL][30] = {"Baki", "Castor", "Sprenn", "La oveja del gaucho (Oscar)"};

// Función para cargar datos aleatorios
void CargarDatosAleatorios(struct Competidor competidores[], struct Instructor instructores[]) {
    srand(time(NULL));

    for (int i = 0; i < FIL; i++) {
        competidores[i].Id = i + 1;
        strcpy(competidores[i].nombre, competidoresNombres[i]);
        strcpy(competidores[i].provincia, provincias[i]);

        for (int j = 0; j < T; j++) {
            competidores[i].tiempo[j] = (float)(rand() % 100 + 1);
        }

        instructores[i].Id = i + 1;
        strcpy(instructores[i].nombre, competidoresNombres[i]);
        strcpy(instructores[i].instructor, instructoresNombres[i]);
    }
}

// Promedio mensual de tiempo para cada competidor
void CalcularPromedioMensual(struct Competidor competidores[]) {
    printf("Promedio mensual de tiempo: \n");
    for (int i = 0; i < FIL; i++) {
        float suma = 0;
        for (int j = 0; j < T; j++) {
            suma += competidores[i].tiempo[j];
        }
        competidores[i].prommes = suma / T;
        printf("Competidor: %s\n", competidores[i].nombre);
        printf("Promedio mensual: %f\n", competidores[i].prommes);
        printf("Provincia: %s\n", competidores[i].provincia);
        printf("\n");
    }
    printf("\n");
}

// Encontrar el máximo promedio mensual y actualizar el campo 'maxprom'
void EncontrarMaximoPromedio(struct Competidor competidores[]) {
    printf("Maximo promedio mensual: \n");
    for (int i = 0; i < FIL; i++) {
        float max = competidores[i].prommes;
        for (int j = 0; j < T; j++) {
            if (competidores[i].tiempo[j] > max) {
                max = competidores[i].tiempo[j];
            }
        }
        competidores[i].maxprom = max;
        printf("Competidor: %s\n", competidores[i].nombre);
        printf("Provincia: %s\n", competidores[i].provincia);
        printf("Promedio maximo: %f\n", competidores[i].maxprom);
        printf("\n");
    }
    printf("\n");
}

// Encontrar competidores cuyo 'prommes' no supere 'maxprom'
int EncontrarCompetidores(struct Competidor competidores[], int posiciones[]) {
    int cantidad = 0;
    printf("Competidores con promedio mensual menor o igual al maximo: \n");
    for (int i = 0; i < FIL; i++) {
        if (competidores[i].prommes <= competidores[i].maxprom) {
            posiciones[cantidad] = i;
            cantidad++;
            printf("Competidor: %s\n", competidores[i].nombre);
            printf("Promedio mensual: %f\n", competidores[i].prommes);
            printf("Provincia: %s\n", competidores[i].provincia);
            printf("\n");
        }
    }
    return cantidad;
}

// Emitir datos de competidores y sus instructores
void EmitirDatos(struct Competidor competidores[], struct Instructor instructores[], int posiciones[], int cantidad) {
    printf("Datos de los competidores: \n");
    for (int i = 0; i < cantidad; i++) {
        int indice = posiciones[i];
        printf("Provincia: %s\n", competidores[indice].provincia);
        printf("Competidor: %s\n", competidores[indice].nombre);
        printf("Instructor: ");
        for (int j = 0; j < FIL; j++) {
            if (strcmp(competidores[indice].nombre, instructores[j].nombre) == 0) {
                printf("%s\n", instructores[j].instructor);
                break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Ordenar competidores por provincia
void OrdenarCompetidores(struct Competidor competidores[], struct Instructor instructores[]) {
    struct Competidor temp;
    printf("Competidores ordenados por provincia: \n");
    for (int i = 0; i < FIL - 1; i++) {
        for (int j = 0; j < FIL - i - 1; j++) {
            if (strcmp(competidores[j].provincia, competidores[j + 1].provincia) > 0) {
                temp = competidores[j];
                competidores[j] = competidores[j + 1];
                competidores[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < FIL; i++) {
        printf("Provincia: %s\n", competidores[i].provincia);
        printf("Competidor: %s\n", competidores[i].nombre);
        printf("Instructor: ");
        for (int j = 0; j < FIL; j++) {
            if (strcmp(competidores[i].nombre, instructores[j].nombre) == 0) {
                printf("%s\n", instructores[j].instructor);
                break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    struct Competidor competidores[FIL];
    struct Instructor instructores[FIL];
    int posiciones[FIL];
    CargarDatosAleatorios(competidores, instructores);

    CalcularPromedioMensual(competidores);
    EncontrarMaximoPromedio(competidores);
    int cantidad = EncontrarCompetidores(competidores, posiciones);
    EmitirDatos(competidores, instructores, posiciones, cantidad);
    OrdenarCompetidores(competidores, instructores);

    return 0;
}

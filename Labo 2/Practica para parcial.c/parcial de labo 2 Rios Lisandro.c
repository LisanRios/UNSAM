#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5
#define M 6

// Definición de la estructura Franquicia
struct Franquicia {
    int Id_franquicia;
    char Partido[30];
    float ventas_del_mes[M];
    float Total_de_ventas_del_mes;
    float Promedio_ventas;
};

// Definición de la estructura CEO
struct CEO {
    int Id_ceo;
    int Id_franquicia;
    char Nombre_del_ceo[30];
};

// Nombres aleatorios para los CEOs
char *nombresCEO[] = {"John Doe", "Jane Smith", "Michel Johnson", "Emily Davis", "Michael Wilson"};

// Definición de la función para cargar las ventas aleatorias
void cargarVentasAleatorias(struct Franquicia franquicias[]) {
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            franquicias[i].ventas_del_mes[j] = (rand() % 901) + 100;
        }
    }
}

// Definición de la función para calcular el total de ventas
void calcularTotalVentas(struct Franquicia franquicias[]) {
    for (int i = 0; i < N; i++) {
        float totalVentas = 0.0;
        for (int j = 0; j < M; j++) {
            totalVentas += franquicias[i].ventas_del_mes[j];
        }
        franquicias[i].Total_de_ventas_del_mes = totalVentas;

        printf("Franquicia %d:\n", franquicias[i].Id_franquicia);
        printf("Partido: %s\n", franquicias[i].Partido);
        printf("Ventas del mes:\n");
        for (int j = 0; j < M; j++) {
            printf("Mes %d: %.2f\n", j + 1, franquicias[i].ventas_del_mes[j]);
        }
        printf("Total de ventas del mes: %.2f\n", franquicias[i].Total_de_ventas_del_mes);
        printf("\n");
    }
}

// Definición de la función para calcular el promedio de ventas
void calcularPromedioVentas(struct Franquicia franquicias[]) {
    for (int i = 0; i < N; i++) {
        float totalVentas = 0.0;
        for (int j = 0; j < M; j++) {
            totalVentas += franquicias[i].ventas_del_mes[j];
        }
        franquicias[i].Total_de_ventas_del_mes = totalVentas;
        franquicias[i].Promedio_ventas = totalVentas / M;

        printf("Franquicia %d:\n", franquicias[i].Id_franquicia);
        printf("Partido: %s\n", franquicias[i].Partido);
        printf("Ventas del mes:\n");
        for (int j = 0; j < M; j++) {
            printf("Mes %d: %.2f\n", j + 1, franquicias[i].ventas_del_mes[j]);
        }
        printf("Total de ventas del mes: %.2f\n", franquicias[i].Total_de_ventas_del_mes);
        printf("Promedio de ventas: %.2f\n", franquicias[i].Promedio_ventas);
        printf("\n");
    }
}

// Función para detectar franquicias cuyas ventas superan el promedio
int detectarFranquiciasSuperioresAlPromedio(struct Franquicia franquicias[], int indices[], int totalFranquicias) {
    int contador = 0;
    for (int i = 0; i < totalFranquicias; i++) {
        if (franquicias[i].Total_de_ventas_del_mes > franquicias[i].Promedio_ventas) {
            indices[contador] = i;
            contador++;
        }
    }

    printf("Franquicias cuyas ventas superan el promedio:\n");
    for (int i = 0; i < contador; i++) {
        int indice = indices[i];
        printf("Franquicia %d:\n", franquicias[indice].Id_franquicia);
        printf("Partido: %s\n", franquicias[indice].Partido);
        printf("Total de ventas del mes: %.2f\n", franquicias[indice].Total_de_ventas_del_mes);
        printf("Promedio de ventas: %.2f\n", franquicias[indice].Promedio_ventas);
        printf("\n");
    }

    return contador;
}

// Función para intercambiar dos CEOs
void intercambiarCEOs(struct CEO *a, struct CEO *b) {
    struct CEO temp = *a;
    *a = *b;
    *b = temp;
}

// Función para ordenar el vector de CEOs por nombre (ordenamiento burbuja)
void ordenarCEOsPorNombre(struct CEO ceos[]) {
    int i, j;
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (strcmp(ceos[j].Nombre_del_ceo, ceos[j + 1].Nombre_del_ceo) > 0) {
                intercambiarCEOs(&ceos[j], &ceos[j + 1]);
            }
        }
    }

    // Imprimir los CEOs ordenados
    printf("CEOs ordenados por nombre en forma ascendente:\n");
    for (i = 0; i < N; i++) {
        printf("CEO %d:\n", ceos[i].Id_ceo);
        printf("Nombre: %s\n", ceos[i].Nombre_del_ceo);
        printf("Franquicia a cargo: %d\n\n", ceos[i].Id_franquicia);
    }
}

int main() {
    // Declaración de los vectores y matrices
    struct Franquicia franquicias[N];
    struct CEO ceos[N];
    int descuentos[N][M];
    int indices[N];
    
    // Inicialización del vector de descuentos
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            descuentos[i][j] = -30;
        }
    }

    // Inicialización de los datos de franquicias
    franquicias[0].Id_franquicia = 1;
    strcpy(franquicias[0].Partido, "San Martin");
    
    franquicias[1].Id_franquicia = 2;
    strcpy(franquicias[1].Partido, "Moron");
    
    franquicias[2].Id_franquicia = 3;
    strcpy(franquicias[2].Partido, "Quilmes");
    
    franquicias[3].Id_franquicia = 4;
    strcpy(franquicias[3].Partido, "Tigre");
    
    franquicias[4].Id_franquicia = 5;
    strcpy(franquicias[4].Partido, "Trenque Lauquen");

    // Cargar ventas aleatorias
    cargarVentasAleatorias(franquicias);

    // Inicialización de los datos de los CEOs con nombres aleatorios
    for (int i = 0; i < N; i++) {
        ceos[i].Id_ceo = i + 1;
        ceos[i].Id_franquicia = franquicias[i].Id_franquicia;
        int randomIndex = rand() % (sizeof(nombresCEO) / sizeof(nombresCEO[0]));
        strcpy(ceos[i].Nombre_del_ceo, nombresCEO[randomIndex]);
    }

    // Impresión de los datos de las franquicias
    printf("Datos de las Franquicias:\n");
    for (int i = 0; i < N; i++) {
        printf("Franquicia %d:\n", franquicias[i].Id_franquicia);
        printf("Partido: %s\n", franquicias[i].Partido);
        printf("Ventas del mes:\n");
        for (int j = 0; j < M; j++) {
            printf("Mes %d: %.2f\n", j + 1, franquicias[i].ventas_del_mes[j]);
        }
        printf("\n");
    }

    // Impresión de los datos de los CEOs
    printf("Datos de los CEOs:\n");
    for (int i = 0; i < N; i++) {
        printf("CEO %d:\n", ceos[i].Id_ceo);
        printf("Nombre: %s\n", ceos[i].Nombre_del_ceo);
        printf("Franquicia a cargo: %d\n\n", ceos[i].Id_franquicia);
    }

    // 1. Calcular total de ventas
    calcularTotalVentas(franquicias);

    // 2. Calcular promedio de ventas
    calcularPromedioVentas(franquicias);

    // 3. Detectar franquicias cuyas ventas superan el promedio
    int cantidadFranquiciasSuperiores = detectarFranquiciasSuperioresAlPromedio(franquicias, indices, N);
    printf("Total de franquicias cuyas ventas superan el promedio: %d\n", cantidadFranquiciasSuperiores);

    // 4. Ordenar CEOs por nombre
    ordenarCEOsPorNombre(ceos);

    return 0;
}

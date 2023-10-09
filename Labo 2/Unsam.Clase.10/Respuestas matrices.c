/*
    1) Escribe un programa que almacene en una matriz los números impares del 1 al 50 y los
imprima. 
*/
/*

#include <stdio.h>

int main(){
    int matriz[10][10]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30},{31,32,33,34,35},{36,37,38,39,40},{41,42,43,44,45},{46,47,48,49,50}};
    int count = 10;
    int count2 = 5;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count2; j++) {
            printf("%d ", matriz[i][j]);
        }
    }
    
}
*/
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/*
    2)  Se ingresa una matriz de NxM componentes. Se emite por pantalla:
a. la cantidad de ceros que contiene
b. el valor máximo de cada columna.
c. el elemento mínimo de toda la matriz y las posiciones en que aparece.
d. el promedio de la matriz
e. el promedio de cada columna
f. los promedios de cada fila, e indica qué filas tienen el promedio máximo.
g. el menor y mayor elemento de esa matriz y sus posiciones.
h. devuelva el número de elementos negativos, iguales a cero y positivos que hay en
ella.
*/
/*
#include <stdio.h>

void cargarMatriz(int n, int m, int matriz[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Ingrese el valor [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void cant_ceros(int n, int m, int matriz[n][m]) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] == 0) {
                cont++;
            }
        }
    }
    printf("La cantidad de ceros es: %d\n", cont);
}

void max_columnas(int n, int m, int matriz[n][m]) {
    for (int j = 0; j < m; j++) {
        int maximo = matriz[0][j];
        for (int i = 1; i < n; i++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
            }
        }
        printf("El valor máximo de la columna %d es: %d\n", j, maximo);
    }
}

void minimo_y_posiciones(int n, int m, int matriz[n][m]) {
    int minimo = matriz[0][0];
    int fila_min = 0;
    int columna_min = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
                fila_min = i;
                columna_min = j;
            }
        }
    }
    
    printf("El valor mínimo de la matriz es: %d\n", minimo);
    printf("Se encuentra en la posición [%d][%d]\n", fila_min, columna_min);
}

void promedio(int n, int m, int matriz[n][m]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += matriz[i][j];
        }
    }
    float promedio = (float)sum / (n * m);
    printf("El promedio de la matriz es: %.2f\n", promedio);
}

void promedio_columnas(int n, int m, int matriz[n][m]) {
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matriz[i][j];
        }
        float promedio = (float)sum / n;
        printf("El promedio de la columna %d es: %.2f\n", j, promedio);
    }
}

void promedio_filas(int n, int m, int matriz[n][m]) {
    int fila_max_promedio = 0;
    float max_promedio = -1;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += matriz[i][j];
        }
        float promedio = (float)sum / m;
        printf("El promedio de la fila %d es: %.2f\n", i, promedio);
        
        if (promedio > max_promedio) {
            max_promedio = promedio;
            fila_max_promedio = i;
        }
    }
    
    printf("La fila con el promedio máximo es la fila %d\n", fila_max_promedio);
}

void min_y_max(int n, int m, int matriz[n][m]) {
    int minimo = matriz[0][0];
    int fila_min = 0;
    int columna_min = 0;
    
    int maximo = matriz[0][0];
    int fila_max = 0;
    int columna_max = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
                fila_min = i;
                columna_min = j;
            }
            
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
                fila_max = i;
                columna_max = j;
            }
        }
    }
    
    printf("El valor mínimo de la matriz es: %d\n", minimo);
    printf("Se encuentra en la posición [%d][%d]\n", fila_min, columna_min);
    
    printf("El valor máximo de la matriz es: %d\n", maximo);
    printf("Se encuentra en la posición [%d][%d]\n", fila_max, columna_max);
}

void contar_tipos_numeros(int n, int m, int matriz[n][m]) {
    int negativos = 0;
    int ceros = 0;
    int positivos = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] < 0) {
                negativos++;
            } else if (matriz[i][j] == 0) {
                ceros++;
            } else {
                positivos++;
            }
        }
    }
    
    printf("Número de elementos negativos: %d\n", negativos);
    printf("Número de elementos iguales a cero: %d\n", ceros);
    printf("Número de elementos positivos: %d\n", positivos);
}

int main() {
    int n, m;
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &n);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &m);
    
    int matriz[n][m];
    
    cargarMatriz(n, m, matriz);
    cant_ceros(n, m, matriz);
    max_columnas(n, m, matriz);
    minimo_y_posiciones(n, m, matriz);
    promedio(n, m, matriz);
    promedio_columnas(n, m, matriz);
    promedio_filas(n, m, matriz);
    min_y_max(n, m, matriz);
    contar_tipos_numeros(n, m, matriz);
    
    return 0;
}
*/

/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*
    3)  Se ingresa una matriz de NxM componentes enteras. La computadora muestra las sumatorias
de las columnas y emite los elementos de cada una ordenados de menor a mayor.
*/
/*
#include <stdio.h>
struct Matrix {
    int rows;
    int cols;
    int data[100][100]; 
};

void leerMatriz(struct Matrix *matriz) {
    printf("Ingrese el número de filas (N): ");
    scanf("%d", &(matriz->rows));
    printf("Ingrese el número de columnas (M): ");
    scanf("%d", &(matriz->cols));

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < matriz->rows; i++) {
        for (int j = 0; j < matriz->cols; j++) {
            scanf("%d", &(matriz->data[i][j]));
        }
    }
}

void calcularYOrdenar(struct Matrix matriz) {
    int sumatoria[100] = {0}; 

    
    for (int j = 0; j < matriz.cols; j++) {
        for (int i = 0; i < matriz.rows; i++) {
            sumatoria[j] += matriz.data[i][j];
        }
    }

    
    printf("Sumatorias de las columnas:\n");
    for (int j = 0; j < matriz.cols; j++) {
        printf("Columna %d: %d\n", j + 1, sumatoria[j]);
    }

    printf("Elementos de cada columna ordenados de menor a mayor:\n");
    for (int j = 0; j < matriz.cols; j++) {
        int elementos[100];
        for (int i = 0; i < matriz.rows; i++) {
            elementos[i] = matriz.data[i][j];
        }

        for (int i = 0; i < matriz.rows - 1; i++) {
            for (int k = i + 1; k < matriz.rows; k++) {
                if (elementos[i] > elementos[k]) {
                    int temp = elementos[i];
                    elementos[i] = elementos[k];
                    elementos[k] = temp;
                }
            }
        }

        printf("Columna %d: ", j + 1);
        for (int i = 0; i < matriz.rows; i++) {
            printf("%d ", elementos[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Matrix matriz;

    leerMatriz(&matriz);
    calcularYOrdenar(matriz);

    return 0;
}
*/

/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*
    4)  Declara una matriz de número reales de tamaño DIMxDIM (DIM constante con valor 5).
        Escribir las siguientes funciones:
    a. Función Simetrica: Dada una matriz indica si la matriz es simétrica (1) o si no lo es (0).
        int simetrica(float mat[]);
    b. Funcion Suma: Dadas dos matrices, calcular la suma de éstas. 
        void sumaMat(float mat1[],float mat2[], res[]);
    c. Funcion Resta: Dadas dos matrices, calcular la resta de éstas. Piensa esta
        respuesta utilizando el procedimiento de suma de matrices, definido anteriormente.
    d. Función Multiplica: Dadas dos matrices, devuelve el producto de ellas.
        void multiMat(float mat1[],float mat2[], res[]);
*/
/*
#include <stdio.h>

#define DIM 5 

// Función para determinar si una matriz es simétrica
int simetrica(float mat[][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            
            if (mat[i][j] != mat[j][i]) {
                return 0;
            }
        }
    }
    return 1; 
}

// Función para sumar dos matrices
void sumaMat(float mat1[][DIM], float mat2[][DIM], float res[][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            printf("%f ", res[i][j]);
        }
        printf("\n");
    }
    
}

// Función para restar dos matrices utilizando la función sumaMat
void restaMat(float mat1[][DIM], float mat2[][DIM], float res[][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            printf("%f ", res[i][j]);
        }
        printf("\n");
    }
}

// Función para multiplicar dos matrices
void multiMat(float mat1[][DIM], float mat2[][DIM], float res[][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            res[i][j] = 0; 
            for (int k = 0; k < DIM; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Resultado de la multiplicación:\n");
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            printf("%f ", res[i][j]);
        }
        printf("\n");
    }
}


int main() {
    float matriz1[DIM][DIM];
    float matriz2[DIM][DIM];
    float resultado[DIM][DIM];

    printf("Ingrese los elementos de la matriz 1 (%dx%d):\n", DIM, DIM);
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            printf("Elemento (%d, %d): ", i + 1, j + 1);
            scanf("%f", &matriz1[i][j]);
        }
    }

    printf("Ingrese los elementos de la matriz 2 (%dx%d):\n", DIM, DIM);
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            printf("Elemento (%d, %d): ", i + 1, j + 1);
            scanf("%f", &matriz2[i][j]);
        }
    }

    if (simetrica(matriz1)) {
        printf("La matriz 1 es simétrica.\n");
    } else {
        printf("La matriz 1 no es simétrica.\n");
    }

    sumaMat(matriz1, matriz2, resultado);
    printf("Resultado de la suma:\n");
    
    restaMat(matriz1, matriz2, resultado);
    printf("Resultado de la resta:\n");
    
    multiMat(matriz1, matriz2, resultado);
    printf("Resultado de la multiplicación:\n");
    
    return 0;
}
*/

/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*
    5)  Escribe un programa que lea un vector de N elementos enteros. A continuación, debe
rellenar una matriz de NxN elementos de tal forma que la primera fila contenga el vector
leído; las siguientes deben contener el vector de la fila anterior pero con los
elementos rotados a la izquierda una unidad. Por último, se debe visualizar dicha
matriz. Por ejemplo, supongamos que N = 5 y V = f 1; 2; 3; 4; 5 , el programa
visualizará:
1 2 3 4 5
2 3 4 5 1
3 4 5 1 2
4 5 1 2 3
5 1 2 3 4
*/
/*
#include <stdio.h>

void rotate(int arr[], int n) {
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    arr[n - 1] = temp;
}

int main() {
    int N;
    printf("Ingrese el valor de N: ");
    scanf("%d", &N);

    int arr[N];

    printf("Ingrese los %d valores de N separados por espacios:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int matrix[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = arr[j];
        }
        rotate(arr, N);
    }

    printf("Matriz resultante:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

*/



/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*
    6)  Disponemos de un conjunto de ciudades C, y una matriz D, donde cada D[i][j] almacena la
distancia de la carretera que conecta las ciudades C[i], C[j]. Un valor D[i][j] = 0
indica que no existe camino directo entre C[i] y C[j]. Diseñe e implemente programas que
permitan responder las siguientes preguntas:
a. ¿Cuáles son las ciudades que se encuentran más cercanas?
b. ¿Ídem las más lejanas?
c. ¿Cuál es la longitud promedio de las carreteras?
d. ¿Cuál es la ciudad mejor conectada?
e. ¿Y la peor?
*/
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_CIUDADES 100

// Función para encontrar la ciudad más cercana
void ciudadMasCercana(int n, int D[MAX_CIUDADES][MAX_CIUDADES]) {
    int i, j;
    int minDistancia = D[0][1];
    int ciudadA = 0;
    int ciudadB = 1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (D[i][j] < minDistancia && D[i][j] != 0) {
                minDistancia = D[i][j];
                ciudadA = i;
                ciudadB = j;
            }
        }
    }

    printf("Las ciudades más cercanas son: %d y %d, con una distancia de %d\n", ciudadA, ciudadB, minDistancia);
}

// Función para encontrar la ciudad más lejana
void ciudadMasLejana(int n, int D[MAX_CIUDADES][MAX_CIUDADES]) {
    int i, j;
    int maxDistancia = 0;
    int ciudadA = 0;
    int ciudadB = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (D[i][j] > maxDistancia && D[i][j] != 0) {
                maxDistancia = D[i][j];
                ciudadA = i;
                ciudadB = j;
            }
        }
    }

    printf("Las ciudades más lejanas son: %d y %d, con una distancia de %d\n", ciudadA, ciudadB, maxDistancia);
}

// Función para calcular la longitud promedio de las carreteras
void longitudPromedio(int n, int D[MAX_CIUDADES][MAX_CIUDADES]) {
    int i, j;
    int sumaDistancias = 0;
    int contador = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (D[i][j] != 0) {
                sumaDistancias += D[i][j];
                contador++;
            }
        }
    }

    double promedio = (double)sumaDistancias / contador;
    printf("La longitud promedio de las carreteras es: %.2lf\n", promedio);
}

// Función para encontrar la ciudad mejor conectada
void ciudadMejorConectada(int n, int D[MAX_CIUDADES][MAX_CIUDADES]) {
    int i, j;
    int minConexiones = n + 1; // Inicializar con un valor mayor al número máximo de ciudades
    int ciudad = -1;

    for (i = 0; i < n; i++) {
        int conexiones = 0;
        for (j = 0; j < n; j++) {
            if (D[i][j] != 0) {
                conexiones++;
            }
        }
        if (conexiones < minConexiones) {
            minConexiones = conexiones;
            ciudad = i;
        }
    }

    printf("La ciudad mejor conectada es: %d con %d conexiones\n", ciudad, minConexiones);
}

// Función para encontrar la ciudad peor conectada
void ciudadPeorConectada(int n, int D[MAX_CIUDADES][MAX_CIUDADES]) {
    int i, j;
    int maxConexiones = 0;
    int ciudad = -1;

    for (i = 0; i < n; i++) {
        int conexiones = 0;
        for (j = 0; j < n; j++) {
            if (D[i][j] != 0) {
                conexiones++;
            }
        }
        if (conexiones > maxConexiones) {
            maxConexiones = conexiones;
            ciudad = i;
        }
    }

    printf("La ciudad peor conectada es: %d con %d conexiones\n", ciudad, maxConexiones);
}

int main() {
    int n; // Número de ciudades
    int D[MAX_CIUDADES][MAX_CIUDADES]; // Matriz de distancias

    // Solicitar al usuario el número de ciudades
    printf("Ingrese el numero de ciudades (maximo %d): ", MAX_CIUDADES);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_CIUDADES) {
        printf("Numero de ciudades invalido. Debe ser un valor entre 1 y %d\n", MAX_CIUDADES);
        return 1;
    }

    // Solicitar al usuario las distancias entre ciudades
    printf("Ingrese las distancias entre las ciudades:\n");
    for (int i = 0; i < n; i++) {
        printf("Ciudad %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            printf("Distancia entre %d y %d: ", i + 1, j + 1);
            scanf("%d", &D[i][j]);
        }
        printf("\n");
    }

    // Realizar los cálculos solicitados
    ciudadMasCercana(n, D);
    ciudadMasLejana(n, D);
    longitudPromedio(n, D);
    ciudadMejorConectada(n, D);
    ciudadPeorConectada(n, D);

    return 0;
}*/

/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*
    7)  Se utiliza una matriz para cargar la información referida a las ventas realizadas por un
grupo de N (numerados de 1 a N) vendedores en cada una de las M zonas (numeradas de 1 a
M). Para ello, se lee un número no determinado de veces una terna formada por número de
vendedor, zona, venta. Cada vendedor puede realizar ventas en varias zonas y cada zona
puede corresponder a varios vendedores. Se desea emitir el listado de zonas con su total
por venta, ordenado en forma decreciente por venta. 
*/
/*
#include <stdio.h>

#define MAX_VENDEDORES 100
#define MAX_ZONAS 100

int main() {
    int ventas[MAX_VENDEDORES][MAX_ZONAS] = {0};
    int vendedor, zona, venta;
    int N = 0, M = 0;

    // Leer las ventas hasta que se introduzca un vendedor negativo
    while (1) {
        printf("Ingrese el número de vendedor (-1 para salir): ");
        scanf("%d", &vendedor);
        if (vendedor == -1) {
            break;
        }

        printf("Ingrese el número de zona: ");
        scanf("%d", &zona);

        printf("Ingrese el monto de la venta: ");
        scanf("%d", &venta);

        // Asegurarse de que los índices estén dentro de los límites
        if (vendedor >= 1 && vendedor <= MAX_VENDEDORES &&
            zona >= 1 && zona <= MAX_ZONAS) {
            ventas[vendedor - 1][zona - 1] += venta;
            if (vendedor > N) {
                N = vendedor;
            }
            if (zona > M) {
                M = zona;
            }
        } else {
            printf("Error: Vendedor o zona fuera de rango.\n");
        }
    }

    // Calcular el total de ventas por zona
    int total_por_zona[MAX_ZONAS] = {0};
    for (zona = 0; zona < M; zona++) {
        for (vendedor = 0; vendedor < N; vendedor++) {
            total_por_zona[zona] += ventas[vendedor][zona];
        }
    }

    // Ordenar las zonas en forma decreciente por ventas
    for (zona = 0; zona < M - 1; zona++) {
        for (int j = zona + 1; j < M; j++) {
            if (total_por_zona[zona] < total_por_zona[j]) {
                // Intercambiar las ventas y las zonas
                int temp = total_por_zona[zona];
                total_por_zona[zona] = total_por_zona[j];
                total_por_zona[j] = temp;
                // También se deben intercambiar las ventas de los vendedores correspondientes si es necesario
                for (vendedor = 0; vendedor < N; vendedor++) {
                    int temp_venta = ventas[vendedor][zona];
                    ventas[vendedor][zona] = ventas[vendedor][j];
                    ventas[vendedor][j] = temp_venta;
                }
            }
        }
    }

    // Mostrar el listado de zonas con su total por venta
    printf("\nListado de zonas ordenado por ventas decrecientes:\n");
    for (zona = 0; zona < M; zona++) {
        printf("Zona %d: %d\n", zona + 1, total_por_zona[zona]);
    }

    return 0;
}

*/
/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*
    8)  Una agencia tiene 5 vendedores. Cada uno se identifica con un número entero entre
1 y 120. Cada vendedor vende en distintas zonas. Las zonas son ‘a’, ‘b’, ‘c’. Cada
uno realiza una o más ventas. Se quiere emitir el listado de las ventas máximas
por vendedor, es decir el listado de los vendedores con el mayor monto que hayan
alcanzado en una operación de venta. En esta lista no deben figurar quienes no
hayan vendido nada. También se quiere los totales por zona. Para ello, se ingresa
un número no determinado de veces una terna: número de vendedor, número de zona,
monto de la operación. Los datos no están ordenados de manera alguna. El fin de
datos se indica con número de vendedor –1 y no se lee para el ni zona ni venta.
Escribir el programa que resuelva el problema.
*/
/*
#include <stdio.h>

#define NUM_VENDEDORES 5
#define NUM_ZONAS 3

int main() {
    int ventas[NUM_VENDEDORES][NUM_ZONAS] = {0};
    int vendedor, monto;
    char zona;
    int ventas_maximas[NUM_VENDEDORES] = {0};
    int total_por_zona[NUM_ZONAS] = {0};

    while (1) {
        printf("Ingrese el número de vendedor (-1 para salir): ");
        scanf("%d", &vendedor);

        if (vendedor == -1) {
            break;
        }

        printf("Ingrese la zona (a, b, c): ");
        scanf(" %c", &zona);

        printf("Ingrese el monto de la operación: ");
        scanf("%d", &monto);

        // Verificar si el vendedor ha alcanzado una venta máxima
        if (monto > ventas_maximas[vendedor - 1]) {
            ventas_maximas[vendedor - 1] = monto;
        }

        // Actualizar el total por zona
        if (zona == 'a') {
            total_por_zona[0] += monto;
        } else if (zona == 'b') {
            total_por_zona[1] += monto;
        } else if (zona == 'c') {
            total_por_zona[2] += monto;
        }

        // Actualizar las ventas del vendedor en la zona
        ventas[vendedor - 1][zona - 'a'] += monto;
    }

    printf("\nVentas máximas por vendedor:\n");
    for (int i = 0; i < NUM_VENDEDORES; i++) {
        if (ventas_maximas[i] > 0) {
            printf("Vendedor %d: %d\n", i + 1, ventas_maximas[i]);
        }
    }

    printf("\nTotales por zona:\n");
    for (int i = 0; i < NUM_ZONAS; i++) {
        printf("Zona %c: %d\n", 'a' + i, total_por_zona[i]);
    }

    return 0;
}
*/
/*--------------------------------------------------------------------------------------------------------------------------------------------*/
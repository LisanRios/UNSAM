/*
    1) Se define el tipo siguiente:
struct alumno {
char apellido[40];
char nombre[20];
float notajunio,notasept,notaprac;
}
En un archivo binario con datos de esta estructura (construye y carga con datos) disponemos de
los alumnos matriculados en una asignatura. Se quiere obtener un archivo de texto en el que
aparezca en cada línea el nombre de cada alumno con el formato apellidos, nombre, promedio. Hacer
un programa que realice esta tarea.
*/
/*
#include <stdio.h>
#include <string.h>

struct alumno {
    char apellido[40];
    char nombre[20];
    float notajunio, notasept, notaprac;
};

int main() {
    FILE *archivoBinario, *archivoTexto;
    struct alumno alumnoActual;
    float promedio;

    // Abrir el archivo binario para escritura
    archivoBinario = fopen("alumnos.dat", "wb");
    if (archivoBinario == NULL) {
        perror("Error al abrir el archivo binario");
        return 1;
    }

    // Datos de ejemplo de alumnos
    struct alumno alumnos[] = {
        {"Elva", "Ginon", 7.5, 8.0, 9.0},
        {"Elver", "Galarga", 6.0, 7.5, 8.5},
        {"Marcelo", "Agachateyconocelo", 8.0, 8.0, 7.0},
    };

    // Escribir los datos en el archivo binario
    fwrite(alumnos, sizeof(struct alumno), sizeof(alumnos) / sizeof(struct alumno), archivoBinario);

    // Cerrar el archivo binario
    fclose(archivoBinario);

    printf("Archivo binario 'alumnos.dat' creado y cargado con datos de ejemplo.\n");

    // Abrir el archivo binario para lectura
    archivoBinario = fopen("alumnos.dat", "rb");
    if (archivoBinario == NULL) {
        perror("Error al abrir el archivo binario");
        return 1;
    }

    // Abrir el archivo de texto para escritura
    archivoTexto = fopen("promedios.txt", "w");
    if (archivoTexto == NULL) {
        perror("Error al abrir el archivo de texto");
        fclose(archivoBinario);
        return 1;
    }

    // Leer y procesar cada registro del archivo binario
    while (fread(&alumnoActual, sizeof(struct alumno), 1, archivoBinario) == 1) {
        // Calcular el promedio
        promedio = (alumnoActual.notajunio + alumnoActual.notasept + alumnoActual.notaprac) / 3.0;

        // Escribir el nombre y promedio en el archivo de texto
        fprintf(archivoTexto, "%s, %s, %.2f\n", alumnoActual.apellido, alumnoActual.nombre, promedio);
    }

    // Cerrar los archivos
    fclose(archivoBinario);
    fclose(archivoTexto);

    printf("Archivo de texto 'promedios.txt' creado con éxito.\n");

    return 0;
}
*/
/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*
2) Tenemos un archivo de registros cuyas componentes están definidas según la declaración
siguiente:
struct registro1{
char partido[60];
char localidad[60];
int candidatos;
}
Se quiere sustituir la estructura del registro por el siguiente:
struct registro1{
char partido[60];
char localidad[60];
int candidatos,votos;
}
Escribir un programa que modifique la estructura y pase toda la información del archivo primitivo
al nuevo, inicializando a 0 el nuevo campo creado. El candidato es representado por un número
entero.
*/
#include <stdio.h>
#include <string.h>

struct registro1_original {
    char partido[60];
    char localidad[60];
    int candidatos;
};

struct registro1_nuevo {
    char partido[60];
    char localidad[60];
    int candidatos;
    int votos;
};

int main() {
    FILE *archivo_original, *archivo_nuevo;
    struct registro1_original registro_original;
    struct registro1_nuevo registro_nuevo;

    // Generar algunos registros de ejemplo y escribir en el archivo original
    archivo_original = fopen("registros_original.dat", "wb");
    if (archivo_original == NULL) {
        printf("No se pudo abrir el archivo de registros original.\n");
        return 1;
    }

    strcpy(registro_original.partido, "Eso para delante");
    strcpy(registro_original.localidad, "Cyrus");
    registro_original.candidatos = 5;
    fwrite(&registro_original, sizeof(struct registro1_original), 1, archivo_original);

    strcpy(registro_original.partido, "Frente de por halla y de esos");
    strcpy(registro_original.localidad, "Brigwoman");
    registro_original.candidatos = 4;
    fwrite(&registro_original, sizeof(struct registro1_original), 1, archivo_original);

    strcpy(registro_original.partido, "Le metemos por nuestra argentina");
    strcpy(registro_original.localidad, "Spaguetti");
    registro_original.candidatos = 3;
    fwrite(&registro_original, sizeof(struct registro1_original), 1, archivo_original);

    strcpy(registro_original.partido, "Unos para argentina, los argentinos los amigos"); 
    strcpy(registro_original.localidad, "Masita");
    registro_original.candidatos = 2;
    fwrite(&registro_original, sizeof(struct registro1_original), 1, archivo_original);

    strcpy(registro_original.partido, "Agrupados por el pelado");
    strcpy(registro_original.localidad, "Boomrich");
    registro_original.candidatos = 1;
    fwrite(&registro_original, sizeof(struct registro1_original), 1, archivo_original);

    fclose(archivo_original);

    // Abrir el archivo original en modo lectura y el archivo nuevo en modo escritura
    archivo_original = fopen("registros_original.dat", "rb");
    if (archivo_original == NULL) {
        printf("No se pudo abrir el archivo de registros original.\n");
        return 1;
    }

    archivo_nuevo = fopen("registros_nuevo.dat", "wb");
    if (archivo_nuevo == NULL) {
        printf("No se pudo abrir el archivo de registros nuevo.\n");
        fclose(archivo_original);
        return 1;
    }

    // Leer registros del archivo original y escribir en el archivo nuevo
    while (fread(&registro_original, sizeof(struct registro1_original), 1, archivo_original)) {
        strncpy(registro_nuevo.partido, registro_original.partido, sizeof(registro_nuevo.partido));
        strncpy(registro_nuevo.localidad, registro_original.localidad, sizeof(registro_nuevo.localidad));
        registro_nuevo.candidatos = registro_original.candidatos;
        registro_nuevo.votos = 0; // Inicializar el campo "votos" a 0

        fwrite(&registro_nuevo, sizeof(struct registro1_nuevo), 1, archivo_nuevo);
    }

    printf("Se ha modificado la estructura y copiado la información al nuevo archivo.\n");

    fclose(archivo_original);
    fclose(archivo_nuevo);

    return 0;
}

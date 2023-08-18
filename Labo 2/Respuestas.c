/*
    11. Dado el siguiente código
    main() {
        int a=1, b=2;
        mmm (___a, ___b);
        printf ("%d,%d", a, b);
    }
    void mmm (___ x, ___ y){
        ___x=___y+1;
        ___y=___y+___x;
    }

    Si el resultado impreso es: 1 y 5 (1,5) y teniendo en cuenta que algunos de los vacíos pueden no contener nada, indica cuál
de las siguientes afirmaciones es cierta:

   | No | En la línea 10 hay que colocar un total de tres *
   | No | En la línea 7 las dos variables x e y son de tipo pint 3
   | No | En la línea 9 hay que colocar un * delante de la variable x
   | Si | En la línea 4 hay que colocar un & delante de la variable b
   | No | Hay más de una respuesta correcta

*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
/*
   12. Desarrolla una función que emita los múltiplos de n menores que m. Tanto n como m serán dos parámetros de entrada de
la función.
*/
/*
#include <stdio.h>

void multiplos(int n, int m) {

    for (int i = 1; n * i < m; i++) {
        printf("%d\n", n * i);
    }
}

int main() {

    int n, m;
    printf("Escriba dos números: n y m, donde n es el múltiplo y m es el límite.\n");
    scanf("%d %d", &n, &m);
    multiplos(n, m);

    return 0;
}
*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
/*
    13. Construye una función que imprima la suma de los cuadrados de los n primeros números naturales, siendo n un valor
recibido como parámetro.
*/
/*
#include <stdio.h>
cuadrados(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d^2 = %d\n", i, i * i);
    }
    return 0;
}

int main() {
    int n;
    printf("Escriba un número: ");
    scanf("%d", &n);
    cuadrados(n);
    return 0;
}
*/
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
    14. Escribe dos funciones: Cada una de ellas debe calcular la superficie de un rectángulo en función de la base y la altura
(ambos datos tipo int). La primera función llamada area1() recibe los argumentos por valor y la segunda, area2(), por
referencia. Los resultado se deben imprimir en la función main()
*/
/*
#include <stdio.h>

int area1(int base, int altura){
    return base * altura;
}

int area2(int * base, int * altura){
    return *base * *altura;
}

int main() {
    int base, altura;
    printf("Escriba la base del rectángulo: ");
    scanf("%d", &base);
    printf("Escriba la altura del rectángulo: ");
    scanf("%d", &altura);
    printf("La superficie del rectángulo es: %d\n", area1(base, altura));
    printf("La superficie del rectángulo es: %d\n", area2(&base, &altura));

    return 0;
}
*/
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
    15. Sea el siguiente código
    void mmm (int ___);
    main() { 
        int a,b;
        mmm (___a);
        mmm (___b);
        printf ("%d", a+b);
    }
    void mmm (int ___ x) {
        scanf ("%d", ___x);
    }

    Si se introducen desde el teclado los valores 1 y 2, el resultado en pantalla es un 3. Teniendo en cuenta que algunas de las líneas en
blanco pueden no contener nada, indique cuántos símbolos & y * faltan en el código.

    | SI | Faltan dos * y dos &
    | NO | Faltan dos * y tres &
    | NO | No falta nada
    | NO | Faltan tres * y dos &
    | NO | Faltan tres & y ningún *
*/
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
    16. Escribe una función:
    void maxmin (int x1, int x2, int * max, int * min);

     que reciba como parámetros de entrada dos números enteros x1 y x2 y devuelva a través de los parámetros de
    salida max y min el máximo y el mínimo, respectivamente, de ambos números.
     Modifica la función anterior para que calcule también el valor medio de ambos números. El nuevo prototipo de la
    función será ahora el siguiente: void maxmin (int x1, int x2, int * max, int * min, int * media);
*/
/*
#include <stdio.h>

void maxmin(int x1, int x2, int *max, int *min){
    if (x1 > x2){
        *max = x1;
        *min = x2;
        printf("El valor máximo es: %d\n", *max);
        printf("El valor mínimo es: %d\n", *min);
    } else {
        *max = x2;
        *min = x1;
        printf("El valor máximo es: %d\n", *max);
        printf("El valor mínimo es: %d\n", *min);
    }
}

int main() {
    int x1, x2, *max = NULL, *min = NULL;
    printf("Escriba dos números enteros: ");
    scanf("%d %d", &x1, &x2);
    maxmin(x1, x2, &max, &min);
    return 0;
}
*/
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
    
*/
/*
#include <stdio.h>



int main() {
    

    return 0;
}
*//*---------------------------------------------------------------------------------------------------------------------------*/
/*
    
*/
/*
#include <stdio.h>



int main() {
    

    return 0;
}
*//*---------------------------------------------------------------------------------------------------------------------------*/
/*
    
*/
/*
#include <stdio.h>



int main() {
    

    return 0;
}
*//*---------------------------------------------------------------------------------------------------------------------------*/
/*
    
*/
/*
#include <stdio.h>



int main() {
    

    return 0;
}
*//*---------------------------------------------------------------------------------------------------------------------------*/
/*
    
*/
/*
#include <stdio.h>



int main() {
    

    return 0;
}
*//*---------------------------------------------------------------------------------------------------------------------------*/
/*
    
*/
/*
#include <stdio.h>



int main() {
    

    return 0;
}
*//*---------------------------------------------------------------------------------------------------------------------------*/
/*
    
*/
/*
#include <stdio.h>



int main() {
    

    return 0;
}
*//*---------------------------------------------------------------------------------------------------------------------------*/
/*
    
*/
/*
#include <stdio.h>



int main() {
    

    return 0;
}
*/









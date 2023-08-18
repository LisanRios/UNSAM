#include <stdio.h>

void intercambio1(void*,void*);
void intercambio2(void*,void*);

int main() {
int a=40,b=100;

printf("Direcci�n de a:%p y b:%p \n",&a,&b);
printf("En main valores de a:%d y b:%d\n\n\n",a,b);

intercambio1(&a,&b);

printf("\nEn main despu�s de intercambio1, direcci�n de a:%p y b:%p \n",&a,&b);
printf("En main valores de a:%d y b:%d\n",a,b);

intercambio2(&a,&b);
printf("\nEn main despu�s de intercambio2, direcci�n de a:%p y b:%p \n",&a,&b);
printf("En main valores de a:%d y b:%d\n",a,b);

return 0;
}

void intercambio1(void* a, void* b){
    void* aux;
    printf("\n\nDentro de intercambio1, direcciones: a=%p, b=%p\n",a,b);
    aux = a;
    a = b;
    b = aux;
    printf("\n\nDentro de intercambio1 despu�s del intercambio: a=%p, b=%p\n",a,b);
}

void intercambio2(void* a, void* b){
    int aux;
    printf("\n\nDentro de intercambio2, direcciones: a=%p, b=%p\n",a,b);
    aux = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = aux;
    printf("\n\nDentro de intercambio2 despu�s del intercambio, valores de: a=%d, b=%d\n",*(int*)a,*(int*)b);
}

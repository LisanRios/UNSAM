#include <stdio.h>

struct persona{
int leg;
char ape[20];
float suel;
};

int main(){
struct persona unapersona;
FILE *pArchivo;
float suma=0;
pArchivo=fopen("empleados.dat","rb");

if(pArchivo!=NULL){
fread(&unapersona,sizeof(struct persona),1,pArchivo);
while(!feof(pArchivo)){
	printf("%d%10s%10.2f\n", unapersona.leg,unapersona.ape,unapersona.suel);
    fread(&unapersona,sizeof(struct persona),1,pArchivo);
    suma = suma + unapersona.suel;
}
printf("La suma de sueldos es: %f", suma);
fclose(pArchivo);
}
else{printf("Error en la apertura del archivo");}
getchar();
return 0;
}

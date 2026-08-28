#include <stdio.h>
#include <stdlib.h>

#define N 3
#define POSIBILIDADES 27

void pintarEncabezado();
void pintarSaltoDeLineaDoble();

int main()
{
    pintarEncabezado();

    int peso;
    printf("Ingrese el peso a buscar: ");
    scanf("%d", &peso);

    int cont=0;
    int cadena[N];

    for (int i = 0; i < N; i++) {
        cadena[i] = i;

        for (int j = 0; j < N; j++) {
            cadena[j] = j;

            for (int k = 0; k < N; k++) {
                cadena[k] = k;
                printf("%d %d %d \n", i, j, k);

                if (i+j+k == peso)
                    cont++;

            }
        }
    }

    printf("El numero de cadenas con peso=%d de las %d posibles es: %d", peso, POSIBILIDADES, cont);
    pintarSaltoDeLineaDoble();

    return 0;
}


void pintarEncabezado() {
    printf("UNIVERSIDAD AUTONOMA DE AGUASCALIENTES\n");
    printf("LITC - 9°\n");
    printf("ASIGNATURA:  TEORIA DE TECNICAS MODERNAS DE INFORMATICA\n");
    printf("ALUMNO:      ELIAS EDUARDO CARDONA RODRIGUEZ \n\n");
    printf("Ejercicio 28 de agosto - Combinatoria \n\n");
}


void pintarSaltoDeLineaDoble() {
    printf("\n\n");
}



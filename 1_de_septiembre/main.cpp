#include <stdio.h>
#include <stdlib.h>

void pintarEncabezado();
void pintarSaltoDeLinea();
void pintarSaltoDeLineaDoble();

int main() {
    pintarEncabezado();

    const unsigned int VALOR_R = 2;

    unsigned int n = 0;

    printf("Ingrese el valor para n: ");
    scanf("%u", &n);

    if (n < 2 || n > 100) {
        printf("El valor de n debe estar entre 2 y 100.\n");
        return 1;
    }

    /* Genera los valores 1, 2, 3, ..., n */
    unsigned int arreglo[n];
    unsigned int cont = 0;

    for (unsigned int i = 0; i < n; i++) {
        arreglo[i] = i + 1;
    }

    for (unsigned int i = 0; i < n; i++) {
        printf("%u, ", arreglo[i]);
    }

    pintarSaltoDeLineaDoble();

    /* Generar las combinaciones */
    for (unsigned int i = 0; i < n; i++) {

        for (unsigned int j = i + 1; j < n; j++) {

            printf("%u, %u\n", arreglo[i], arreglo[j]);
            cont++;
        }
    }

    pintarSaltoDeLineaDoble();
    printf("Combinaciones distintas de C(%u, %u): %u\n\n", n, VALOR_R, cont);
    pintarSaltoDeLineaDoble();

    return 0;
}


void pintarEncabezado() {
    printf("UNIVERSIDAD AUTONOMA DE AGUASCALIENTES\n");
    printf("LITC - 9°\n");
    printf("ASIGNATURA: TEORIA DE TECNICAS MODERNAS DE INFORMATICA\n");
    printf("ALUMNO: ELIAS EDUARDO CARDONA RODRIGUEZ\n\n");
    printf("Ejercicio 28 de agosto - Combinatoria\n\n");
}


void pintarSaltoDeLinea() {
    printf("\n");
}


void pintarSaltoDeLineaDoble() {
    printf("\n\n");
}


#include <stdio.h>
#include <stdlib.h>

#define LIMITE_OCTAL 8

void pintarEncabezado();
void pintarSaltoDeLinea();
void pintarSaltoDeLineaDoble();

int main() {
    pintarEncabezado();

    const unsigned int VALOR_R = 3;

    unsigned int octales[LIMITE_OCTAL] = {0, 1, 2, 3, 4, 5, 6, 7};
    unsigned int cont = 0;

    /* Generar las combinaciones */
    for (unsigned int i = 0; i < LIMITE_OCTAL; i++) {

        for (unsigned int j = 0; j < LIMITE_OCTAL; j++) {

            for (unsigned int k = 0; k < LIMITE_OCTAL; k++) {

                printf("%u, %u, %u\n", octales[i], octales[j], octales[k]);

                unsigned int suma = octales[i] + octales[j] + octales[k];

                if (suma == 15) {
                    cont++;
                }
            }
            printf("----------");
            pintarSaltoDeLinea();
        }
    }

    pintarSaltoDeLineaDoble();
    printf("Codigos octales de 3 digitos que suman 15: %u\n\n", cont);
    pintarSaltoDeLineaDoble();

    return 0;
}


void pintarEncabezado() {
    printf("UNIVERSIDAD AUTONOMA DE AGUASCALIENTES\n");
    printf("LITC - 9°\n");
    printf("ASIGNATURA: TEORIA DE TECNICAS MODERNAS DE INFORMATICA\n");
    printf("ALUMNO: ELIAS EDUARDO CARDONA RODRIGUEZ\n\n");
    printf("Ejercicio 1er parcial - Encontrar los codigos octales que suman 15 con 3 digitos \n\n");
}


void pintarSaltoDeLinea() {
    printf("\n");
}


void pintarSaltoDeLineaDoble() {
    printf("\n\n");
}


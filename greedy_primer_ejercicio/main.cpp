#include <stdio.h>
#include <stdlib.h>

#define NUM_MONEDAS 8

void pintarEncabezado();
void pintarSaltoDeLinea();
void pintarSaltoDeLineaDoble();
void mostrarOpciones();
void sinRestricciones();
void pintarInstrucciones();


int main() {
    pintarEncabezado();
    pintarInstrucciones();

    return 0;
}


void pintarEncabezado() {
    printf("UNIVERSIDAD AUTONOMA DE AGUASCALIENTES\n");
    printf("LITC - 9°\n");
    printf("ASIGNATURA: TEORIA DE TECNICAS MODERNAS DE INFORMATICA\n");
    printf("ALUMNO: ELIAS EDUARDO CARDONA RODRIGUEZ\n\n");
    printf("Ejercicio del dia 7 de septiembre - Familia en el cine\n\n");
}


void pintarSaltoDeLinea() {
    printf("\n");
}


void pintarSaltoDeLineaDoble() {
    printf("\n\n");
}


void pintarInstrucciones() {
    pintarSaltoDeLinea();
	printf("\tMENU\n");
	printf(" Monedas disponibles:        \n");
	printf(" 25, 20, 15, 10, 7, 5, 3, 1  \n");
	printf(" Ingrese el cambio a entregar: ");
}


void sinRestricciones() {

    unsigned int conjunto_candidatos[NUM_MONEDAS] = {25, 20, 15, 10, 7, 5, 3, 1};
    unsigned int conjunto_tabu[NUM_MONEDAS] = {0};
    unsigned int conteo_permutaciones = 0;

    pintarSaltoDeLineaDoble();

    for (unsigned int i = 0; i < INTEGRANTES_FAMILIA; i++) {

        for (unsigned int j = 0; j < INTEGRANTES_FAMILIA; j++) {

                    if (l == i || l == j || l == k)
                        continue;

                        printf("%u, %u, %u, %u, %u\n",
                               familia[i],
                               familia[j],
                               familia[k],
                               familia[l],
                               familia[m]);

                        conteo_permutaciones++;
                    
                
            }
        }


    pintarSaltoDeLineaDoble();

    printf(
        "Cantidad de permutaciones validas de una familia "
        "sentada en el cine (sin restriccion en el orden): %u\n\n",
        conteo_permutaciones
    );
}


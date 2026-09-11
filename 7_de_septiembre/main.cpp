#include <stdio.h>
#include <stdlib.h>

#define INTEGRANTES_FAMILIA 5

void pintarEncabezado();
void pintarSaltoDeLinea();
void pintarSaltoDeLineaDoble();
void mostrarOpciones();
void sinRestricciones();
void padresEnLosExtremos();
void mostrarMenu();


int main() {
    pintarEncabezado();
    mostrarMenu();

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


void mostrarOpciones() {
    pintarSaltoDeLinea();
	printf("\tMENU\n");
	printf("1. mostrar solucion sin restricciones\n");
	printf("2. mostrar solucion con los padres en los extremos\n");
	printf("3. salir del programa\n");
	printf("   ingrese una opcion: ");
}


void sinRestricciones() {

    unsigned int familia[INTEGRANTES_FAMILIA] = {1, 2, 3, 4, 5};
    unsigned int conteo_permutaciones = 0;

    pintarSaltoDeLineaDoble();

    for (unsigned int i = 0; i < INTEGRANTES_FAMILIA; i++) {

        for (unsigned int j = 0; j < INTEGRANTES_FAMILIA; j++) {

            if (j == i)
                continue;

            for (unsigned int k = 0; k < INTEGRANTES_FAMILIA; k++) {

                if (k == i || k == j)
                    continue;

                for (unsigned int l = 0; l < INTEGRANTES_FAMILIA; l++) {

                    if (l == i || l == j || l == k)
                        continue;

                    for (unsigned int m = 0; m < INTEGRANTES_FAMILIA; m++) {

                        if (m == i || m == j || m == k || m == l)
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
            }
        }
    }

    pintarSaltoDeLineaDoble();

    printf(
        "Cantidad de permutaciones validas de una familia "
        "sentada en el cine (sin restriccion en el orden): %u\n\n",
        conteo_permutaciones
    );
}


void padresEnLosExtremos() {

    unsigned int padres[2] = {1, 2};
    unsigned int hijos[3] = {3, 4, 5};

    unsigned int conteo_permutaciones = 0;

    pintarSaltoDeLineaDoble();

    /*
     * Los padres ocupan las posiciones 0 y 4.
     * Los hijos ocupan las posiciones 1, 2 y 3.
     */

    for (unsigned int i = 0; i < 2; i++) {

        for (unsigned int j = 0; j < 2; j++) {

            /* El mismo padre no puede ocupar ambos extremos */
            if (j == i)
                continue;

            for (unsigned int k = 0; k < 3; k++) {

                for (unsigned int l = 0; l < 3; l++) {

                    if (l == k)
                        continue;

                    for (unsigned int m = 0; m < 3; m++) {

                        if (m == k || m == l)
                            continue;

                        printf(
                            "%u, %u, %u, %u, %u\n",
                            padres[i],
                            hijos[k],
                            hijos[l],
                            hijos[m],
                            padres[j]
                        );

                        conteo_permutaciones++;
                    }
                }
            }
        }
    }

    pintarSaltoDeLineaDoble();

    printf(
        "Cantidad de permutaciones validas de una familia "
        "sentada en el cine (con los padres en los extremos): %u\n\n",
        conteo_permutaciones
    );
}


void mostrarMenu() {
    int opcion;
    while(1) {
		mostrarOpciones();
        scanf("%u", &opcion);
        pintarSaltoDeLinea();

        switch(opcion) {
			case 1: {
				sinRestricciones();
			}
			break;

			case 2: {
                padresEnLosExtremos();
			}
			break;

			case 3: {
				exit(0);
			}
			break;


			default:
				printf("opcion no valida");
			break;
		}
	}
}




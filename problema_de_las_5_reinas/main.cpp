#include <stdio.h>
#include <stdlib.h>

#define FILAS 5
#define COLUMNAS 5

void colocarReinas(unsigned int tablero[FILAS][COLUMNAS]);
bool revisarDiagonal(unsigned int tablero[FILAS][COLUMNAS], unsigned int index_filas, unsigned int index_columnas);
void pintarEncabezado();
void pintarSaltoDeLinea();
void pintarSaltoDeLineaDoble();

int main() {
    pintarEncabezado();
    mostrarMenu();

    unsigned int tablero[FILAS][COLUMNAS] = {0};

    colocarReinas(tablero);

    return 0;
}


void colocarReinas(unsigned int tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            // En la iteración con índice 0 para filas, nunca se revisa la diagonal
            tablero[i][j] = 1;
            // En el primer elemento se coloca una reina
            // En el segundo elemento se coloca una reina
            // En el tercer elemento se coloca una reina
            // En el cuarto elemento se coloca una reina
            // En el quinto elemento se coloca una reina
            //
            // La primera fila está llena
            //
            // Se comienza a iterar en la segunda fila
            //
            bool estaOcupadaLaDiagonal = revisarDiagonal(tablero, i, j);
        }
    }
}


bool revisarDiagonal(unsigned int tablero[FILAS][COLUMNAS], unsigned int index_filas, unsigned int index_columnas) {
    if (index_filas > 0) {
        /*
            0 1 1 0 0
            0 0 0 0 0
            1 0 0 0 0
            0 0 0 0 0
            0 0 0 0 0
         */
        if (index_columnas > 0) {
            if (tablero[index_filas-1][index_columnas-1] = 1) {
                // Aquí se debe reducir recursivamente el índice,
                // de modo que no sólo se revisa index-1, sino
                // index-n donde, n va disminuyendo de uno en uno
            }
        }
    }
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


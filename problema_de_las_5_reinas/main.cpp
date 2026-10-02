#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILAS 5
#define COLUMNAS 5
#define NUMERO_REINAS 5

#define NUMERO_SOLUCIONES_A_MOSTRAR 5

void colocarReinas(
    unsigned int tablero[FILAS][COLUMNAS],
    unsigned int numero_reina
);

bool revisarTablero(
    unsigned int tablero[FILAS][COLUMNAS]
);

bool revisarDirecciones(
    unsigned int tablero[FILAS][COLUMNAS],
    unsigned int index_filas,
    unsigned int index_columnas
);

unsigned long long calcularPosibilidades();

void guardarSolucion(
    unsigned int tablero[FILAS][COLUMNAS]
);

void pintarUltimasSoluciones();

void pintarTablero(
    unsigned int tablero[FILAS][COLUMNAS]
);

void pintarEncabezado();
void pintarSaltoDeLinea();
void pintarSaltoDeLineaDoble();


/*
    Aquí almacenaremos solamente las últimas 5 soluciones.

    No necesitamos guardar las 9,765,625 posibilidades.

    Solamente necesitamos:

        5 soluciones
        x
        5 filas
        x
        5 columnas
*/
unsigned int ultimasSoluciones[
    NUMERO_SOLUCIONES_A_MOSTRAR
][FILAS][COLUMNAS] = {0};


/*
    Cantidad total de soluciones encontradas.

    Esta variable puede superar 5.

    Por ejemplo:

        solución 1
        solución 2
        ...
        solución 10

    Al encontrar la solución 6, sobrescribiremos
    la solución 1 almacenada.

    Al encontrar la solución 10, tendremos almacenadas
    las soluciones 6, 7, 8, 9 y 10.
*/
unsigned long long cantidadSoluciones = 0;


int main() {

    pintarEncabezado();

    unsigned int tablero[FILAS][COLUMNAS] = {0};

    unsigned long long posibilidades = calcularPosibilidades();

    printf(
        "Numero total de posibilidades: %llu\n",
        posibilidades
    );

    pintarSaltoDeLineaDoble();

    /*
        Comenzamos a colocar la primera reina.

        Esta función recorrerá las 9,765,625 posibilidades.
    */
    colocarReinas(tablero, 0);

    /*
        La impresión se realiza DESPUÉS de terminar
        toda la búsqueda.

        De esta manera sabemos cuáles fueron realmente
        las últimas 5 soluciones encontradas.
    */
    pintarUltimasSoluciones();

    return 0;
}


/*
    Calcula:

        25^5

    porque tenemos:

        25 casillas disponibles
        5 reinas

    y cada reina puede ser colocada en cualquiera
    de las 25 casillas.
*/
unsigned long long calcularPosibilidades() {

    unsigned long long posibilidades = 1;

    for (int i = 0; i < NUMERO_REINAS; i++) {

        posibilidades =
            posibilidades * (FILAS * COLUMNAS);
    }

    return posibilidades;
}


/*
    Fuerza bruta.

    No descartamos una posibilidad antes de tiempo.

    Cada reina puede ocupar cualquiera de las 25 casillas.

    Por lo tanto:

        25 x 25 x 25 x 25 x 25

        = 25^5

        = 9,765,625 posibilidades
*/
void colocarReinas(
    unsigned int tablero[FILAS][COLUMNAS],
    unsigned int numero_reina
) {

    /*
        Si ya colocamos las 5 reinas,
        tenemos una configuración completa.

        Ahora podemos comprobar si es válida.
    */
    if (numero_reina == NUMERO_REINAS) {

        if (revisarTablero(tablero)) {

            /*
                Encontramos una solución.

                La guardamos, pero NO la imprimimos todavía.
            */
            guardarSolucion(tablero);
        }

        return;
    }


    /*
        Recorremos todas las filas.
    */
    for (int i = 0; i < FILAS; i++) {

        /*
            Recorremos todas las columnas.
        */
        for (int j = 0; j < COLUMNAS; j++) {

            /*
                Colocamos una reina.

                Usamos ++ porque puede existir una posibilidad
                en la que varias reinas ocupen la misma casilla.
            */
            tablero[i][j]++;


            /*
                Intentamos colocar la siguiente reina.
            */
            colocarReinas(
                tablero,
                numero_reina + 1
            );


            /*
                Terminamos de analizar todas las posibilidades
                que comienzan con esta posición.

                Retiramos la reina para probar otra casilla.
            */
            tablero[i][j]--;
        }
    }
}


/*
    Guarda una solución dentro del arreglo de las
    últimas soluciones.

    Utilizamos:

        cantidadSoluciones % 5

    para determinar en qué posición almacenarla.

    Ejemplo:

        solución 1 -> posición 0
        solución 2 -> posición 1
        solución 3 -> posición 2
        solución 4 -> posición 3
        solución 5 -> posición 4
        solución 6 -> posición 0
        solución 7 -> posición 1

    De esta manera vamos sobrescribiendo las soluciones
    más antiguas.
*/
void guardarSolucion(
    unsigned int tablero[FILAS][COLUMNAS]
) {

    unsigned int posicion =
        cantidadSoluciones % NUMERO_SOLUCIONES_A_MOSTRAR;


    /*
        Copiamos todo el tablero de la solución encontrada
        hacia el arreglo donde almacenamos las últimas 5.
    */
    for (int i = 0; i < FILAS; i++) {

        for (int j = 0; j < COLUMNAS; j++) {

            ultimasSoluciones[posicion][i][j] =
                tablero[i][j];
        }
    }


    /*
        Ya encontramos una solución más.
    */
    cantidadSoluciones++;
}


/*
    Imprime únicamente las últimas 5 soluciones encontradas.
*/
void pintarUltimasSoluciones() {

    pintarSaltoDeLineaDoble();

    printf(
        "Cantidad total de soluciones encontradas: %llu\n",
        cantidadSoluciones
    );

    pintarSaltoDeLineaDoble();

    printf(
        "Ultimas %d soluciones encontradas:\n",
        NUMERO_SOLUCIONES_A_MOSTRAR
    );

    pintarSaltoDeLinea();


    /*
        Si encontramos menos de 5 soluciones,
        solamente imprimimos las que realmente existen.
    */
    unsigned long long cantidadAImprimir =
        cantidadSoluciones < NUMERO_SOLUCIONES_A_MOSTRAR
        ? cantidadSoluciones
        : NUMERO_SOLUCIONES_A_MOSTRAR;


    /*
        Calculamos dónde comienza nuestro arreglo circular.

        Si encontramos exactamente 10 soluciones:

            solución 6 -> posición 0
            solución 7 -> posición 1
            solución 8 -> posición 2
            solución 9 -> posición 3
            solución 10 -> posición 4

        Por lo tanto debemos comenzar en la posición 0.
    */
    unsigned int posicionInicial =
        cantidadSoluciones < NUMERO_SOLUCIONES_A_MOSTRAR
        ? 0
        : cantidadSoluciones % NUMERO_SOLUCIONES_A_MOSTRAR;


    for (unsigned int i = 0; i < cantidadAImprimir; i++) {

        unsigned int posicion =
            (posicionInicial + i)
            % NUMERO_SOLUCIONES_A_MOSTRAR;


        printf(
            "Solucion %llu:\n",
            cantidadSoluciones
            - cantidadAImprimir
            + i
            + 1
        );

        pintarTablero(
            ultimasSoluciones[posicion]
        );

        pintarSaltoDeLinea();
    }
}


/*
    Revisa todo el tablero.

    Cada vez que encuentra una reina,
    revisa sus 8 posibles direcciones de ataque.
*/
bool revisarTablero(
    unsigned int tablero[FILAS][COLUMNAS]
) {

    for (int i = 0; i < FILAS; i++) {

        for (int j = 0; j < COLUMNAS; j++) {

            if (tablero[i][j] > 0) {

                if (!revisarDirecciones(
                    tablero,
                    i,
                    j
                )) {

                    return false;
                }
            }
        }
    }

    return true;
}


/*
    Revisa las 8 direcciones posibles de ataque.
*/
bool revisarDirecciones(
    unsigned int tablero[FILAS][COLUMNAS],
    unsigned int index_filas,
    unsigned int index_columnas
) {

    /*
        Si hay más de una reina en la misma casilla,
        la configuración es inválida.
    */
    if (tablero[index_filas][index_columnas] > 1) {
        return false;
    }


    /*
        Convertimos los índices a int antes de restar.

        Esto evita problemas con unsigned int cuando
        queremos llegar hasta -1.
    */

    int fila = (int) index_filas;
    int columna = (int) index_columnas;


    /*
        1. ARRIBA
    */
    for (int i = fila - 1; i >= 0; i--) {

        if (tablero[i][columna] > 0) {
            return false;
        }
    }


    /*
        2. ABAJO
    */
    for (int i = fila + 1; i < FILAS; i++) {

        if (tablero[i][columna] > 0) {
            return false;
        }
    }


    /*
        3. IZQUIERDA
    */
    for (int j = columna - 1; j >= 0; j--) {

        if (tablero[fila][j] > 0) {
            return false;
        }
    }


    /*
        4. DERECHA
    */
    for (int j = columna + 1; j < COLUMNAS; j++) {

        if (tablero[fila][j] > 0) {
            return false;
        }
    }


    /*
        5. DIAGONAL SUPERIOR IZQUIERDA
    */
    for (
        int i = fila - 1, j = columna - 1;
        i >= 0 && j >= 0;
        i--, j--
    ) {

        if (tablero[i][j] > 0) {
            return false;
        }
    }


    /*
        6. DIAGONAL SUPERIOR DERECHA
    */
    for (
        int i = fila - 1, j = columna + 1;
        i >= 0 && j < COLUMNAS;
        i--, j++
    ) {

        if (tablero[i][j] > 0) {
            return false;
        }
    }


    /*
        7. DIAGONAL INFERIOR IZQUIERDA
    */
    for (
        int i = fila + 1, j = columna - 1;
        i < FILAS && j >= 0;
        i++, j--
    ) {

        if (tablero[i][j] > 0) {
            return false;
        }
    }


    /*
        8. DIAGONAL INFERIOR DERECHA
    */
    for (
        int i = fila + 1, j = columna + 1;
        i < FILAS && j < COLUMNAS;
        i++, j++
    ) {

        if (tablero[i][j] > 0) {
            return false;
        }
    }


    return true;
}


/*
    Imprime visualmente un tablero.
*/
void pintarTablero(
    unsigned int tablero[FILAS][COLUMNAS]
) {

    for (int i = 0; i < FILAS; i++) {

        for (int j = 0; j < COLUMNAS; j++) {

            if (tablero[i][j] > 0) {
                printf(" Q ");
            }
            else {
                printf(" . ");
            }
        }

        pintarSaltoDeLinea();
    }
}


void pintarEncabezado() {

    printf("UNIVERSIDAD AUTONOMA DE AGUASCALIENTES\n");
    printf("LITC - 9°\n");
    printf("ASIGNATURA: TEORIA DE TECNICAS MODERNAS DE INFORMATICA\n");
    printf("ALUMNO: ELIAS EDUARDO CARDONA RODRIGUEZ\n\n");
    printf("Ejercicio de las 5 reinas - Fuerza Bruta\n\n");
}


void pintarSaltoDeLinea() {
    printf("\n");
}


void pintarSaltoDeLineaDoble() {
    printf("\n\n");
}


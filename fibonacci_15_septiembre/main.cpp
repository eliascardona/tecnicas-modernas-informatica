#include <stdio.h>
#include <stdlib.h>

#define MAX_FIBONACCI 18

unsigned long long fibonacci(
    unsigned int n,
    unsigned long long conteoLlamadas[]
);

void pintarConteoLlamadas(
    unsigned int n,
    unsigned long long conteoLlamadas[]
);

void pintarEncabezado();
void pintarSaltoDeLinea();
void pintarSaltoDeLineaDoble();


int main() {
    pintarEncabezado();

    unsigned int n;

    printf("Ingrese un valor para n: ");
    scanf("%u", &n);


    /*
        El arreglo almacenara cuantas veces se llamo
        a la funcion fibonacci() con cada parametro.

        Por ejemplo:

            conteoLlamadas[0]

        indica cuantas veces se calculo fibonacci(0).

        Y:

            conteoLlamadas[5]

        indica cuantas veces se calculo fibonacci(5).
    */
    unsigned long long conteoLlamadas[MAX_FIBONACCI + 1] = {0};


    /*
        Comenzamos el problema desde fibonacci(n).

        La funcion se encargara de dividir el problema
        en fibonacci(n - 1) y fibonacci(n - 2).
    */
    unsigned long long resultado =
        fibonacci(n, conteoLlamadas);


    pintarSaltoDeLinea();

    printf("Fibonacci de %u = %llu\n", n, resultado);

    pintarSaltoDeLineaDoble();


    /*
        Ahora mostramos cuantas veces fue calculado
        cada parametro durante la ejecucion.
    */
    pintarConteoLlamadas(n, conteoLlamadas);


    return 0;
}


/*
    Esta es la funcion principal del problema.

    La sucesion de Fibonacci se define como:

        F(0) = 0
        F(1) = 1

    Y para cualquier n mayor que 1:

        F(n) = F(n - 1) + F(n - 2)


    Aqui aparece la estrategia de DIVIDE Y VENCERAS.

    Para resolver:

        fibonacci(n)

    dividimos el problema en:

        fibonacci(n - 1)

    y:

        fibonacci(n - 2)

    Despues combinamos ambos resultados
    mediante una suma.
*/
unsigned long long fibonacci(
    unsigned int n,
    unsigned long long conteoLlamadas[]
) {

    /*
        Cada vez que esta funcion recibe un parametro,
        registramos una llamada.

        Si n = 5:

            conteoLlamadas[5]++

        Si posteriormente volvemos a calcular fibonacci(5),
        volveremos a incrementar el mismo contador.
    */
    conteoLlamadas[n]++;


    /*
        CASO BASE 1

        Si n es 0:

            F(0) = 0

        Ya no necesitamos dividir el problema.
    */
    if (n == 0) {
        return 0;
    }


    /*
        CASO BASE 2

        Si n es 1:

            F(1) = 1

        Nuevamente ya no necesitamos dividir
        el problema.
    */
    if (n == 1) {
        return 1;
    }


    /*
        DIVIDIR

        El problema fibonacci(n) se divide en
        dos problemas mas pequeños:

            fibonacci(n - 1)

            fibonacci(n - 2)
    */
    unsigned long long fibonacciAnterior =
        fibonacci(n - 1, conteoLlamadas);

    unsigned long long fibonacciAnteriorDos =
        fibonacci(n - 2, conteoLlamadas);


    /*
        VENCER

        Cada uno de los problemas anteriores
        ya fue resuelto por las llamadas recursivas.

        Ahora tenemos:

            fibonacciAnterior
            fibonacciAnteriorDos
    */


    /*
        COMBINAR

        Para obtener fibonacci(n), sumamos
        los resultados de los dos subproblemas.
    */
    return fibonacciAnterior + fibonacciAnteriorDos;
}


/*
    Esta funcion muestra el conteo de llamadas.

    Solamente mostramos los parametros desde:

        0

    hasta:

        n

    porque son los valores que pueden aparecer
    durante el calculo de fibonacci(n).
*/
void pintarConteoLlamadas(
    unsigned int n,
    unsigned long long conteoLlamadas[]
) {

    printf("Conteo de llamadas:\n\n");


    for (unsigned int i = 0; i <= n; i++) {

        printf(
            "fibonacci(%u) -> %llu llamadas\n",
            i,
            conteoLlamadas[i]
        );
    }
}


void pintarEncabezado() {
    printf("UNIVERSIDAD AUTONOMA DE AGUASCALIENTES\n");
    printf("LITC - 9°\n");
    printf("ASIGNATURA: TEORIA DE TECNICAS MODERNAS DE INFORMATICA\n");
    printf("ALUMNO: ELIAS EDUARDO CARDONA RODRIGUEZ\n\n");
    printf("Ejercicio de Fibonacci - Divide y Venceras\n\n");
}


void pintarSaltoDeLinea() {
    printf("\n");
}


void pintarSaltoDeLineaDoble() {
    printf("\n\n");
}


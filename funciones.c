#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 10

void ingresarDatos(char nombres[MAX_PRODUCTOS][50], float precios[MAX_PRODUCTOS], int totalProductos) {
    for (int i = 0; i < totalProductos; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fgets(nombres[i], 50, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = 0;

        // Validar que el precio sea positivo
        do {
            printf("Ingrese el precio de %s: ", nombres[i]);
            scanf("%f", &precios[i]);
            if (precios[i] < 0) {
                printf("Error: El precio no puede ser negativo.\n");
            }
        } while (precios[i] < 0);  // Repetir si el precio es negativo.

        getchar();  // Limpiar el buffer
    }
}

float calcularPrecioTotal(float precios[MAX_PRODUCTOS], int totalProductos) {
    float total = 0.0;
    for (int i = 0; i < totalProductos; i++) {
        total += precios[i];
    }
    return total;
}

float encontrarCaroYBarato(char nombres[MAX_PRODUCTOS][50], float precios[MAX_PRODUCTOS], int totalProductos) {
    int indiceCaro = 0, indiceBarato = 0;
    for (int i = 1; i < totalProductos; i++) {
        if (precios[i] > precios[indiceCaro]) {
            indiceCaro = i;
        }
        if (precios[i] < precios[indiceBarato]) {
            indiceBarato = i;
        }
    }
    printf("El producto más caro es '%s' con un precio de %.2f\n", nombres[indiceCaro], precios[indiceCaro]);
    printf("El producto más barato es '%s' con un precio de %.2f\n", nombres[indiceBarato], precios[indiceBarato]);
}

float calcularPromedio(float precios[MAX_PRODUCTOS], int totalProductos) {
    return calcularPrecioTotal(precios, totalProductos) / totalProductos;
}

void buscarProducto(char nombres[MAX_PRODUCTOS][50], float precios[MAX_PRODUCTOS], int totalProductos, char nombreBuscado[50]) {
    for (int i = 0; i < totalProductos; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("El precio de %s es %.2f\n", nombres[i], precios[i]);
            return;
        }
    }
    printf("Producto '%s' no encontrado.\n", nombreBuscado);
}


#include <stdio.h>
#include <string.h>
#include "funciones.h"

float ingresarDatos(char nombres[MAX_PRODUCTOS][20], float precios[MAX_PRODUCTOS], int totalProductos) {
    for (int i = 0; i < totalProductos; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%s", nombres[i]);
        printf("Ingrese el precio de %s: ", nombres[i]);
        scanf("%f", &precios[i]);
    }
}

float calcularPrecioTotal(float precios[MAX_PRODUCTOS], int totalProductos) {
    float total = 0.0;
    for (int i = 0; i < totalProductos; i++) {
        total += precios[i];
    }
    return total;
}

float encontrarCaroYBarato(char nombres[MAX_PRODUCTOS][20], float precios[MAX_PRODUCTOS], int totalProductos) {
    int indiceCaro = 0, indiceBarato = 0;
    for (int i = 1; i < totalProductos; i++) {
        if (precios[i] > precios[indiceCaro]) {
            indiceCaro = i;
        }
        if (precios[i] < precios[indiceBarato]) {
            indiceBarato = i;
        }
    }
    printf("El producto mas caro es '%s' con un precio de %.2f\n", nombres[indiceCaro], precios[indiceCaro]);
    printf("El producto mas barato es '%s' con un precio de %.2f\n", nombres[indiceBarato], precios[indiceBarato]);
}

float calcularPromedio(float precios[MAX_PRODUCTOS], int totalProductos) {
    return calcularPrecioTotal(precios, totalProductos) / totalProductos;
}

void buscarProducto(char nombres[MAX_PRODUCTOS][20], float precios[MAX_PRODUCTOS], int totalProductos, char nombreBuscado[20]) {
    for (int i = 0; i < totalProductos; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("El precio de %s es %.2f\n", nombres[i], precios[i]);
            return;
        }
    }
    printf("Producto '%s' no encontrado.\n", nombreBuscado);
}

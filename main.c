#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PRODUCTOS][20];
    float precios[MAX_PRODUCTOS];
    int totalProductos = 0;

    printf("Cuantos productos desea ingresar (maximo %d): ", MAX_PRODUCTOS);
    scanf("%d", &totalProductos);
    if (totalProductos > MAX_PRODUCTOS) {
        totalProductos = MAX_PRODUCTOS;
    }

    ingresarDatos(nombres, precios, totalProductos);
    printf("El precio total del inventario es: %.2f\n", calcularPrecioTotal(precios, totalProductos));
    encontrarCaroYBarato(nombres, precios, totalProductos);
    printf("El precio promedio de los productos es: %.2f\n", calcularPromedio(precios, totalProductos));

    char nombreBuscado[20];
    printf("Ingrese el nombre del producto que desea buscar: ");
    scanf("%s", nombreBuscado);
    buscarProducto(nombres, precios, totalProductos, nombreBuscado);

    return 0;
}
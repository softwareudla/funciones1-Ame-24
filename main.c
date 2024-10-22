#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PRODUCTOS][50];
    float precios[MAX_PRODUCTOS];
    int totalProductos = 0;

    // Validar la cantidad de productos para que no sea negativa
    do {
        printf("Cuantos productos desea ingresar (maximo %d): ", MAX_PRODUCTOS);
        scanf("%d", &totalProductos);
        if (totalProductos < 0) {
            printf("Error: La cantidad de productos no puede ser negativa.\n");
        }
    } while (totalProductos < 0);  // Repetir si el número es negativo.

    if (totalProductos > MAX_PRODUCTOS) {
        totalProductos = MAX_PRODUCTOS;
    }

    // Limpiar el buffer después de leer el número
    getchar();

    ingresarDatos(nombres, precios, totalProductos);
    printf("El precio total del inventario es: %.2f\n", calcularPrecioTotal(precios, totalProductos));
    encontrarCaroYBarato(nombres, precios, totalProductos);
    printf("El precio promedio de los productos es: %.2f\n", calcularPromedio(precios, totalProductos));

    char nombreBuscado[50];
    printf("Ingrese el nombre del producto que desea buscar: ");
    fgets(nombreBuscado, 50, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = 0;  // Eliminar el salto de línea.
    
    buscarProducto(nombres, precios, totalProductos, nombreBuscado);

    return 0;
}
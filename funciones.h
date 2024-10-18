#define MAX_PRODUCTOS 10

float ingresarDatos(char nombres[MAX_PRODUCTOS][20], float precios[MAX_PRODUCTOS], int totalProductos);
float calcularPrecioTotal(float precios[MAX_PRODUCTOS], int totalProductos);
float encontrarCaroYBarato(char nombres[MAX_PRODUCTOS][20], float precios[MAX_PRODUCTOS], int totalProductos);
float calcularPromedio(float precios[MAX_PRODUCTOS], int totalProductos);
void buscarProducto(char nombres[MAX_PRODUCTOS][20], float precios[MAX_PRODUCTOS], int totalProductos, char nombreBuscado[20]);
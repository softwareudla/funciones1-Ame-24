#define MAX_PRODUCTOS 10 

// Cambiar el tamaño de las cadenas de 20 a 50 para nombres largos
void ingresarDatos(char nombres[MAX_PRODUCTOS][50], float precios[MAX_PRODUCTOS], int totalProductos);
float calcularPrecioTotal(float precios[MAX_PRODUCTOS], int totalProductos);
float encontrarCaroYBarato(char nombres[MAX_PRODUCTOS][50], float precios[MAX_PRODUCTOS], int totalProductos);
float calcularPromedio(float precios[MAX_PRODUCTOS], int totalProductos);
void buscarProducto(char nombres[MAX_PRODUCTOS][50], float precios[MAX_PRODUCTOS], int totalProductos, char nombreBuscado[50]);

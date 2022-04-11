#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Producto {
    int productoID; //numero en ciclo iterativo
    int cantidad; //entre 1 y 10
    char *tipoProducto; //Algún valor del arreglo tipoProdutos
    float precioUnitario;//entre 10 - 100
};

struct Cliente {
    int clienteID; //Numerado en el ciclo iterativo
    char *nombreCliente; //ingresado por usuario
    int cantidadProductosAPedir; //aleatorio entre 1 y 5
    struct Producto *productos; //El tamaño de este arreglo depende de la variable cantidadProductosAPedir
};

int main (){

    int cantClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);

    struct Cliente **clientes;
    clientes=(struct Cliente)malloc(sizeof(struct Cliente) * cantClientes);



    return 0;
}
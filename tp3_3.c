#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

void cargarClientes(struct Cliente *clientes, char *tiposProductos[], int cantClientes);
void mostrarClientes(struct Cliente *clientes, int cantClientes);
float calcularPrecioProductos (int cantidadProductos, float precioProducto);

int main (){
    srand(time(NULL));
    srand48(time(NULL));
    /* srand48(getpid()); */
    char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cantClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    getchar();
    struct Cliente *clientes;
    clientes=(struct Cliente*)malloc(sizeof(struct Cliente) * cantClientes);

    cargarClientes(clientes,tiposProductos, cantClientes);
    mostrarClientes(clientes,cantClientes);

    free(clientes);


    return 0;
}

void cargarClientes(struct Cliente *clientes, char *tiposProductos[], int cantClientes){
    srand(time(NULL));
    char *aux=(char*)malloc(sizeof(char)*100);
    for(unsigned i=0;i<cantClientes;i++){
        clientes[i].clienteID= i+1;
        printf("\tINGRESE EL NOMBRE DEL CLIENTE %d\n", i+1);
        fgets(aux,100,stdin);
        fflush(stdin);
        clientes[i].nombreCliente=(char*)malloc(sizeof(char)*(strlen(aux)+1));
        strcpy(clientes[i].nombreCliente,aux);
        clientes[i].cantidadProductosAPedir= rand()%(5 -1 + 1)+1;

        clientes[i].productos=(struct Producto*)malloc(sizeof(struct Producto)*(clientes[i].cantidadProductosAPedir));
        for(unsigned a=0;a< clientes[i].cantidadProductosAPedir;a++){
            clientes[i].productos[a].productoID=a+1;
            clientes[i].productos[a].cantidad= rand() % (10 - 1 + 1) + 1;
            clientes[i].productos[a].tipoProducto=(char*)malloc(sizeof(char)*(strlen(tiposProductos[rand()%5])+1));
            strcpy(clientes[i].productos[a].tipoProducto, tiposProductos[rand()%5]);
            clientes[i].productos[a].precioUnitario= drand48() * (100.0 - 10.0) + 10.0;
        }
    }
}

void mostrarClientes(struct Cliente *clientes, int cantClientes){
    for(unsigned i=0;i<cantClientes;i++){
        printf("\tCLIENTE %d\n", i+1);
        printf("CLIENTE ID %d\n",clientes[i].clienteID);
        printf("NOMBRE DEL CLIENTE: ");
        puts(clientes[i].nombreCliente);
        printf("Cantidad de productos a perdir: %d\n\n",clientes[i].cantidadProductosAPedir);
        float total=0;
        for(unsigned a=0; a < clientes[i].cantidadProductosAPedir;a++){
            printf("PRODUCTO ID %d\n", clientes[i].productos[a].productoID);
            printf("CANTIDAD DE PRODUCTOS: %d\n", clientes[i].productos[a].cantidad);
            printf("TIPO DE PRODUCTO: ");
            puts(clientes[i].productos[a].tipoProducto);
            printf("PRECIO UNITARIO: %0.2f\n", clientes[i].productos[a].precioUnitario);
            printf("TOTAL DE LOS PRODUCTOS: %0.2f\n", calcularPrecioProductos(clientes[i].productos[a].cantidad, clientes[i].productos[a].precioUnitario));
            total += calcularPrecioProductos(clientes[i].productos[a].cantidad, clientes[i].productos[a].precioUnitario);
            printf("\n\n");
        }
        printf("TOTAL A PAGAR: %0.2f\n", total);
        printf("==========================================================================\n\n");
    }
}

float calcularPrecioProductos (int cantidadProductos, float precioProducto){
    return (float) (cantidadProductos * precioProducto);
}
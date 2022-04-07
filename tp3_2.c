#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    //char *nombres=(char *) malloc(5 * sizeof(char));  -> reseva 5 caracteres
    //char *nombres=(char *) malloc((strlen(aux)+1) * sizeof(char)); -> reserva la cantidad de caracteres que se ingresen en aux
    char *nombre[]=(char *) malloc(5 * sizeof(char));
    char *aux=(char*)malloc(100 * sizeof(char));
    *nombre=(char *) malloc((strlen(aux)+1) * sizeof(char));
    int i,j;
    for(i=0;i<5;i++){
        printf("Ingrese el nombre...\n");
        gets(aux);
        strcpy(nombre[i],aux);
    }
    for(j=0;j<5;j++){
        printf("\n\nNombre.....\n");
        puts(nombre[i]);
    }
    


    free(aux);
    free(nombre);

    return 0;
}
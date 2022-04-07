#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    /* char *nombres=(char *) malloc(5 * sizeof(char));  -> reseva 5 caracteres */
    /* char *nombres=(char *) malloc((strlen(aux)+1) * sizeof(char)); -> reserva la cantidad de caracteres que se ingresen en aux */

    /* ejemplo
    char **v
    v=(char**)malloc(n * sizeof(char*)) */
    char *nombre[5];
    char *aux;
    int i,j;
    for(i=0;i<5;i++){
        aux=(char*)malloc(100 * sizeof(char));
        printf("Ingrese el nombre...\n");
        gets(aux);
        nombre[i]=(char *) malloc((strlen(aux)+1) * sizeof(char));
        strcpy(nombre[i],aux);
    }
    free(aux);

    for(j=0;j<5;j++){
        printf("\n\nNombre.....\n");
        puts(nombre[j]);
    }
    for(j=0;j<5;j++){
        free(nombre[j]);
    }
    

    return 0;
}
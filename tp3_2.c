#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    char **nombres,*aux;
    int cant;
    printf("\tINGRESE LA CANTIDAD DE NOMBRES: ");
    scanf("%d", &cant);
    getchar();
    fflush(stdin);
    nombres=(char**)malloc(sizeof(char*)*cant);
    aux=(char*)malloc(sizeof(char)*100);

    printf("\t\tINGRESE LOS NOMBRES\n");
    for(unsigned i=0; i<cant;i++){
        printf("NOMBRE %d: \n\n",i+1);
        gets(aux);
        fflush(stdin);
        nombres[i]=(char*)malloc(sizeof(char)*(strlen(aux)+1));
        strcpy(nombres[i], aux);
    }
    free(aux);

    printf("\n\t\tNOMBRES: \n");
    for(unsigned i=0;i<cant;i++){
        puts(nombres[i]);
        free(nombres[i]);
    }
    free(nombres);
    return 0;
}
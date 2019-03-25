//
//  Principal.c
//  A-Shop
//
//  Created by Samuel Arturo Garrido Sánchez on 3/25/19.
//  Copyright © 2019 SamArtGS. All rights reserved.
//

#include <stdio.h>
int main(){
FILE *archivo;
char caracter;

archivo = fopen("prueba.txt","r");

if (archivo == NULL){
    printf("\nError de apertura del archivo. \n\n");
}
else{
    printf("\nEl contenido del archivo de prueba es \n\n");
    while((caracter = fgetc(archivo)) != EOF){
        printf("%c",caracter);
    }
}
fclose(archivo);
    return 0;
}

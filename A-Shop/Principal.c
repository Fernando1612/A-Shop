//
//  Principal.c
//  A-Shop
//
//  Created by Samuel Arturo Garrido Sánchez on 3/25/19.
//  Copyright © 2019 SamArtGS. All rights reserved.
//

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nombre[10];
    char apellido[10];
    char usuario[10];
    char pass[10];
    char area[10];
    int sueldo;
}Empleado;
//Venta de empleado
typedef struct {
    char producto[10];
    int venta;
    char fecha[9];
}Ventas;
typedef struct{
    char idArticulo[11];
    char nombre[10];
    int precioCompra;
    int precioVenta;
    int cantidad;
}Producto;
typedef struct{
    char nombre[10];
    int cantidadProdTotal;
    int MoneyTotalDepto;
}Departamento;
int getch(void);
void ventaArticulo(Producto produ[],Empleado emp);
int main(int argc, char **argv){
    
    //Lectura de los archivos principales
    //Agregar empleados empleados.add
    Empleado emp1,emp2,emp3,emp4,emp5;
    strcpy(emp1.usuario,"nana");
    strcpy(emp1.pass,"nana");
    Producto prod1,prod2,prod3,prod4;
    
    //Bloque inicial para carga
    
    strcpy(prod1.idArticulo,"12GOPR24C4");
    strcpy(prod2.idArticulo,"2132341GSD");
    strcpy(prod3.idArticulo,"GEF3R123DS");
    strcpy(prod4.idArticulo,"21FWDSGME2");
    
    strcpy(prod1.nombre,"Producto1");
    strcpy(prod2.nombre,"Producto2");
    strcpy(prod3.nombre,"Producto3");
    strcpy(prod4.nombre,"Producto4");
    
    prod1.precioVenta = 44;
    prod2.precioVenta = 62;
    prod3.precioVenta = 12;
    prod4.precioVenta = 122;
    
    prod1.cantidad = 122;
    prod2.cantidad = 1233;
    prod3.cantidad = 111;
    prod4.cantidad = 1245;
    
    Producto productos[]= {prod1,prod2,prod3,prod4};
    
    
    
    
    //int tamanio = (int )malloc(sizeof(Empleado));
    Empleado emp[] = {emp1,emp2,emp3,emp4,emp5};
    
    //Bloque de pruebas
    bool bandera = true;
    
    do{
    char nombreusuario[10];
    char contrasena[10];
    printf("\tBienvenido al sistema de punto de venta de ASHOP\n");
    printf("Ingrese su nombre de usuario: ");
    scanf("%s",nombreusuario);
    printf("\nIngrese su contraseña: ");
    scanf("%s",contrasena);
    int i;
    for(i=0;i<4;i++){
        if(strcmp(emp[i].usuario,nombreusuario)==0 && strcmp(emp[i].pass,contrasena)==0){
            
            bandera = false;
            break;
        }else{
            printf(" NOMBRE DE USUARIO O CONTRASEÑA INCORRECTO");
            bandera = true;
        }
    }
    }while(bandera);
    
    printf("ACCEDISTE!\n");
    printf("%d",productos[3].cantidad);
    ventaArticulo(productos,emp1);
    printf("%d",productos[3].cantidad);
    /*
    contrasena = getch();
    FILE *archivo;
    char caracter;
    archivo = fopen("usuarios.txt","r");
    if (archivo == NULL){
    printf("\nError. \n\n");
    }else{
    while((caracter = fgetc(archivo)) != EOF){
        printf("%c",caracter);
    }
    }
    fclose(archivo);*/
    return 0;
}
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
void agregarEmpleado(){
    return;
}
void ventaArticulo(Producto *produ,Empleado emp){
    char producto[11];
    int productoCan = 0;
    printf("-----------------\n");
    printf("\tVENTA DE PRODUCTO. ");
    printf("--------------------\n");
    printf("\nProductos disponibles: \n");
    for(int i=0;i<sizeof(&produ);i++){
        if(produ[i].cantidad>0){
            printf("ID: %s,  Nombre: %s   , Precio: %d \n",produ[i].idArticulo,produ[i].nombre,produ[i].precioVenta);
        }
    }
    int cantidad = 0;
    printf("Ingrese la cantidad de artículos que desea comprar: ");
    scanf("%d",&cantidad);
    for(int p = 0;p<cantidad;p++){
        printf("Ingrese el ID del producto a comprar: ");
        scanf("%s",producto);
        printf("Ingrese la cantidad de productos de éste que quiera comprar: ");
        scanf("%d",&productoCan);
        for(int i=0;i<sizeof(&produ);i++){
            if(strcmp(produ[i].idArticulo, producto)==0){
                produ[i].cantidad = produ[i].cantidad-productoCan;
                printf("%d \n",produ[i].cantidad);
            }
        }
    }
    printf("Le hemos generado su recibo: \n");
    
    FILE *fp;
    system("touch recibo.txt");
    fp = fopen ("recibo.txt", "wr" );
    if (fp==NULL) {
        fputs ("Error al generar el recibo",stderr);
        exit (1);
    }
    fprintf (fp, "\tTienda A Shop Retail\n");
    fprintf(fp, "\tAv. Proteco #33, Av. Tabasco 2000, Villahermosa, Tabasco.\n");
    fprintf(fp,"Empleado: %s",emp.nombre);
    fprintf(fp, "---------------\n\tRECIBO DE COMPRA\n---------------");
    int j;
    for(j = 0; j < sizeof(&produ); j++){
        fprintf(fp, "%s - %s : $%d , Cantidad: %d   Sub: %d\n",produ[j].idArticulo,produ[j].nombre,produ[j].precioVenta,productoCan,produ[j].precioVenta*productoCan);
    }
    //fprintf(fp, "\n\t TOTAL : $%d\n",);
    fprintf(fp, "\n\tA SHOP agradece su preferencia\n");
    fclose(fp);
}




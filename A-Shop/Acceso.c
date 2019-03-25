//
//  Acceso.c
//  A-Shop
//
//  Created by Samuel Arturo Garrido Sánchez on 3/24/19.
//  Copyright © 2019 SamArtGS. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Acceso.h"
typedef struct {
    char nombre[20];
    char user[8];
    char contrasena[8];
    char area[5];
    int sueldo;
}Empleado;
typedef struct {
    int costo;
    int precio;
    char nombre[10];
    char categoria[10];
}Producto;

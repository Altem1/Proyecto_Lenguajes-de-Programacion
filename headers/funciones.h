#ifndef FUNCIONES_H
#define FUNCIONES_H

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define LONG 5

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    int tipo;
    char basurero;
}TRegistros;

char *nombre();
char *crear_ar();
void capturar(char *nombre_archivo);
void consultar(char *nombre_archivo);
int menu_principal();
int menu_secundario();
void *crea_dato_generico(int tipo);
int menu_tipo_dato();

#endif

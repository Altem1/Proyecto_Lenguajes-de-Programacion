#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    int tipo;
    char basurero[100];
}TRegistros;

char *nombre();
char *crear_ar();
void capturar(char *nombre_archivo);
void consultar(char *nombre_archivo);
int menu_principal();
int menu_secundario();
int menu_tipo_dato();
void limpiar_y_pausar();

#endif

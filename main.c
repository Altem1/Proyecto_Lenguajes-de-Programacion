#include "headers/funciones.h"

int main(){
    int opcion_principal, opcion_secundaria;
    char *nombre_archivo = NULL;

    do {
        opcion_principal = menu_principal();
        if ((opcion_principal == 1 || opcion_principal == 2)) {
            nombre_archivo = (opcion_principal == 1) ? crear_ar() : nombre();
            if (nombre_archivo == NULL) continue;

            do {
                opcion_secundaria = menu_secundario();
                switch (opcion_secundaria) {
                    case 1:
                        capturar(nombre_archivo);
                        limpiar_y_pausar(); 
                        break;
                    case 2: 
                        consultar(nombre_archivo);
                        limpiar_y_pausar(); 
                        break;
                    case 3:
                        printf("Regresando...\n");
                        break;
                }
            } while(opcion_secundaria != 3);

            free(nombre_archivo);
            nombre_archivo = NULL;
        }
    } while (opcion_principal != 3);
    
    return 0;
}

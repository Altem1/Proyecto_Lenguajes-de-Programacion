#include "headers/funciones.h"

int main(){

    int opcion_principal, opcion_secundaria;
    char *nombre_archivo;

    do{

        opcion_principal=menu_principal();

        switch (opcion_principal){
            case 1:
                nombre_archivo = crear_ar();
                //Crear nuevo archivo
                do{
                    opcion_secundaria = menu_secundario();
                    //por mientras hago el switch aqui luego optimizo
                    switch (opcion_secundaria){
                        case 1:
                            //capturar
                            break;
                        
                        case 2: 
                            //consultar
                        default:
                            printf("Regresando el menu anterior");
                            break;
                            return;
                    }

                }while(opcion_secundaria > 0 && opcion_principal < 3);
                free(nombre);
                break;
            case 2: 
                nombre_archivo = nombre();
                //Abrir un archivo existente
                 do{
                    opcion_secundaria = menu_secundario();
                    //por mientras hago el switch aqui luego optimizo
                    switch (opcion_secundaria){
                        case 1:
                            //capturar
                            break;
                        
                        case 2: 
                            //consultar
                        default:
                            printf("Regresando el menu anterior");
                            break;
                            return;
                    }

                }while(opcion_secundaria > 0 && opcion_principal < 3);
                break;
            default:
                printf("Saliendo del menu principal");
                break;
        }

    }while (opcion_principal < 3 && opcion_principal > 0);
    

}


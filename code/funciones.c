#include "../headers/funciones.h"

int menu_principal(){

    int op;

    printf("Bienvenido! \n Selecciones una opcion: \n");
    printf("\t1- Crear un nuevo archivo\n");
    printf("\t2- Abrir un archivo existente");
    printf("\t3.- Salir");
    printf("\t Ingresa tu seleccion: ");
    scanf("%d", &op);
    return(op);

}

int menu_secundario(){

    int op;

    printf("Selecciones una opcion: \n");
    printf("\t1- Capturar\n");
    printf("\t2- Consultar");
    printf("\t3.- Regresar al menu anterior");
    printf("\t Ingresa tu seleccion: ");
    scanf("%d", &op);
    return(op);
    
}

char *crear_ar(){

    //Datos necesarios dentro de la funcion
    char *nombre_archivo = nombre ();
    //Creando el archivo
    FILE *f;
    f = fopen(nombre_archivo, "wb+");
    if(!f){
        printf("Error: no se pudo crear el archivo");
        return NULL;
    }

    //cerramos el archivo se estara abriendo y cerrando 
    //cada que se haga un cambio en el menu secundario
    fclose(f);

    //regresamos el nombre
    return nombre_archivo;

}

char *nombre(){

    char *nombre_archivo = (char *)malloc(100*sizeof(char));
    printf("Ingresa el nombre del nuevo archivo\nDe preferencia sin espacios o usa '- , _' ");
    scanf("%99s", nombre_archivo);
    return nombre_archivo;
}

void capturar(char *nombre_archivo){

    void *dato;

    TRegistros registro;

    int opcion;
    FILE *f;
    f = fopen(nombre_archivo, "ab+");
    if(!f){
        printf("Error el archivo no pudo ser abierto");
        return;
    }

    opcion = menu_tipo_dato();
    registro.tipo = opcion;
    dato = crea_dato_generico(opcion);



}

void consultar(char *nombre_archivo){

    FILE *f;
    f = fopen(nombre_archivo, "ab+");
    if(!f){
        printf("Error el archivo no pudo ser abierto");
        return;
    }

}

void *crea_dato_generico(int tipo){

    void *ptr;
    int tam;

    switch (tipo){
        case INT:
            ptr = malloc(sizeof(int));
            break;
        
        case FLOAT:
            ptr = malloc(sizeof(float));
            break;

        case CHAR:
            ptr = malloc(sizeof(char));
            break;
        
        case DOUBLE:
            ptr = malloc(sizeof(double));
            break;
        
        case LONG:
            ptr = malloc(sizeof(long));
        default:
            break;
        }

    return ptr;
}

int menu_tipo_dato(){

    int op;
    printf("Elige una opción: \n");
    printf("Opcion 1: int \n");
    printf("Opcion 2: float \n");
    printf("Opcion 3: char \n");
    printf("Opcion 4: double \n");
    printf("Opcion 5: long \n");
    printf("Opcion 6: Salir \n");
    printf("Elige: ");
    scanf("%d", &op);

    return op;
}
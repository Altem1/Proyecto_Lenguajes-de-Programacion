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

    TRegistros registro; 
    int opcion;
    FILE *f;

    memset(registro.basurero, 0, sizeof(registro.basurero));

    f = fopen(nombre_archivo, "ab+");
    if(!f){
        printf("Error el archivo no pudo ser abierto");
        return;
    }

    opcion = menu_tipo_dato();
    registro.tipo = opcion;
    
    if(opcion == 1){
        //Enteros
        int valor;
        printf("Ingresa el valor del numero: ");
        scanf("%d", &valor);
        memcpy(registro.basurero, &valor, sizeof(int));
    }else if(opcion == 2){
        //Flotantes
        float valor;
        printf("Ingresa el valor del numero: ");
        scanf("%d", &valor);
        memcpy(registro.basurero, &valor, sizeof(float));
    }else if(opcion == 3){
        //Caracteres o cadenas
        printf("Ingresa tu cadena de caracteres: ");
        scanf("%50[^\n]", registro.basurero);
        memcpy(registro.basurero, &registro.basurero, sizeof(char)*50);
    }else if(opcion == 4){
        //Double
        double valor;
        printf("Ingresa el valor del numero: ");
        scanf("%lf", &valor);
        memcpy(registro.basurero, &valor, sizeof(double));
    }else if(opcion == 5){
        //long
        long valor;
        printf("Ingresa el valor del numero: ");
        scanf("%ld", &valor);
        memcpy(registro.basurero, &valor, sizeof(long));
    }else{

        printf("Error: La opcion que introduciste es NO VALIDA");

    }

    fwrite(&registro, sizeof(registro), 1, f);
    fclose(f);

}

void consultar(char *nombre_archivo){

    FILE *f;
    f = fopen(nombre_archivo, "ab+");
    if(!f){
        printf("Error el archivo no pudo ser abierto");
        return;
    }

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
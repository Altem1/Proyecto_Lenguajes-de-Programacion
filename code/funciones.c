#include "../headers/funciones.h"

int menu_principal(){

    int op;

    printf("Bienvenido! \n Selecciones una opcion: \n");
    printf("\t1- Crear un nuevo archivo\n");
    printf("\t2- Abrir un archivo existente\n");
    printf("\t3.- Salir\n");
    printf("\t Ingresa tu seleccion: ");
    scanf("%d", &op);
    return(op);

}

int menu_secundario(){

    int op;

    printf("Selecciones una opcion: \n");
    printf("\t1- Capturar\n");
    printf("\t2- Consultar\n");
    printf("\t3.- Regresar al menu anterior\n");
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
    //se crea el buffer el nombre del archivo para darle uso
    char *buffer = (char *)malloc(100*sizeof(char));
    if(buffer == NULL) return NULL;
    
    printf("Ingresa el nombre del archivo\nDe preferencia sin espacios o usa '- , _' \n:");
    scanf("%99s", buffer);

    //creamos el puntero nombre_archivo 
    char *nombre_archivo = (char *)malloc(256 * sizeof(char));
    if (nombre_archivo == NULL) return NULL;

    //creamos la cadena donde se guardara la direccion completa de donde estara el archivo
    //es como concatenar pero poder asignar un tipo a un puntero en este caso %s
    sprintf(nombre_archivo, "Archivos/%s", buffer);

    //regresamos el nombre con la direccion de la carpeta y nombre del archivo
    //se hace unicamente en  esta funcion al ser la funcion raiz de main

    free(buffer);

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
        scanf("%f", &valor);
        memcpy(registro.basurero, &valor, sizeof(float));
    }else if(opcion == 3){
        //Caracteres o cadenas
        char aux_texto[50];
        printf("Ingresa el texto: ");
        scanf(" %49[^\n]", aux_texto);

        memcpy(registro.basurero, aux_texto, sizeof(char) * 50);
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

void consultar(char *nombre_archivo) {

    int indice;

    printf("¿Que numero de registro quieres consultar? (0, 1, 2...): ");
    scanf("%d", &indice);

    FILE *f = fopen(nombre_archivo, "rb");
    if (!f) return;

    fseek(f, 0, SEEK_END);
    long tamano_total = ftell(f);
    int total_registros = tamano_total / sizeof(TRegistros);

    if (indice < 0 || indice >= total_registros) {
        //Validar que ese registro existe
        printf("Error: Ese registro no existe. Total de registros: %d\n", total_registros);
        fclose(f);
        return;
    }

    //me muevo al lugar donde esta
    fseek(f, indice * sizeof(TRegistros), SEEK_SET);

    //creo un struct auxiliar para copiar la informacion
    TRegistros aux;
    fread(&aux, sizeof(TRegistros), 1, f);

    //Le doy informacion sobre el registro
    printf("\nRegistro #%d - Tipo [%d]: ", indice, aux.tipo);
    
    //dependiendo el tipo de dato le muestro en pantalla el dato
    if (aux.tipo == 1) { 
        //Entero
        int val;
        memcpy(&val, aux.basurero, sizeof(int));
        printf("%d\n", val);
    }else if (aux.tipo == 2) {
        //Flotante
        float val;
        memcpy(&val, aux.basurero, sizeof(float));
        printf("%f\n", val);
    }else if(aux.tipo == 3) {
        //caracter
        printf("%s\n", aux.basurero);
    }else if(aux.tipo == 4){
        //double
        double val;
        memcpy(&val, aux.basurero, sizeof(double));
        printf("%lf\n", val);
    }else if(aux.tipo == 5){
        //long
        long val;
        memcpy(&val, aux.basurero, sizeof(long));
        printf("%ld\n", val);

    }

    fclose(f);
}

void limpiar_y_pausar() {
    printf("\nPresiona Enter para continuar...");
    fflush(stdout);
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    getchar();
    
    printf("\033[H\033[J"); 
}

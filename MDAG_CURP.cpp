// Mauro Daniel Arango Gómez     Matrícula: 379620
// Descripción: CURP
// Fecha: 14 Octubre 2025    Modif: 14 Octubre 2025
// MDAG_CURP.cpp

#include "llenar_curp.h"
void imprimir_tabla(char apellido_paterno[], char apellido_materno[], char nombre[], char curp[]);

int main()
{

    srand(time(NULL));

    char CURP[19] = {'\0'};

    char AP_PAT[50], AP_MAT[50], NOMBRE[50];

    int ANIO, MES, DIA;

    // llenar curp
    datos(AP_PAT, AP_MAT, NOMBRE);

    posicion_0_3(CURP, AP_PAT, AP_MAT, NOMBRE);

    ANIO = posicion_4_9(CURP, ANIO, MES, DIA);

    posicion_10(CURP);

    posicion_11_12(CURP);

    posicion_13_15(CURP, AP_PAT, AP_MAT, NOMBRE);

    posicion_16(CURP, ANIO);

    // validar curp

    validar_letras(CURP);

    palabrotas(CURP);

    posicion_17(CURP);

    imprimir_tabla(AP_PAT, AP_MAT, NOMBRE, CURP);

    return 0;
}

void imprimir_tabla(char apellido_paterno[], char apellido_materno[], char nombre[], char curp[])
{

    printf(" ------------------- --------------------------- \n");
    printf("| Apellido Paterno  | %-25s |\n", apellido_paterno);
    printf("| Apellido Materno  | %-25s |\n", apellido_materno);
    printf("| Nombre(s)         | %-25s |\n", nombre);
    printf("| CURP              | %-25s |\n", curp);
    printf(" ------------------- --------------------------- \n");
}

// Mauro Daniel Arango Gómez     Matrícula: 379620
// Descripción: validar curp
// Fecha: 14 Octubre 2025    Modif: 14 Octubre 2025
// validar_curp.h
#include "mauro.h"
#include <string.h>
#include <ctype.h>

char primera_vocal_interna(char cadena[]);
char primera_consonante_interna(char cadena[]);
void palabrotas(char curp[]);
void validar_letras(char cadena[]);
int compuesto(char cadena[]);
void nombre_valido_inicial(char nombre[], char inicial_final[]);
void preapellido(char apellido[]);
void eliminar_espacios(char cadena[]);

char primera_vocal_interna(char cadena[])
{
    char vocales[] = "AEIOUÁÉÍÓÚÀÈÌÒÙÄËÏÖÜaeiouáéíóúàèìòùäëïöü";
    int i, j;
    for (i = 1; cadena[i] != '\0'; i++)
    {
        for (j = 0; vocales[j] != '\0'; j++)
        {
            if (cadena[i] == vocales[j])
            {
                mayusculas(cadena);
                return cadena[i];
            }
        }
    }
    return 'X';
}

char primera_consonante_interna(char cadena[])
{
    char vocales[] = "AEIOUÁÉÍÓÚÀÈÌÒÙÄËÏÖÜaeiouáéíóúàèìòùäëïöü";
    int i, j, es_vocal;

    mayusculas(cadena);
    for (i = 1; cadena[i] != '\0'; i++)
    {
        while (cadena[i] == ' ')
        {
            i++;
        }

        es_vocal = 0;
        for (j = 0; vocales[j] != '\0'; j++)
        {
            if (cadena[i] == vocales[j])
            {
                es_vocal = 1;
            }
        }

        if (es_vocal == 0)
        {
            if ((unsigned char)cadena[i] == 165 || (unsigned char)cadena[i] == 164)
            {
                return 'X';
            }
            if (cadena[i] >= 'A' && cadena[i] <= 'Z')
            {
                return cadena[i];
            }
        }
    }

    return 'X';
}

void palabrotas(char curp[])
{
    char palabras_prohibidas[80][5] = {
        "BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGO", "CAKA", "CAKO", "WUEY",
        "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO",
        "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA",
        "KAKO", "KAGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO",
        "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR",
        "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE",
        "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO",
        "RUIN", "SENO", "TETA", "VACA", "CAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI"};

    int i, j;
    int len = 18;

    for (i = 0; i <= len - 4; i++)
    {
        for (j = 0; j < 80; j++)
        {
            if (iguales4(curp + i, palabras_prohibidas[j]))
            {
                curp[i + 1] = 'X';
            }
        }
    }
}

void validar_letras(char cadena[])
{
    char letras[5][23] = {
        "aáàâãAÁÀÂÃ",
        "eéèêëEÉÈÊË",
        "iíìîïIÍÌÎÏ",
        "oóòôõöOÓÒÔÕÖ",
        "uúùûüUÚÙÛÜ"};
    char resultado[5] = {'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; cadena[i] != '\0'; i++)
    {
        int remplazado = 0;
        int j = 0;

        while (j < 5 && !remplazado)
        {
            int k = 0;
            while (letras[j][k] != '\0' && !remplazado)
            {
                if (cadena[i] == letras[j][k])
                {
                    cadena[i] = resultado[j];
                    remplazado = 1;
                }
                k++;
            }
            j++;
        }

        if (!remplazado)
        {
            if (cadena[i] == '/' || cadena[i] == '-' || cadena[i] == '.' || cadena[i] == '_')
            {
                cadena[i] = 'X';
            }
        }
    }
}

int compuesto(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == ' ')
        {
            return 1;
        }
    }
    return 0;
}

void nombre_valido_inicial(char nombre[], char inicial_final[])
{
    char nombres_baneados[6][6] = {"MARIA", "MA.", "MA", "JOSE", "J", "J."};

    char primer_nombre[50] = "";
    char segundo_nombre[50] = "";

    int i = 0, j = 0;

    while (nombre[i] == ' ')
    {
        i++;
    }
    while (nombre[i] != ' ' && nombre[i] != '\0')
    {
        primer_nombre[j++] = nombre[i++];
    }
    primer_nombre[j] = '\0';

    while (nombre[i] == ' ')
        i++;
    j = 0;
    while (nombre[i] != '\0')
    {
        segundo_nombre[j++] = nombre[i++];
    }
    segundo_nombre[j] = '\0';

    mayusculas(primer_nombre);
    mayusculas(segundo_nombre);

    int baneado = 0;
    for (i = 0; i < 6; i++)
    {
        if (iguales(primer_nombre, nombres_baneados[i]) == 0)
        {
            baneado = 1;
            break;
        }
    }

    if (baneado && segundo_nombre[0] != '\0')
    {
        inicial_final[0] = segundo_nombre[0];
    }
    else
    {
        inicial_final[0] = primer_nombre[0];
    }
    inicial_final[1] = '\0';
}

void preapellido(char apellido[])
{
    char preposiciones[20][5] = {
        "DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD",
        "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC",
        "VAN", "VON", "Y"};

    int inicio = 0;
    int i, j, k;
    int procesando = 1;

    while (procesando)
    {
        while (apellido[inicio] == ' ')
        {
            inicio++;
        }

        char palabra[50];
        i = 0;
        while (apellido[inicio] != ' ' && apellido[inicio] != '\0')
        {
            palabra[i++] = apellido[inicio++];
        }
        palabra[i] = '\0';

        int es_preposicion = 0;
        for (k = 0; k < 20; k++)
        {
            if (iguales(palabra, preposiciones[k]))
            {
                es_preposicion = 1;
                break;
            }
        }

        if (es_preposicion == 0)
        {
            int m = 0;
            for (j = 0; palabra[j] != '\0'; j++)
            {
                apellido[m++] = palabra[j];
            }

            while (apellido[inicio] != '\0')
            {
                apellido[m++] = apellido[inicio++];
            }

            apellido[m] = '\0';
            procesando = 0;
        }
    }
}

void eliminar_espacios(char cadena[])
{
    int i = 0, j = 0;
    while (cadena[i] == ' ')
    {
        i++;
    }

    while (cadena[i] != '\0')
    {
        if (cadena[i] != ' ')
        {
            cadena[j++] = cadena[i];
        }
        else
        {
            if (j > 0 && cadena[j - 1] != ' ')
            {
                cadena[j++] = ' ';
            }
        }
        i++;
    }

    if (j > 0 && cadena[j - 1] == ' ')
    {
        j--;
    }

    cadena[j] = '\0';
}
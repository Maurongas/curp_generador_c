#include "alumno.h"

void burbuja(Ts_alumno vector[], int m)
{
    Ts_alumno temp;
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - i - 1; j++)
            if (vector[j].matricula > vector[j + 1].matricula)
            {
                temp = vector[j + 1];
                vector[j + 1] = vector[j];
                vector[j] = temp;
            }
}

void seleccion(Ts_alumno vector[], int m)
{
    Ts_alumno temp;
    for (int i = 0; i < m - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < m; j++)
            if (vector[j].matricula < vector[min_idx].matricula)
                min_idx = j;
        temp = vector[min_idx];
        vector[min_idx] = vector[i];
        vector[i] = temp;
    }
}

void insercion(Ts_alumno vector[], int m)
{
    Ts_alumno key;
    int j;
    for (int i = 1; i < m; i++)
    {
        key = vector[i];
        j = i - 1;
        while (j >= 0 && vector[j].matricula > key.matricula)
        {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = key;
    }
}

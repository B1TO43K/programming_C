#include <stdio.h>
#include <stdlib.h>
#include "func.h"

double** calc(int n, double* mat1, double** mat2, char op) { //  char op: Символ операции (+, - или *).
    double** result = NULL;
    int i;
    int j;
    int k;

    // Выделение памяти для результирующей матрицы
    result = (double**)malloc(n * sizeof(double*));
    if (result == NULL) {
        perror("Memory allocation error for result");
        return NULL;
    }
    for (i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
        if (result[i] == NULL) {
            perror("Memory allocation error for result[i]");
            // Освобождаем ранее выделенную память
            for (k = 0; k < i; k++) {
                free(result[k]);
            }
            free(result);
            return NULL;
        }
    }

    if (op == '+') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                result[i][j] = ((double**)mat1)[i][j] + mat2[i][j];
            }
        }
    } else if (op == '-') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                result[i][j] = ((double**)mat1)[i][j] - mat2[i][j];
            }
        }
    } else if (op == '*') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                result[i][j] = 0;
                for (k = 0; k < n; k++) {
                    result[i][j] += ((double**)mat1)[i][k] * mat2[k][j];
                }
            }
        }
    } else {
        printf("Некорректная операция.\n");


        
        // Освобождаем ранее выделенную память
        for (i = 0; i < n; i++) {
            free(result[i]);
        }
        free(result);
        return NULL;
    }

    return result;
}

/*
1. Разместить в динамической памяти 2 массива - 2 матрицы размерностью n на n с элементами типа double (с консоли). 
2. Ввести с консоли знак операции: '+', '-' или '*'. 
3. Написать функцию, вычисляющую сум-му, разность или произведение данных матриц (их передать по указателю) возвра-щающую указатель на массив-результат. 
4. Разместить эту функцию в отдельном модуле (отличном от того, где располагается функция main()). 
5.Выдать на консоль значения по-лученного вектора. */

/*Calc — это функция, которая выполняет над ненулевыми вещественными числами одну из арифметических операций
и возвращает её результат*/

/*malloc(): Функция, которая выделяет память из кучи*/

/*NULL в языке программирования Си — макрос, значением которого является константа нулевого указателя*/


#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
	
    int N;
    double **mat1;  
    double **mat2;
    double **result = NULL;
    char f;
    int i;
    int j;

    printf("Enter the size of the matrix: ");
    scanf("%d", &N);

    // Выделяем память для mat1 (с проверкой ошибок)
    mat1 = (double**)malloc(N * sizeof(double *)); // Память под строки
    //Проверка на ошибку.
    if (!mat1) {
        perror("MEMORY ERROR mat1");
        return 1;
    }
    for (i = 0; i < N; i++) {
        mat1[i] = (double*)malloc(N * sizeof(double)); // Память под элементы в строке
        if (!mat1[i]) {
            perror("MEMORY ERROR mat1[i]");
            // Освобождаем ранее выделенную память
            for (j = 0; j < i; j++) {
                free(mat1[j]);
            }
            free(mat1);
            return 1;
        }
    }

    // Выделяем память для mat2 (с проверкой ошибок)
    mat2 = (double **)malloc(N * sizeof(double *));
    //Проверка на ошибку.
    if (!mat2) {
        perror("MEMORY ERROR mat2");
        // Освобождаем память, выделенную для mat1, если что-то пошло не так.
        for (i = 0; i < N; i++) {
            free(mat1[i]);
        }
        free(mat1);
        return 1;
    }
    for (i = 0; i < N; i++) {
        mat2[i] = (double *)malloc(N * sizeof(double));
        if (!mat2[i]) {
            perror("MEMORY ERROR mat2[i]");
            // Освобождаем ранее выделенную память.
            for (j = 0; j < i; j++) {
                free(mat2[j]);
            }
            free(mat2);
            for (j = 0; j < N; j++) {
                free(mat1[j]);
            }
            free(mat1);
            return 1;
        }
    }

    printf("Enter the elements of the matrix one:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("mat1[%d][%d]: ", i, j);
            scanf("%lf", &mat1[i][j]); 
        }
    }


    printf("Enter the elements of the matrix two:\n");
    for (i = 0; i < N; i++) { //перебирает строки матрицы. Цикл будет выполняться, пока i меньше, чем N 
        for (j = 0; j < N; j++) { //Это внутренний цикл, который перебирает столбцы матрицы. Цикл будет выполняться, пока j меньше, чем N
            printf("mat2[%d][%d]: ", i, j); //выводит на экран подсказку, предлагая пользователю ввести элемент матрицы с индексами i и j
            scanf("%lf", &mat2[i][j]); 
        }
    }

    printf("Enter the operation sign: + / - / * \nYour answer: ");
    scanf(" %c", &f);
    printf("\n");

    result = calc(N, (double*)mat1, mat2, f); 

    if (result != NULL) { //вернула ли функция calc указатель на результирующую матрицу / NULL
        printf("Result:\n"); //Если result не NULL - вывод
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                printf("%.2lf ", result[i][j]); 
            }
            printf("\n");
        }
        // Освобождение памяти для результирующей матрицы
        for (i = 0; i < N; i++) {
            free(result[i]);
        }
        free(result);

    } else {
      printf("Вычисление не удалось.\n");
    }

    // Освобождаем память
    for (i = 0; i < N; i++) {
        free(mat1[i]);
        free(mat2[i]);
    }
    free(mat1);
    free(mat2);
    return 0;
}

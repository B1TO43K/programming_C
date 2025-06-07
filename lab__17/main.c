#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// Объявляем глобальные переменные для счетчиков
int row, col;

// Функция для создания файла со случайными числами
void generate_number_file(int count) {
    FILE *file = fopen("input.txt", "w"); 
    
    // Инициализируем генератор случайных чисел
    srand(time(0));
    for (row = 0; row < count; row++) {
        // Генерируем числа от 1 до 20 вместо 1 до 10
        fprintf(file, "%d ", rand() % 20 + 1);
    }

    fclose(file);
}

// Функция для обработки чисел и создания выходного файла
void process_numbers(int count) {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w"); 
    
    int value;
    for (row = 0; row < count; row++) {
        fscanf(input, "%d", &value);

        // Проверяем делимость и записываем соответствующие строки
        if (value % 35 == 0) { // 5*7=35, так эффективнее
            fprintf(output, "FIVESEVEN ");
        } 
        else if (value % 5 == 0) {
            fprintf(output, "FIVE ");
        } 
        else if (value % 7 == 0) {
            fprintf(output, "SEVEN ");
        } 
        else {
            fprintf(output, "%d ", value);
        }
    }

    fclose(input);
    fclose(output);
}

// Функция для создания матрицы и вычисления сумм
void create_matrix_and_calculate(int count) {
    FILE *input = fopen("input.txt", "r");

    // Вычисляем размеры матрицы
    int dimension = (int)ceil(sqrt(count)); // Округляем вверх
    
    // Динамически выделяем память для матрицы
    int **matrix = (int **)malloc(dimension * sizeof(int *));
    for (row = 0; row < dimension; row++) {
        matrix[row] = (int *)malloc(dimension * sizeof(int));
    }

    // Заполняем матрицу числами из файла
    int number, elements = 0;
    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            if (elements < count && fscanf(input, "%d", &number) == 1) {
                matrix[row][col] = number;
                elements++;
            } 
            else {
                matrix[row][col] = -1; // Заполняем -1 вместо 0
            }
        }
    }

    fclose(input);

    // Выводим матрицу
    printf("Matrix %dx%d:\n", dimension, dimension);
    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            printf("%4d ", matrix[row][col]);
        }
        printf("\n");
    }

    // Вычисляем и выводим суммы строк
    printf("\nRow sums:\n");
    for (row = 0; row < dimension; row++) {
        int sum_row = 0;
        for (col = 0; col < dimension; col++) {
            if (matrix[row][col] != -1) {
                sum_row += matrix[row][col];
            }
        }
        printf("Row %d: %d\n", row + 1, sum_row);
    }

    // Вычисляем и выводим суммы столбцов
    printf("\nColumn sums:\n");
    for (col = 0; col < dimension; col++) {
        int sum_col = 0;
        for (row = 0; row < dimension; row++) {
            if (matrix[row][col] != -1) {
                sum_col += matrix[row][col];
            }
        }
        printf("Column %d: %d\n", col + 1, sum_col);
    }

    // Освобождаем память
    for (row = 0; row < dimension; row++) {
        free(matrix[row]);
    }
    free(matrix);
}

int main() {
    clock_t start = clock();

    int number_count;
    printf("Enter number count: ");
    scanf("%d", &number_count);

    generate_number_file(number_count);
    process_numbers(number_count);
    create_matrix_and_calculate(number_count);

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time: %.6f seconds\n", duration);

    return 0;
}

